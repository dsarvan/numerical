# File: deriv.py
# Programmer: D.Saravanan   dayalsaravanan@gmail.com
# Date: 13 May 2018
# Version: Original
# Comments: Python code to find derivative of a function

from math import exp

def f(x, alpha):
	return exp(alpha * x)

def forward(x, h, f):
	for_calc = (f(x+h, alpha)-f(x, alpha))/h
	print "The derivative by forward difference method: ", for_calc

def backward(x, h, f):
	bac_calc = (f(x, alpha)-f(x-h, alpha))/h
	print "The derivative by backward difference method: ", bac_calc

def central(x, h, f):
	cen_calc = (f(x+h, alpha)-f(x-h, alpha))/(2*h)
	print "The derivative by central difference method: ", cen_calc

x = 1.
h = 1e-15
alpha = 1.

forward(x, h, f)
backward(x, h, f)
central(x, h, f)
