/*File: interpolation.c
  Programmer: D.Saravanan ph15m015@smail.iitm.ac.in
  Date: 06 March 2018
  Version: Original
  Comments: C code for Lagrange Interpolation.
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 9

int main(void) {

	FILE *in_ptr;

	int n, i, j;
	double x_old[N], f_old[N];
	char line[125];
	
	in_ptr = fopen("sample_data.dat", "r");
	
	fgets(line, sizeof(line), in_ptr);
	fgets(line, sizeof(line), in_ptr);
	
	n = 0;	

	while(fgets(line, sizeof(line), in_ptr) != NULL) {
		sscanf(line, "%lf %lf", &x_old[n], &f_old[n]);
		n++;
	}
	
	fclose(in_ptr);

	FILE *fptr;

	fptr = fopen("result_data1.dat", "w");

	int x_new = 0;	
		
	while(x_new <= 200) {
		double f_new = 0.;
		for(i=0; i<N; i++) {
			double lamda = 1.;
			
			for(j=0; j<N; j++) {
				if(i != j)
					lamda *= (x_new - x_old[j])/(x_old[i] - x_old[j]);
			}
			f_new = f_new + lamda * f_old[i];
		}
		fprintf(fptr, "%d \t %lf\n", x_new, f_new);
		x_new = x_new + 2;
	}
	
	fclose(fptr);

	FILE *gptr;

	gptr = fopen("result_data2.dat", "w");

	int x_new0 = 0;

	while(x_new0 <= 50) {
		double f_new0 = 0.;
		for(i=0; i<3; i++) {
			double lamda0 = 1.;

			for(j=0; j<3; j++) {
				if(i != j)
					lamda0 *= (x_new0 - x_old[j])/(x_old[i] - x_old[j]);
			}
			f_new0 = f_new0 + lamda0 * f_old[i];
		}
		fprintf(fptr, "%d \t %lf\n", x_new0, f_new0);
		x_new0 = x_new0 + 2;
	}

	int x_new1 = 50;

	while(x_new1 <= 100) {
		double f_new1 = 0.;
		for(i=2; i<5; i++) {
			double lamda1 = 1.;

			for(j=2; j<5; j++) {
				if(i != j)
					lamda1 *= (x_new1 - x_old[j])/(x_old[i] - x_old[j]);
			}
			f_new1 = f_new1 + lamda1 * f_old[i];
		}
		fprintf(fptr, "%d \t %lf\n", x_new1, f_new1);
		x_new1 = x_new1 + 2;
	}

	int x_new2 = 100;

	while(x_new2 <= 150) {
		double f_new2 = 0.;
		for(i=4; i<7; i++) {
			double lamda2 = 1.;

			for(j=4; j<7; j++) {
				if(i != j)
					lamda2 *= (x_new2 - x_old[j])/(x_old[i] - x_old[j]);
			}
			f_new2 = f_new2 + lamda2 * f_old[i];
		}
		fprintf(fptr, "%d \t %lf\n", x_new2, f_new2);
		x_new2 = x_new2 + 2;
	}
	
	int x_new3 = 150;

	while(x_new3 <= 200) {
		double f_new3 = 0.;
		for(i=6; i<9; i++) {
			double lamda3 = 1.;

			for(j=6; j<9; j++) {
				if(i != j)
					lamda3 *= (x_new3 - x_old[j])/(x_old[i] - x_old[j]);
			}
			f_new3 = f_new3 + lamda3 * f_old[i];
		}
		fprintf(fptr, "%d \t %lf\n", x_new3, f_new3);
		x_new3 = x_new3 + 2;
	}

	fclose(gptr);


return 0;	
}
