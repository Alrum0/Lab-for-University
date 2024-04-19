#include "Header.h"



void switchMenuTask() {
	
	

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);


	int menuitem;
	Space spaces[N];
	char spectralClass;
	float mass, part;
	long num;

	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	Figure kr(7);
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

			srand(time(NULL));
			

			for (int i = 0; i < N; i++) {
#if INPUT_TYPE == 1
				cout << "Введiть спектральний клас: ";
				cin >> spectralClass;
				cout << "Введiть масу: ";
				cin >> mass;
				cout << "Введiть частку: ";
				cin >> part;
				cout << "Введiть кiлькiсть: ";
				cin >> num;

#elif INPUT_TYPE == 2
				spectralClass = letters[rand() % letters.size() + 1];
				mass = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
				part = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
				num = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
#endif				

#if	USE_CONSTRUCTOR == 1
				//using default constructor
				spaces[i].setSpectralClass(spectralClass);
				spaces[i].setMass(mass);
				spaces[i].setPart(part);
				spaces[i].setNum(num);
#elif USE_CONSTRUCTOR == 2
				// using constructor with arguments
				spaces[i] = { spectralClass, mass, part, num };

#elif USE_CONSTRUCTOR == 3
				// using constructor of copy
				Space tempSpace(spectralClass, mass, part, num);
				Space space(&tempSpace);
				spaces[i] = space;
#endif
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

			cout << "Сума двох комплексних чисел: ";
			sum.print();

			num1.add(6, 6);
			cout << "Пiсля додавання: ";
			num1.print();

			

			break;
		case 4:

			system("cls");
			int editIndex;
			int choice;
			do {
				cout << "Меню власника собаки:" << endl;

				SetConsoleTextAttribute(h, 3);
				cout << "1. Додати собаку" << endl;
				cout << "2. Видалити собаку" << endl;
				cout << "3. Переглянути iнформацiю про всiх собак" << endl;
				cout << "4. Редагування даних собаки" << endl;
				SetConsoleTextAttribute(h, 4);
				cout << "5. Вийти" << endl;
				SetConsoleTextAttribute(h, 6);
				cout << "Виберiть опцiю: ";
				SetConsoleTextAttribute(h, 7);
				cin >> choice;

				switch (choice) {
				case 1:
					cout << "Додавання нової собаки." << endl;
					owner.addToOwner(owner);
					break;
				case 2:
					cout << "Видалення собаки." << endl;
					owner.removeDogFromOwner(owner);
					break;
				case 3:
					cout << "Перегляд iнформацiї про всiх собак" << endl;
					owner.displayDogs();
					break;
				case 4:
					cout << "Введiть iндекс собаки, яку бажаєте редагувати: ";
					cin >> editIndex;
					owner.editDog(editIndex);
					break;
				case 5:
					cout << "Вихiд з програми." << endl;
					break;
				default:
					cout << "Некоректний вибір. Будь ласка, спробуйте знову." << endl;
					break;
				}
				system("pause");
				system("cls");
			} while (choice != 5);

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
};

