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

	int mas2[N][M];
	cout << "Друк ДМ з ОМ: " << endl;
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

	cout << "Середнє значення мiнiмальних значень рядкiв -> : " << average << "\n";
}
void twoArrayProc() { // Two-dimensional array processing

	setlocale(LC_ALL, "rus");

	int mas1[N * M] = { 4, 6 ,9 ,2, 6 , 8 ,9, 5 ,7 };
	cout << "Одновимiрний масив ->: ";
	for (int i = 0; i < N * M; i++) {
		cout << setw(4) << mas1[i];
	}
	cout << endl;
	cout << endl;

	fun(mas1);

	cout << endl << "Одновимiрний масив (пiсля функцiї) ->: ";
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

	setlocale(LC_ALL, "rus");

	int num1,
		num2;

	cout << "Введiть перше число ->: ";
	cin >> num1;
	cout << "Введiть друге число ->: ";
	cin >> num2;

	char result = enteredNumbers(num1, num2);
	cout << num1 << " " << result << " " << num2 << endl;
}
//

//
void fillArray(int arr[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << "Введiть елемент [" << i << "][" << j << "]: ";
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
void functionArray(){ //functionTwoDimensionalArray
	setlocale(LC_ALL, "rus");
	int arr[N][M];

	fillArray(arr);

	cout << "Двовимiрний масив:" << endl;
	printArray(arr);

	for (int i = 0; i < N; i++) {
		int sum = sumPositiveElementsInRow(arr[i], M);
		cout << "Сума позитивних елементiв в рядку " << i << ": " << sum << endl;
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
	CONSOLE_FONT_INFOEX fontInfo;
	
	
	
	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0,0);


		SetConsoleTextAttribute(h, 3);
		cout << endl <<"1. --- Task1. Two-dimensional array processing" << endl;
		cout << "2. --- Task2. ComparisonArray" << endl;
		cout << "3. --- Task3. Function Two-Dimensional Array" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "0.Exit" <<endl;
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

int main(){
	StartMenu();
}