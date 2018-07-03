/*File: programb.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 30 January 2018
  Version: Original
  Comments: C code to compute exp(-x) using recursion relation s(n) = (-1)*s(n-1)*x/n
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	FILE *function;

	int x = 10;
	int n, N;
	double sum, res, res_calc2, rel_err2;
	double sn;

	function = fopen("file2.dat", "w");
		

	for (N=0; N<=1000; N+=1)
	{	
		
		sum = 0.0;
		for (n=0; n<=N; n+=1)
		{      
			if (n == 0)
				sn = 1;

			else 
			  sn = (-1) * sn * (x/n);		
		
		sum += sn;
		res_calc2 = sum;
		}
		res = exp(-x);
		rel_err2 = fabs((res_calc2 - res)/(res));

	fprintf(function, "%4d \t %12.3e \t %12.3e \t %12.3e \n", N, res_calc2, res, rel_err2);
	}
	fclose(function);
return 0;
}
