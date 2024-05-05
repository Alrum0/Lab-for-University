#include "Header.h"



int main()
{
	setlocale(LC_ALL, "ukr");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	Space space;
	Space temp;
	int choice;
	int index;
	int index1, index2;
	bool tableGenerated = false;

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
			if (!tableGenerated) {
				space.activeTask();
				tableGenerated = true;
			}
			else {
				cout << "Таблиця вже згенерована! Ви можете змiнити її або порiвняти рядки." << endl;
			}
			break;
		case 2:
			if (!tableGenerated) {
				cout << "Спочатку потрiбно згенерувати таблицю!" << endl;
			}
			else {
				cout << "Введiть iндекс рядка, який бажаєте змiнити: ";
				cin >> index;
				if (index >= 0 && index < N) {
					cout << "Введiть новi данi для рядка" << index << ":" << endl;
					cin >> Space::originalSpaces[index];
					cout << "Рядок успiшно змiнено!" << endl;
				}
				else {
					cout << "Неправильний iндекс рядка!" << endl;
				}
			}
			break;
		case 3:
			if (!tableGenerated) {
				cout << "Спочатку потрiбно згенерувати таблицю!" << endl;
			}
			else {
				cout << "Введiть iндекс першого рядка: ";
				cin >> index1;
				cout << "Введiть iндекс для другого рядка: ";
				cin >> index2;
				if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
					if (Space::originalSpaces[index1] == Space::originalSpaces[index2]) {
						Space::originalSpaces[index1].show();
						Space::originalSpaces[index2].show();
						cout << "Рядки " << index1 << " i " << index2 << " спiвпадають!" << endl;
					}
					else {
						cout << "Рядки " << index1 << " i " << index2 << " не спiвпадають!" << endl;
					}
				}
				else {
					cout << "Неправильний iндекс рядкiв!" << endl;
				}
			}
			break;
		case 4:
			if (!tableGenerated) {
				cout << "Спочатку потрiбно згенерувати таблицю!" << endl;
			}
			else {
				cout << "Оновлена таблиця:" << endl;
				for (int i = 0; i < N; i++) {
					 Space::originalSpaces[i].show();
				}
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