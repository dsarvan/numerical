/*midpoint rule*/
#include<stdio.h>
double midpoint(double a, double b, double n, double (*funct) (double, void *), void *params_ptr);

double midpoint(double a, double b, double n, double (*funct) (double, void *), void *params_ptr)
{
	int i;
	double x, h;
	double sum = 0.;

	h = (b-a)/n;

	for(i=0; i<n; i++)
	{
		x = a + i * h;
		x = x + (h/2.);
		sum += h * ((*funct) (x, params_ptr));
	}

	return sum;
}

