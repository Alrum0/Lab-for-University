#include "Header.h"

void switchMenuTask() {
	Menu menu;
	Task1 tsk;
	Task2 tsk2(7, 4, 8); // 1 - radius, 2 - height, 3 - base
	Task3 tsk3;
	Master owner("John", 1);

	int menuitem;

	do {
		menu.menuShowGeneral();
		cin >> menuitem;

		switch (menuitem) {
		case 1:
			tsk.activeTask();
			break;
		case 2:
			tsk2.activeTask2();
			break;
		case 3:
			tsk3.activeTask3();
			break;
		case 4:

			system("cls");
			int editIndex;
			int choice;
			do {
				menu.menuForTask4();
				cin >> choice;

				switch (choice) {
				case 1:
					cout << "��������� ���� ������." << endl;
					owner.addToOwner(owner);
					break;
				case 2:
					cout << "��������� ������." << endl;
					owner.removeDogFromOwner(owner);
					break;
				case 3:
					cout << "�������� i�������i� ��� ��i� �����" << endl;
					owner.displayDogs();
					break;
				case 4:
					cout << "����i�� i����� ������, ��� ������ ����������: ";
					cin >> editIndex;
					owner.editDog(editIndex);
					break;
				case 5:
					cout << "���i� � ��������." << endl;
					break;
				default:
					cout << "����������� ����. ���� �����, ��������� �����." << endl;
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

