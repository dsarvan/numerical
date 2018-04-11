/*File: adaptive.c
  Programmer: D.Saravanan ph15m015@gmail.com
  Date: 06 March 2018
  Version: Original
  Comments: C code for adaptive integration using trapezoidal rule.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double funct(double x);
double trapezoid0(double a, double b, int n, double (*funct) (double));
double trapezoid1(double a, double c, double b, int n, double (*funct) (double));
double apadtive(double a, double b, int n, double epsilon);

double funct(double x) {
	return 1./(2. + x*x);
}

double trapezoid0(double a, double b, int n, double (*funct) (double)) {  

	int i;
	double h, x, sum;

	h = (b-a)/(double)n;
	sum = 0.;
	
	for(i=0; i<n; i=i+1) {
		x = a+i*h;
		sum += (h/2.) * ((*funct) (x) + (*funct) (x+h));
	}
	return sum;
}

double trapezoid1(double a, double c, double b, int n, double (*funct) (double)) {

	int i,j;
	double h1, h2, x1, x2, sum1, sum2;

	h1 = (c-a)/(double)n;
	h2 = (b-c)/(double)n;
	sum1 = 0., sum2 = 0.;
	
	for(i=0; i<n; i=i+1) {
		x1 = a+i*h1;
		sum1 += (h1/2.) * ((*funct) (x1) + (*funct) (x1+h1));
	}
	
	for(j=0; j<n; j=j+1) {
		x2 = c+j*h2;
		sum2 += (h2/2.) * ((*funct) (x2) + (*funct) (x2+h2));
	}	
	
	return sum1+sum2;

}

double adaptive(double a, double b, int n, double epsilon) {

	double c;
	double I0, I1;

	c = (a+b)/2.;

	I0 = trapezoid0(a, b, n, &funct);
	I1 = trapezoid1(a, c, b, n, &funct);

	if((fabs(I0 - I1) < epsilon))
		return I1;
	else
		return ( (adaptive(a, c, n, epsilon)) + (adaptive(c, b, n, epsilon)) );
}

int main(void) {

	int n, N;
	double xmin, xmax;
	double epsilon = 0.00005;
	double result;
	
	N = 2;
	xmin = 0., xmax = 3.;

	for(n=2; n<=N; n=n+1) {

		result = adaptive(xmin, xmax, n, epsilon);
	}

	printf("result: %lf\n", result);			

return 0;

}
