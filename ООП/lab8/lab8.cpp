#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>

using namespace std;

void fillingArray(int* inputArray, int size) {
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	int* positiveElements = new int[size];
	int positiveCount = 0;

	for (int i = 1; i < size - 1; ++i) {
		if (*(inputArray + i) < *(inputArray + i - 1) && *(inputArray + i) < *(inputArray + i + 1)) {
			cout << "Елемент ";
			SetConsoleTextAttribute(h, 2);
			cout << *(inputArray + i);
			SetConsoleTextAttribute(h, 7);
			cout << " менший за попереднiй та наступний." << endl;
		}

		if (*(inputArray + i) > 0) {
			*(positiveElements + positiveCount) = *(inputArray + i);
			positiveCount++;
		}
	}

	SetConsoleTextAttribute(h, 3);
	cout << "Новий динамiчний масив з позитивними елементами ->: ";
	SetConsoleTextAttribute(h, 7);
	for (int i = 0; i < positiveCount; ++i) {
		cout << *(positiveElements + i) << setw(4);
	}
	cout << endl;
	SetConsoleTextAttribute(h, 3);
	cout << endl << "Кiлькiсть позитивних елементiв ->: ";
	SetConsoleTextAttribute(h, 2);
	cout << positiveCount << endl;
	SetConsoleTextAttribute(h, 7);
	cout << endl;

	delete[] positiveElements;
}

void countPositivElements() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");

	int size;
	SetConsoleTextAttribute(h, 3);
	cout << "Введiть кiлькiсть елементiв ->: ";
	SetConsoleTextAttribute(h, 7);
	cin >> size;

	if (size < 3) {
		SetConsoleTextAttribute(h, 4);
		cout << "Некоректний ввiд. Кiлькiсть елементiв повинна бути мiнiмум 3." << endl;
		SetConsoleTextAttribute(h, 7);
		return;
	}

	int* inputArray = new int[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		*(inputArray + i) = rand() % 21 - 10;
	}

	for (int i = 0; i < size; i++) {
		cout << *(inputArray + i) << setw(4);
	}
	cout << endl;

	fillingArray(inputArray, size);

	delete[] inputArray;
}

void gotoxy(int x, int y) {
	COORD crds;
	crds.X = x;
	crds.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}

void StartMenu() {

	int menuitem;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);




	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. --- Task1. Count positive elements" << endl;
		cout << "2. --- Task2. ComparisonArray" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "0.Exit" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "Choise task by his number: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem)
		{
		case 1:
			countPositivElements();
			break;
		case 2:
			;
			break;
		case 0:
			cout << "Bye-Bye";
			break;

		default:
			cout << "incorrect choice ";
			break;
		}
		cout << "Press anykay";
		system("pause");
		system("cls");


	} while (menuitem != 0);

}

int main() {
	StartMenu();
}