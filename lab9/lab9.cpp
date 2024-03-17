#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <cstring> // for using strchr

using namespace std;

#define N 40

char findFirstSymbol(const char* referenceString, const char* inputSring) {
	for (; *inputSring != '\0'; inputSring++) {
		if (strchr(referenceString, *inputSring) == nullptr) { // the first position where we search, the second position the symbol are looking for in a string
			return *inputSring;
		}
	}
	return 0;
}

void gotoxy(int x, int y) {
	COORD crds;
	crds.X = x;
	crds.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}

void startMenu() {
	setlocale(LC_ALL, "ukr");

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	int menuItem;
	char referencrString[N];
	char inputString[N];
	char firstSymbol;

	do {
		gotoxy(65, 0);
		cout << "Меню" << endl;
		gotoxy(0, 0);

		SetConsoleTextAttribute(h, 3);
		cout << "1. Ввести заданий рядок" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "2. Вийти з програми" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "Введiть з запропопонованих варiантiв пункт: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuItem;

		switch (menuItem) {
		case 1:
			cout << "Введiть заданий рядок: ";
			cin >> referencrString;

			cout << "Введiть рядок для аналiзу:";
			cin >> inputString;

			firstSymbol = findFirstSymbol(referencrString, inputString);

			if (firstSymbol != '\0') {
				SetConsoleTextAttribute(h, 3);
				cout << "Перший символ, який не входить в заданий рядок: ";
				SetConsoleTextAttribute(h, 6);
				cout << firstSymbol << endl;
				SetConsoleTextAttribute(h, 7);
			}
			else {
				SetConsoleTextAttribute(h, 2);
				cout << "Усi символи в рядку входить в заданий рядок." << endl;
				SetConsoleTextAttribute(h, 7);
			}
			break;

		case 2:
			cout << "Press anykay" << endl << endl;
			break;

		default:
			cout << "Некоректний вибiр. Спробуйте ще раз." << endl;
			break;
		}
		system("pause");
		system("cls");



	} while (menuItem != 2);
}

int main() {
	startMenu();
}