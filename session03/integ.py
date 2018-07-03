#File: integ.py
#Programmer: D.Saravanan dayalsaravanan@gmail.com
#Date: 16 February 2018
#Version: Original
#Comments: Python code to compute integral exp(x)

from math import exp

def f(x):
	return exp(x)

def midpoint(n, a, b, h, f):
	sum = 0.0
	for i in range(0, n):
		x = a + i * h
		x = x + h/2
		sum += h * exp(x)
	return sum

def trapezoid(n, a, b, h, f):
	sum = 0.0
	for i in range(0, n):
		x = a + i * h
		sum += (h/2.) * (f(x) + f(x+h))
	return sum

N = 5000
a = 0.
b = 1.

exact = exp(b) - exp(a)

file = open("datafile.txt", "w")

for n in range(2, N+1):
	h = (b-a)/n
	 
	mid_calc = midpoint(n, a, b, h, f)
	trap_calc = trapezoid(n, a, b, h, f)

	mid_err = abs((mid_calc - exact)/(exact))
	trap_err = abs((trap_calc - exact)/(exact))

	file.write("%d \t %e \t %e\n" %(n, mid_err, trap_err))

file.close()
