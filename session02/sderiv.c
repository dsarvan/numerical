/*File: sderiv.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 06 February 2018
  Version: Original
  Comments: C code to compute second derivative of exp(x)
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double sderiv(double x, double h);

int main(void)
{
	FILE *fptr;

	double x, h, h_min, h_max;
	double res, res_calc, rel_err;

	x = 10.0;
	h_min = 1e-15;
	h_max = 0.1;

	fptr = fopen("datafile2.dat", "w");
	
	h = h_max;

	while(h > h_min)
	{
		res_calc = sderiv(x,h);

		res = exp(x);

		rel_err = fabs((res_calc - res)/(res));

		printf("h: %e exact: %e calculated: %e\n", h, res, res_calc);

		fprintf(fptr, "%e \t %e\n", h, rel_err);

		h = h/2.;
	}
	
	fclose(fptr);

return 0;
}

double sderiv(double x, double h)
{
	return (exp(x+h)-2*exp(x)+exp(x-h))/(h*h);
}

