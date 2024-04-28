#include "Header.h"

char Space::getSpectralClass() { return spectralClass; }
float Space::getMass() { return mass; }
float Space::getPart() { return part; }
auto Space::getNum() { return num; }

void Menu::menuForTask4() {
    
    cout << "���� �������� ������:" << endl;

    SetConsoleTextAttribute(h, 3);
    cout << "1. ������ ������" << endl;
    cout << "2. �������� ������" << endl;
    cout << "3. ����������� i�������i� ��� ��i� �����" << endl;
    cout << "4. ����������� ����� ������" << endl;
    SetConsoleTextAttribute(h, 4);
    cout << "5. �����" << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "�����i�� ���i�: ";
    SetConsoleTextAttribute(h, 7);
}
void Menu::menuShowGeneral() {

    gotoxy(65, 0);
    cout << "Menu";
    gotoxy(0, 0);

    SetConsoleTextAttribute(h, 3);
    cout << endl << "1. �������� 1. I����������� �������" << endl;
    cout << "2. �������� 2. ���������� ����i" << endl;
    cout << "3. �������� 3. ���������i �����" << endl;
    cout << "4. �������� 4. ������ �����" << endl;

    SetConsoleTextAttribute(h, 4);
    cout << "7. ���i�" << endl;
    SetConsoleTextAttribute(h, 7);
    SetConsoleTextAttribute(h, 6);
    cout << "����� ���� i� �������������� ���i���i�: ";
    SetConsoleTextAttribute(h, 7);
}
void Task1::activeTask() {

    srand(time(NULL));


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
    cout << "����� ����: " << kr.circleArea() << endl;
    cout << "����� ����������: " << tr.triangleArea() << endl;
}
void Task3::activeTask3() {
    cout << "����� ���������� �����: ";
    this->num1.print();
    cout << "����� ���������� �����: ";
    this->num2.print();

    cout << "���� ���� ����������� �����: ";
    this->sum.print();

    this->num1.add(6, 6);
    cout << "�i��� ���������: ";
    this->num1.print();
}

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
void Space::show() {
    cout << "|" << setw(DISTANCE) << getSpectralClass() << "|" << setw(33) << getMass() << "|" << setw(13) << getPart() << "|" << setw(13) << getNum() << "|" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}
void Space::showDown() {
    cout << "|" << "                ����i���: �� �������i ���i ��� ����i�: B, A, G, K                " << "|"; cout << endl;
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
        cout << "� �������� ���� �����." << endl;
    }
    else {
        cout << "I�'� ��������� �����: " << name << " (ID: " << ID << " )" << endl;
        for (int i = 0; i < dogCount; i++) {
            cout << i << ". " << "I�'� ������: " << dogs[i].getName() << ", ����: " << dogs[i].getWeight() << ", �i�: " << dogs[i].getAge() << endl;
        }
    }

}
void Master::addToOwner(Master& owner) {
    string name;
    double weight;
    int age;

    cout << "����i�� i�'� ������: ";
    cin >> name;
    cout << "����i�� ���� ������: ";
    cin >> weight;
    cout << "����i�� �i� ������: ";
    cin >> age;

    Dog newDog(name, weight, age);
    owner.addDog(newDog);
}
void Master::removeDogFromOwner(Master& owner) {
    int index;
    cout << "����i�� i����� ��� ���i�����: ";
    cin >> index;
    owner.removeDog(index);
}
void Master::editDog(int index) {
    if (index >= 0 && index < dogCount) {
        string name;
        double weight;
        int age;

        cout << "�������� i�������i� ��� ������ � i������� " << index << endl;

        cout << "����i�� i�'� ������: ";
        cin >> name;
        cout << "����i�� ���� ������: ";
        cin >> weight;
        cout << "����i�� �i� ������: ";
        cin >> age;

        dogs[index].setName(name);
        dogs[index].setWeight(weight);
        dogs[index].setAge(age);

        cout << "I�������i� ��� ������ ���� �i��������.";
    }
    else {
        cout << "��i���� i����� ������. ��������� �� ���.";
    }
}


void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}
