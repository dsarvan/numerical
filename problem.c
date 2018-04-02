/*File: problem.c
  Programmer: D.Saravanan    ph15m015@smail.iitm.ac.in
  Date: 13 March 2018
  Version: Original
  Comments: C code to obtain the binding energy of a deuteron 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EPSILON 1.E-10   /* tolerance value */
#define MAX_ITR 1000     /* maximum no. of iterations */

/* function prototypes */
double f(double E);
double df(double E);
void bisection(double E1, double E2);
void newton(double E1, double E2); 
void secant(double E1, double E2);

/* function */
double f(double E) {
	
	double V0, a, m, h;
	double k, B;

	V0 = 60.;                   /* V0 = 60 MeV */
	a = 1.45E-15;               /* a = 1.45 fm */
	m = 938.;                   /* mc^2 = 938 MeV */
	h = 2.E-13;               /* hc = 200 MeV fm */

	k = sqrt(m * (V0 - fabs(E)))/h;
	B = sqrt(m * fabs(E))/h;

	return k * (cos(k*a)/sin(k*a)) + B;
}

/* derivative */
double df(double E) {
	
	double V0, a, m, h;
	double k;

	V0 = 60.;                  /* V0 = 60 MeV */
	a = 1.45E-15;              /* a = 1.45 fm */
	m = 938.;          	   /* mc^2 = 938 MeV */
	h = 2.E-13;              /* hc = 200 MeV fm */

	k = sqrt(m * (V0 - fabs(E)))/h;

	return sqrt(m/(4*h*h*E)) * (a*a*k*(1./sin(a*k))*(1./sin(a*k)) - (cos(k*a)/sin(k*a)) + 1);
} 

/* Bisection Method */
void bisection(double E1, double E2) {
	
	double E, fE1, fE2, fE;
	int itr;

	itr = 0;

	do {
		fE1 = f(E1);
		fE2 = f(E2);
		E = (E1+E2)/2;
		fE = f(E);
	
		if(fE1 * fE < 0  && fE2 * fE > 0) {
			E2 = E;
			fE2 = fE;
		}

		else {
			E1 = E;
			fE1 = fE;
		}
	
		itr ++;
	
	} while(fabs(f(E)) > EPSILON && itr <= MAX_ITR);

	printf("\nBisection Method:\n");

	if(fabs(f(E)) <= EPSILON)
		printf("The binding energy of the deuteron |E| is %f MeV\n", E);
	else
		printf("Error, no convergence.\n");

	printf("No. of iterations: %d\n\n", itr);

}

/* Newton-Raphson Method */
void newton(double E1, double E2) {

	double E, E3 = (E1+E2)/2;
	int itr;

	itr = 0;

	do {
	
		E = E3 - f(E3)/df(E3);

		E3 = E;
	
		itr ++;
	
	} while(fabs(f(E)) > EPSILON && itr <= MAX_ITR);

	printf("\nNewton-Raphson Method:\n");
	
	if(fabs(f(E)) <= EPSILON)
		printf("The binding energy of the deuteron |E| is %f MeV\n", E);
	else 
		printf("Error, no convergence.\n");

	printf("No. of iterations: %d\n\n", itr);

}

/* Secant Method */
void secant(double E1, double E2) {

	double E;
	double fE1, fE2;
	int itr;

	itr = 0;

	do {
		
		fE1 = f(E1);
		fE2 = f(E2);

		E = (fE2 * E1 - fE1 * E2)/(fE2 - fE1);

		E1 = E2;
		E2 = E;

		itr ++;

	} while (fabs(f(E)) > EPSILON && itr <= MAX_ITR);

	printf("\nSecant Method:\n");

	if(fabs(f(E)) <= EPSILON)
		printf("The binding energy of the deuteron |E| is %f MeV\n", E);
	else
		printf("Error, no convergence.\n");

	printf("No. of iterations: %d\n\n", itr);

}

/* main function */
int main(void) {
	
	double E1, E2;

	E1 = 0.8;
	E2 = 1.2;

	if(f(E1)*f(E2) < 0) {

		bisection(E1, E2);
		newton(E1, E2);
		secant(E1, E2);
	}

	else
		printf("Error, root not in interval.\n");

	return 0;

}
