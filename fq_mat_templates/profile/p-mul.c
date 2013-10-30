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

    Copyright (C) 2013 Mike Hansen

******************************************************************************/

#ifdef T

#include "templates.h"

#include <stdio.h>
#include <math.h>
#include "profiler.h"

#define nalgs 2
#define cpumin 2
#define ncases 1

int
main(int argc, char** argv)
{
    fmpz_t p;
    int c, n, reps = 0;
    long d, mat_size;
    fq_ctx_t ctx;
    fq_mat_t f, g, h;

    double s[nalgs];
    
    flint_rand_t state;
    flint_randinit(state);

    fmpz_init(p);
    fmpz_set_str(p, argv[1], 10);

    d = atol(argv[2]);
    mat_size = atol(argv[3]);

    TEMPLATE(T, ctx_init)(ctx, p, d, "a");

    TEMPLATE(T, mat_init)(f, mat_size, mat_size, ctx);
    TEMPLATE(T, mat_init)(g, mat_size, mat_size, ctx);
    TEMPLATE(T, mat_init)(h, mat_size, mat_size, ctx);

    for (c = 0; c < nalgs; c++)
        s[c] = 0.0;
            
    for (n = 0; n < ncases; n++)
    {
        double t[nalgs];
        int lo, loops = 1;

        /*
          Construct random elements of fq
        */
        {
            TEMPLATE(T, mat_randtest)(g, state, ctx);
            TEMPLATE(T, mat_randtest)(h, state, ctx);
        }
                
    loop:

        t[0] = 0.0;
        init_clock(0);
        prof_start();
        for (lo = 0; lo < loops; lo++)
        {
            TEMPLATE(T, mat_mul_classical)(h, f, g, ctx);
        }
        prof_stop();
        t[0] += get_clock(0);
                
        t[1] = 0.0;
        init_clock(0);
        prof_start();
        for (lo = 0; lo < loops; lo++)
        {
            TEMPLATE(T, mat_mul_KS)(h, f, g, ctx);
        }
        prof_stop();
        t[1] += get_clock(0);

        for (c = 0; c < nalgs; c++)
            if (t[c] * FLINT_CLOCK_SCALE_FACTOR <= cpumin)
            {
                loops *= 10;
                goto loop;
            }
                
        for (c = 0; c < nalgs; c++)
            s[c] += t[c];
        reps += loops;
    }
            
    for (c = 0; c < nalgs; c++)
    {
        printf("%20f", s[c] / (double) reps);
        fflush(stdout);
    }
    printf("\n");
    
    TEMPLATE(T, mat_clear)(f, ctx);
    TEMPLATE(T, mat_clear)(g, ctx);
    TEMPLATE(T, mat_clear)(h, ctx);
    TEMPLATE(T, ctx_clear)(ctx);
    fmpz_clear(p);

    return 0;
}

#endif
