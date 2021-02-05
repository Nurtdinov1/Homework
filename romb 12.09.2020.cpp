#include <iostream>

int main()
{
    int n;
    do {
        std::cout << "Input n > 0: ";
        std::cin >> n;
    } while (n <= 0);
    char space = ' ', asterisk = '*'; // asterisk - звездочка

    // Верхний тругольник
    for (int i = 1; i <= n; ++i) {
        for (int step = 1; step <= n; ++step) {
            for (int j = 1; j <= n - i; ++j) {
                std::cout << space;
            }
            for (int j = 1; j <= 2 * i - 1; ++j) {
                std::cout << asterisk;
            }
            for (int j = 1; j <= n - i; ++j) {
                std::cout << space;
            }
        }
        std::cout << std::endl;
    }
    
    // Нижний треугольник
    for (int i = n - 1; i >= 1; --i) {
        for (int step = 1; step <= n; ++step) {
            for (int j = 1; j <= n - i; ++j) {
                std::cout << space;
            }
            for (int j = 1; j <= 2 * i - 1; ++j) {
                std::cout << asterisk;
            }
            for (int j = 1; j <= n - i; ++j) {
                std::cout << space;
            }
        }
        std::cout << std::endl;
    }
}