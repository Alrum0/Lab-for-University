#include "Header.h"



void switchMenuTask() {

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	Menu menu;
	Task1 tsk;
	Task2 area(7, 4, 8); // 1 - radius, 2 - height, 3 - base

	int menuitem;

	Complex num1(5, 4);
	Complex num2(2, 3);
	Complex sum = num1.add(num2);

	Master owner("John", 1);
	int choose;

	do {
		menu.menuShowGeneral();
		cin >> menuitem;

		switch (menuitem) {
		case 1:
			tsk.activeTask();
			break;
		case 2:
			area.activeTask2();
			break;
		case 3:


			cout << "����� ���������� �����: ";
			num1.print();
			cout << "����� ���������� �����: ";
			num2.print();

			cout << "���� ���� ����������� �����: ";
			sum.print();

			num1.add(6, 6);
			cout << "�i��� ���������: ";
			num1.print();



			break;
		case 4:

			system("cls");
			int editIndex;
			int choice;
			do {
				cout << "���� �������� ������:" << endl;

				SetConsoleTextAttribute(h, 3);
				cout << "1. ������ ������" << endl;
				cout << "2. �������� ������" << endl;
				cout << "3. ����������� i�������i� ��� ��i� �����" << endl;
				cout << "4. ����������� ����� ������" << endl;
				SetConsoleTextAttribute(h, 4);
				cout << "5. �����" << endl;
				SetConsoleTextAttribute(h, 6);
				cout << "�����i�� ���i�: ";
				SetConsoleTextAttribute(h, 7);
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

