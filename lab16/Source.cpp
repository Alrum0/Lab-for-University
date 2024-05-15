#include "Header.h"

char Space::getSpectralClass() { return spectralClass; }
float Space::getMass() { return mass; }
float Space::getPart() { return part; }
auto Space::getNum() { return num; }
void Space::setSpectralClass(char SpectralClass) { this->spectralClass = SpectralClass; }
void Space::setMass(float mass) { this->mass = mass; }
void Space::setPart(float part) { this->part = part; }
void Space::setNum(long num) { this->num = num; }
void Space::showUp() {
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "|" << "         ��������� �i���i��� �i��� �i���� ����������i� ����i� � ��������i        " << "|"; cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "| ������������ ���� | ��������� ���� (�i������ �����) | ������� (%) | �������i��� |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

}
void Space::show(){
	cout << "|" << setw(DISTANCE) << getSpectralClass() << "|" << setw(33) << getMass() << "|" << setw(13) << getPart() << "|" << setw(13) << getNum() << "|" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}
void Space::showDown() {
	cout << "|" << "                ����i���: �� �������i ���i ��� ����i�: B, A, G, K                " << "|"; cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}

void Space::saveArrayToFile(Space spaces[], int size, const string& filename) {
#if CHOOSE_TYPE == 1
	ofstream file(filename);
#else
	ofstream file(filename, ios::binary);
#endif
	if (!file.is_open()) {
		cout << "������� �������� �����!" << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
#if CHOOSE_TYPE == 1
		file << spaces[i].getSpectralClass() << " " << spaces[i].getMass() << " " << spaces[i].getPart() << " " << spaces[i].getNum() << endl;
#else
		file.write((const char*)&spaces[i], sizeof(Space));
#endif
	}
	file.close();
}

void Space::removeInfo(const string& filename) {
	ofstream clearFile(filename, ios::trunc);
}
void Space::saveObjectToFile(string& filename) {
#if CHOOSE_TYPE == 1
	ofstream file(filename, ios::app);
#else
	ofstream file(filename, ios::binary | ios::app);
#endif
	if (!file.is_open()) {
		cout << "������� �������� �����!" << endl;
		return;
	}
#if CHOOSE_TYPE == 1
	file << spectralClass << " " << mass << " " << part << " " << num << endl;
#else
	file.write((const char*)this, sizeof(Space));
#endif
	file.flush();
	file.close();
}


