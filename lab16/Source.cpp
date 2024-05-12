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
	cout << "|" << "         Приблизна кiлькiсть зiрок рiзних спектральнiв класiв в Галактицi        " << "|"; cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "| Спектральний клас | Приблизна маса (вiдносно Сонця) | Частина (%) | Чисельнiсть |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

}
void Space::show() {
	cout << "|" << setw(DISTANCE) << getSpectralClass() << "|" << setw(33) << getMass() << "|" << setw(13) << getPart() << "|" << setw(13) << getNum() << "|" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}
void Space::showDown() {
	cout << "|" << "                Примiтка: не показанi данi для класiв: B, A, G, K                " << "|"; cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}

float COMP::getReal() const { return real; }
float COMP::getImag() const { return imag; }
void COMP::read(ifstream& inFout) { inFout >> real >> imag; }
void COMP::write(ofstream& outFout) { outFout << real << " " << imag; }
void COMP::add(const COMP& other) {
	real += other.getReal();
	imag += other.getImag();
}
ostream& operator<<(ostream& os, const COMP& c) {
	os << c.real << " + " << c.imag << "i";
	return os;
}



void Starter::task1() {
	Space spaces[N];
	char spectralClass;
	float mass, part;
	long num;

	srand(time(NULL));


	for (int i = 0; i < N; i++) {
#if INPUT_TYPE == 1
		cout << "Введiть спектральний клас: ";
		cin >> spectralClass;
		cout << "Введiть масу: ";
		cin >> mass;
		cout << "Введiть частку: ";
		cin >> part;
		cout << "Введiть кiлькiсть: ";
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

	spaces[0].showUp();

	for (int i = 0; i < N; i++) {
		spaces[i].show();
	}

	spaces[0].showDown();
}
void Starter::task2() {

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

		fout.open("text3.txt", ios::binary | ios::in); throw 10;
		fout.seekg(4 * sizeof(int));
		int fifthNumber;
		fout.read((char*)&fifthNumber, sizeof(int));

		fout.seekg(0, ios::beg);
		cout << "Початковi 10 чисел: " << endl;

		int number;
		while (fout.read((char*)&number, sizeof(int))) {
			cout << number << setw(5);
		}
		cout << endl;

		fout.close();

		fout.open("text3.txt", ios::binary | ios::out | ios::in); throw 10;
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

		fout.open("text3.txt", ios::binary | ios::in); throw 10;
		cout << "Оновленi 10 чисел: " << endl;
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

		cout << "Меню:" << endl;
		cout << "1. Завдання 1. Робота з таблицею" << endl;
		cout << "2. Завдання 2. Робота з числами" << endl;
		cout << "3. Завдання 3. Робота з бiнарним файлом" << endl;
		cout << "4. Вихiд" << endl;

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
