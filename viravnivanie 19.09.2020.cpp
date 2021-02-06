#include <iostream>

int main()
{
	const int n = 5, m = 6;
	int M[n][m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			M[i][j] = rand() % 100000;

	int* w = new int[m];
	for (int j = 0; j < m; ++j) {
		w[j] = 0;
		for (int i = 0; i < n; ++i) {
			int a = 0;
			int n = M[i][j];
			do {
				++a;
				n /= 10;
			} while (n > 0);

			if (w[j] < a)
				w[j] = a;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int a = 0;
			int x = M[i][j];
			do {
				++a;
				x /= 10;
			} while (x > 0);

			for (int s = a; s < w[j]; ++s)
				std::cout << ' ';
			std::cout << M[i][j];
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			int a = 0;
			int x = M[i][j];
			do {
				++a;
				x /= 10;
			} while (x > 0);

			std::cout << M[i][j];
			for (int s = a; s < w[j]; ++s)
				std::cout << ' ';
			std::cout << ' ';
		}
		std::cout << std::endl;
	}
	delete[] w;
	return 0;
}