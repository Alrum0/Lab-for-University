#include "Header.h"


void switchMenuTask() {
	int menuitem;
	int width;
	int lenght;
	int area;
	int num1, num2, num3;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);




	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. ���������� 1. ��������� ����" << endl;
		cout << "2. �������� 2. ���������� ����i" << endl;
		cout << "3. �������� 3. ��i�� �i����� ����������� i �i�i������ ��������" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "4. ���i�" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "����� ���� i� �������������� ���i���i�: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem) {
		case 1:
#if CHOISE == 1
			searchSumBetweenNegativeNum();
#elif CHOISE == 2
			searchSumBetweenNegativeNum2();
#endif
			break;
		case 2:
			
			cout << "������ ������: ";
			cin >> width;
			cout << "������ ������: ";
			cin >> lenght;

	

			area = searchArea(lenght, width);
			cout << "�����: " << area;

			break;
		case 3:
			cout << "����i�� 3 �����: ";
			cin >> num1 >> num2 >> num3;

			cout << "�� ����� �����: ����� 1 = " << num1 << ", ����� 2 = " << num2 << ", ����� 3 = " << num3 << endl;
			swapMaxMinNumberRef(num1, num2, num3);
			cout << "�i��� ����� �����: ����� 1 = " << num1 << ", ����� 2 = " << num2 << ", ����� 3 = " << num3;
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

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