# File: integ.py
# Programmer: D.Saravanan  dayalsaravanan@gmail.com
# Date: 13 May 2018
# Version: Original
# Comments: Python code to compute integration numerically

from math import exp

def f(x, alpha):
	return exp(alpha * x)

def midpoint(N, a, h, f):
	midpt_sum = 0.

	for i in range(0, N, 1):
		x = a + i * h
		x = x + (h/2.)
		midpt_sum += h * ( f(x, alpha) )
	
	midpt_calc = midpt_sum

	print "The integral determined by Midpoint rule: ", midpt_calc

def trapezoid(N, a, h, f):
	trap_sum = 0.

	for i in range(0, N, 1):
		x = a + i * h
		trap_sum += (h/2.) * ( f(x, alpha) + f(x+h, alpha) )

	trap_calc = trap_sum

	print "The integral determined by Trapezoid rule: ", trap_calc

def simpson13(N, a, h, f):
	simp13_sum = 0.

	for i in range(0, N, 2):
		x = a + i * h
		simp13_sum += (h/3.) * ( f(x, alpha) + 4 * f(x+h, alpha) + f(x+2*h, alpha) )

	simp13_calc = simp13_sum

	print "The integral determined by Simpson's 1/3 rule: ", simp13_calc

def simpson38(N, a, h, f):
	simp38_sum = 0.

	for i in range(0, N, 3):
		x = a + i * h
		simp38_sum += (3.*h)/8. * ( f(x, alpha) + 3 * f(x+h, alpha) + 3 * f(x+2*h, alpha) + f(x+3*h, alpha) )

	simp38_calc = simp38_sum

	print "The integral determined by Simpson's 3/8 rule: ", simp38_calc

a = 0.
b = 1.
N = 500000
alpha = 1.

h = (b-a)/N

midpoint(N, a, h, f)
trapezoid(N, a, h, f)
simpson13(N, a, h, f)
simpson38(N, a, h, f)	
