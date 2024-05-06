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



void Space::activeTask() {
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
    
    cout << "Введіть спектральний клас: ";
    in >> space.spectralClass;
    cout << "Введіть масу: ";
    in >> space.mass;
    cout << "Введіть частку: ";
    in >> space.part;
    cout << "Введіть кількість: ";
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


void Menu::menuActive() {

    do {
        gotoxy(65, 0);
        cout << "Menu";
        gotoxy(0, 0);

        SetConsoleTextAttribute(h, 3);
        cout << endl << "1. Будувати табличку" << endl;
        cout << "2. Змiнити рядок" << endl;
        cout << "3. Порiвняти рядки" << endl;
        cout << "4. Вiдображення змiненої таблицi" << endl;
        SetConsoleTextAttribute(h, 4);
        cout << "7. Вихiд" << endl;
        SetConsoleTextAttribute(h, 7);
        SetConsoleTextAttribute(h, 6);
        cout << "Обери один iз запропонованих варiантiв: ";
        SetConsoleTextAttribute(h, 7);

        cin >> choice;

        switch (choice) {
        case 1:
            if (!tableGenerated) {
                space.activeTask();
                tableGenerated = true;
            }
            else {
                cout << "Таблиця вже згенерована! Ви можете змiнити її або порiвняти рядки." << endl;
            }
            break;
        case 2:
            if (!tableGenerated) {
                cout << "Спочатку потрiбно згенерувати таблицю!" << endl;
            }
            else {
                cout << "Введiть iндекс рядка, який бажаєте змiнити(Примiтка, нумерацiя рядкiв починається з 0): ";
                cin >> index;
                if (index >= 0 && index < N) {
                    cout << "Введiть новi данi для рядка" << index << ":" << endl;
                    cin >> Space::originalSpaces[index];
                    cout << "Рядок успiшно змiнено!" << endl;
                }
                else {
                    cout << "Неправильний iндекс рядка!" << endl;
                }
            }
            break;
        case 3:
            if (!tableGenerated) {
                cout << "Спочатку потрiбно згенерувати таблицю!" << endl;
            }
            else {
                cout << "Введiть iндекс першого рядка(Примiтка, нумерацiя рядкiв починається з 0): ";
                cin >> index1;
                cout << "Введiть iндекс для другого рядка: ";
                cin >> index2;
                if (index1 >= 0 && index1 < N && index2 >= 0 && index2 < N) {
                    if (Space::originalSpaces[index1] == Space::originalSpaces[index2]) {
                        Space::originalSpaces[index1].show();
                        Space::originalSpaces[index2].show();
                        cout << "Рядки " << index1 << " i " << index2 << " спiвпадають!" << endl;
                    }
                    else {
                        cout << "Рядки " << index1 << " i " << index2 << " не спiвпадають!" << endl;
                        Space::originalSpaces[index1].show();
                        Space::originalSpaces[index2].show();
                    }
                }
                else {
                    cout << "Неправильний iндекс рядкiв!" << endl;
                }
            }
            break;
        case 4:
            if (!tableGenerated) {
                cout << "Спочатку потрiбно згенерувати таблицю!" << endl;
            }
            else {
                cout << "Оновлена таблиця:" << endl;
                Space::originalSpaces[0].showUp();
                for (int i = 0; i < N; i++) {
                    Space::originalSpaces[i].show();
                }
                Space::originalSpaces[0].showDown();
            }
            break;
        case 7:
            cout << "До побачення!" << endl;
            break;
        default:
            cout << "Неправильний вибір опції. Будт ласка, спробуйте щн раз." << endl;
            break;

        }
        system("pause");
        system("cls");
    } while (choice != 7);
}