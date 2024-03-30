#include "Header.h"



void fillStructure() {
    const int size = 3;
    Space galaxy[size];

#if PRINT_TYPE == 1

    for (int i = 0; i < size; i++) {
        cout << "¬вед≥ть спектральний клас: ";
        cin >> galaxy[i].spectralClass;
        cout << "¬вед≥ть приблизну масу (в≥дносно —онц€): ";
        cin >> galaxy[i].mass;
        cout << "¬вед≥ть частину: ";
        cin >> galaxy[i].part;
        cout << "¬вед≥ть чисельн≥сть: ";
        cin >> galaxy[i].num;
    }

#elif PRINT_TYPE == 2

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        galaxy[i].mass = rand() % 100 + 1;
        galaxy[i].part = rand() % 100 + 1;
        galaxy[i].num = rand() % 100 + 1;
    }

#endif
}

void sortStructure() {
    // –еал≥зуйте сортуванн€ структури за потреби
}

void printSpaceStructure(Space galaxy[], int size) {

    

    cout << "---------------------------------------------------------------------" << endl;
    cout << "|" << "  ѕриблизна к≥льк≥сть з≥рок р≥зних спектральн≥в клас≥в в √алактиц≥ " << "|"; cout << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << "|" << setw(distance) << galaxy[i].spectralClass << "|" << setw(distance) << galaxy[i].mass << "|" << setw(distance) << galaxy[i].part << "|" << setw(distance) << galaxy[i].num << "|" << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }
}

void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}