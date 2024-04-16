#include "Header.h"



void switchMenuTask() {
	
	

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);


	int menuitem;
	Space spaces[N];
	char spectralClass;
	float mass, part;
	long num;

	Figure kr(10);
	Figure tr(20, 10);

	Complex num1(5, 4);
	Complex num2(2, 3);
	Complex sum = num1.add(num2);

	Master owner("John", 1);
	int choose;

	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. Завдання 1. Iнформативна таблиця" << endl;
		cout << "2. Завдання 2. Розрахунок площi" << endl;
		cout << "3. Завдання 3. Комплекснi числа" << endl;
		cout << "4. Завдання 4. Список собак" << endl;

		SetConsoleTextAttribute(h, 4);
		cout << "7. Вихiд" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "Обери один iз запропонованих варiантiв: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem) {
		case 1:
			
			for (int i = 0; i < N; i++) {
				cout << "Введiть спектральний клас: ";
				cin >> spectralClass;
				cout << "Введiть масу: ";
				cin >> mass;
				cout << "Введiть частку: ";
				cin >> part;
				cout << "Введiть кiлькiсть: ";
				cin >> num;

				spaces[i].setSpectralClass(spectralClass);
				spaces[i].setMass(mass);
				spaces[i].setPart(part);
				spaces[i].setNum(num);
			}

			spaces[0].showUp();

			for (int i = 0; i < N; i++) {
				spaces[i].show();
			}

			spaces[0].showDown();
			break;
		case 2:

			cout << "Площа кола: " << kr.circleArea() << endl;
			cout << "Площа трикутника: " << tr.triangleArea() << endl;

			break;
		case 3:
			

			cout << "Перше комплексне число: ";
			num1.print();
			cout << "Друге комплексне число: ";
			num2.print();

			num1.add(6, 6);
			cout << "Після додавання: ";
			num1.print();

			cout << "Сума двох комплексних чисел: ";
			sum.print();

			break;
		case 4:

			int choice;
			do {
				cout << "Меню власника собаки:" << endl;

				SetConsoleTextAttribute(h, 3);
				cout << "1. Додати собаку" << endl;
				cout << "2. Видалити собаку" << endl;
				cout << "3. Переглянути iнформацiю про всiх собак" << endl;
				SetConsoleTextAttribute(h, 4);
				cout << "4. Вийти" << endl;
				SetConsoleTextAttribute(h, 6);
				cout << "Виберiть опцiю: ";
				SetConsoleTextAttribute(h, 7);
				cin >> choice;

				switch (choice) {
				case 1:
					cout << "Додавання нової собаки в список" << endl;
					owner.addToOwner(owner); 
					break;
				case 2:
					cout << "Видалення собаки з списку" << endl;
					owner.removeDogFromOwner(owner); 
					break;
				case 3:
					cout << "Перегляд iнформацiї про всiх собак у списку" << endl;
					owner.displayDogs(); 
					break;
				case 4:
					cout << "Вихiд з програми." << endl;
					break;
				default:
					cout << "Некоректний вибір. Будь ласка, спробуйте знову." << endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice != 4);

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

