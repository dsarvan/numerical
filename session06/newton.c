/* File: newton.c
   Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
   Date: 13 March 2018
   Version: Original
   Comments: C code for Newton-Raphson's method
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 1.E-10

double f(double x);
double df(double x);
void newton(double a, double b);

double f(double x) {
	return x*x - 13;
}

double df(double x) {
	return 2*x;
}

void newton(double a, double b) {

	double x, c = (a+b)/2;
	int itr, max_itr = 1000;
	
	itr = 0;
	
	do {		
		x = c - f(c)/df(c);
		c = x;
		itr ++;

	} while (fabs(f(x)) > epsilon && itr <= max_itr);

	printf("\nNewton_Raphson Method:\n");
	
	if(fabs(f(x)) <= epsilon)
		printf("The root of the equation is %f\n", x);
	else
		printf("Error, no convergence.\n");

	printf("No. of iterations: %d\n\n", itr);
}
		
int main(void) {

	double a = 3., b = 4.;
	
	if(f(a)*f(b) < 0)
		newton(a, b);

	else
		printf("Error, root not in interval.\n");

	return 0;

}
