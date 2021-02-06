#include <iostream>

void reversArray(int N[], int n) {
    for (int l = 0, r = n - 1; l < r; ++l, --r) {
         int tmp = N[l]; N[l] = N[r]; N[r] = tmp;
    }
}

void shiftArray(int N[], int n, int k) {
    while (k < 0) {
        k += n;
    }
    while (k >= n) {
        k -= n;
    }
    if (k > 0) {
        reversArray(N, k);
        reversArray(N + k, n - k);
        reversArray(N, n);
    }
}

void printArray(const int N[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << N[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int n = 20, m = 5;
    int* M = new int[n];
    
    for (int i = 0; i < n; ++i) {
        M[i] = i + 1;
    }
    
    shiftArray(M, n, m);
    printArray(M, n);
    delete[] M;
    
    return 0;
}