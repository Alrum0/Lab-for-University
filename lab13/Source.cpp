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
    cout << "---------------------------------------------------------------------" << endl;
    cout << "|" << "  Приблизна кiлькiсть зiрок рiзних спектральнiв класiв в Галактицi " << "|"; cout << endl;
    cout << "---------------------------------------------------------------------" << endl; 
}
void Space::show() {
    for (int i = 0; i < N; i++) {
        cout << "|" << setw(distance) << getSpectralClass() << "|" << setw(distance) << getMass() << "|" << setw(distance) << getPart() << "|" << setw(distance) << getNum() << "|" << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }
}
void Space::showDown() {
    cout << "|" << "         Примiтка: не показанi данi для класiв: B, A, G, K         " << "|"; cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
}






void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}