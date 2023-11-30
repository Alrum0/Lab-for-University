#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

#define N 3
#define M 3

//
void fun(int mas1[]) {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	int mas2[N][M];
	SetConsoleTextAttribute(h, 3);
	cout << "Друк ДМ з ОМ: " << endl;
	SetConsoleTextAttribute(h, 7);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mas2[i][j] = mas1[i * M + j];
			cout << mas2[i][j] << " ";
		}
		cout << endl;
	}

	int minValue[N];
	for (int i = 0; i < N; i++) {
		minValue[i] = mas2[i][0];
		for (int j = 1; j < M; j++) {
			if (mas2[i][j] < minValue[i]) {
				minValue[i] = mas2[i][j];
			}
		}
	}

	int sumMin = 0;
	for (int i = 0; i < N; i++) {
		sumMin += minValue[i];
	}

	float average = (float)sumMin / N;

	SetConsoleTextAttribute(h, 2);
	cout << "Середнє значення мiнiмальних значень рядкiв -> : ";
	SetConsoleTextAttribute(h, 5);
	cout << average << endl;
	SetConsoleTextAttribute(h, 7);
}
void twoArrayProc() { // Two-dimensional array processing

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");

	int mas1[N * M] = { 4, 6 ,9 ,2, 6 , 8 ,9, 5 ,7 };
	SetConsoleTextAttribute(h, 3);
	cout << "Одновимiрний масив ->: ";
	SetConsoleTextAttribute(h, 7);
	for (int i = 0; i < N * M; i++) {
		cout << setw(4) << mas1[i];
	}
	cout << endl;
	cout << endl;

	fun(mas1);

	SetConsoleTextAttribute(h, 3);
	cout << endl << "Одновимiрний масив (пiсля функцiї) ->: ";
	SetConsoleTextAttribute(h, 7);
	for (int i = 0; i < N * M; i++) {
		cout << setw(4) << mas1[i];
	}
	cout << endl;
	cout << endl;
}
//

//
char enteredNumbers(int a, int b) {
	if (a > b) {
		return '>';
	}
	if (a < b) {
		return '<';
	}
	else {
		return '=';
	}
}
void comparisonArray() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");

	int num1,
		num2;
	cout << endl;
	SetConsoleTextAttribute(h, 3);
	cout << "Введiть перше число ->: ";
	SetConsoleTextAttribute(h, 5);
	cin >> num1;
	SetConsoleTextAttribute(h, 3);
	cout << "Введiть друге число ->: ";
	SetConsoleTextAttribute(h, 5);
	cin >> num2;
	SetConsoleTextAttribute(h, 7);

	char result = enteredNumbers(num1, num2);
	SetConsoleTextAttribute(h, 5);
	cout << num1;
	SetConsoleTextAttribute(h, 7);
	cout << " ";
	SetConsoleTextAttribute(h, 2);
	cout << result;
	SetConsoleTextAttribute(h, 7);
	cout << " ";
	SetConsoleTextAttribute(h, 5);
	cout << num2 << endl;
	SetConsoleTextAttribute(h, 7);
}
//

//
void fillArray(int arr[N][M]) {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			SetConsoleTextAttribute(h, 3);
			cout << "Введiть елемент ";
			SetConsoleTextAttribute(h, 7);
			cout << "[" << i << "][" << j << "]: ";
			cin >> arr[i][j];
		}
	}
}
void printArray(int arr[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << setw(4) << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int sumPositiveElementsInRow(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > 0) {
			sum += arr[i];
		}
	}
	return sum;
}
void functionArray() { //functionTwoDimensionalArray

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");
	int arr[N][M];

	fillArray(arr);
	SetConsoleTextAttribute(h, 2);
	cout << "Двовимiрний масив:" << endl;
	SetConsoleTextAttribute(h, 7);
	printArray(arr);

	for (int i = 0; i < N; i++) {
		int sum = sumPositiveElementsInRow(arr[i], M);
		SetConsoleTextAttribute(h, 2);
		cout << "Сума позитивних елементiв в рядку ";
		SetConsoleTextAttribute(h, 5);
		cout << i;
		SetConsoleTextAttribute(h, 7);
		cout << ": ";
		SetConsoleTextAttribute(h, 1);
		cout << sum << endl;
		SetConsoleTextAttribute(h, 7);
	}
}
//

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
		cout << endl << "1. --- Task1. Two-dimensional array processing" << endl;
		cout << "2. --- Task2. ComparisonArray" << endl;
		cout << "3. --- Task3. Function Two-Dimensional Array" << endl;
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
			twoArrayProc();
			break;
		case 2:
			comparisonArray();
			break;

		case 3:
			functionArray();
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