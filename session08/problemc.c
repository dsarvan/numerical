/* File: problemc.c
   Name: D.Saravanan      ph15m015@smail.iitm.ac.in
   Date: 3 April 2018
   Version: Original
   Comments: C code to cast the Poisson's Equation in the form of a matrix equation AX = B 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_eigen.h>

int main(void) {

	FILE *fptr1;
	FILE *fptr2;

	int i, N;              

	double x, numerical;
	double exact, rel_err;

	clock_t start, stop;	 /* Declaring variables start and stop of */
				 /* type clock_t, which is defined in time.h */
					
	for(N=10; N<=1000; N=N+10) {

		start = clock ();
			
		const double h = 1./(N+1.);

		fptr1 = fopen("datafile_time.dat", "w"); 
		fptr2 = fopen("datafile.dat", "w");

		/* construct matrix A */
		gsl_matrix *A = gsl_matrix_alloc (N, N);

		/* construct first row */
		gsl_matrix_set(A, 0, 0, 2);
		gsl_matrix_set(A, 0, 1, -1);

		/* construct rows [1:N-2] */
		for(i=1; i<N-1; ++i) {
			gsl_matrix_set(A, i, i+1, -1);
			gsl_matrix_set(A, i, i, 2);
			gsl_matrix_set(A, i, i-1, -1);
		}	

		/* construct last row */
		gsl_matrix_set(A, N-1, N-1, 2);
		gsl_matrix_set(A, N-1, N-2, -1);

		gsl_vector *B = gsl_vector_alloc (N);

		/* construct vector B */
		for(i=0; i<N; i++) {
			x = i*h;
			gsl_vector_set(B, i, (3*x+x*x)*exp(x) * h*h);	
		}
	
		int s;

		gsl_permutation *P = gsl_permutation_alloc (N);

		gsl_linalg_LU_decomp (A, P, &s);

		gsl_vector *X = gsl_vector_alloc (N);	

		gsl_linalg_LU_solve (A, P, B, X);

		/* printf("x = \n");
		gsl_vector_fprintf (stdout, X, "%g"); */

		for(i=0; i<N; i++) {
			x = i*h;
			exact = x*(1-x) * exp(x);

			numerical = gsl_vector_get (X, i);

			rel_err = fabs(numerical - exact)/(exact);

			fprintf(fptr2, "%e \t %e\n", x, rel_err);
		}
	
		/* free memory */
		gsl_permutation_free(P);
		gsl_vector_free(X);
		gsl_vector_free(B);
		gsl_matrix_free(A);
	
		stop = clock ();
		
		fprintf(fptr1, "%d \t %e\n", N, (double) (stop-start)/(CLOCKS_PER_SEC));		/* CLOCKS_PER_SEC is the number of ticks in a second and */
												/* the clock () functions measures time in units of ticks. */
	}

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}
