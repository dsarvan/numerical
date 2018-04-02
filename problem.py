# File: problem.py
# Programmer: D.Saravanan  dayalsaravanan@gmail.com
# Date: 23 March 2018
# Version: Original
# Comments: Python code to solve Schrodinger equation in momentum space using gsl.

gsl_matrix *H
gsl_vector *eigenval
gsl_matrix *eigenvec

file = open("kmesh_wts.dat", "r")

file.close()

file = open("matrix_elements.dat", "r")

file.close()

H = gsl_matrix_alloc (54, 54)

for i in range(0, 54, 1):
	for j in range(0, 54, 1):
		if i == j:
			M = (k[j]*k[j])/2. + 2./pi * k[i] * sqrt(w[i]) * V[i][j] * k[j] * sqrt(w[j]) * h;
		else:
			M = 2./pi * k[i] * sqrt(w[i]) * V[i][j] * k[j] * sqrt(w[j]) * h;
		
		gsl_matrix_set (H, i, j, M)

eigenval = gsl_vector_alloc (54)
eigenvec = gsl_matrix_alloc (54, 54)

wkr = gsl_eigen_symmv_alloc (54)
gsl_eigen_symmv (H, eigenval, eigenvec, wkr)

gsl_eigen_symmv_sort (eigenval, eigenvec, GSL_EIGEN_SORT_ABS_ASC)

for i in range(0, 54, 1):
	eigenval_i = gsl_vector_get (eigenval, i)
	print("eigenvalue = %g\n", eigenval_i)

gsl_eigen_symmv_free (wkr)
gsl_vector_free (eigenval)
gsl_matrix_free (eigenvec)
gsl_matrix_free (H)
