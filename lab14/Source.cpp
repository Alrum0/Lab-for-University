#include "Header.h"

char Space::getSpectralClass() { return spectralClass; }
float Space::getMass() { return mass; }
float Space::getPart() { return part; }
auto Space::getNum() { return num; }

void Menu::menuForTask4() {
    
    cout << "Меню власника собаки:" << endl;

    SetConsoleTextAttribute(h, 3);
    cout << "1. Додати собаку" << endl;
    cout << "2. Видалити собаку" << endl;
    cout << "3. Переглянути iнформацiю про всiх собак" << endl;
    cout << "4. Редагування даних собаки" << endl;
    SetConsoleTextAttribute(h, 4);
    cout << "5. Вийти" << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "Виберiть опцiю: ";
    SetConsoleTextAttribute(h, 7);
}
void Menu::menuShowGeneral() {

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

    Space space1( 10, 20, 30);
    Space space2( 5, 15, 25);

    Space sum = space1 + space2;
    cout << "Sum: " << sum << endl;
    if (space1 == space2) {
        cout << "Spaces are equal" << endl;
    }
    else {
        cout << "Spaces are not equal" << endl;
    }
    Space space3;
    cin >> space3;
    cout << "You entered: " << space3 << endl;
}
////////////////////////
Space& Space::operator=(const Space & space) {
    this->mass = space.mass;
    this->part = space.part;
    this->num = space.num;
    this->spectralClass = space.spectralClass;

    return *this;
}
bool Space::operator==(const Space& space) const {
    return(mass == space.mass &&
        part == space.part &&
        num == space.num &&
        spectralClass == space.spectralClass);

}
Space Space::operator+(const Space& space) const {
    Space result;
    result.mass = mass + space.mass;
    result.part = part + space.part;
    result.num = num + space.num;

    return result;
}
Space operator+(const Space& space1, const Space& space2) {
    Space result;
    result.mass = space1.mass + space2.mass;
    result.part = space1.part + space2.part;
    result.num = space1.part + space2.part;

    return result;
}
bool operator==(const Space& space1, const Space& space2) {
    return(space1.mass == space2.mass &&
           space1.part == space2.part &&
           space1.num == space2.num);
}
ostream& operator<<(ostream& out, const Space& space) {
    out << "Spectral Class: " << space.spectralClass << ", Mass: " << space.mass << ", Part: " << space.part << ", Num: " << space.num << endl;
    return out;
}
istream& operator>>(istream& in,Space& space) {
    string temp;
    cout << "Enter Spectral Class: ";
    in >> temp;
    temp = space.spectralClass ;
    cout << "Enter Mass: ";
    in >> space.mass;
    cout << "Enter Part: ";
    in >> space.part;
    cout << "Enter Num: ";
    in >> space.num;
    return in;
}
///////////////////////
double Task2::activeTask2() {
    cout << "Площа кола: " << kr.circleArea() << endl;
    cout << "Площа трикутника: " << tr.triangleArea() << endl;
}
void Task3::activeTask3() {
    cout << "Перше комплексне число: ";
    this->num1.print();
    cout << "Друге комплексне число: ";
    this->num2.print();

    cout << "Сума двох комплексних чисел: ";
    this->sum.print();

    this->num1.add(6, 6);
    cout << "Пiсля додавання: ";
    this->num1.print();
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
