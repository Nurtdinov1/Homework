#include <iostream>

int main()
{
    const int x = 6, c = 7;
    int M[x][c];
    int k = 1, a = 0, b = 0, L = 0, R = c - 1, T = 1, B = x - 1;
    do {
        do {
            M[b][a] = k;
            ++k;
            ++a;
        } while (a < R);
        --R;
        
        if (k <= x * c) {
            do {
                M[b][a] = k;
                ++k;
                ++b;
            } while (b < B);
            --B;
        }
        
        if (k <= x * c) {
            do {
                M[b][a] = k;
                ++k;
                --a;
            } while (a > L);
            ++L;
        }
        
        if (k <= x * c) {
            do {
                M[b][a] = k;
                ++k;
                --b;
            } while (b > T);
            ++T;
        }

    } while (k <= x * c);
    
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < c; ++j) {
            std::cout << M[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}