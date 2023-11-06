#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>


using namespace std;





void PeriodicFunction() {
	short  n;
	double x,
		   y;
	short  h;

	/*const int W = 602,
		      H = 602;*/



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
			for (; h > 0; h--) cout <<" ";
			cout <<"*" << endl;
		}
	}
}


void Random() {

	int NumberOfSteps = 0,
		UserNumber;

	/*int RandomNumber(int min, int max)
	{

	
		int RandomNumber
		{
		srand(time(NULL));
		int num = min + rand() % (max - min + 1);
		};*/
	
	int RandomNumber;

	setlocale(LC_ALL, "rus");

	
	while (true) {
		NumberOfSteps++;


		cout << "Напиши менi число: ";
		cin >> UserNumber;

		if (UserNumber < RandomNumber) {
			cout << "нi, моє число бiльше" << endl;
		}
	    if (UserNumber > RandomNumber) {
			cout << "нi, моє число меньше" << endl;
		}
		if (UserNumber == RandomNumber) {
			cout << "Так, ти вгадав " << UserNumber << " саме це число я загадав" << endl;
			cout << "Кiлькiсть крокiв: " << NumberOfSteps <<endl << endl << endl << endl << endl;
			break;
		}
	}
}


//void MultiplicationTable() {
//
//	std::srand(static_cast<unsigned>(std::time(nullptr)));
//
//	int correctAnswers = 0;
//
//	for (int i = 0; i < 10; ++i) {
//		int num1 = (std::rand() % 8) + 2; // Генеруємо перший множник від 2 до 9
//		int num2 = (std::rand() % 8) + 2; // Генеруємо другий множник від 2 до 9
//
//		int correctResult = num1 * num2;
//
//		std::cout << "Питання " << i + 1 << ": " << num1 << " * " << num2 << " = ";
//
//		int userAnswer;
//		std::cin >> userAnswer;
//
//		if (userAnswer == correctResult) {
//			std::cout << "Правильно!\n";
//			correctAnswers++;
//		}
//		else {
//			std::cout << "Неправильно. Правильна відповідь: " << correctResult << "\n";
//		}
//	}
//
//	int score;
//	if (correctAnswers == 10) {
//		score = 5;
//	}
//	else if (correctAnswers == 9) {
//		score = 4;
//	}
//	else if (correctAnswers >= 7) {
//		score = 3;
//	}
//	else {
//		score = 2;
//	}
//
//	std::cout << "Ваша оцінка: " << score << std::endl;
//
//	return 0;
//
//}


void SumOfNumbers() {

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
