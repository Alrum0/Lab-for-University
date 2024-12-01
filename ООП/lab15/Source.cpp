#include "Header.h"

void SOBAKA::show() { cout << "����: " << weight << " ��, �i�: " << age <<endl; }
void SOBAKA::K() { cout << "�� ����������� ����� SOBAKA" << endl; }
void SOBAKA::D() { cout << "�� ���������� ����� SOBAKA" << endl; }
void SPANIEL::K() { cout << "�� ����������� ����� SPANIEL" << endl; }
void SPANIEL::D() { cout << "�� ���������� ����� SPANIEL" << endl; }
void DOG::K() { cout << "�� ����������� ����� DOG" << endl; }
void DOG::D() { cout << "�� ���������� ����� DOG" << endl; }
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

void BOOK::printInfo() const {
	cout << "�����: " << title << endl;
	cout << "�����: " << author << endl;
	cout << "����i���: " << pages << endl;
	cout << "�������i���: " << (available ? "���" : "�i") << endl;
}

void LIBRARY::printLibraryBooks(const vector<BOOK>& books) const {
	cout << "�������i ����� � �i��i����i: " << endl;
	for (const auto& book : books) {
		book.printInfo();
		cout << "----------------------------------------" << endl;
	}
}
void LIBRARY::borrowBook(vector<BOOK>& books) {
	printLibraryBooks(books);
	cout << "����i�� ����� �����, ��� ������ �������: ";
	string searchTitle;
	cin.ignore();
	getline(cin, searchTitle);

	bool found = false;
	for (auto& book : books) {
		if (book.getTitle() == searchTitle) {
			found = true;
			if (book.isAvailable()) {
				book.borrowBook();
				cout << "����� ���i��� ��������!" << endl;
			}
			else {
				cout << "�������, ����� ����������" << endl;
			}
			break;
		}
	}

	if (!found) {
		cout << "����� �� ��������" << endl;
	}
}
void LIBRARY::returnBook(vector<BOOK>& books) {
	printLibraryBooks(books);
	cout << "����i�� ����� �����, ��� ������ ���������: ";
	string searchTitle;
	cin.ignore();
	getline(cin, searchTitle);

	bool found = false;
	for (auto& book : books) {
		if (book.getTitle() == searchTitle) {
			found = true;
			book.returnBook();
			cout << "����� ���i��� ���������!" << endl;
			break;
		}
	}

	if (!found) {
		cout << "����� �� ��������" << endl;
	}
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
void VUZ::generateRandomData() {
	/*srand(time(NULL));
	int count = rand() % (MAX_COUNT - MIN_COUNT + 1) + MIN_COUNT;
	string randNames[] = { "����","�����","����" ,"�����" ,"�����" ,"���������" ,"�������" ,"������" ,"������" ,"�������" ,"���" ,"³����" };
	string randLastNames[] = { "��������","��������", "��������", "�����", "�������������", "�������", "����������", "�����볿���", "�������������", "��������" };
	string disciplines[MAX_DISCIPLINES] = { "����������","Գ����", "�����������", "ճ��", "�������","������","���������","����" };
	for (int i = 0; i < count; i++) {
		string name = randNames[rand() % MAX_NAMES] + " " + randLastNames[rand() % MAX_LAST_NAMES];
		int age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
		int type = rand() % TYPE;
		if (type == 0) {
			string discipline = "�������: " + disciplines[rand() % MAX_DISCIPLINES];
			int degree = rand() % DEGREE;
			addPersona(new Prepod(name, age, discipline, degree));
		}
		else if (type == 1) {
			addPersona(new Student(name, age));
		}
		else {
			string discipline = disciplines[rand() % MAX_DISCIPLINES];
			int degree = rand() % DEGREE;
			string position = "������ " + to_string(i);
			addPersona(new Zav_kaf(name, age, discipline, degree, position));
		}
	}*/
	int count = rand() % (MAX_COUNT - MIN_COUNT + 1) + MIN_COUNT;
	vector<string> availableNames = { "I���", "�����", "���i�", "�����", "���������", "��i�����", "����i�", "��i�", "�i���i�", "�������i�" };
	vector<string> availableLastNames = { "��������", "I�������", "�����i����", "��i����", "�������������", "I���i���", "����������", "������i����", "�������������", "��������" };
	string disciplines[MAX_DISCIPLINES] = { "����������", "�i����", "I����������", "�i�i�", "�i����i�", "I����i�", "�������i�", "������i��", "����", "������" };
	for (int i = 0; i < count; ++i) {
		if (availableNames.empty() || availableLastNames.empty()) {
			break; 
		}
		string name = availableNames[rand() % availableNames.size()];
		availableNames.erase(remove(availableNames.begin(), availableNames.end(), name), availableNames.end()); 
		string lastName = availableLastNames[rand() % availableLastNames.size()];
		availableLastNames.erase(remove(availableLastNames.begin(), availableLastNames.end(), lastName), availableLastNames.end()); 
		int age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE; 
		int type = rand() % TYPE; 
		if (type == 0) {
			string discipline = disciplines[rand() % MAX_DISCIPLINES];
			int degree = rand() % DEGREE + 1; 
			addPersona(new Prepod(name + " " + lastName, age, discipline, degree));
		}
		else if (type == 1) {
			addPersona(new Student(name + " " + lastName, age));
		}
		else {
			string discipline = disciplines[rand() % MAX_DISCIPLINES];
			int degree = rand() % DEGREE + 1; 
			string position = "������: " + to_string(i);
			addPersona(new Zav_kaf(name + " " + lastName, age, discipline, degree, position));
		}
	}
}

//////////////////////////////////////
void Starter::main() {
	int add;
	B b;
	D1 d1;
	D2 d2;
	D3 d3;
	D4 d4;
	D5 d5;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	do {
		cout << "���� ��� ������ �����: " << endl;
		SetConsoleTextAttribute(h, 3);
		cout << "1. B" << endl;
		cout << "2. D1" << endl;
		cout << "3. D2" << endl;
		cout << "4. D3" << endl;
		cout << "5. D4" << endl;
		cout << "6. D5" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "7. ���i�" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "����� ���� i� �������������� ���i���i�: ";
		SetConsoleTextAttribute(h, 7);
		cin >> add;

		switch (add)
		{
		case 1:
			cout << "CONTENT OF CLASS B:" << endl;
			b.show();
			break;
		case 2:
			cout << "CONTENT OF CLASS D1:" << endl;
			d1.show();
			break;
		case 3:
			cout << "CONTENT OF CLASS D2:" << endl;
			d2.show();
			break;
		case 4:
			cout << "CONTENT OF CLASS D3:" << endl;
			d3.show();
			break;
		case 5:
			cout << "CONTENT OF CLASS D4:" << endl;
			d4.show();
			break;
		case 6:
			cout << "CONTENT OF CLASS D5:" << endl;
			d5.show();
			break;
		case 7:
			cout << "Bye" <<endl;
			break;
		default: 
			cout << "Incorrect choice";
			break;
		}
		system("pause");
		system("cls");

	} while (add != 7);
}
void Starter::task1() {
	SOBAKA sobaka1(8.5, 5);
	SPANIEL spaniel1(12, 3, "Brown");
	DOG dog1(15, 7, 0.6);

	std::cout << "SOBAKA:\n";
	sobaka1.K();
	sobaka1.D();
	sobaka1.show();
	sobaka1.golos();

	std::cout << "\nSPANIEL:\n";
	spaniel1.K();
	spaniel1.D();
	spaniel1.show();
	spaniel1.golos();

	std::cout << "\nDOG:\n";
	dog1.K();
	dog1.D();
	dog1.show();
	dog1.golos();
}
void Starter::task3() {
	vector<BOOK> books = {
			BOOK("Volodar", "���� ������ ���� ����i�", 200),
			BOOK("1984", "������ ������", 300),
			BOOK("DUNA", "����� �������", 250)
	};

	LIBRARY library;

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice;
	do {
		cout << "����:" << endl;
		SetConsoleTextAttribute(h, 3);
		cout << "1. �����i���� �������i��� ����� �� ������" << endl;
		cout << "2. �������� �����" << endl;
		cout << "3. ��������� �����" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "4. ���i�" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "����� ���� i� �������������� ���i���i�: ";
		SetConsoleTextAttribute(h, 7);
		cin >> choice;

		switch (choice) {
		case 1: {
			library.printLibraryBooks(books);
			break;
		}
		case 2: {
			library.borrowBook(books);
			break;
		}
		case 3: {
			library.returnBook(books);
			break;
		}
		case 4: {
			cout << "���i� ��������." << endl;
			break;
		}
		default: {
			cout << "������������ ���i�. ���� �����, ����i�� ����� �i� 1 �� 4." << endl;
		}
		}

		system("pause");
		system("cls");
	} while (choice != 4);
}
void Starter::task4() {
	VUZ university;

	university.generateRandomData();
	university.printStudents();
	cout << endl;
	university.printStudentsWithDebt();
	cout << endl;
	university.printTeachers();
	cout << endl;
	university.printTeachersUnder50();

	for (auto person : university.Shtat) {
		delete person;
	}
}
////////////////////////////////////////////


void Menu::MenuAct() {
	do {
		cout << "����:" << endl;
		SetConsoleTextAttribute(h, 3);
		cout << "1. ����i�������" << endl;
		cout << "2. ������" << endl;
		cout << "3. �i��i�����" << endl;
		cout << "4. ��i��������" << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "5. Exit" << endl;
		SetConsoleTextAttribute(h, 6);
		cout << "����� ���� i� �������������� ���i���i�: ";
		SetConsoleTextAttribute(h, 7);

		cin >> choose;
		switch (choose){
		case 1:
			Starter::main();
			break;
		case 2:
			Starter::task1();
			break;
		case 3:
			Starter::task3();
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
