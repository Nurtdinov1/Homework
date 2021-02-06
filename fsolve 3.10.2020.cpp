#include <iostream>
#include <cmath>

double fx(double x) {
	return 2 * x * x * x - 15 * x * x + 9 * x - 17;
}
double derivative(double x) {
	return 6 * x * x - 30 * x + 9;
}
typedef double(*fun)(double x);
double fsolve(fun fx, fun derivative, double x_0) {
	double x_1 = x_0 - fx(x_0) / derivative(x_0);
	while (fabs(x_1 - x_0) > 0.000001) {
		x_0 = x_1;
		x_1 = x_0 - fx(x_0) / derivative(x_0);
	}
	return x_1;
}

int main() {
	std::cout << fsolve(fx, derivative, 10);
	return 0;
}