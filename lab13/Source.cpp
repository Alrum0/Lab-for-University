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
        cout << "|" << setw(distance) << getSpectralClass() << "|" << setw(33) << getMass() << "|" << setw(13) << getPart() << "|" << setw(13) << getNum() << "|" << endl;
        cout << "-----------------------------------------------------------------------------------" << endl;
}
void Space::showDown() {
    cout << "|" << "                Примiтка: не показанi данi для класiв: B, A, G, K                " << "|"; cout << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}


double Figure::circleArea(){ return 3.14 * radius * radius; }
double Figure::triangleArea(){ return 0.5 * base * height; }

void Complex::add(int r, int m) { material += m; imaginary += m; }
void Complex::print(){ cout << material << " + " << imaginary << "i" << endl; }

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
void Master::displayDogs(){
    cout << "Iм'я господаря собаки: " << name << " (ID: " << ID << " )" << endl;
    for (int i = 0; i < dogCount; i++) {
        cout << "Iм'я собаки: " << dogs[i].getName() << ", Вага: " << dogs[i].getWeight() << ", Вiк: " << dogs[i].getAge();
    }
}
void Master::addToOwner(Master& owner) {
    string name;
    double weight;
    int age;

    std::cout << "Введіть ім'я собаки: ";
    std::cin >> name;
    std::cout << "Введіть вагу собаки: ";
    std::cin >> weight;
    std::cout << "Введіть вік собаки: ";
    std::cin >> age;

    Dog newDog(name, weight, age);
    owner.addDog(newDog);
}
void Master::removeDogFromOwner(Master& owner){
    int index;
    cout << "Введіть індекс для виділення: ";
    cin >> index;
    owner.removeDog(index);
}

void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}
