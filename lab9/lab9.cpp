#include <iostream>
#include <stdlib.h>
#include <stdio.h>
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

void startMenu() {
	setlocale(LC_ALL, "ukr");

	int menuItem;
	char referencrString[N];
	char inputString[N];
	char firstSymbol;

	do {

		cout << "Меню" << endl;
		cout << "1. Ввести заданий рядок" << endl;
		cout << "2. Вийти з програми" << endl;
		cout << "Введiть заданий рядок: ";

		cin >> menuItem;

		switch (menuItem) {
		case 1:
			cout << "Введiть заданий рядок: ";
			cin >> referencrString;

			cout << "Введіть рядок для аналiзу:";
			cin >> inputString;

			firstSymbol = findFirstSymbol(referencrString, inputString);

			if (firstSymbol != '\0') {
				cout << "Перший символ, який не входить в заданий рядок: " << firstSymbol << endl;
			}
			else {
				cout << "Усi символи в рядку входить в заданий рядок." << endl;
			}
			break;

		case 2:
			cout << "Бувай";
			break;

		default:
			cout << "Некоректний вибiр. Спробуйте ще раз." << endl;
			break;
		}
		cout << "Press anykay";
		system("pause");
		system("cls");



	} while (menuItem != 2);
}

int main() {
	startMenu();
}