vector<Space> Space::readObjectsFromFile(const string& filename) {
	
	vector<Space> objects;
#if CHOOSE_TYPE == 1
	ifstream file(filename);
#else
	ifstream file(filename, ios::binary);
#endif
	if (!file.is_open()) {
		cout << "������� �������� �����!" << endl;
		return objects;
	}
#if CHOOSE_TYPE == 1
	char spectralClass;
	float mass, part;
	long num;
	while (file >> spectralClass >> mass >> part >> num) {
		objects.push_back(Space{ spectralClass, mass, part, num });
	
#else
	Space space;
	while (file.read((char*)&space, sizeof(Space))) {
		objects.push_back(space);
	}
#endif
	file.close();
	return objects;
}

static void saveOneObjectToFile( Space& space, const string& filename) {
#if CHOOSE_TYPE == 1
	ofstream file(filename);
#else
	ofstream file(filename, ios::binary);
#endif
	if (!file.is_open()) {
		cout << "������� �������� �����!" << endl;
		return;
	}
#if CHOOSE_TYPE == 1
	file << space.getSpectralClass() << " " << space.getMass() << " " << space.getPart() << " " << space.getNum() << endl;
#else
	file.write((const char*)&space, sizeof(Space));
#endif
	file.close();
}

ostream& operator<<(ostream& os, const COMP& c) {
	os << c.r << " + " << c.m << "i";
	return os;
}

void COMP::write(ofstream& out) const {
	out << r << " + " << m << "i" << endl;
}

void COMP::read(ifstream& in) {
	in >> r >> m;
}

void Starter::task1() {

	Space spaces[N];
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char spectralClass;
	float mass, part;
	long num;
	vector<Space> objects;
	vector<string> lines;
	string line;
	int index;
	int ch;
	bool tableCreated = false;
	bool tableDisplayed = false;
	bool tableSaved = false;

	do {
		cout << "\nMENU:" << endl;
		cout << "1. ������ ����i ��� ������i" << endl;
		cout << "2. ������� ����i ������i" << endl;
		cout << "3. �������� ����� ������i � ����" << endl;
		cout << "4. ������� ��i ����� ������i � �����" << endl;
		cout << "5. �������� ���� ����� ������i � ����" << endl;
		cout << "6. ������� ���� ����� ������i � �����" << endl;
		cout << "7. ��������� ��i��� �����" << endl;
		cout << "8. ���i�" << endl;
		cout << "�����i�� ����� ����: ";
		cin >> ch;

		switch (ch) {
		case 1:
			if (!tableCreated) {
				for (int i = 0; i < N; i++) {
#if INPUT_TYPE == 1
					cout << "����i�� ������������ ����: ";
					cin >> spectralClass;
					cout << "����i�� ����: ";
					cin >> mass;
					cout << "����i�� ������: ";
					cin >> part;
					cout << "����i�� �i���i���: ";
					cin >> num;

#elif INPUT_TYPE == 2
					spectralClass = letters[rand() % letters.size() + 1];
					mass = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
					part = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
					num = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
#endif				

#if	USE_CONSTRUCTOR == 1
					//using default constructor
					spaces[i].setSpectralClass(spectralClass);
					spaces[i].setMass(mass);
					spaces[i].setPart(part);
					spaces[i].setNum(num);
#elif USE_CONSTRUCTOR == 2
					// using constructor with arguments
					spaces[i] = { spectralClass, mass, part, num };

#elif USE_CONSTRUCTOR == 3
					// using constructor of copy
					Space tempSpace(spectralClass, mass, part, num);
					Space space(&tempSpace);
					spaces[i] = space;
#endif

		}
				tableCreated = true;
				cout << "������� ���i��� ��������!";
	}
			else {
				cout << "������� ��� ��������!" << endl;
			}
			break;
		case 2:
			if (!tableCreated) {
				cout << "������� �� ���� ��������!" << endl;
				break;
			}
			spaces[0].showUp();
			for (int i = 0; i < N; i++) {
				spaces[i].show();
			}
			spaces[0].showDown();
			tableDisplayed = true;
			break;
		case 3:
			if (!tableDisplayed) {
				cout << "������� �� ���� ����������!" << endl;
				break;
			}
			Space::saveArrayToFile(spaces, N, "text.txt");
			cout << "����� ������i ��������i � ���� 'text.txt'." << endl;
			tableSaved = true;
			break;

		case 4:
			if (!tableSaved) {
				cout << "������� �� ���� ���������!" << endl;
				break;
			}
			objects = Space::readObjectsFromFile("text.txt");
			cout << "���i ������i � �����:" << endl;
			objects[0].showUp();
			for (const auto& obj : objects) {
				Space temp = obj;
				temp.show();
			}
			objects[0].showDown();
			break;
		case 5:
			cout << "����i�� ����� ������i ��� ���������� (1-" << N << "): ";
			cin >> index;
			index--; 
			if (index >= 0 && index < N) {
				ofstream file("text.txt");
				if (file.is_open()) {

					file << spaces[index].getSpectralClass() << " "
						<< spaces[index].getMass() << " "
						<< spaces[index].getPart() << " "
						<< spaces[index].getNum();
					file.close();
					cout << "����� � �����������: " << index + 1 << " ��������� � ���� 'text.txt'." << endl;
				}
				else {
					cout << "������� �i������� ����� 'text.txt'." << endl;
				}
			}
			else {
				cout << "������������ �����!" << endl;
			}
			tableSaved = true;
			break;
		case 6:
			if (!tableSaved) {
				cout << "������� �� ���� ���������!" << endl;
				break;
			}
			cout << "����i�� ����� ����� ������i ��� �i���������� (1-" << N << "): ";
			cin >> index;
			index--; 
			
			objects = Space::readObjectsFromFile("text.txt");

			if (index >= 0 && index < objects.size()) {
				objects[0].showUp();
				objects[index].show();
				objects[0].showDown();
			}
			else {
				cout << "������������ �����!" << endl;
			}
			break;
		case 7:
			spaces[0].removeInfo("text.txt");
			break;
		case 8:
			exit(1);
			break;
		default:
			cout << "������������ ���i�!" << endl;
			break;
}
		system("pause");
		system("cls");
	} while (true);

}


void Starter::task2() {
	// �������� � ��������� ���� ����� ������� ������ �����.
	ofstream outFile("realNumbers.txt");
	for (int i = 0; i < 10; i++) {
		outFile << static_cast<float>(i) << endl;
	}
	outFile.close();

	// ��������� � ����� ���� �����.
	vector<float> realNumbers;
	ifstream inFile("realNumbers.txt");
	float number;
	while (inFile >> number) {
		realNumbers.push_back(number);
	}
	inFile.close();

	// �������� ����� � ��'���� ����� COMP.
	vector<COMP> compNumbers;
	for (size_t i = 0; i < realNumbers.size(); i += 2) {
		compNumbers.push_back(COMP(realNumbers[i], realNumbers[i + 1]));
	}

	// ������������ �� �� �����
	for (const auto& compNumber : compNumbers) {
		cout << compNumber << endl;
	}

	// �������� � ����� ����.
	ofstream compFile("compNumbers.txt");
	for (const auto& compNumber : compNumbers) {
		compNumber.write(compFile);
	}
	compFile.close();

}
void Starter::task3() {
	fstream fout("text3.txt", ios::binary | ios::out);

	try {
		if (!fout.is_open()) throw 10;

		for (int i = 0; i < 10; i++) {
			int random = rand() % 100;
			fout.write((const char*)&random, sizeof(int));
		}

		fout.close();

		fout.open("text3.txt", ios::binary | ios::in);
		if (!fout.is_open()) throw 10;
		fout.seekg(4 * sizeof(int));
		int fifthNumber;
		fout.read((char*)&fifthNumber, sizeof(int));

		fout.seekg(0, ios::beg);
		cout << "��������i 10 �����: " << endl;

		int number;
		while (fout.read((char*)&number, sizeof(int))) {
			cout << number << setw(5);
		}
		cout << endl;

		fout.close();

		fout.open("text3.txt", ios::binary | ios::out | ios::in);
		if (!fout.is_open()) throw 10;
		if (fifthNumber % 2 == 0) {
			int newNumber = 77;
			fout.seekp(0, ios::beg);
			for (int i = 0; i < 4; i++) {
				fout.write((const char*)&newNumber, sizeof(int));
			}
		}
		else {
			int newNumber = 88;
			fout.seekp(5 * sizeof(int));
			for (int i = 5; i < 10; i++) {
				fout.write((const char*)&newNumber, sizeof(int));
			}
		}
		fout.close();

		fout.open("text3.txt", ios::binary | ios::in);
		if (!fout.is_open()) throw 10;
		cout << "�������i 10 �����: " << endl;
		while (fout.read((char*)&number, sizeof(int))) {
			cout << number << setw(5);
		}
		cout << endl;
	}

	catch (int) { cout << "WARNING, THIS FILE IS NOT FOUND" << endl; }

	fout.close();
}

void Menu::MenuActive() {
	do{

		cout << "����:" << endl;
		cout << "1. �������� 1. ������ � ��������" << endl;
		cout << "2. �������� 2. ������ � �������" << endl;
		cout << "3. �������� 3. ������ � �i������ ������" << endl;
		cout << "4. ���i�" << endl;

		cin >> inputNum;
		switch (inputNum) {
		case 1:
			Starter::task1();
			break;
		case 2:
			Starter::task2();
			break;
		case 3:
			Starter::task3();
			break;
		case 4:
			exit(1);
			break;
		default: cout << "Incorrect choice" << endl;
			break;
		}
		system("pause");
		system("cls");
	} while (true);
}
