/*    Программа Lab_18     */
/*     бинарные файлы      */
/*Дата:06.12.21            */
/*Програмист : Шитиков Д.П.*/
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
	 fopen_s(&f1, "f2.lab", "wb");

	 for (int i = 0; i < n; i++)
	 {
		 cout << "введите " << i + 1 << " оценку" << endl;
		 cin >> m ;
		 fwrite(&m, sizeof(int), 1, f1);

	 }
	 fclose(f1);


	cout << "введите кол-во оценок за вступительные экзамены" << endl;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cout << "введите " << i+1 << "оценку за вступит. экз." << endl;
		cin >> a;
		fwrite(&a, sizeof(int), 1, f);

	}

	fseek(f, n1 * sizeof(int), SEEK_SET);

	fopen_s(&f1, "f2.lab", "rb");

	for (int i = 0; i < n; i++)
	{
		d = fgetc(f1);
		fwrite(&d, sizeof(int), 1, f);
	}

	fclose(f);
	fclose(f1);

	fopen_s(&f, "f1.lab", "rb");
		if (f != NULL)
		{
			while (k = fread(&a, sizeof(int), 1, f))
			{
				cout << setw(7)<< a; 
			}
		}
		fclose(f);


}