#include "Header.h"

void SOBAKA::show() { cout << "����: " << weight << " ��, �i�: " << age <<endl; }
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
	cout << "��i��: " << height << endl;
}
void DOG::golos() {
	SOBAKA::golos();
}
void Book::show(){ cout << "�����: " << title << ", �����: " << author << ", �������: " << pages << endl; }
void Library::show() {
	cout << "�������i���: " << (available ? "���" : "�i") << ", ���i� � ��������i: " << copiesInStock 
		 << ", ����������� ��ﳿ: " << copiesRegistered << endl;
	Book::show();
}

int Persona::getAge() const { return age; }

void Prepod::print() const {
		cout << "I�'�: " << name << ", �i�: " << age << ", �������i��: " << discipline << ", C���i��: ";
		switch (degree) {
		case 1:
			cout << "KTN";
			break;
		case 2:
			cout << "DTN";
			break;
		default:
			cout << "None";
			break;
		}
		cout << endl;
}
int Prepod::who() const { return 1; }
int Prepod::ask() const { return degree; }


void Student::print() const {
	cout << "I�'�: " << name << ", �i�: " << age << ", ��i���: ";
	for (int i = 0; i < 5; ++i) {
		cout << marks[i] << " ";
	}
	cout << endl;
}
int Student::who() const { return 3; }
int Student::ask() const {
	int count = 0;
	for (int i = 0; i < 5; ++i) {
		if (marks[i] == 2) {
			return 1;
		}
	}
	return 0;
}

void Zav_kaf::print() const {
	cout << "I�'�: " << name << ", �i�: " << age << ", �������i��: " << discipline << ", C���i��: ";
	switch (degree) {
	case 1:
		cout << "KTN";
		break;
	case 2:
		cout << "DTN";
		break;
	default:
		cout << "None";
		break;
	}
	cout << ", �������: " << position << endl;
}
int Zav_kaf::who() const { return 2; }
int Zav_kaf::ask() const { return age; }

void VUZ::printTeachersUnder50() const {
	cout << "��������i �� 50 ���i�: " << endl;
	for (auto person : Shtat) {
		if (person->who() == 1 && person->getAge() < 50) {
			person->print();
		}
	}
	cout << "\n\n\n\n_______________________" << endl;
}
void VUZ::printStudents() const {
	cout << "��������: " << endl;
	for (auto person : Shtat) {
		if (person->who() == 3) {
			person->print();
		}
	}
}
void VUZ::printTeachers() const {
	cout << "��������: " << endl;
	for (auto person : Shtat) {
		if (person->who() == 1) {
			person->print();
		}
	}
}
void VUZ::printStudentsWithDebt() const {
	cout << "�������� � �������: " << endl;
	for (auto person : Shtat) {
		if (person->who() == 3 && person->ask() > 0) {
			person->print();
		}
	}
}

void Menu::MenuAct() {
	do {
		cout << "1. Task 1" << endl;
		cout << "2. Task 2" << endl;
		cout << "3. Task 3" << endl;
		cout << "4. Task 4" << endl;
		cout << "5. Exit" << endl;

		cin >> choose;
		switch (choose){
		case 1:
			Starter::main();
			break;
		case 2:
			Starter::task1();
			break;
		case 3:
			break;
		case 4:
			Starter::task4();
			break;
		default:
			cout << "Incorrect choice" << endl;
		}
		system("pause");
		system("cls");

	} while (choose != 5);

}
