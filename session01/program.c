/*File: program.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 05/02/2018
  Version: Original
  Comments: C code for computing exp(-x) by the methods of power series, recursion relation and modified recursion (x = 0, 10, 50, 100) with data saved in file11.dat
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double power_series (int x, int N);
double factorial (int n);
double recursion_relation (int x, int N);
double modified_recursion (int x, int N);

int main(void)
{
	FILE *function;
	
	int N, x = 10;
	double res, res_calc1, rel_err1;
	double res_calc2, rel_err2;
	double res_calc3, rel_err3;	

	function = fopen("file.dat", "w");
	fprintf(function, "N \t res_calc1 \t res_calc2 \t res_calc3 \t res \t rel_err1 \t rel_err2 \t rel_err3\n");
	fprintf(function, "----------------------------------------------------------------------------------------------------------------\n");

	for (N=0; N<=1000; N+=1)
	{	
			
		res_calc1 = power_series (x, N);
		res_calc2 = recursion_relation (x, N);
		res_calc3 = modified_recursion (x, N);
		
		res = exp(-x);
		rel_err1 = fabs((res_calc1 - res) / (res));
		rel_err2 = fabs((res_calc2 - res) / (res));
		rel_err3 = fabs((res_calc3 - res) / (res));
	
	fprintf(function, "%4d  %12.3e  %12.3e  %12.3e  %12.3e  %12.3e  %12.3e  %12.3e\n", N, res_calc1, res_calc2, res_calc3, res, rel_err1, rel_err2, rel_err3);
	}
	fclose(function);
return 0;
}

double power_series (int x, int N)
{
	int n, fact;
	double sum1 = 0.0, term;

	for (n=0; n<=N; n+=1)
	{	
		fact = factorial (n);
		term = pow(-1, n) * (pow(x, n)/fact);
		sum1 = sum1 + term;
	}	
	return sum1;
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

double recursion_relation (int x, int N)
{
	int n;
	double sn, sum2 = 0.0;
	
	for (n=0; n<=N; n+=1)
	{
		if (n == 0)
			sn = 1;
		else
			sn = (-1) * sn * (x/n);


   		sum2 = sum2 + sn;
	}
	return sum2;	
}

double modified_recursion (int x, int N)
{
	int n;
	double sn, sum3 = 0.0;
	
 	for (n=0; n<=N; n+=1)
	{
		if (n == 0)
			sn = 1;
		else 
			sn = sn * (x/n);


  		sum3 = sum3 + sn;
		sum3 = sum3;
	}
	return 1./sum3;
}
