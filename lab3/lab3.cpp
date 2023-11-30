#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;


void SquareRoot() {
	int a, // first number
		b, // second number
		c, // third number
		x1,//first roots of the equation
		x2;// second roots of the equation
	double d; // discriminator


	setlocale(LC_ALL, "rus");

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 9);
	cout << "Input number a: ";
	SetConsoleTextAttribute(h, 5);
	cin >> a;
	SetConsoleTextAttribute(h, 9);
	cout << "Input number b: ";
	SetConsoleTextAttribute(h, 5);
	cin >> b;
	SetConsoleTextAttribute(h, 9);
	cout << "Input number c: ";
	SetConsoleTextAttribute(h, 5);
	cin >> c;
	if (a != 0) {
		d = (b * b) - (4 * a * c);
		if (d > 0) {
			x1 = (-b + sqrt(d) / (2 * a));
			x2 = (-b - sqrt(d) / (2 * a));
			SetConsoleTextAttribute(h, 2);
			cout << "Two roots: " << x1 << " " << x2 << endl;
			SetConsoleTextAttribute(h, 7);
		}
		else {
			SetConsoleTextAttribute(h, 4);
			cout << "D<0 There are no roots" << endl;
			SetConsoleTextAttribute(h, 7);
		}
		if (d == 0) {
			x1 = (-b / (2 * a));
			cout << x1 << endl;
		}
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "The equation is not quadratic" << endl;
		SetConsoleTextAttribute(h, 7);
	}

}


void ConditionalOperator() {

	double x, // x coordinate
		y; // y coordinate

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 6);
	cout << "Input coordinate x ->  ";
	SetConsoleTextAttribute(h, 5);
	cin >> x;
	SetConsoleTextAttribute(h, 6);
	cout << "Input coordinate y ->  ";
	SetConsoleTextAttribute(h, 5);
	cin >> y;
	cout << "x= " << x << " " << "y= " << y << endl;
	if (x >= -1 && x <= 0 && y >= 0 && y <= 1 || -x <= 1 && x >= 0 && y >= 0 && y <= 1 || x <= 1 && x >= 0 && y <= 0 && y >= -1) {
		SetConsoleTextAttribute(h, 2);
		cout << "The point falls into the region" << endl;
		SetConsoleTextAttribute(h, 7);
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "The point does not fall into the region" << endl;
		SetConsoleTextAttribute(h, 7);
	}
}





void Mushrooms() {

	setlocale(LC_ALL, "rus");
	int mushrooms;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 6);
	cout << "Введiть кiлькiсть грибiв -> ";
	SetConsoleTextAttribute(h, 5);
	cin >> mushrooms;
	SetConsoleTextAttribute(h, 7);

	char MsEnding[3]; // mushroom Ending for "nothing" "ів" "а"
	int LastTwo = mushrooms % 100; // variable that contains the last 2 digits
	int Last = mushrooms % 10; // variable that contains the last 1 digits

	if (LastTwo > 10 && LastTwo < 20) { //  If from 10 to іnfinity always will be грибів //&& LastTwo < 20
		MsEnding[0] = 'i';
		MsEnding[1] = 'в';
		MsEnding[2] = '\0';
	}
	if (Last == 1) { // If number is 1 always write гриб 
		MsEnding[0] = '\0';
	}
	if (Last > 1 && Last < 5) { // If from 1 to 5 we use ending "a", гриба 
		MsEnding[0] = 'а';
		MsEnding[1] = '\0';
	}
	if (Last == 0 || Last >= 5) { // If number ends 0, 5 ,6 ,7 ,8 ,9
		MsEnding[0] = 'i';
		MsEnding[1] = 'в';
		MsEnding[2] = '\0';
	}

	SetConsoleTextAttribute(h, 6);
	cout << "У мене ";
	SetConsoleTextAttribute(h, 5);
	cout << mushrooms;
	SetConsoleTextAttribute(h, 6);
	cout << " гриб";
	SetConsoleTextAttribute(h, 2);
	cout << MsEnding << endl;
	SetConsoleTextAttribute(h, 7);



}


void StartMenu() {

	int menuitem;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	do {
		SetConsoleTextAttribute(h, 3);
		cout << "1. --- Task1. Square root" << endl;
		cout << "2. --- Task2. Conditional operator (falling into the area)" << endl;
		cout << "3. --- Task3. Mushrooms" << endl;
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
			SquareRoot();
			break;

		case 2:
			ConditionalOperator();
			break;

		case 3:
			Mushrooms();
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
