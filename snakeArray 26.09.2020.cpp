#include <iostream>
#include <iomanip>

void snake(int** N, int n) {
	int a = 1, b = 0, c = 0, d = 1;
	while (a <= n * (n + 1) / 2) {
		N[b][c] = a++;
		b += d;
		c -= d;
		if (c < 0) {
			c = 0;
			d = -d;
		}
		if (b < 0) {
			b = 0;
			d = -d;
		}
	}
	b += d;
	c -= d;
	
	while (a <= n * n) {
		N[b][c] = a++;
		b += d;
		c -= d;
		if (b >= n) {
			d = -d;
			b = n - 1;
			c += 2;
		}if (c >= n) {
			d = -d;
			c = n - 1;
			b += 2;
		}
	}
}

int main()
{
	int n = 10;
	int** N = new int* [n];
	for (int i = 0; i < n; ++i) {
		N[i] = new int[n];
	}
	snake(N, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			std::cout << std::setw(4) << N[i][j];
		std::cout << std::endl;
	}
	for (int i = 0; i < n; ++i)
		delete[] N[i];
	delete[] N;
	return 0;
}