/*File: deriv.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 06 February 2018
  Version: Original
  Comments: C code to compute first derivative of exp(x) by forward, backward and central difference method.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double forward(double x, double h);
double backward(double x, double h);
double central(double x, double h);

int main(void)
{
	FILE *fptr;

	double x, h, h_min, h_max;
	double res, res_calc1, rel_err1;
	double res_calc2, rel_err2;
	double res_calc3, rel_err3;

	x = 1.0;
	h_min = 1e-15;
	h_max = 0.1;

	fptr = fopen("datafile1.dat", "w");

	h = h_max;

	fprintf(fptr, "#\t h \t\t res \t res_calc1 \t res_calc2 \t res_calc3 \t rel_err1 \t rel_err2 \t rel_err3\n");
	fprintf(fptr, "#--------------------------------------------------------------------------------------------------------------------------\n");

	while(h > h_min)
	{
	
		res_calc1 = forward(x,h);
		res_calc2 = backward(x,h);
		res_calc3 = central(x,h);

		res = exp(x);

		rel_err1 = fabs((res_calc1 - res)/(res));
		rel_err2 = fabs((res_calc2 - res)/(res));
		rel_err3 = fabs((res_calc3 - res)/(res));

		fprintf(fptr, "%e \t %e \t %e \t %e \t %e \t %e \t %e \t %e\n", h, res, res_calc1, res_calc2, res_calc3, rel_err1, rel_err2, rel_err3);

		h = h/2.;	
	}

	fclose(fptr);

return 0;
}

double forward(double x, double h)
{
	return (exp(x+h)-exp(x))/h;
}	

double backward(double x, double h)
{
	return (exp(x)-exp(x-h))/h;
}	

double central(double x, double h)
{
	return (exp(x+h)-exp(x-h))/(2*h);
}
