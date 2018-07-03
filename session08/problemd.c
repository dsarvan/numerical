/* File: problemd.c
   Programmer: D.Saravanan   ph15m015@smail.iitm.ac.in
   Date: 04 April 2018
   Version: Original
   Comments: C code to solve the Poisson's Equation in 1D using tridiagonal solver
	     in the GSL library
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_linalg.h>

int main(void) {

	FILE *fptr1;
	FILE *fptr2;

	int i, N;

	double q, numerical;
	double exact, rel_err;

	clock_t start, stop;

	N = 10;
	while(N<=1000) {

		start = clock ();

		const double h = 1./(N+1.);

		fptr1 = fopen("datafile_tri1.dat", "w");
		fptr2 = fopen("datafile_tri2.dat", "w");
		
		/* construct vector d */
		gsl_vector *d = gsl_vector_alloc (N);
		
		for(i=0; i<N; i++) {
			gsl_vector_set(d, i, 2);
		}

		/* construct vector e */
		gsl_vector *e = gsl_vector_alloc (N-1);	

		for(i=0; i<N-1; i++) {
			gsl_vector_set(e, i, -1);
		}	

		/* construct vector f */
		gsl_vector *f = gsl_vector_alloc (N-1);

		for(i=0; i<N-1; i++) {
			gsl_vector_set(f, i, -1);
		}

		/* construct vector b */
		gsl_vector *b = gsl_vector_alloc (N);

		for(i=0; i<N; i++) {
			q = i*h;
			gsl_vector_set(b, i, (3*q+q*q)*exp(q) * h*h);
		}

		/* construct vector x */
		gsl_vector *x = gsl_vector_alloc (N);

		/* Tridiagonal Solver */
		gsl_linalg_solve_tridiag (d, e, f, b, x);

		for(i=0; i<N; i++) {
			q = i*h;
			exact = q*(1-q) * exp(q);
			
			numerical = gsl_vector_get (x, i);
		
			rel_err = fabs(numerical - exact)/(exact);

			fprintf(fptr2, "%d \t %d \t %e \t %e\n", N, i, q, rel_err);
		}

		/* free memory */
		gsl_vector_free(d);
		gsl_vector_free(e);
		gsl_vector_free(f);
		gsl_vector_free(x);
		gsl_vector_free(b);

		stop = clock ();
	
		fprintf(fptr1, "%d \t %e\n", N, (double) (stop-start)/(CLOCKS_PER_SEC));

		N = N + 10;
	
	}

	fclose(fptr1);
	fclose(fptr2);

	return 0;
}
