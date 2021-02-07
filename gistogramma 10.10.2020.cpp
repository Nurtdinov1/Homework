#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream openingFile()
{
	fstream file1;
	string fname;
	cout << "Введите название файла: ";
	cin >> fname;
	file1.open(fname);
	while (!file1.is_open())
	{
		cout << "Введено неверное название файла." << "\n" << "Введите название файла заново: ";
		cin >> fname;
		file1.open(fname);
	}
	cout << "Файл открыт.";
	return file1;
}

void main()
{
	setlocale(LC_ALL, "ru");
	fstream file1;
	ofstream file2;
	string fileName;
	file1 = openingFile();
	int l;
	int* mas = new int[255];
	for (int i = 0; i < 255; ++i)
		mas[i] = 0;

	while (!file1.eof())
		if (file1.get() != '\n')
			++mas[int(file1.get())];

	cout << "\n" << "Введите имя файла для гистограммы: ";
	cin >> fileName;
	file2.open(fileName);
	if (!file2.is_open())
	{
		cout << "Ошибка при открытии файла.";
		exit(-1);
	}
	int max = 0;
	for (int i = 0; i < 255; ++i)
		if (mas[i] > max)
			max = mas[i];
	for (int i = 0; i < max; ++i)
	{
		for (int j = 0; j < 255; ++j)
		{
			if ((max - mas[j] > i) && (mas[j] > 0))
				file2 << " ";
			else if (mas[j] > 0 && max - mas[j] <= i)
				file2 << " * ";
		}
		file2 << "\n";
	}
	bool first = false;
	for (int i = 0; i < 255; ++i)
	{
		if (i == 10)
		{
			if (first == false)
				file2 << "\n" << " ";
			else
				file2 << "" << "\n" << "";
			continue;
		}
		if (mas[i] > 0)
		{
			if (first == false)
			{
				cout << char(i) << "";
				first = true;
			}
			file2 << " " << char(i) << " ";
		}
	}
}