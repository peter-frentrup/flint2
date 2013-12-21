/*=============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

=============================================================================*/
/******************************************************************************

    Copyright (C) 2010,2011 Fredrik Johansson
    Copyright (C) 2013 Mike Hansen

******************************************************************************/


#ifdef T

#include "templates.h"

void
TEMPLATE(T, mat_solve_triu_recursive) (TEMPLATE(T, mat_t) X,
                                       const TEMPLATE(T, mat_t) U,
                                       const TEMPLATE(T, mat_t) B,
                                       int unit, const TEMPLATE(T, ctx_t) ctx)
{
    TEMPLATE(T, mat_t) UA, UB, UD, XX, XY, BX, BY;
    slong r, n, m;

    n = U->r;
    m = B->c;
    r = n / 2;

    if (n == 0 || m == 0)
        return;

    /*
       Denoting inv(M) by M^, we have:

       [A B]^ [X]  ==  [A^ (X - B D^ Y)]
       [0 D]  [Y]  ==  [    D^ Y       ]
     */

    TEMPLATE(T, mat_window_init) (UA, U, 0, 0, r, r, ctx);
    TEMPLATE(T, mat_window_init) (UB, U, 0, r, r, n, ctx);
    TEMPLATE(T, mat_window_init) (UD, U, r, r, n, n, ctx);
    TEMPLATE(T, mat_window_init) (BX, B, 0, 0, r, m, ctx);
    TEMPLATE(T, mat_window_init) (BY, B, r, 0, n, m, ctx);
    TEMPLATE(T, mat_window_init) (XX, X, 0, 0, r, m, ctx);
    TEMPLATE(T, mat_window_init) (XY, X, r, 0, n, m, ctx);

    TEMPLATE(T, mat_solve_triu) (XY, UD, BY, unit, ctx);
    TEMPLATE(T, mat_submul) (XX, BX, UB, XY, ctx);
    TEMPLATE(T, mat_solve_triu) (XX, UA, XX, unit, ctx);

    TEMPLATE(T, mat_window_clear) (UA, ctx);
    TEMPLATE(T, mat_window_clear) (UB, ctx);
    TEMPLATE(T, mat_window_clear) (UD, ctx);
    TEMPLATE(T, mat_window_clear) (BX, ctx);
    TEMPLATE(T, mat_window_clear) (BY, ctx);
    TEMPLATE(T, mat_window_clear) (XX, ctx);
    TEMPLATE(T, mat_window_clear) (XY, ctx);
}


#endif
