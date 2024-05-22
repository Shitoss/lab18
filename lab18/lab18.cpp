/*    Программа Lab_18     */
/*     бинарные файлы      */
/*Записать в файл оценки (в баллах), 
полученные некоторым студентом на
экзаменах в течение всех сессий. 
Добавить в начало файла оценки, 
полученные на вступительных экзаменах*/
/*Дата:06.12.21            */
/*Программист : Шитиков Д.П.*/
/*Проверил: Козлов А.И.    */
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
using namespace std;

int main()
{
	FILE* f;
	FILE* f1;
	int a,d;
	int n,m,k,n1;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "введите кол-во оценок" << endl;
	cin >> n;

	 fopen_s (&f,"f1.lab", "wb");
	 fopen_s(&f1, "f2.lab", "wb"); // открытие обоих файлов для записи

	 for (int i = 0; i < n; i++) // запись в файл с оценками
	 {
		 cout << "введите " << i + 1 << " оценку" << endl;
		 cin >> m ;
		 fwrite(&m, sizeof(int), 1, f1);

	 }
	 fclose(f1); // закрытие файла с оценками


	cout << "введите кол-во оценок за вступительные экзамены" << endl;
	cin >> n1;
	for (int i = 0; i < n1; i++) //запись в файл с оценками за вступительные экзамены
	{
		cout << "введите " << i+1 << "оценку за вступит. экз." << endl;
		cin >> a;
		fwrite(&a, sizeof(int), 1, f);

	}

	fseek(f, n1 * sizeof(int), SEEK_SET); 

	fopen_s(&f1, "f2.lab", "rb"); // открытие файла с оценками на чтение

	for (int i = 0; i < n; i++) // запись оценок в конец  файла с оценками за вступит экзамены
	{
		d = fgetc(f1);
		fwrite(&d, sizeof(int), 1, f);
	}

	fclose(f);
	fclose(f1); // закрытие файлов

	fopen_s(&f, "f1.lab", "rb");  // открытие файла на чтение
		if (f != NULL) // проверка на пустоту файла
		{
			while (k = fread(&a, sizeof(int), 1, f)) // вывод значений файла
			{
				cout << setw(7)<< a; 
			}
		}
		fclose(f); // закрытие файла

}
