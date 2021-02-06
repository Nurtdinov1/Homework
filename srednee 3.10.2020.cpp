#include <iostream>
#include <stdarg.h>

double average(double x, ...) {
	va_list args;
	va_start(args, x);
	double c = x, sr = 0;
	int n = 0;
	do {
		sr += c;
		++n;
		c = va_arg(args, double);
	} while (c != -1.);
	va_end(args);
	sr /= n;
	return sr;
}

int main()
{
	std::cout << average(1., 2., 3., 4., 5., -1.) << std::endl;
}