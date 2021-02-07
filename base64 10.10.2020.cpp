#include <iostream>
#include <fstream>

using namespace  std;

char Base64Char(unsigned char b) {
	if (b >= 'A' && b <= 'Z') {
		return b - 'A';
	}
	if (b >= 'a' && b <= 'z') {
		return b - 'a' + 26;
	}
	if (b >= '0' && b <= '9') {
		return b - '0' + 52;
	}
	if (b == '+') {
		return 62;
	}
	if (b == '/') {
		return 63;
	}
	return 64;
}

char С(unsigned char b) {
	int c = (int)b;
	return c;
}

int Base64Decode(char* inStr, int Len, char* outStr) {
	unsigned char a1, a2, a3, b1, b2, b3, b4;
	int x = 0, y = 0;

	for (int i = 0; i < Len; i += 4) {
		b1 = Base64Char(inStr[i]);
		b2 = Base64Char(inStr[i + 1]);
		b3 = Base64Char(inStr[i + 2]);
		b4 = Base64Char(inStr[i + 3]);
		if (b3 == 64) {
			b3 = 0;
			b4 = 0;
			y = 2;
		}
		if (b4 == 64) {
			b4 = 0;
			y = 1;
		}
		a1 = (b1 << 2) | (b2 >> 4);
		a2 = (b2 << 4) | (b3 >> 2);
		a3 = (b3 << 6) | b4;
		outStr[x++] = a1;
		outStr[x++] = a2;
		outStr[x++] = a3;
	}
	int z = x - y;
	return z;
}
int main()
{
	setlocale(LC_ALL, "ru");
	char iFname[256];
	char oFname[256];
	cout << "Input source file name: ";
	cin.getline(iFname, 256);
	ifstream inFile(iFname);

	if (!inFile) {
		cout << "Can not open file " << iFname << "\n";
		return 1;
	}
	cout << "Input destination file name: ";
	cin.getline(oFname, 256);
	ofstream outFile(oFname, ios_base::binary);

	if (!outFile) {
		inFile.close();
		cout << "Can not write to file" << oFname << "\n";
		return 2;
	}
	const int block_size = 19;
	char inStr[4 * block_size], outStr[3 * block_size];
	while (inFile.peek() != EOF) {
		int f = 0;
		for (int i = 0; i < 4 * block_size && inFile.peek() != EOF; ++i) {
			char j;
			j = inFile.get();
			if (j >= 'A' && j <= 'Z' || j >= 'a' && j <= 'z' || j >= '0' && j <= '9' || j == '+' || j == '/' || j == '=') {
				inStr[i] = j;
				++f;
			}
		}
		f = Base64Decode(inStr, f, outStr);
		outFile.write(outStr, f);
	}
	inFile.close();
	outFile.close();
	cout << "Decoder completed operation" << "\n";
}