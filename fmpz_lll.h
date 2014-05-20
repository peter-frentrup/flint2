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

    Copyright (C) 2005, 2006 Damien Stehlé
    Copyright (C) 2009, 2010 William Hart
    Copyright (C) 2009, 2010 Andy Novocin
    Copyright (C) 2010 Fredrik Johansson
    Copyright (C) 2014 Abhinav Baid

******************************************************************************/

#ifndef FMPZ_LLL_H
#define FMPZ_LLL_H

#include <gmp.h>
#include "flint.h"
#include "fmpz_mat.h"
#include "d_mat.h"
#include "mpf_mat.h"

#ifdef __cplusplus
 extern "C" {
#endif

#ifndef NAN
#define NAN (0.0/0.0)
#endif 

#if FLINT_BITS == 32
#define CPU_SIZE_1 31
#define MAX_LONG 2147483647
#else
#define CPU_SIZE_1 53
#define MAX_LONG 9007199254740991
#endif

/* The various Babai's  ******************************************************/

int fmpz_lll_check_babai (int kappa, fmpz_mat_t B, d_mat_t mu, d_mat_t r, double *s, 
       d_mat_t appB, int *expo, d_mat_t appSP, 
       int a, int zeros, int kappamax, int n, double delta, double eta);


/* double heuristic_scalar_product(double * vec1, double * vec2, ulong n, 
								F_mpz_mat_t B, ulong k, ulong j, long exp_adj);

int check_Babai (int kappa, F_mpz_mat_t B, double **mu, double **r, double *s, 
       double **appB, int *expo, double **appSP, 
       int a, int zeros, int kappamax, int n);

int check_Babai_heuristic_d (int kappa, F_mpz_mat_t B, double **mu, double **r, double *s, 
       double **appB, int *expo, double **appSP, 
       int a, int zeros, int kappamax, int n);

int check_Babai_heuristic(int kappa, F_mpz_mat_t B, __mpfr_struct **mu, __mpfr_struct **r, __mpfr_struct *s, 
       __mpfr_struct **appB, __mpfr_struct **appSP, 
       int a, int zeros, int kappamax, int n, mpfr_t tmp, mpfr_t rtmp, mp_prec_t prec);

int check_Babai_heuristic_d_zero_vec (int kappa, F_mpz_mat_t B, double **mu, double **r, double *s, 
       double **appB, int *expo, double **appSP, 
       int a, int zeros, int kappamax, int n);

int LLL_d(F_mpz_mat_t B);

int LLL_d_heuristic(F_mpz_mat_t B);

int LLL_mpfr2(F_mpz_mat_t B, mp_prec_t prec);

int LLL_mpfr(F_mpz_mat_t B);

int LLL_wrapper(F_mpz_mat_t B);

int LLL_d_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int LLL_d_heuristic_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int LLL_mpfr2_with_removal(F_mpz_mat_t B, mp_prec_t prec, F_mpz_t gs_B);

int LLL_mpfr_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int LLL_wrapper_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int knapsack_LLL_wrapper_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int knapsack_LLL_d_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int knapsack_LLL_d_heuristic_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int knapsack_LLL_mpfr2_with_removal(F_mpz_mat_t B, mp_prec_t prec, F_mpz_t gs_B);

int knapsack_LLL_mpfr_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int knapsack_LLL_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int LLL_d_zero_vec_heuristic_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

int LLL_wrapper_zero_vec_with_removal(F_mpz_mat_t B, F_mpz_t gs_B);

ulong F_mpz_mat_gs_d( F_mpz_mat_t B, F_mpz_t gs_B);

void gs_Babai(int kappa, F_mpz_mat_t B, double **mu, double **r, double *s, 
       double **appB, int *expo, double **appSP, 
       int a, int zeros, int kappamax, int n);

int U_LLL_with_removal(F_mpz_mat_t FM, long new_size, F_mpz_t gs_B);

ulong getShift(F_mpz_mat_t B);

void LLL (F_mpz_mat_t B); */

#ifdef __cplusplus
}
#endif
 
#endif

