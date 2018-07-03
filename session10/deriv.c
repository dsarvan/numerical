/* File: deriv.c
   Programmer: D.Saravanan  dayalsaravanan@gmail.com
   Date: 11 May 2018
   Version: Original
   Comments: C code to find derivative of a function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x, void *params_ptr);
void forward(double x, double h, double (*f) (double, void *), void *params_ptr);
void backward(double x, double h, double (*f) (double, void *), void *params_ptr);
void central(double x, double h, double (*f) (double, void *), void *params_ptr);

double f(double x, void *params_ptr) {
	double alpha;
	alpha = *(double *)params_ptr;
	return exp(alpha * x);	
}

void forward(double x, double h, double (*f) (double, void *), void *params_ptr) {
	double for_calc;
	for_calc = ( (*f) (x+h, params_ptr) - (*f) (x, params_ptr) )/h;	
	printf("The derivative by forward diffrence method: %lf\n", for_calc);
}

void backward(double x, double h, double (*f) (double, void *), void *params_ptr) {
	double bac_calc;
	bac_calc = ( (*f) (x, params_ptr) - (*f) (x-h, params_ptr) )/h;
	printf("The derivative by backward difference method: %lf\n", bac_calc);
}

void central(double x, double h, double (*f) (double, void *), void *params_ptr) {
	double cen_calc;
	cen_calc = ( (*f) (x+h, params_ptr) - (*f) (x-h, params_ptr) )/(2*h);
	printf("The derivative by central difference method: %lf\n", cen_calc);
}

int main(void) {

	double x, h;
	double alpha;
	void *params_ptr;

	params_ptr = &alpha;

	x = 1.;
	h = 1e-15;
	alpha = 1.;
	
	forward(x, h, &f, params_ptr);
	backward(x, h, &f, params_ptr);
	central(x, h, &f, params_ptr);

	return 0;
}
