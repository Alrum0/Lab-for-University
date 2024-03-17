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

		cout << "����" << endl;
		cout << "1. ������ ������� �����" << endl;
		cout << "2. ����� � ��������" << endl;
		cout << "����i�� ������� �����: ";

		cin >> menuItem;

		switch (menuItem) {
		case 1:
			cout << "����i�� ������� �����: ";
			cin >> referencrString;

			cout << "������ ����� ��� ����i��:";
			cin >> inputString;

			firstSymbol = findFirstSymbol(referencrString, inputString);

			if (firstSymbol != '\0') {
				cout << "������ ������, ���� �� ������� � ������� �����: " << firstSymbol << endl;
			}
			else {
				cout << "��i ������� � ����� ������� � ������� �����." << endl;
			}
			break;

		case 2:
			cout << "�����";
			break;

		default:
			cout << "����������� ���i�. ��������� �� ���." << endl;
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