#include <iostream>
#include <stdio.h>
#include <windows.h>



int main()
{
	setlocale(LC_ALL, "rus");

	HANDLE h; // Link on window of Console 

	char class1[2], class2[2], class3[2];
	float mass_1, mass_2, mass_3;
	float part_1, part_2, part_3;
	int number_1, number_2, number_3;

	h = GetStdHandle(STD_OUTPUT_HANDLE); // Set link on standart consol 
	SetConsoleTextAttribute(h, 14);

	/* �������� ��������� ����� */
	printf("1. ����i��: ������������ ����, ��������� ����(�i������ �����), ������� , �������i��� >");
	SetConsoleTextAttribute(h, 8);
	scanf("%s %f %f %d", &class1, &mass_1, &part_1, &number_1);
	SetConsoleTextAttribute(h, 14);
	printf("2. ����i��: ������������ ����, ��������� ����(�i������ �����), ������� , �������i��� >");
	SetConsoleTextAttribute(h, 8);
	scanf("%s %f %f %d", &class2, &mass_2, &part_2, &number_2);
	SetConsoleTextAttribute(h, 14);
	printf("3. ����i��: ������������ ����, ��������� ����(�i������ �����), ������� , �������i��� >");
	SetConsoleTextAttribute(h, 8);
	scanf("%s %f %f %d", &class3, &mass_3, &part_3, &number_3);
	SetConsoleTextAttribute(h, 14);
	printf("\n");
	/* ��������� ������� */ /* ��������� ��������� */
	SetConsoleTextAttribute(h, 1);
	printf("---------------------------------------------------------------------------------\n");
	SetConsoleTextAttribute(h, 15);
	SetConsoleTextAttribute(h, 4);
	printf("|		��������� �i���i��� �i��� �i���� ������������ ����i� � ��������i		|\n");
	SetConsoleTextAttribute(h, 15);
	SetConsoleTextAttribute(h, 1);
	printf("|-------------------------------------------------------------------------------|\n");
	SetConsoleTextAttribute(h, 15);
	SetConsoleTextAttribute(h, 7);
	printf("|   ������������ ����  | ��������� ����(�i������ �����) | ������� | �������i��� |\n");
	SetConsoleTextAttribute(h, 15);
	SetConsoleTextAttribute(h, 1);
	printf("|----------------------|--------------------------------|---------|-------------|\n");
	SetConsoleTextAttribute(h, 15);
	/* ��������� ����� ��������� ����� */
	SetConsoleTextAttribute(h, 3);
	printf("| %-20s | %-30.f | %2.5f | %11d |\n", class1, mass_1, part_1, number_1);
	printf("| %-20s | %-30.2f | %7.1f | %11d |\n", class2, mass_2, part_2, number_2);
	printf("| %-20s | %-30.1f | %7.1f | %11d |\n", class3, mass_3, part_3, number_3);
	SetConsoleTextAttribute(h, 15);
	/* ��������� ������� */
	SetConsoleTextAttribute(h, 1);
	printf("|-------------------------------------------------------------------------------|\n");
	SetConsoleTextAttribute(h, 15);
	SetConsoleTextAttribute(h, 2);
	printf("|����i���: �� �������i ���i ��� ����i�: B, A, G, K					            |\n");
	SetConsoleTextAttribute(h, 15);
	SetConsoleTextAttribute(h, 1);
	printf("|-------------------------------------------------------------------------------|\n");
	SetConsoleTextAttribute(h, 15);
	return 0;

}
