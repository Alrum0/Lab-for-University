#include "Header.h"


void switchMenuTask() {
	
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	int menuitem;


	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. Завдання 1. Рахування суми" << endl;
		cout << "2. Завдання 2. Розрахунок площi" << endl;
		cout << "3. Завдання 3. Змiна мiсцями максимальне i мiнiмальне значення" << endl;
		cout << "4. Завдання 4. Обчислення суми та добутку в масивi" << endl;
		cout << "5. Завдання 5. Рахування суми позитивиних, та добуток негативних" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "7. Вихiд" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "Обери один iз запропонованих варiантiв: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem) {
		case 1:

		case 2:


			break;
		case 3:
			
			break;
		case 7:
			exit(1);
			break;

		default:
			cout << "incorrect choice ";
			break;
		}
		cout << "\n\n\n\nPress anykay";
		system("pause");
		system("cls");


	} while (menuitem != 7);
}