#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<windows.h> 
#include <iomanip>
#include <Windows.h>
#include <string>
#include <cstdlib> 
#include <conio.h>	 //console
#include"My_Lib.h"
using namespace std;





int main()
{
	setlocale(LC_ALL, "rus");
	Book* bookBacklist = 0;		 //=  Sponsor* OurSponsors = 0;
	int bookAmount = 0;			 //=  int sponsorAmount = 0;
	int tab = 0;
	char* st_book ="super1.dat";
	

	
	int YesOrNot = 0; //  продолжить или остановить ввод данных

	do
	{
		bookBacklist = AddStruct(bookBacklist, bookAmount);
		SetDataBook(bookBacklist, bookAmount);

		bookAmount++;

		cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
		cin >> YesOrNot;
		cin.get();
	} while (YesOrNot != 0);

	ShowDataBook(bookBacklist, bookAmount);

	
	SaveFile(bookBacklist, st_book, bookAmount);
	OpenFile(tab, st_book, bookAmount);
	
	delete[] bookBacklist;
	cin >> tab;
}

Book* AddStruct(Book* Obj, const int amount) {
	if (amount == 0)
	{
		Obj = new Book[amount + 1]; // выделение памяти для первой структуры
	}
	else
	{
		Book* tempObj = new Book[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = Obj[i]; // копируем во временный объект
		}
		delete[] Obj;

		Obj = tempObj;
	}
	return Obj;
}

void SetDataBook(Book* Obj, const int amount) {
	//cout << "Фамилия: ";
	//cin.getline(Obj[amount].surname, 32);
	//cout << "Имя: ";
	//cin.getline(Obj[amount].name, 32);
	//cout << "Сумма пожертвования: ";
	//cin >> Obj[amount].sum;
	//cin.get();
	//cout << endl;

	char buf[200];
	int temp;


		MassageBook_1();
		cin.get(Obj[amount].B_name, 110);

		while (strlen(Obj[amount].B_name) > 100)
		{
			MassageBook_2();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(Obj[amount].B_name, 110);
		}

		if (Obj[amount].B_name[0] != '\0')
			eatline();
		else {
			SetConsoleCursorPosition(2, 41);
			cout << "\t\t\t\t\t\t\t\t\t\t\t\n";
			return;
		}
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_3();
		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());
		cin.get(Obj[amount].Aut, 110);

		while (strlen(Obj[amount].Aut) > 100)
		{
			MassageBook_4();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(Obj[amount].Aut, 110);
		}

		if (Obj[amount].Aut[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_5();
		cin.get(Obj[amount].R_date, 15);

		while (strlen(Obj[amount].R_date)>10)		//chek leng
		{
			SetConsoleCursorPosition(2, 41);

			MassageBook_5();
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(Obj[amount].R_date, 15);
		}				 //temp

		if (Obj[amount].R_date[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_6();
		cin.get(Obj[amount].Con, 35);

		while (strlen(Obj[amount].Con) > 30) {

			MassageBook_7();
			cin.clear(0);
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get(Obj[amount].Con, 35);
		}


		if (Obj[amount].Con[0] != '\0')
			eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_8();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (1>temp || temp>11 || !atoi(buf))
		{
			MassageBook_9();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		Obj[amount].Cou = temp;

		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_10();
		cin.getline(buf, 8);
		temp = atoi(buf);

		while (0>temp || temp>5 || !atoi(buf))
		{
			MassageBook_11();
			cin.getline(buf, 5);
			temp = atoi(buf);

		}
		Obj[amount].Rat = temp;
		eatline();

		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream

		MassageBook_12();
		cin.getline(buf, 10);
		temp = atoi(buf);

		while (0>temp || temp>9999 || !atoi(buf))
		{
			MassageBook_13();
			cin.getline(buf, 10);
			temp = atoi(buf);

		}
		Obj[amount].ID_b = temp;
		eatline();



		cin.clear(0);
		cin.ignore(cin.rdbuf()->in_avail());			 //clear stream


}

void ShowDataBook(const  Book* Obj, const int amount) {
	//system("cls");
	//cout << "№  " << "Фамилия\t" << "Имя\t" << "Сумма\t" << endl;
	//cout << "========================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		//cout << i + 1 << "  " << Obj[i].surname << '\t' << Obj[i].name << '\t' << Obj[i].sum << endl;
	

	cout << setiosflags(ios::left);					//viravnivanie
	cout <<i << setw(3) << i<< ":" << setw(20) << Obj[i].B_name;
	cout << i << setw(20) << Obj[i].Aut;
	cout << i << setw(10) << Obj[i].R_date;
	cout << i << setw(20) << Obj[i].Con;
	cout << i << setw(2) << Obj[i].Rat;
	cout << i << setw(5) << Obj[i].ID_b;
	cout << i << setw(3) << Obj[i].Cou << endl;	  }
}

User* AddStruct(User* Obj, const int amount){
	if (amount == 0)
	{
		Obj = new User[amount + 1]; // выделение памяти для первой структуры
	}
	else
	{
		User* tempObj = new User[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			tempObj[i] = Obj[i]; // копируем во временный объект
		}
		delete[] Obj;

		Obj = tempObj;
	}
	return Obj;
}

void SetDataUser(User* Obj, const int amount){}

void ShowDataUser(const  User* Obj, const int amount){}

void OpenFile(int tab,char* filename, int  bookAmount) {
	char* file = filename;
	Book book;
	FILE * pFile;
	int n = 0;
	long lSize;
	char * buffer;
	size_t result;

	pFile = fopen(file, "rb");
	if (pFile == NULL) perror("Error opening file");
	else
	{
		while (fgetc(pFile) != EOF) {							
			fread((char *)&book, sizeof(book), 1, pFile);
			cout << setiosflags(ios::left);					//viravnivanie	 //zamena vivod na ekran
			cout << n << setw(20) << book.B_name << endl;
			cout << '|' << setw(20) << book.Aut << endl;
			cout << '|' << setw(10) << book.R_date << endl;
			cout << '|' << setw(20) << book.Con << endl;
			cout << '|' << setw(2) << book.Rat << endl;
			cout << '|' << setw(5) << book.ID_b << endl;
			cout << '|' << setw(3) << book.Cou << endl << endl;

			++n;
		}
		if (feof(pFile)) {
			puts("End-of-File reached.");
			printf("Total number of bytes read: %d\n", n);
		}
		else puts("End-of-File was not reached.");
		fclose(pFile);
	}
	return ;
}


void SaveFile(Book* Obj, char* filename, int  bookAmount) {
	char* file = filename;
	//struct device labaDevice;
	  Book book;

	FILE* outFile;
	if ((outFile = fopen(file, "wb")) == NULL) {
		cout << "Con not open the file" << endl;
		return ;
	}
	//////////////////////
	//fwrite(&count_emp, sizeof(int), 1, fp);
	//for (i = 0; i < count_emp; ++i)
	//	fwrite(&A[i], sizeof(struct employee), 1, fp);
	//fclose(fp);
  //////////////////////
	fwrite(&bookAmount, sizeof(int), 1, outFile);
	for (int i = 0; i < bookAmount; ++i)
		fwrite(&Obj[i], sizeof(struct Book ), 1, outFile);

	fclose(outFile);

	return ;
}


