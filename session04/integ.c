/*File: integ.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 20 February 2018
  Version: Original
  Comments: C code to compute integral of exp(ax) by simpson 1/3 and simpson 3/8 rule.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double funct(double x, void *params_ptr);
void midpoint(int n, double a, double h, double exact, double (*funct) (double, void *), void *params_ptr);
void trapezoid(int n, double a, double h, double exact, double (*funct) (double, void *), void *params_ptr);
void simpson13(int n, double a, double h, double exact, double (*funct) (double, void *), void *params_ptr);
void simpson38(int n, double a, double h, double exact, double (*funct) (double, void *), void *params_ptr);

int main(void) {

	int N;
	double a, b, h;
	double alpha;
	void *params_ptr;

	params_ptr = &alpha;

	a = 0., b = 1.;
	alpha = 1.;
	N = 500;
	
	double exact = exp(b) - exp(a);
			
	h = (b-a)/(double)n;

	midpoint(n, a, h, exact, &funct, params_ptr);
	trapezoid(n, a, h, exact, &funct, params_ptr);
	simpson13(n, a, h, exact, &funct, params_ptr);
	simpson38(n, a, h, exact, &funct, params_ptr);

	return 0;
}

double funct(double x, void *params_ptr) {

	double alpha;

	alpha = *(double *)params_ptr;
	
	return exp(alpha * x);
}
