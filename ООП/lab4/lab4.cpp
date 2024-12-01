#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <iomanip>

using namespace std;


void PeriodicFunction() {

	HANDLE d;
	d = GetStdHandle(STD_OUTPUT_HANDLE);


	short  n;
	double x, // ось координати x
		y; // ось координати y
	short  h;

	for (n = 0; n < 5; n++) {
		cout << "|   x   |      y     |" << endl;
		cout << "|-------|------------|" << endl;
		for (x = 0; x < 4; x += 0.25) {
			if (x < 2) {
				y = sqrt(4 - (x - 2) * (x - 2));
			}
			else if (x < 4) {
				y = 4 * x - 4;
			}
			printf("| %5.2lf | %10.7lf |\n", x + n * 4, y);
			h = (y + 1) * 10;
			if (y - 1 - h * 10 > 0.5) h++;
			/* виведення точки графіка */
			SetConsoleTextAttribute(d, 5);
			for (; h > 0; h--) cout << " ";
			cout << "*" << endl;
			SetConsoleTextAttribute(d, 7);
		}
	}
}

void Random() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	int NumberOfSteps = 0,
		UserNumber;


	int RandomNumber = rand() % 11;
	srand(time(NULL));

	setlocale(LC_ALL, "rus");


	while (true) {
		NumberOfSteps++;


		cout << "Напиши менi число: ";
		SetConsoleTextAttribute(h, 5);
		cin >> UserNumber;
		SetConsoleTextAttribute(h, 7);

		if (UserNumber < RandomNumber) {
			SetConsoleTextAttribute(h, 4);
			cout << "нi, моє число бiльше" << endl;
			SetConsoleTextAttribute(h, 7);
		}
		if (UserNumber > RandomNumber) {
			SetConsoleTextAttribute(h, 4);
			cout << "нi, моє число меньше" << endl;
			SetConsoleTextAttribute(h, 7);
		}
		if (UserNumber == RandomNumber) {
			SetConsoleTextAttribute(h, 2);
			cout << "Так, ти вгадав " << " саме це число я загадав ";
			SetConsoleTextAttribute(h, 5);
			cout << UserNumber;
			SetConsoleTextAttribute(h, 2);
			cout << " Кiлькiсть крокiв: " << endl << endl << endl << endl << endl;
			SetConsoleTextAttribute(h, 5);
			cout << NumberOfSteps;
			SetConsoleTextAttribute(h, 7);
			break;
		}
	}
}

void MultiplicationTable() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");

	int correctAnswers = 0;

	for (int i = 0; i < 10; ++i) {
		int num1 = (rand() % 8) + 2; // Генеруємо перший множник від 2 до 9
		int num2 = (rand() % 8) + 2; // Генеруємо другий множник від 2 до 9
		srand(time(NULL));

		int correctResult = num1 * num2;

		cout << "Питання " << i + 1 << ": " << num1 << " * " << num2 << " = ";

		int userAnswer;
		SetConsoleTextAttribute(h, 5);
		cin >> userAnswer;
		SetConsoleTextAttribute(h, 7);

		if (userAnswer == correctResult) {
			SetConsoleTextAttribute(h, 2);
			cout << "Правильно!\n";
			SetConsoleTextAttribute(h, 7);
			correctAnswers++;
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "Неправильно. Правильна вiдповiдь: " << correctResult << "\n";
			SetConsoleTextAttribute(h, 7);
		}
	}

	int score;
	if (correctAnswers == 10) {
		score = 5;
	}
	else if (correctAnswers == 9) {
		score = 4;
	}
	else if (correctAnswers >= 7) {
		score = 3;
	}
	else {
		score = 2;
	}

	cout << "Ваша оцiнка: " << score << endl;


}

void SumOfNumbers() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	setlocale(LC_ALL, "rus");

	int mas[] = { 1 ,5 ,4 ,6 , 7, 9 };
	int N = sizeof(mas) / sizeof(int);

	for (int i = 0; i < N; i++) {
		SetConsoleTextAttribute(h, 6);
		cout << setw(5) << mas[i] << left;
		SetConsoleTextAttribute(h, 7);
	}

	int temp;
	cout << endl;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i; j < N; j++) {
			if (mas[i] < mas[j]) {
				temp = mas[i];
				mas[i] = mas[j];
				mas[j] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		SetConsoleTextAttribute(h, 6);
		cout << setw(5) << mas[i] << left;
		SetConsoleTextAttribute(h, 7);
	}

	cout << endl << "Кiлькiсть чиисел: " << N << endl;



	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += mas[i];
	}
	SetConsoleTextAttribute(h, 1);
	cout << "Сума чисел: " << sum;
	SetConsoleTextAttribute(h, 7);
	cout << endl;
}

void StartMenu() {

	int menuitem;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	do {
		SetConsoleTextAttribute(h, 3);
		cout << "1. --- Task1. Periodic Function" << endl;
		cout << "2. --- Task2. Random" << endl;
		cout << "3. --- Task3. MultiplicationTable" << endl;
		cout << "4. --- Task4. SumOfNumbers" << endl;
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
			PeriodicFunction();
			break;

		case 2:
			Random();
			break;

		case 3:
			MultiplicationTable();
			break;

		case 4:
			SumOfNumbers();
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