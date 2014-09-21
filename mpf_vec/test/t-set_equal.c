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

    Copyright (C) 2009, 2010 William Hart
    Copyright (C) 2014 Abhinav Baid

******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include "flint.h"
#include "mpf_vec.h"
#include "ulong_extras.h"

int
main(void)
{
    int i, result;
    FLINT_TEST_INIT(state);

    flint_printf("set/equal....");
    fflush(stdout);



    /* Check aliasing of a and b */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        mpf *a;
        slong len = n_randint(state, 100);

        a = _mpf_vec_init(len, 200);
        _mpf_vec_randtest(a, state, len, 200);

        _mpf_vec_set(a, a, len);

        result = (_mpf_vec_equal(a, a, len));
        if (!result)
        {
            flint_printf("FAIL:\n");
            abort();
        }

        _mpf_vec_clear(a, len);
    }

    /* Compare copied vectors */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        mpf *a, *b;
        slong len = n_randint(state, 100);

        a = _mpf_vec_init(len, 200);
        b = _mpf_vec_init(len, 200);
        _mpf_vec_randtest(a, state, len, 200);

        _mpf_vec_set(b, a, len);

        result = (_mpf_vec_equal(a, b, len));
        if (!result)
        {
            flint_printf("FAIL:\n");
            abort();
        }

        _mpf_vec_clear(a, len);
        _mpf_vec_clear(b, len);
    }

    /* Compare unequal vectors */
    for (i = 0; i < 1000 * flint_test_multiplier(); i++)
    {
        mpf *a, *b;
        slong len = n_randint(state, 100) + 1;
        slong coeff;

        a = _mpf_vec_init(len, 200);
        b = _mpf_vec_init(len, 200);
        _mpf_vec_randtest(a, state, len, 200);

        _mpf_vec_set(b, a, len);
        coeff = n_randint(state, len);
        mpf_add_ui(b + coeff, b + coeff, 1);

        result = (!_mpf_vec_equal(a, b, len));
        if (!result)
        {
            flint_printf("FAIL:\n");
            abort();
        }

        _mpf_vec_clear(a, len);
        _mpf_vec_clear(b, len);
    }

    FLINT_TEST_CLEANUP(state);

    flint_printf("PASS\n");
    return 0;
}
