#include "Header.h"


void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}



void fillStructure(Space *galaxy, int size) {
    
    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

#if PRINT_TYPE == 1

    for (int i = 0; i < size; i++) {
        cout << "����i�� ������������ ����: ";
        cin >> galaxy[i].spectralClass;
        cout << "����i�� ��������� ���� (�i������ �����): ";
        cin >> galaxy[i].mass;
        cout << "����i�� �������: ";
        cin >> galaxy[i].part;
        cout << "����i�� �������i���: ";
        cin >> galaxy[i].num;
    }

#elif PRINT_TYPE == 2

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        galaxy[i].spectralClass = letters[rand() % letters.size()];
        galaxy[i].mass = rand() % 100 + 1;
        galaxy[i].part = rand() % 100 + 1;
        galaxy[i].num = rand() % 100 + 1;
    }

#endif
}

void sortStructure(Space* galaxy, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (galaxy[j].spectralClass > galaxy[j + 1].spectralClass) {
                Space temp = galaxy[j];
                galaxy[j] = galaxy[j + 1];
                galaxy[j + 1] = temp;
            }
        }
    }
}

void printSpaceStructure(Space* galaxy, int size) {

    

    cout << "---------------------------------------------------------------------" << endl;
    cout << "|" << "  ��������� �i���i��� �i��� �i���� ����������i� ����i� � ��������i " << "|"; cout << endl;
    cout << "---------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << "|" << setw(distance) << galaxy[i].spectralClass << "|" << setw(distance) << galaxy[i].mass << "|" << setw(distance) << galaxy[i].part << "|" << setw(distance) << galaxy[i].num << "|" << endl;
        cout << "---------------------------------------------------------------------" << endl;
    }

    cout << "|" << "         ����i���: �� �������i ���i ��� ����i�: B, A, G, K         " << "|"; cout << endl;
    cout << "---------------------------------------------------------------------" << endl;

}

