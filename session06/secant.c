/*File: secant.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 13 March 2018
  Version: Original
  Comments: C code to find the root by secant method. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPSILON 1.E-10

double f(double x);
void sexant(double a, double b);

double f(double x) {
	return x*x - 13;
}

void secant(double a, double b) {

	double x;
	double fa, fb, fx;
	int itr, max_itr = 1000;

	itr = 0;
	
	do {
		
		fa = f(a);
		fb = f(b);

		x = (fb * a - fa * b)/(fb - fa);
		
		fx = f(x);

		a = b;
		b = x;

		itr ++;

	} while (fabs(fx) > EPSILON  && itr <= max_itr);

	printf("\nSecant Method:\n");

	if(fabs(fx) <= EPSILON)
		printf("The root of the equation is %f\n", x);
	else
		printf("Error, no convergence.\n");

	printf("No. of iterations: %d\n\n", itr);
}


int main(void) {

	double a = 3., b = 4.;

	if(f(a)*f(b) < 0) 
		secant(a, b);

	else
		printf("Error, the root not in interval.\n");

	return 0;

}
