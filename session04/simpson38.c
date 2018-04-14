#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void simpson38(int N, double a, double b, double exact, double (*f) (double, void *), void *params_ptr);

void simpson38(int N, double a, double b, double exact, double (*f) (double, void *), void *params_ptr) {

	FILE *fptr2;
	
	int n, i;
	double h, x, sum;
	double simp38_calc, simp38_err;

	fptr2= fopen("datafile2.dat", "w");

	for(n=3; n<N; n=n+3) {

		h = (b-a)/(double)n;
		sum = 0.;
		
		for(i=0; i<n; i=i+3) {

			x = a + i * h;

			sum += (3.*h)/8. * ( (*f) (x, params_ptr) + 3 * (*f) (x+h, params_ptr) + 3 * (*f) (x+(2*h), params_ptr) + (*f) (x+(3*h), params_ptr) );
		}

		simp38_calc = sum;
		simp38_err = fabs((simp38_calc - exact)/(exact));

		fprintf(fptr2, "%d \t %e\n", n, simp38_err);
	}

	fclose(fptr2);
}
