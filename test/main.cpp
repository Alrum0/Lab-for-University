#include "Header.h"


int main()
{
	setlocale(LC_ALL, "ukr");
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	Space originalSpaces[N];
	Space spaces[N];
	Space space;
	Space temp;
	int choice;
	int index;
	int index1, index2;

	do {
		/*gotoxy(65, 0);*/
		cout << "Menu";
	/*	gotoxy(0, 0);*/


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. �������� ��������" << endl;
		cout << "2. ������ �����" << endl;
		cout << "3. �������� �����" << endl;
		cout << "4. ³���������� ������ �������" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "7. ���i�" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "����� ���� i� �������������� ���i���i�: ";
		SetConsoleTextAttribute(h, 7);

		cin >> choice;

		switch (choice) {
		case 1:
			space.activeTask();
			break;
		case 2:
			/*cout << "������ ������ �����, ���� ������ ������: ";
			cin >> index;
			if (index >= 0 && index <= N) {
				if (index == 0 || index == 3) {
					temp = spaces[index];
				}
				cout << "������ ��� ��� ��� �����" << index << ":" << endl;
				cin >> spaces[index];

				if (index == 0 || index == 3) {
					spaces[index] = temp;
				}
				cout << "����� ������ ������!" << endl;
			}
			else {
				cout << "������������ ������ �����!" << endl;
			}*/
			cout << "������ ������ �����, ���� ������ ������: ";
			cin >> index;
			if (index >= 0 && index < N) {
				if (index == 0 || index == 3) {
					originalSpaces[index] = spaces[index];
				}
				cout << "������ ��� ��� ��� �����" << index << ":" << endl;
				cin >> spaces[index];
				cout << "����� ������ ������!" << endl;
			}
			else {
				cout << "������������ ������ �����!" << endl;
			}
			break;
		case 3:
			cout << "������ ������ ������� �����: ";
			cin >> index1;
			cout << "������ ������ ��� ������� �����: ";
			cin >> index2;

			

			if (index1 >= 0 && index1 <= N && index2 >= 0 && index2 <= N) {
				if (spaces[index1] == spaces[index2]) {
					spaces[index1].show();
					spaces[index2].show();
					cout << "����� " << index1 << " � " << index2 << " ����������!" << endl;
				}
				else {
					cout << "����� " << index1 << " � " << index2 << " �� ����������!" << endl;
				}
			}
			else {
				cout << "������������ ������ �����!" << endl;
			}

			break;
		case 4:
			cout << "�������� �������:" << endl;
			for (int i = 0; i < N; i++) {
				if (originalSpaces[i] != spaces[i]) {
					cout << "����� " << i << ": " << spaces[i] << endl;
				}
				else {
					cout << "����� " << i << ": " << originalSpaces[i] << endl;
				}
			}
			break;
		case 7:
			cout << "�� ���������!" << endl;
			break;
		default:
			cout << "������������ ���� �����. ���� �����, ��������� �� ���." << endl;
			break;

		}
		system("pause");
		system("cls");
	} while (choice != 7);
}

