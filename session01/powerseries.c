/*File: programa.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 30 January 2018
  Version: Original
  Comments: C code to compute exp(-x) using power series
*/

#include<stdio.h>
#include<stdio.h>
#include<math.h>

double factorial (int n);
double power_series (int x, int n);


int main(void)
{
	FILE *function;
	
	int x = 10;
	int n, N;
	double res, res_calc1, rel_err1;
	
	function = fopen("file1.dat", "w");

	for (N=0; N<=3; N+=1)
	{
		for(n=0; n<=N; n+=1)
		{
			res_calc1 = power_series (x, n);
		}
		res = exp(-x);
		rel_err1 = fabs((res_calc1 - res)/ (res));

	fprintf(function, "%4d \t %12.3e \t %12.3e \t %12.3e  \n", N, res_calc1,  res, rel_err1);
	}

	fclose(function);

return 0;
}



double power_series (int x, int n)
{
	int fact;
	double sum, term;
	sum = 0.0;
	
	fact = factorial (n);
	term = pow(-1, n) * (pow(x, n)/fact);
	sum += term;
	return sum;
}

double factorial (int n)
{
	int i;
	int fact = 1;
	
	for (i=n; i>=1; i--)
	{
		fact = fact * i;
	}
	return fact;
}	


