/* File: problem.c
   Programmer: D.Saravanan  ph15m015@smail.iitm.ac.in
   Date: 20 March 2018
   Version: Original
   Comments: C code to solve Schrodinger equation in momentum space
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>

int main(void) {

	FILE *mesh_ptr;
	FILE *pot_ptr;

	int i, j;
	int n, m, Nkmax;
	double M;
	const double pi = 4.*atan(1.);
	const double h = 197.32705;

	double kdum, kpdum;
	double k[54], w[54];
	double V[54][54];
	char line[125];

	/* Matrix and its decompositions */
	gsl_matrix *H;
	gsl_vector *eval;
	gsl_matrix *evec;

	/* Workspace */
	gsl_eigen_symmv_workspace *wkr; 

	mesh_ptr = fopen("kmesh_wts.dat", "r");

	n = 0;

	while(fgets(line, sizeof(line), mesh_ptr) != NULL) {
		sscanf(line, "%lf %lf", &k[n], &w[n]);
		n ++;
	}

	Nkmax = n;

	fclose(mesh_ptr);

	pot_ptr = fopen("matrix_elements.dat", "r");

	fgets(line, sizeof(line), pot_ptr);
	fgets(line, sizeof(line), pot_ptr);
	fgets(line, sizeof(line), pot_ptr);

	n = 0;
	m = 0;

	while(fgets(line, sizeof(line), pot_ptr) != NULL) {
		sscanf(line, "%lf %lf %lf", &kdum, &kpdum, &V[n][m]);
		m ++;
		if(m == Nkmax) {
			n ++;
			m = 0;
		}
     	}

	fclose(pot_ptr);

	/* Initialize matirx H{i,j} */
	H = gsl_matrix_alloc (54, 54);

	for(i=0; i<54; i++) {
		for(j=0; j<54; j++) {
			if(i==j)
				M = ((k[j]*k[j])/2. + 2./pi * k[i] * sqrt(w[i]) * V[i][j] * k[j] * sqrt(w[j])) * h;
			else
				M = 2./pi * k[i] * sqrt(w[i]) * V[i][j] * k[j] * sqrt(w[j]) * h;
			gsl_matrix_set (H, i, j, M);
		}
	}

	/* Print matrix H */
	/*for(i=0; i<54; i++) {
		for(j=0; j<54; j++) {
			if(i==j)
				printf("H(%d,%d) = %g\n", i, j, gsl_matrix_get (H, i, j));
		}
	}*/
	
	/* Compute eigendecomposition */	
	eval = gsl_vector_alloc (54);
	evec = gsl_matrix_alloc (54, 54);

	/* Workspace */
	wkr = gsl_eigen_symmv_alloc (54);
	gsl_eigen_symmv (H, eval, evec, wkr);

	gsl_eigen_symmv_sort (eval, evec, GSL_EIGEN_SORT_ABS_ASC);

	/* Sort and print eigenvalues */
   	for (i=0; i<54; i++) {
        	double eval_i = gsl_vector_get (eval, i);
		printf ("eigenvalue = %g\n", eval_i);
	}


	/* Clean up */	
	gsl_eigen_symmv_free (wkr);
	gsl_vector_free (eval);
	gsl_matrix_free (evec);
	gsl_matrix_free (H);

	return 0;

}
