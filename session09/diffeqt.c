/* File: diffeqt.c
   Programmer: D.Saravanan   ph15m015@smail.iitm.ac.in
   Date: 16 April 2018
   Version: Original
   Comments: C code for solving ODE by a) Euler, b) Runge-Kutta second and fourth order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double t, double N);
void euler(double h, double t, double t0, double N0, double f(double t, double N));
void RK2(double h, double t, double t0, double N0, double f(double t, double N));
void RK4(double h, double t, double t0, double N0, double f(double t, double N));

double f(double t, double N) {
	return -N;
}

void euler(double h, double t, double t0, double N0, double f(double t, double N)) {

	FILE *fptr1;

	double N;
	double exact, rel_err;
	
	fptr1 = fopen("euler.dat", "w");

	for(t=0; t<=1; t=t+h) {

		exact = N0 * exp(-t);

		while(fabs(t-t0)>0.0000000001) {
			N = N0+h*f(t0,N0);
			N0 = N;
			t0 = t0+h;
		}	
	
	rel_err = fabs(N - exact)/(exact);

	fprintf(fptr1, "%lf \t %lf \t %lf \t %lf\n", t, N, exact, rel_err);

	}

	fclose(fptr1);

}

void RK2(double h, double t, double t0, double N0, double f(double t, double N)) {

	FILE *fptr2;
	
	double k1, k2;
	double N;
	double exact, rel_err;

	fptr2 = fopen("rk2.dat", "w");
	
	for(t=0; t<=1; t=t+h) {

		exact = N0 * exp(-t);

		while(fabs(t-t0)>0.0000000001) {
			k1 = h*f(t0,N0);
			k2 = h*f(t0+h/2., N0+k1/2.);
			N = N0+k2;
			N0 = N;
			t0 = t0+h;
		}

	rel_err = fabs(N - exact)/(exact);

	fprintf(fptr2, "%lf \t %lf \t %lf \t %lf\n", t, N, exact, rel_err);

	}

	fclose(fptr2);
	
}

void RK4(double h, double t, double t0, double N0, double f(double t, double N)) {
	
	FILE *fptr3;
	
	double k1, k2;
	double k3, k4;
	double N;
	double exact, rel_err;

	fptr3 = fopen("rk4.dat", "w");

	for(t=0; t<=1; t=t+h) {

		exact = N0 * exp(-t);

		while(fabs(t-t0)>0.0000000001) {
			k1 = h*f(t0,N0);
			k2 = h*f(t0+h/2., N0+k1/2.);
			k3 = h*f(t0+h/2., N0+k2/2.);
			k4 = h*f(t0+h, N0+k3);
			N = N0+1./6. * (k1+2*k2+2*k3+k4);
			N0 = N;
			t0 = t0+h;
		}

	rel_err = fabs(N - exact)/(exact);

	fprintf(fptr3, "%lf \t %lf \t %lf \t %lf\n", t, N, exact, rel_err);

	}
	
	fclose(fptr3); 
}

int main(void) {

	double t0, N0;
	double t, N;
	double h;

	printf("Enter the initial values of t and N: \n");
	printf("t0 = ");
	scanf("%lf", &t0);
	printf("N0 = ");
	scanf("%lf", &N0);

	printf("Enter the step-width, h = ");
	scanf("%lf", &h);

	euler(h, t, t0, N0, f);
	RK2(h, t, t0, N0, f);
	RK4(h, t, t0, N0, f);

	return 0;

}
