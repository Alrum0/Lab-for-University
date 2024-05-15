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
void Space::show(){
	cout << "|" << setw(DISTANCE) << getSpectralClass() << "|" << setw(33) << getMass() << "|" << setw(13) << getPart() << "|" << setw(13) << getNum() << "|" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}
void Space::showDown() {
	cout << "|" << "                Примiтка: не показанi данi для класiв: B, A, G, K                " << "|"; cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
}

//void Space::saveObjectToFile(const string& filename) {
//	ofstream file(filename, ios::app);
//	try
//	{
//		if (!file.is_open()) throw 10;
//		file << spectralClass << " " << mass << " " << part << " " << num << endl;
//		file.close();
//	}
//	catch (int){
//		cout << "WARNING, THIS FILE IS NOT FIND!" << endl;
//	}
//}
void Space::saveArrayToFile(Space spaces[], int size, const string& filename) {
	ofstream file(filename);
	try
	{
		if (!file.is_open()) throw runtime_error("WARNING, THIS FILE IS NOT FOUND");
		for (int i = 0; i < size; i++) {
			file << spaces[i].spectralClass << " " << spaces[i].mass << " " << spaces[i].part << " " << spaces[i].num << endl;
		}
		file.close();
	}
	catch (const exception& a){
		cout << a.what();
	}
}
//vector<Space> Space::readObjectsFromFile(const string& filename) {
//	vector<Space> obj;
//	ifstream file(filename);
//	try {
//		if (!file.is_open()) throw runtime_error("WARNING, THIS FILE IS NOT FOUND");
//		char spectralClass;
//		float mass, part;
//		long num;
//		while (file >> spectralClass >> mass >> part >> num) {
//			obj.push_back(Space(spectralClass, mass, part, num));
//		}
//		file.close();
//		return obj;
//	}
//	catch (const exception& b){
//		 cout << b.what();
//	}
//}
void Space::removeInfo(const string& filename) {
	ofstream clearFile(filename, ios::trunc);
}

void Space::saveObjectToFile(const string& filename) {
	/*ofstream file(filename, ios::binary);
	if (!file.is_open()) {
		cout << "Помилка!" << endl;
		return;
	}
	file.write(reinterpret_cast<const char*>(this), sizeof(Space));
	file.close();*/

#if CHOOSE_TYPE == 1
	ofstream file(filename, ios::app);
#else
	ofstream file(filename, ios::binary | ios::app);
#endif
	if (!file.is_open()) {
		cout << "Помилка відкриття файлу!" << endl;
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
	/*vector<Space> objects;
	ifstream file(filename, ios::binary);
	if (!file.is_open()) {
		cout << "Error opening file!" << endl;
		return objects;
	}
	Space space;
	while (file.read(reinterpret_cast<char*>(&space), sizeof(Space))) {
		objects.push_back(space);
	}
	file.close();
	return objects;*/

	vector<Space> objects;
#if CHOOSE_TYPE == 1
	ifstream file(filename);
#else
	ifstream file(filename, ios::binary);
#endif
	if (!file.is_open()) {
		cout << "Помилка відкриття файлу!" << endl;
		return objects;
	}
#if CHOOSE_TYPE == 1
	char spectralClass;
	float mass, part;
	long num;
	while (file >> spectralClass >> mass >> part >> num) {
		objects.push_back(Space{ spectralClass, mass, part, num });
	}
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
		cout << "Помилка відкриття файлу!" << endl;
		return;
	}
#if CHOOSE_TYPE == 1
	file << space.getSpectralClass() << " " << space.getMass() << " " << space.getPart() << " " << space.getNum() << endl;
#else
	file.write((const char*)&space, sizeof(Space));
#endif
	file.close();
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
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char spectralClass;
	float mass, part;
	long num;
	vector<Space> objects;
	vector<string> lines;
	string line;
	int index;
	int ch;
	bool tableCreatede = false;


	do {
		cout << "\nMENU:" << endl;
		cout << "1. Ввести данi для об'єкта" << endl;
		cout << "2. Відобразити данi для об'єкта" << endl;
		cout << "3. Зберегти всi об'єкти  у файл" << endl;
		cout << "4. Зчитати всi об'єкти з файлу" << endl;
		cout << "5. Зберегти один об'єкт у файл" << endl;
		cout << "6. Вiдобразити один об'єкт з файлу" << endl;
		cout << "7. Видалення вмiсту файлу" << endl;
		cout << "8. Вихiд" << endl;
		cout << "Виберiть пункт меню: ";
		cin >> ch;

		switch (ch) {
		case 1:
			if (!tableCreatede) {
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

					spaces[i].saveObjectToFile("text.txt");
				}
				tableCreatede = true;
			}
			else {
				cout << "Таблиця вже створена!" << endl;
			}
			break;
		case 2:
			for (int i = 0; i < N; i++) {
				cout << "Данi для об'єкта простору " << i + 1 << ":" << endl;
				spaces[i].show();
			}
			break;
		case 3:
			Space::saveArrayToFile(spaces, N, "text.txt");
			cout << "Об'єкти простору збереженi у файл 'text.txt'." << endl;
			break;

		case 4:
			objects = Space::readObjectsFromFile("text.txt");
			cout << "Данi зчитані з файлу:" << endl;
			for (const auto& obj : objects) {
				Space temp = obj;
				temp.show();
			}
			break;
		case 5:
			cout << "Введіть індекс об'єкта простору для збереження (0-" << N - 1 << "): ";
			cin >> index;
			if (index >= 0 && index < N) {
				ofstream file("text.txt"); 
				if (file.is_open()) {
					
					file << spaces[index].getSpectralClass() << " "
						<< spaces[index].getMass() << " "
						<< spaces[index].getPart() << " "
						<< spaces[index].getNum();
					file.close();
					cout << "Об'єкт простору з індексом " << index << " збережено у файл 'text.txt'." << endl;
				}
				else {
					cout << "Помилка відкриття файлу 'text.txt'." << endl;
				}
			}
			else {
				cout << "Неправильний індекс!" << endl;
			}

			break;

			//	spaces[index].saveObjectToFile("text.txt");
			//	cout << "Об'єкт простору з індексом " << index << " збережено у файл 'text.txt'." << endl;

			//	fstream file("text.txt", ios::out);
			//	if (file) {
			//		file.seekp(index * sizeof(Space)); // Переміщаємо вказівник до потрібного об'єкта
			//		for (int i = index + 1; i < N; ++i) {
			//			Space emptySpace; // Створюємо пустий об'єкт Space
			//			file.write(reinterpret_cast<char*>(&emptySpace), sizeof(Space)); // Записуємо пустий об'єкт у файл
			//		}
			//		file.close();
			//}
			//else {
			//	cout << "Неправильний індекс!" << endl;
			//}
		case 6:
			cout << "Введiть iндекс об'єкта простору для відображення (0-" << N - 1 << "): ";
			cin >> index;
			if (index >= 0 && index < N) {
				cout << "Данi для об'єкта простору " << index + 1 << ":" << endl;
				spaces[index].show();
			}
			else {
				cout << "Неправильний індекс!" << endl;
			}
			break;
		case 7:
			spaces[0].removeInfo("text.txt");
			break;
		case 8:
			exit(1);
			break;
		default:
			cout << "Incorrect choice" <<endl;
			break;
		}
		system("pause");
		system("cls");
	} while (true);

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

		fout.open("text3.txt", ios::binary | ios::in);
		if (!fout.is_open()) throw 10;
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
