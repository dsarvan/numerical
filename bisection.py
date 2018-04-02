# File: bisection.py
# Programmer: D.Saravanan     dayalsaravanan@gmail.com
# Date: 15 March 2018
# Version: Original
# Comments: Python code for root finding by Bisection Method

def funct(x):
	return x*x - 13

def bisection(a, b):
	fa = funct(a)
	fb = funct(b)
	c = (a+b)/2.
	fc = funct(c)

	EPSILON = 1.E-10

	itr = 0
	
	while(abs(fc) > EPSILON): 
		if(fa*fc < 0): 
			b = c
			fb = fc
		else:
			a = c
			fa = fc
	
		itr = itr + 1
	
	print("\nBisection Method:\n")
	
	if(abs(fc) <= EPSILON):
		print("The root of the equation is %f\n", c)
	else:
		print("Error, no convergence.\n")
	
	print("No. of iterations: %d\n\n", itr)

a = 3.
b = 4.

if(funct(a)*funct(b) < 0):
	bisection(a,b)
else:
	print("Error, root not in interval.\n")
