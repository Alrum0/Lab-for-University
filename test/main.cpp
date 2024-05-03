#include "Header.h"

Space originalSpaces[N];

int main()
{
	setlocale(LC_ALL, "ukr");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	
	Space spaces[N];
	Space space;
	Space temp;
	int choice;
	int index;
	int index1, index2;

	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. Будувати табличку" << endl;
		cout << "2. Змінити рядок" << endl;
		cout << "3. Порівняти рядки" << endl;
		cout << "4. Відображення зміненої таблиці" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "7. Вихiд" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "Обери один iз запропонованих варiантiв: ";
		SetConsoleTextAttribute(h, 7);

		cin >> choice;

		switch (choice) {
		case 1:
			space.activeTask();
			for (int i = 0; i < N; i++) {
				spaces[i] = originalSpaces[i];
			}
			break;
		case 2:
			cout << "Введіть індекс рядка, який бажаєте змінити: ";
			cin >> index;
			if (index >= 0 && index < N) {
				if (index == 0 || index == 3) {
					originalSpaces[index] = space;
				}
				cout << "Введіть нові дані для рядка" << index << ":" << endl;
				cin >> originalSpaces[index];
				cout << "Рядок успішно змінено!" << endl;
			}
			else {
				cout << "Неправильний індекс рядка!" << endl;
			}
			break;
		case 3:
			cout << "Введіть індекс першого рядка: ";
			cin >> index1;
			cout << "Введіть індекс для другого рядка: ";
			cin >> index2;
			if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
				if (originalSpaces[index1] == originalSpaces[index2]) {
					originalSpaces[index1].show();
					originalSpaces[index2].show();
					cout << "Рядки " << index1 << " і " << index2 << " співпадають!" << endl;
				}
				else {
					cout << "Рядки " << index1 << " і " << index2 << " не співпадають!" << endl;
				}
			}
			else {
				cout << "Неправильний індекс рядків!" << endl;
			}
			break;
		case 4:
			cout << "Оновлена таблиця:" << endl;
			for (int i = 0; i < N; i++) {
				cout << "Рядок " << i << ": " << originalSpaces[i] << endl;
			}
			break;
		case 7:
			cout << "До побачення!" << endl;
			break;
		default:
			cout << "Неправильний вибір опції. Будт ласка, спробуйте щн раз." << endl;
			break;

		}
		system("pause");
		system("cls");
	} while (choice != 7);
}

