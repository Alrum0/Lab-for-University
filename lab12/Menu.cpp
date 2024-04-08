#include "Header.h"


void switchMenuTask() {
	int menuitem;
	int width;
	int lenght;
	int area;
	int num1, num2, num3;

	int n, m;
	int** A;
	int* min, * max, S, P;
	int* res;

	int choose;
	int* array;

	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);




	do {
		gotoxy(65, 0);
		cout << "Menu";
		gotoxy(0, 0);


		SetConsoleTextAttribute(h, 3);
		cout << endl << "1. �������� 1. ��������� ����" << endl;
		cout << "2. �������� 2. ���������� ����i" << endl;
		cout << "3. �������� 3. ��i�� �i����� ����������� i �i�i������ ��������" << endl;
		cout << "4. �������� 4. ���������� ���� �� ������� � �����i" << endl;
		cout << "5. �������� 5. ��������� ���� �����������, �� ������� ����������" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "7. ���i�" << endl;
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

	

			area = f(lenght, width);
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

			cout << "������ ����� ������� (n x m):";
			cin >> n >> m;

			A = new int* [n];
			for (int i = 0; i < n; i++) {
				A[i] = new int[m];
				for (int j = 0; j < m; j++) {
					A[i][j] = rand() % 11;
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << setw(5) << A[i][j];
				}
				cout << endl;
			}

			 min = new int[m];
			 max = new int[n];
			

			res = f(A, n, m, min, max, &S, &P);


			cout << "���� �� ������i� �������i: " << res[0] << endl;
			cout << "������� �� ���i��i� �i������i: " << res[1] << endl;
			break;
		case 5:

			srand(time(NULL));

			cout << "����i�� �i���i��� �������i�: ";
			cin >> choose;

			array = new int[choose];

			for (int i = 0; i < choose; i++) {
				array[i] = rand() % 101 - 30;
			}

			for (int i = 0; i < choose; i++) {
				if (array[i] > 0) {
					cout << "\033[1;32m";
				}
				else {
					cout << "\033[0m";
				}
				cout << setw(5) << array[i];
			}
			cout << "\033[0m";

			func_ptr ptr;
			ptr = sumPositiveNum; // or productNegativeNum
			
			cout << "\n���� ���������� �������i�: " << ptr(array, choose);

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