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
			if (!tableGenerated) {
				space.activeTask();
				tableGenerated = true;
			}
			else {
				cout << "������� ��� �����������! �� ������ ��i���� �� ��� ���i����� �����." << endl;
			}
			break;
		case 2:
			if (!tableGenerated) {
				cout << "�������� ����i��� ����������� �������!" << endl;
			}
			else {
				cout << "����i�� i����� �����, ���� ������ ��i����: ";
				cin >> index;
				if (index >= 0 && index < N) {
					cout << "����i�� ���i ���i ��� �����" << index << ":" << endl;
					cin >> Space::originalSpaces[index];
					cout << "����� ���i��� ��i����!" << endl;
				}
				else {
					cout << "������������ i����� �����!" << endl;
				}
			}
			break;
		case 3:
			if (!tableGenerated) {
				cout << "�������� ����i��� ����������� �������!" << endl;
			}
			else {
				cout << "����i�� i����� ������� �����: ";
				cin >> index1;
				cout << "����i�� i����� ��� ������� �����: ";
				cin >> index2;
				if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
					if (Space::originalSpaces[index1] == Space::originalSpaces[index2]) {
						Space::originalSpaces[index1].show();
						Space::originalSpaces[index2].show();
						cout << "����� " << index1 << " i " << index2 << " ��i��������!" << endl;
					}
					else {
						cout << "����� " << index1 << " i " << index2 << " �� ��i��������!" << endl;
					}
				}
				else {
					cout << "������������ i����� ����i�!" << endl;
				}
			}
			break;
		case 4:
			if (!tableGenerated) {
				cout << "�������� ����i��� ����������� �������!" << endl;
			}
			else {
				cout << "�������� �������:" << endl;
				for (int i = 0; i < N; i++) {
					 Space::originalSpaces[i].show();
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