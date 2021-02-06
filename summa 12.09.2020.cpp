#include <iostream>

int main()
{
    double x;
    int n;
    std::cout << "Input x: ";
    std::cin >> x;

    do {
        std::cout << "n: ";
        std::cin >> n;
    } while (n < 1);

    double S = 0, ak = x;
    for (int k = 0; k <= n; ++k) {
        S += ak;
        ak *= (-1) * x * x / (2. * k + 2.) / (2. * k + 3.);
    }
    std::cout << "S1 = " << S << std::endl;

    double eps = 1e-6;
    S = 0;
    ak = x;
    int k = 0;
    double sign = 1;
    while (ak > eps) {
        S += sign * ak;
        ak *= x * x / (2. * k + 2.) / (2. * k + 3.);
        sign *= -1;
        ++k;
    }
    std::cout << "S2 = " << S << std::endl;
    std::cout << k << " steps" << std::endl;
}