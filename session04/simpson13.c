#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void simpson13(int N, double a, double b, double exact, double (*f) (double, void *), void *params_ptr);

void simpson13(int N, double a, double b, double exact, double (*f) (double, void *), void *params_ptr) {

	FILE *fptr1;

	int n, i;
	double h, x, sum;
	double simp13_calc, simp13_err;

	fptr1 = fopen("datafile1.dat", "w");

	for(n=2; n<N; n=n+2) {

		h = (b-a)/(double)n;
		sum = 0.;

		for(i=0; i<n; i=i+2) {

			x = a + i * h;
		
			sum += (h/3.) * ( (*f) (x, params_ptr) + 4 * (*f) (x+h, params_ptr) + (*f) (x+(2*h), params_ptr) );
		}

		simp13_calc = sum;
		simp13_err = fabs((simp13_calc - exact)/(exact));

		fprintf(fptr1, "%d \t %e\n", n, simp13_err);
	}

	fclose(fptr1);
}
