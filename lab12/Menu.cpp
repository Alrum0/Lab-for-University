#include "Header.h"


void switchMenuTask() {
	int menuitem;
	int width;
	int lenght;
	int area;
	int num1, num2, num3;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);




	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. Завдвдання 1. Рахування суми" << endl;
		cout << "2. Завдання 2. Розрахунок площi" << endl;
		cout << "3. Завдання 3. Змiна мiсцями максимальне i мiнiмальне значення" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "4. Вихiд" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "Обери один iз запропонованих варiантiв: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem) {
		case 1:
#if CHOISE == 1
			searchSumBetweenNegativeNum();
#elif CHOISE == 2
			searchSumBetweenNegativeNum2();
#endif
			break;
		case 2:
			
			cout << "Введіть ширину: ";
			cin >> width;
			cout << "Введіть висоту: ";
			cin >> lenght;

	

			area = searchArea(lenght, width);
			cout << "Площа: " << area;

			break;
		case 3:
			cout << "Введiть 3 числа: ";
			cin >> num1 >> num2 >> num3;

			cout << "До свапу чисел: Число 1 = " << num1 << ", Число 2 = " << num2 << ", Число 3 = " << num3 << endl;
			swapMaxMinNumberRef(num1, num2, num3);
			cout << "Пiсля свапу чисел: Число 1 = " << num1 << ", Число 2 = " << num2 << ", Число 3 = " << num3;
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