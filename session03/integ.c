/*File: integ.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 13 February 2018
  Version: Original
  Comments:
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double funct(double x, void *params_ptr);
double trapezoid(double a, double b, double n, double (*funct) (double , void *), void *params_ptr);
double midpoint(double a, double b, double n, double (*funct) (double, void *), void *params_ptr);

int main(void)
{
	FILE *fptr;

	int n, N;
	double a, b;
	double alpha;
	void *params_ptr;

	double mid_calc, mid_err;
	double trap_calc, trap_err;
	
	N = 500;
	a = 0., b = 1.;
	alpha = 1.0;

	params_ptr = &alpha;	
	
	double exact = exp(b) - exp(a);

	fptr = fopen("datafile.dat", "w");

	for(n=2; n<N; n++)
	{
		mid_calc = midpoint(a, b, n, &funct, params_ptr);
		trap_calc = trapezoid(a, b, n, &funct, params_ptr);

		mid_err = fabs((mid_calc - exact)/(exact));
		trap_err = fabs((trap_calc - exact)/(exact));

		fprintf(fptr, "%d \t %e \t %e\n", n, mid_err, trap_err);
	}

	fclose(fptr);

	return 0;
}

double funct(double x, void *params_ptr)
{
	double alpha;

	alpha = *(double *) params_ptr;

	return (exp(alpha * x));
}

/*double trapezoid(double a, double b, double n, double (*funct) (double, void *), void *params_ptr)
{
	double x, h;
	double term, sum = 0.;
	
	h = (b-a)/n;

	for(x=a; x<=(b-1e-07); x=x+h)
	{
		term = (h/2) * ((*funct) (x, params_ptr) + (*funct) (x+h, params_ptr));
		sum = sum + term;
	}

	return sum;
}*/
