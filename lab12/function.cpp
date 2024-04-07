#include "Header.h"

void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}


void searchSumBetweenNegativeNum() {
    
    int size;

#if PRINT_TYPE == 1
    cout << "������ ����� ������: ";
    cin >> size;

    if (size <= 0) {
        cout << "����� ������ ������� ���� ������ �� 0." << endl;
        return;
    }

    int* arr = new int[size];

    cout << "������ �������� ������: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

#elif PRINT_TYPE == 2
    
    srand(time(NULL));

    cout << "������ ����� ������: ";
    cin >> size;

    if (size <= 0) {
        cout << "����� ������ ������� ���� ������ �� 0." << endl;
        return;
    }


    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100 - 20;
    }
    
        
#endif

    
    int* firstNegativeNumber = nullptr;
    int* secondNegativeNumber = nullptr;
    int sum = 0;
   

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (firstNegativeNumber == nullptr) {
                firstNegativeNumber = &arr[i];
            }
            else {
                secondNegativeNumber = &arr[i];
                break;
            }
        }
    }

    if (firstNegativeNumber != nullptr && secondNegativeNumber != nullptr) {
        for (int* ptr = firstNegativeNumber + 1; ptr < secondNegativeNumber; ptr++) {
            sum += *ptr;
        }
    }


    for (int i = 0; i < size; i++) {
        cout << setw(5) <<arr[i];
    }
    cout << endl;

    cout << "���� �� ������ � ������ ��'������ �������: " << sum << endl;

    delete[] arr;
}