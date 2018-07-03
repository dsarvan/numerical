/* File: integ.c
   Programmer: D.Saravanan   dayalsaravanan@gmail.com
   Date: 04 May 2018
   Version: Original
   Comments: C code for integrating a function numerically
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x, void *params_ptr);
void midpoint(int N, double a, double h, double (*f) (double, void *), void *params_ptr);
void trapezoid(int N, double a, double h, double (*f) (double, void *), void *params_ptr);
void simpson13(int N, double a, double h, double (*f) (double, void *), void *params_ptr);
void simpson38(int N, double a, double h, double (*f) (double, void *), void *params_ptr);

double f(double x, void *params_ptr) {
	
	double alpha;
	alpha = *(double *)params_ptr;
	return exp(alpha * x);
}

void midpoint(int N, double a, double h, double (*f) (double, void *), void *params_ptr) {

	int i;
	double x, sum;
	double midpt_calc;

	sum = 0.;

	for(i=0; i<N; i+=1) {

		x = a + i * h;
		x = x + (h/2.);

		sum += h * ( (*f) (x, params_ptr) );
	}

	midpt_calc = sum;

	printf("The integral determined by Midpoint rule: %lf\n", midpt_calc);
}

void trapezoid(int N, double a, double h, double (*f) (double, void *), void *params_ptr) {

	int i;
	double x, sum;
	double trap_calc;

	sum = 0.;
	
	for(i=0; i<N; i+=1) {

		x = a + i * h;

		sum += (h/2.) * ( (*f) (x, params_ptr) + (*f) (x+h, params_ptr) );
	}

	trap_calc = sum;

	printf("The integral determined by Trapezoid rule: %lf\n", trap_calc);
}

void simpson13(int N, double a, double h, double (*f) (double, void *), void *params_ptr) {

	int i;
	double x, sum;
	double simp13_calc;

	sum = 0.;

	for(i=0; i<N; i+=2) {
	
		x = a + i * h;

		sum += (h/3.) * ( (*f) (x, params_ptr) + 4 * (*f) (x+h, params_ptr) + (*f) (x+(2*h), params_ptr) );

	}

	simp13_calc = sum;

	printf("The integral determined by Simpson's 1/3 rule: %lf\n", simp13_calc);
}

void simpson38(int N, double a, double h, double (*f) (double, void *), void *params_ptr) {

	int i;
	double x, sum;
	double simp38_calc;

	sum = 0.;
	
	for(i=0; i<N; i+=3) {

		x = a + i * h;

		sum += (3.*h)/8. * ( (*f) (x, params_ptr) + 3 * (*f) (x+h, params_ptr) + 3 * (*f) (x+(2*h), params_ptr) + (*f) (x+(3*h), params_ptr) );

	}

	simp38_calc = sum;

	printf("The integral determined by Simpson's 3/8 rule: %lf\n", simp38_calc);
}

int main(void) {

	int N;
	double a, b, h;
	double alpha;
	void *params_ptr;

	params_ptr = &alpha;

	a = 0., b = 1.;   /* lower and upper limits of intergration */
	alpha = 1.;       /* some constant value */
	N = 500000;

	h = (b-a)/(double)N;

	midpoint(N, a, h, &f, params_ptr);
	trapezoid(N, a, h, &f, params_ptr);
	simpson13(N, a, h, &f, params_ptr);
	simpson38(N, a, h, &f, params_ptr);

	return 0;
}
