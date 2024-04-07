#include "Header.h"


void switchMenuTask() {
	int menuitem;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);




	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. Завдвдання 1. Рахування суми" << endl;
		cout << "2. Сортування структури" << endl;
		cout << "3. Друк структури" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "4. Вихiд" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "Обери один iз запропонованих варiантiв: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem) {
		case 1:
			searchSumBetweenNegativeNum();
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

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