#include <iostream>
#include <Windows.h>
#include <cstring>

using namespace std;

#define N 40

char findFirstSymbol(const char* referenceString, const char* inputString) {
    for (; *inputString != '\0'; inputString++) {
        if (!isspace(*inputString) && strchr(referenceString, *inputString) == nullptr) {
            return *inputString;
        }
    }
    return 0;
}

void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}

void startMenu() {
    setlocale(LC_ALL, "ukr");

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    int menuItem;
    char referenceString[N];
    char inputString[N];
    char firstSymbol;

    do {
        gotoxy(65, 0);
        cout << "����" << endl;
        gotoxy(0, 0);

        SetConsoleTextAttribute(h, 3);
        cout << "1. ������ ������� �����" << endl;
        SetConsoleTextAttribute(h, 4);
        cout << "2. ����� � ��������" << endl;
        SetConsoleTextAttribute(h, 6);
        cout << "����i�� � ���������������� ���i���i� �����: ";
        SetConsoleTextAttribute(h, 7);


        cin >> menuItem;
        cin.ignore();

        switch (menuItem) {
        case 1:
            cout << "����i�� ������� �����: ";
            cin.getline(referenceString, N);

            cout << "����i�� ����� ��� ����i��: ";
            cin.getline(inputString, N);

            firstSymbol = findFirstSymbol(referenceString, inputString);

            if (firstSymbol != '\0') {
                SetConsoleTextAttribute(h, 3);
                cout << "������ ������, ���� �� ������� � ������� �����: ";
                SetConsoleTextAttribute(h, 6);
                cout << firstSymbol << endl;
                SetConsoleTextAttribute(h, 7);
            }
            else {
                SetConsoleTextAttribute(h, 2);
                cout << "��i ������� � ����� ������� � ������� �����." << endl;
                SetConsoleTextAttribute(h, 7);
            }
            break;

        case 2:
            cout << "Press any key to exit..." << endl << endl;
            break;

        default:
            cout << "����������� ���i�. ��������� �� ���." << endl;
            break;
        }
        system("pause");
        system("cls");

    } while (menuItem != 2);
}

int main() {
    startMenu();
    return 0;
}
