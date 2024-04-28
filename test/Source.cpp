#include "Header.h"

char Space::getSpectralClass() { return spectralClass; }
float Space::getMass() { return mass; }
float Space::getPart() { return part; }
auto Space::getNum() { return num; }

void Space::setSpectralClass(char SpectralClass) { this->spectralClass = SpectralClass; }
void Space::setMass(float mass) { this->mass = mass; }
void Space::setPart(float part) { this->part = part; }
void Space::setNum(long num) { this->num = num; }

void Space::activeTask() {

    Space spaces[N];
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
//TODO: fix operator>> for input infotmation
        /*cin >> spaces[i];*/                               //<-----

        spaces[i] = Space(spectralClass, mass, part, num);

#elif INPUT_TYPE == 2
        spectralClass = letters[rand() % letters.size() + 1];
        mass = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
        part = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
        num = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;

        spaces[i] = Space(spectralClass, mass, part, num);          // <-----
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
    cout << endl;

    Space sum;
    for (int i = 0; i < N; i++) {
        sum = sum + spaces[i];                  //<-----
    }
    cout << "Result: " << sum << endl;                  //<-----

    Space space1('A', 10.5, 20.3, 100);
    Space space2('A', 10.5, 20.3, 100);
    if (space1 == space2) {
        cout << "Значення збiгаються" << endl;
    }
    else {
        cout << "Значення не збiгаються" << endl;
    }
}

Space& Space::operator=(const Space& space) {
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
//Space operator+(const Space& space1, const Space& space2) {
//    Space result;
//    result.mass = space1.mass + space2.mass;
//    result.part = space1.part + space2.part;
//    result.num = space1.part + space2.part;
//
//    return result;
//}
//bool operator==(const Space& space1, const Space& space2) {
//    return(space1.mass == space2.mass &&
//        space1.part == space2.part &&
//        space1.num == space2.num);
//}
ostream& operator<<(ostream& out, const Space& space) {
    out << "Spectral Class: " << space.spectralClass << ", Mass: " << space.mass << ", Part: " << space.part << ", Num: " << space.num << endl;
    return out;
}
istream& operator>>(istream& in, Space& space) {
    
    cout << "Enter Spectral Class: ";
    in >> space.spectralClass;
    cout << "Enter Mass: ";
    in >> space.mass;
    cout << "Enter Part: ";
    in >> space.part;
    cout << "Enter Num: ";
    in >> space.num;
    return in;
}

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