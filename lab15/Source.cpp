#include "Header.h"

void SOBAKA::show() { cout << "����: " << weight << " ��, �i�: " << age; }
void SOBAKA::K() { cout << "�� ����������� ����� SOBAKA" << endl; }
void SOBAKA::D() { cout << "�� ���������� ����� SOBAKA" << endl; }
void SOBAKA::golos(){
	if (weight >= 10) {
		cout << "���" << endl;
	}
	else {
		cout << "���" << endl;
	}
}
void SPANIEL::show() {
	SOBAKA::show();
	cout << "����: " << color << endl;
}
void SPANIEL::golos() {
	SOBAKA::golos();
}
void DOG::show() {
	SOBAKA::show();
	cout << "����: " << height << endl;
}
void DOG::golos() {
	SOBAKA::golos();
}
