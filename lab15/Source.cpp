#include "Header.h"

void SOBAKA::show() { cout << "Вага: " << weight << " кг, Вiк: " << age; }
void SOBAKA::K() { cout << "Це конструктор класу SOBAKA" << endl; }
void SOBAKA::D() { cout << "Це деструктор класу SOBAKA" << endl; }
void SOBAKA::golos(){
	if (weight >= 10) {
		cout << "ГАВ" << endl;
	}
	else {
		cout << "гав" << endl;
	}
}
void SPANIEL::show() {
	SOBAKA::show();
	cout << "Колір: " << color << endl;
}
void SPANIEL::golos() {
	SOBAKA::golos();
}
void DOG::show() {
	SOBAKA::show();
	cout << "Зріст: " << height << endl;
}
void DOG::golos() {
	SOBAKA::golos();
}
