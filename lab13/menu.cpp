#include "Header.h"


void switchMenuTask() {
	
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	int menuitem;
	Space spaces[N];
	char spectralClass;
	float mass, part;
	long num;

	double radius, triangleHeight, trianglel;

	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. �������� 1. ������������ �������" << endl;
		cout << "2. �������� 2. ���������� ����i" << endl;
		cout << "3. �������� 3. ��i�� �i����� ����������� i �i�i������ ��������" << endl;

		SetConsoleTextAttribute(h, 4);
		cout << "7. ���i�" << endl;
		SetConsoleTextAttribute(h, 7);
		SetConsoleTextAttribute(h, 6);
		cout << "����� ���� i� �������������� ���i���i�: ";
		SetConsoleTextAttribute(h, 7);

		cin >> menuitem;

		switch (menuitem) {
		case 1:
			
			for (int i = 0; i < N; i++) {
				cout << "����i�� ������������ ����: ";
				cin >> spectralClass;
				cout << "����i�� ����: ";
				cin >> mass;
				cout << "����i�� ������: ";
				cin >> part;
				cout << "����i�� �i���i���: ";
				cin >> num;

				spaces[i].setSpectralClass(spectralClass);
				spaces[i].setMass(mass);
				spaces[i].setPart(part);
				spaces[i].setNum(num);
			}

			spaces[0].showUp();

			for (int i = 0; i < N; i++) {
				spaces[i].show();
			}

			spaces[0].showDown();
			break;
		case 2:
			cout << "������ ����� �����: ";
			cin >> radius;

			cout << "������ ������ ����������: ";
			cin >> triangleHeight;

			cout << "������ ������ ����������: ";
			cin >> trianglel;

			Figure kr(radius);
			cout << "����� �����: " << kr.circleArea() << endl;

			Figure tr(triangleHeight, trianglel);
			cout << "����� ����������: " << tr.triangleArea() << endl;


			break;
		case 3:
			
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