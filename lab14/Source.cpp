#include "Header.h"

char Space::getSpectralClass() { return spectralClass; }
float Space::getMass() { return mass; }
float Space::getPart() { return part; }
auto Space::getNum() { return num; }

//Space::Space() {
//    spectralClass = 'A';
//    mass = 2.7;
//    this->part = 8.8;
//    num = 0;
//}


void Menu::menuShowGeneral() {

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(65, 0);
    cout << "Menu";
    gotoxy(0, 0);


    SetConsoleTextAttribute(h, 3);
    cout << endl << "1. Завдання 1. Iнформативна таблиця" << endl;
    cout << "2. Завдання 2. Розрахунок площi" << endl;
    cout << "3. Завдання 3. Комплекснi числа" << endl;
    cout << "4. Завдання 4. Список собак" << endl;

    SetConsoleTextAttribute(h, 4);
    cout << "7. Вихiд" << endl;
    SetConsoleTextAttribute(h, 7);
    SetConsoleTextAttribute(h, 6);
    cout << "Обери один iз запропонованих варiантiв: ";
    SetConsoleTextAttribute(h, 7);
}
void Task1::activeTask() {

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
double Task2::activeTask2() {
    cout << "Площа кола: " << kr.circleArea() << endl;
    cout << "Площа трикутника: " << tr.triangleArea() << endl;
}


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

double Figure::circleArea() { return 3.14 * radius * radius; }
double Figure::triangleArea() { return 0.5 * base * height; }

void Complex::add(int r, int m) { material += m; imaginary += m; }
void Complex::print() { cout << material << " + " << imaginary << "i" << endl; }

Complex Complex::add(const Complex& other) {
    int newmaterial = material + other.material;
    int newimaginary = imaginary + other.imaginary;
    return Complex(newmaterial, newimaginary);
}

string Dog::getName() { return name; }
double Dog::getWeight() { return weight; }
int Dog::getAge() { return age; }

void Dog::setName(string name) { this->name = name; }
void Dog::setWeight(double weight) { this->weight = weight; }
void Dog::setAge(int age) { this->age = age; }

int Master::count = 0;
Master::~Master() { delete[] dogs; }


int Master::getID() { return ID; }
void Master::addDog(const Dog& dog) {
    Dog* temp = new Dog[dogCount + 1];
    for (int i = 0; i < dogCount; i++) {
        temp[i] = dogs[i];
    }
    temp[dogCount] = dog;
    delete[] dogs;
    dogs = temp;
    dogCount++;
    count++;
}
void Master::removeDog(int index) {
    if (index >= 0 && index < dogCount) {
        Dog* temp = new Dog[dogCount - 1];
        for (int i = 0, j = 0; i < dogCount; ++i) {
            if (i != index) {
                temp[j] = dogs[i];
                j++;
            }
        }
        delete[] dogs;
        dogs = temp;
        dogCount--;
        count--;
    }
}

void Master::displayDogs() {
    if (dogCount == 0) {
        cout << "У власника немає собак." << endl;
    }
    else {
        cout << "Iм'я господаря собак: " << name << " (ID: " << ID << " )" << endl;
        for (int i = 0; i < dogCount; i++) {
            cout << i << ". " << "Iм'я собаки: " << dogs[i].getName() << ", Вага: " << dogs[i].getWeight() << ", Вiк: " << dogs[i].getAge() << endl;
        }
    }

}
void Master::addToOwner(Master& owner) {
    string name;
    double weight;
    int age;

    cout << "Введiть iм'я собаки: ";
    cin >> name;
    cout << "Введiть вагу собаки: ";
    cin >> weight;
    cout << "Введiть вiк собаки: ";
    cin >> age;

    Dog newDog(name, weight, age);
    owner.addDog(newDog);
}
void Master::removeDogFromOwner(Master& owner) {
    int index;
    cout << "Введiть iндекс для видiлення: ";
    cin >> index;
    owner.removeDog(index);
}
void Master::editDog(int index) {
    if (index >= 0 && index < dogCount) {
        string name;
        double weight;
        int age;

        cout << "Редагуємо iнформацiю про собаку з iндексом " << index << endl;

        cout << "Введiть iм'я собаки: ";
        cin >> name;
        cout << "Введiть вагу собаки: ";
        cin >> weight;
        cout << "Введiть вiк собаки: ";
        cin >> age;

        dogs[index].setName(name);
        dogs[index].setWeight(weight);
        dogs[index].setAge(age);

        cout << "Iнформацiя про собаку була вiдновлена.";
    }
    else {
        cout << "Нвiрний iндекс собаки. Спробуйте ще раз.";
    }
}


void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}
