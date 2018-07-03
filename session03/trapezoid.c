/*trapezoid rule*/
#include<stdio.h>

double trapezoid(double a, double b, double n, double (*funct) (double, void *), void *params_ptr);

double trapezoid(double a, double b, double n, double (*funct) (double, void *), void *params_ptr)
{
	int i;
	double x, h;
	double sum = 0.;

	h = (b-a)/n;

	for(i=0; i<n; i++)
	{
		x = a + i * h;
		sum += (h/2.) * ((*funct) (x, params_ptr) + (*funct) (x+h, params_ptr));
	}

	return sum;
}
