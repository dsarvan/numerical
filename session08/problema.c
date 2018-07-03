/* File: problema.c
   Name: D.Saravanan      ph15m015@smail.iitm.ac.in
   Date: 3 April 2018
   Version: Original
   Comments: C code to cast the Poisson's Equation in the form of a matrix equation AX = B 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <gsl/gsl_math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_eigen.h>

int main(void) {

	FILE *fptr;

	int i;
	const int N = 1000;            /* No. of mesh points */   
	const double h = 1./(N+1.);      

	double x, numerical;
	double exact, rel_err;

	fptr = fopen("datafile_1000.dat", "w"); 

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

	/* construct vector B */
	gsl_vector *B = gsl_vector_alloc (N);

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
		
		fprintf(fptr, "%e \t %e \t %e \t %e\n", x, numerical, exact, rel_err);
	}
	
	/* free memory */
	gsl_permutation_free(P);
	gsl_vector_free(X);
	gsl_vector_free(B);
	gsl_matrix_free(A);

	fclose(fptr);

	return 0;
}
