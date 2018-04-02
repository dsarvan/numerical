/* File: bisection.c
   Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
   Date: 13 March 2018
   Version: Original
   Comments: C code for root finding algorithm by Bisection Method
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 1.E-10              

/* function prototypes */
double funct(double x);
void bisection(double a, double b);

double funct(double x) {
	return x*x - 13;
}

void bisection(double a, double b) {

	double c, fa, fb, fc; 
	int itr, max_itr = 1000;

	itr = 0;
	
	do {

		fa = funct(a);
		fb = funct(b);
		c = (a+b)/2.;
		fc = funct(c);

		if(fa*fc < 0 && fb*fc > 0) {
			b = c;
			fb = fc;
		}
		
		else { 
			a = c;
			fa = fc;
		}

		itr ++;

	} while(fabs(fc) > epsilon  && itr <= max_itr);

	printf("\nBisection Method:\n");

	if(fabs(fc) <= epsilon)
		printf("The root of the equation is %f\n", c);	

	else
		printf("Error, no convergence.\n");

	printf("No. of iterations: %d\n\n", itr);

	
}

int main(void) {

	double a = 3., b = 4.;      /* plot the given function to find a and b */
				   /* approximately such that the root lies between [a,b] */
	if(funct(a)*funct(b) < 0)
	 	bisection(a, b);

	else
		printf("Error, root not in interval.\n");

	return 0;

} 
 
