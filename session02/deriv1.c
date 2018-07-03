/*File: deriv.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 06 February 2018
  Version: Original
  Comments: C code to compute derivative of exp(x) by forward difference method.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double forward(double x, double h);
double backward(double x, double h); 
double secderiv(double x, double h);

int main(int argc, char *argv[])
{
	FILE *fptr1;
	FILE *fptr2;
	FILE *fptr3;

	double x,h;
	double res, res_calc1, rel_err1;
	double res_calc2, rel_err2;
	double res_calc3, rel_err3;

	x = 1.0;

	fptr1 = fopen("file1.dat", "w");
	fptr2 = fopen("file2.dat", "w");
	fptr3 = fopen("file3.dat", "w");

	for(h=0.1; h>=1e-15; h*=0.5)
	{
	
		res_calc1 = forward(x,h);
		res_calc2 = backward(x,h);
		res_calc2 = secderiv(x,h);

		res = exp(x);
		rel_err1 = fabs((res_calc1 - res)/(res));
		rel_err2 = fabs((res_calc2 - res)/(res));
		rel_err3 = fabs((res_calc3 - res)/(res));

	fprintf(fptr1, "%e %e %e %e\n", h, res_calc1, res, rel_err1);
	fprintf(fptr2, "%e %e %e %e\n", h, res_calc2, res, rel_err2);
	fprintf(fptr3, "%e %e %e %e\n", h, res_calc3, res, rel_err3);
	}

	fclose(fptr1);
	fclose(fptr2);
	fclose(fptr3);

return 0;
}

double forward(double x, double h)
{
	return (exp(x+h)-exp(x))/h;
}	

double backward (double x, double h)
{
	return (exp(x)-exp(x-h))/h;
}	

double secderiv(double x, double h)
{
	return (exp(x+h)-2*exp(x)+exp(x-h))/(h*h);
}
