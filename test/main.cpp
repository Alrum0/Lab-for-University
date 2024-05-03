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
			for (int i = 0; i < N; i++) {
				spaces[i] = originalSpaces[i];
			}
			break;
		case 2:
			cout << "������ ������ �����, ���� ������ ������: ";
			cin >> index;
			if (index >= 0 && index < N) {
				if (index == 0 || index == 3) {
					originalSpaces[index] = space;
				}
				cout << "������ ��� ��� ��� �����" << index << ":" << endl;
				cin >> originalSpaces[index];
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
			if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
				if (originalSpaces[index1] == originalSpaces[index2]) {
					originalSpaces[index1].show();
					originalSpaces[index2].show();
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
				cout << "����� " << i << ": " << originalSpaces[i] << endl;
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

