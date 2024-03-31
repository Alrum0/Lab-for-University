#include "Header.h"

int main() {

	int size = 3;
	Space galaxy[3];

	setlocale(LC_ALL, "ukr");
	srand(time(NULL));

	int menuitem;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);




	do {
		gotoxy(65, 0);
		std::cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. ���������� ���������" << endl;
		cout << "2. ���������� ���������" << endl;
		cout << "3. ���� ���������" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "4. ���i�" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "����� ���� i� �������������� ���i���i�: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem) {
		case 1:
			fillStructure(galaxy, size);
			break;
		case 2:
			sortStructure(galaxy, size);
			break;
		case 3:
			printSpaceStructure(galaxy, size);
			break;
		case 4:
			exit(1);
			break;

		default:
			cout << "incorrect choice ";
			break;
		}
		cout << "Press anykay";
		system("pause");
		system("cls");


	} while (menuitem != 4);


	cout << "\n\n\n\n\n\n\n_______________________";
}
