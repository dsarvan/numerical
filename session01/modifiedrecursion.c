/*File: programc.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 30 January 2018
  Version: Original
  Comments: C code to compute exp(-x) using recursion relation s(n) = s(n-1) * x/n
*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	FILE *function;

	int x = 10;
	int n, N;
	double sum, res, res_calc3, rel_err3;
	double sn;

	function = fopen("file3.dat", "w");
	
	for(N=0; N<=1000; N+=1)
	{
		sum = 0.0;
		for (n=0; n<=N; n+=1)
		{	
			if (n == 0)
				sn = 1;
			
			else
				sn = sn * (x/n);
				

		sum += sn;
		res_calc3 = 1./sum;
		}
		res = exp(-x);
		rel_err3 = fabs((res_calc3 - res)/(res));

	fprintf(function, "%4d \t %12.3e \t %12.3e \t %12.3e \n", N, res_calc3, res, rel_err3);
	}
	fclose(function);
return 0;
}
