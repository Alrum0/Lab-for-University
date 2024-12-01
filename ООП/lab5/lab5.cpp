#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

#define N 20

void OnDimenrray() { // One-dimensional array

	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	int mas[N];

	for (int i = 0; i < N; i++) {
		mas[i] = rand() % 20 + -5;
	}
	SetConsoleTextAttribute(h, 3);
	cout << "Початковий масив: " << endl;
	SetConsoleTextAttribute(h, 7);
	for (int i = 0; i < N; i++) {
		cout << setw(5) << mas[i] << " ";
	}
	cout << endl;


	for (int i = 0; i < N; i++) {
		if (mas[i] > 0) {
			for (int j = 0; j < N; j++) {
				if (mas[i] == -mas[j]) {
					mas[i] = 0;
					mas[j] = 0;
				}
			}
		}
	}
	SetConsoleTextAttribute(h, 3);
	cout << "Змiнений масив: " << endl;
	SetConsoleTextAttribute(h, 7);
	for (int i = 0; i < N; i++) {
		cout << setw(5) << mas[i] << " ";
	}
	cout << endl;

}

///
void displaySeats(int seats[10]) {
	for (int i = 0; i < 10; i++) {
		cout << seats[i] << " ";
		if (i == 4) {
			cout << " ";
		}
	}
	cout << endl;
}

void TrafficController() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");

	int seats[10] = { 0 };  // Ініціалізуємо всі місця як порожні

	SetConsoleTextAttribute(h, 6);
	cout << "Ласкаво просимо до бронювання мiсць в лiтаку!" << endl;
	SetConsoleTextAttribute(h, 7);

	while (true) {
		SetConsoleTextAttribute(h, 1);
		cout << "Доступнi мiсця:" << endl;
		SetConsoleTextAttribute(h, 7);
		displaySeats(seats);

		SetConsoleTextAttribute(h, 5);
		cout << endl << "Палите? (yes/no): ";
		SetConsoleTextAttribute(h, 7);
		string smoking;
		cin >> smoking;

		if (smoking == "yes") {
			for (int i = 0; i < 5; ++i) {
				if (seats[i] == 0) {
					seats[i] = 1;
					SetConsoleTextAttribute(h, 4);
					cout << "Мiсце " << i + 1 << " заброньоване для палiльникiв." << endl;
					SetConsoleTextAttribute(h, 7);
					break;
				}
			}
		}
		else if (smoking == "no") {
			for (int i = 5; i < 10; ++i) {
				if (seats[i] == 0) {
					seats[i] = 1;
					SetConsoleTextAttribute(h, 2);
					cout << "Мiсце " << i + 1 << " заброньоване для непалiльникiв." << endl;
					SetConsoleTextAttribute(h, 6);
					break;
				}
			}
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "Будь ласка, виберiть 'yes' або 'no'." << endl;
			SetConsoleTextAttribute(h, 7);
		}

		bool allSeatsTaken = true;
		for (int i = 0; i < 10; ++i) {
			if (seats[i] == 0) {
				allSeatsTaken = false;
				break;
			}
		}

		if (allSeatsTaken) {
			SetConsoleTextAttribute(h, 6);
			cout << "Усi мiсця зайнятi. Запропонувати новi мiсця? (yes/no): ";
			SetConsoleTextAttribute(h, 7);
			string response;
			cin >> response;
			if (response == "yes") {
				for (int i = 0; i < 10; ++i) {
					seats[i] = 0;  // Очистити місця для нового літаку
				}
			}
			else {
				SetConsoleTextAttribute(h, 5);
				cout << "Дякую, до побачення!" << endl;
				SetConsoleTextAttribute(h, 7);
				break;
			}
		}
	}
}
///



///

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");

	int arr[10] = { 0, 1, 2, 3, 4, 5 };
	int n = 6; // Розмір початкового масиву

	// Вставка елементів
	int positionInsert, Numinsert;
	SetConsoleTextAttribute(h, 3);
	cout << "Введiть позицiю для вставки: ";
	SetConsoleTextAttribute(h, 7);
	cin >> positionInsert;
	SetConsoleTextAttribute(h, 3);
	cout << "Введiть кiлькiсть елементiв для вставки: ";
	SetConsoleTextAttribute(h, 7);
	cin >> Numinsert;

	if (positionInsert >= 0 && positionInsert <= n && Numinsert > 0 && n + Numinsert <= 10) {
		SetConsoleTextAttribute(h, 3);
		cout << "Введiть " << Numinsert << " елемент(-iв) для вставки: ";
		SetConsoleTextAttribute(h, 7);
		for (int i = n - 1; i >= positionInsert; i--) {
			arr[i + Numinsert] = arr[i];
		}
		for (int i = 0; i < Numinsert; i++) {
			int val;
			cin >> val;
			arr[positionInsert + i] = val;
		}
		n += Numinsert;
		SetConsoleTextAttribute(h, 6);
		cout << "Масив пiсля вставки:" << endl;
		SetConsoleTextAttribute(h, 7);
		printArray(arr, n);
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "Некоректне введення для вставки." << endl;
		SetConsoleTextAttribute(h, 7);
	}

	int positionDelete, numberDelete;
	SetConsoleTextAttribute(h, 3);
	cout << "Введiть позицiю для видалення: ";
	SetConsoleTextAttribute(h, 7);
	cin >> positionDelete;
	SetConsoleTextAttribute(h, 3);
	cout << "Введiть кiлькiсть елементiв для видалення: ";
	SetConsoleTextAttribute(h, 7);
	cin >> numberDelete;

	if (positionDelete >= 0 && positionDelete < n && numberDelete > 0 && positionDelete + numberDelete <= n) {
		for (int i = positionDelete + numberDelete; i < n; i++) {
			arr[i - numberDelete] = arr[i];
		}
		n -= numberDelete;
		SetConsoleTextAttribute(h, 6);
		cout << "Масив пiсля видалення:" << endl;
		SetConsoleTextAttribute(h, 7);
		printArray(arr, n);
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "Некоректне введення для видалення." << endl;
		SetConsoleTextAttribute(h, 7);
	}
}

/// 


void StartMenu() {

	int menuitem;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	do {
		SetConsoleTextAttribute(h, 3);
		cout << "1. --- Task1. One-dimensional array" << endl;
		cout << "2. --- Task2. Air Traffic Controller" << endl;
		cout << "3. --- Task3. Array" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "0.Exit" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "Chhoise task by his number: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem)
		{
		case 1:
			OnDimenrray();
			break;

		case 2:
			TrafficController();
			break;

		case 3:
			Array();
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
