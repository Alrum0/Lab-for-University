#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void processArray(int A[], int size, int B[], int& sizeB, int C[], int& sizeC, int D[], int& sizeD) {
    sizeB = sizeC = sizeD = 0;

    int* ptrB = B;
    int* ptrC = C;
    int* ptrD = D;

    for (int i = 0; i < size; ++i) {
        if (A[i] < 0) {
            *ptrB = A[i];
            ++ptrB;
            ++sizeB;
        }
        else if (A[i] > 0) {
            *ptrC = A[i];
            ++ptrC;
            ++sizeC;
        }
        else {
            *ptrD = A[i];
            ++ptrD;
            ++sizeD;
        }
    }

    for (int i = 0; i < sizeB; ++i) {
        A[i] = B[i];
    }

    for (int i = 0; i < sizeC; ++i) {
        A[sizeB + i] = C[i];
    }

    for (int i = 0; i < sizeD; ++i) {
        A[sizeB + sizeC + i] = D[i];
    }
}

int main() {

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    const int size = 10;
    int A[size];

    // Рандомне заповнення масиву
    srand(time(0));
    SetConsoleTextAttribute(h, 6);
    cout << "Initial array A: ";
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < size; ++i) {
        A[i] = rand() % 21 - 10; // Генеруємо випадкове число в діапазоні [-10, 10]
        cout << A[i] << setw(4);
    }

    int B[size],
        sizeB,
        C[size],
        sizeC,
        D[size],
        sizeD;

    processArray(A, size, B, sizeB, C, sizeC, D, sizeD);
    SetConsoleTextAttribute(h, 2);
    cout << "\nModified array A: ";
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < size; ++i) {
        cout << A[i] << setw(4);
    }

    return 0;
}
