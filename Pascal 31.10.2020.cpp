#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

long double Triangle(int N, int K)
{
    return ((N < K) ? 0 : ((K == 0) ? 1 : (((N - K) + 1) / long double(K) * Triangle(N, K - 1))));
}
int main()
{
    setlocale(LC_ALL, "ru");
    int x;
    cout << "Введите количество линий треугольника Паскаля (x > 0): ";
    cin >> x;
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= i; ++j)
            cout << Triangle(i, j) << setw(5);
        cout << '\n';
    }
    return 0;
}