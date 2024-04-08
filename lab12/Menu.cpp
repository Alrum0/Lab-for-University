#include "Header.h"


void switchMenuTask() {
	int menuitem;
	int width;
	int lenght;
	int area;
	int num1, num2, num3;

	int n, m;
	int** A;
	int* min, * max, S, P;
	int* res;

	int choose;
	int* array;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);




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

	

			area = f(lenght, width);
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

			cout << "Введіть розмір матриці (n x m):";
			cin >> n >> m;

			A = new int* [n];
			for (int i = 0; i < n; i++) {
				A[i] = new int[m];
				for (int j = 0; j < m; j++) {
					A[i][j] = rand() % 11;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << setw(5) << A[i][j];
				}
				cout << endl;
			}

			 min = new int[m];
			 max = new int[n];
			

			res = f(A, n, m, min, max, &S, &P);


			cout << "Сума на головнiй діагоналi: " << res[0] << endl;
			cout << "Добуток на побiчнiй дiагоналi: " << res[1] << endl;
			break;
		case 5:

			srand(time(NULL));

			cout << "Введiть кiлькiсть елементiв: ";
			cin >> choose;

			array = new int[choose];

			for (int i = 0; i < choose; i++) {
				array[i] = rand() % 101 - 30;
			}

			for (int i = 0; i < choose; i++) {
				if (array[i] > 0) {
					cout << "\033[1;32m";
				}
				else {
					cout << "\033[0m";
				}
				cout << setw(5) << array[i];
			}
			cout << "\033[0m";

			func_ptr ptr;
			ptr = sumPositiveNum; // or productNegativeNum
			
			cout << "\nСума позитивних елементiв: " << ptr(array, choose);

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