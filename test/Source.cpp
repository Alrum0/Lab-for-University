#include "Header.h"

char Space::getSpectralClass() { return spectralClass; }
float Space::getMass() { return mass; }
float Space::getPart() { return part; }
auto Space::getNum() { return num; }

void Space::setSpectralClass(char SpectralClass) { this->spectralClass = SpectralClass; }
void Space::setMass(float mass) { this->mass = mass; }
void Space::setPart(float part) { this->part = part; }
void Space::setNum(long num) { this->num = num; }

Space Space::originalSpaces[N];

void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}

//void Space::activeTask() {
//
//    Space spaces[N];
//    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    srand(time(NULL));
//
//
//    for (int i = 0; i < N; i++) {
//#if INPUT_TYPE == 1
//        cout << "¬ведiть спектральний клас: ";
//        cin >> spectralClass;
//        cout << "¬ведiть масу: ";
//        cin >> mass;
//        cout << "¬ведiть частку: ";
//        cin >> part;
//        cout << "¬ведiть кiлькiсть: ";
//        cin >> num;
////TODO: fix operator>> for input infotmation
//        /*cin >> spaces[i];*/                               //<-----
//
//        spaces[i] = Space(spectralClass, mass, part, num);
//
//#elif INPUT_TYPE == 2
//        spectralClass = letters[rand() % letters.size() + 1];
//        mass = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
//        part = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
//        num = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
//
//        spaces[i] = Space().operator()(spectralClass, mass, part, num);          // <----- // <-----
//#endif				
//
//#if	USE_CONSTRUCTOR == 1
//        //using default constructor
//        spaces[i].setSpectralClass(spectralClass);
//        spaces[i].setMass(mass);
//        spaces[i].setPart(part);
//        spaces[i].setNum(num);
//#elif USE_CONSTRUCTOR == 2
//        // using constructor with arguments
//        spaces[i] = { spectralClass, mass, part, num };
//
//#elif USE_CONSTRUCTOR == 3
//        // using constructor of copy
//        Space tempSpace(spectralClass, mass, part, num);
//        Space space(&tempSpace);
//        spaces[i] = space;
//#endif
//    }
//
//    spaces[0].showUp();
//
//    for (int i = 0; i < N; i++) {
//        spaces[i].show();
//    }
//
//    spaces[0].showDown();
//    cout << endl;
//
//    Space sum;
//    for (int i = 0; i < N; i++) {
//        sum = sum + spaces[i];                  //<-----
//    }
//    cout << "Result: " << sum << endl;                  //<-----
//
//}

void Space::activeTask() {
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
#if INPUT_TYPE == 1
        cout << "¬ведiть спектральний клас: ";
        cin >> spectralClass;
        cout << "¬ведiть масу: ";
        cin >> mass;
        cout << "¬ведiть частку: ";
        cin >> part;
        cout << "¬ведiть кiлькiсть: ";
        cin >> num;

        originalSpaces[i] = Space(spectralClass, mass, part, num);

#elif INPUT_TYPE == 2
        spectralClass = letters[rand() % letters.size() + 1];
        mass = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
        part = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;
        num = rand() % (HIGH_BOUND - LOW_BOUND + 1) + LOW_BOUND;

        originalSpaces[i] = Space().operator()(spectralClass, mass, part, num);
#endif				

#if	USE_CONSTRUCTOR == 1
        //using default constructor
        originalSpaces[i].setSpectralClass(spectralClass);
        originalSpaces[i].setMass(mass);
        originalSpaces[i].setPart(part);
        originalSpaces[i].setNum(num);
#elif USE_CONSTRUCTOR == 2
        // using constructor with arguments
        originalSpaces[i] = { spectralClass, mass, part, num };

#elif USE_CONSTRUCTOR == 3
        // using constructor of copy
        Space tempSpace(spectralClass, mass, part, num);
        Space space(&tempSpace);
        originalSpaces[i] = space;
#endif
    }

    originalSpaces[0].showUp();

    for (int i = 0; i < N; i++) {
        originalSpaces[i].show();
    }

    originalSpaces[0].showDown();
    cout << endl;

    Space sum;
    for (int i = 0; i < N; i++) {
        sum = sum + originalSpaces[i];
    }
    cout << "Result: " << sum << endl;
}


Space& Space::operator=(const Space& space) {
    //this->mass = space.mass;
    //this->part = space.part;
    //this->num = space.num;
    //this->spectralClass = space.spectralClass;

    //return *this;
    if (this == &space) 
        return *this;

    spectralClass = space.spectralClass;
    mass = space.mass;
    part = space.part;
    num = space.num;

    return *this;
}
bool Space::operator==(const Space& space) const {
    return (spectralClass == space.spectralClass &&
        mass == space.mass &&
        part == space.part &&
        num == space.num);
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
    
    cout << "¬вед≥ть спектральний клас: ";
    in >> space.spectralClass;
    cout << "¬вед≥ть масу: ";
    in >> space.mass;
    cout << "¬вед≥ть частку: ";
    in >> space.part;
    cout << "¬вед≥ть к≥льк≥сть: ";
    in >> space.num;
    return in;
}
Space Space::operator()(char spectralClass, float mass, float part, long num) {
    this->spectralClass = spectralClass;
    this->mass = mass;
    this->part = part;
    this->num = num;

    return *this;
}
char Space::operator[](int num) {
    return spectralClass;
}

void Space::showUp() {
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "|" << "         ѕриблизна кiлькiсть зiрок рiзних спектральнiв класiв в √алактицi        " << "|"; cout << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
    cout << "| —пектральний клас | ѕриблизна маса (вiдносно —онц€) | „астина (%) | „исельнiсть |" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;

}
void Space::show() {
    cout << "|" << setw(DISTANCE) << getSpectralClass() << "|" << setw(33) << getMass() << "|" << setw(13) << getPart() << "|" << setw(13) << getNum() << "|" << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}
void Space::showDown() {
    cout << "|" << "                ѕримiтка: не показанi данi дл€ класiв: B, A, G, K                " << "|"; cout << endl;
    cout << "-----------------------------------------------------------------------------------" << endl;
}
