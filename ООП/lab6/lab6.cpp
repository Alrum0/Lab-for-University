#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;

#define N 9 

void matrixSectors() {

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);


    int Ar[N][N]; /* матриця */
    short i, r;  /* поточні індекси */
    short r1, r2; /* граничні номери стовпців */
    short dd;    /* модифікатор граничних номерів */
    short k;     /* поточний член ЛПЧ */
    /* початкові значення змінних */
    r1 = 1; r2 = N - 2; dd = 1; k = 1;
    for (i = 0; i < N; i++) {  /* перебирання рядків */
        for (r = 0; r < N; r++)  /* перебирання стовпців */
            if ((r < r1) || (r > r2)) {
                Ar[i][r] = 0;
            }
            else {
                Ar[i][r] = k++;
            }
        r1 += dd; r2 -= dd;
        if (r1 > r2) {
            dd = -dd;
        }
    }



    for (i = 0; i < N; i++) {
        for (r = 0; r < N; r++) {
            cout << setw(3) << Ar[i][r];
        }
        cout << endl;
    }
}

void twoDimensionalArray() {

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    setlocale(LC_ALL, "rus");

    const int rows = 3; // Кількість рядків
    const int cols = 4; // Кількість стовпців

    // Оголошення та ініціалізація двовимірного масиву
    int matrix[rows][cols] = {
        {5, 8, 2, 1},
        {9, 4, 6, 3},
        {7, 10, 12, 11}
    };
    SetConsoleTextAttribute(h, 2);
    cout << "Початковий масив: " << endl;
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    // а) Знайти максимальний елемент в кожному рядку і поміняти його місцями з першим елементом
    for (int i = 0; i < rows; i++) {
        int maxVal = matrix[i][0];
        int maxIndex = 0;

        // Знайдемо максимальний елемент в поточному рядку
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxIndex = j;
            }
        }

        // Поміняємо максимальний елемент і перший елемент у рядку
        int temp = matrix[i][0];
        matrix[i][0] = matrix[i][maxIndex];
        matrix[i][maxIndex] = temp;
    }

    // Виведення результату після операції (зміненої матриці)
    SetConsoleTextAttribute(h, 5);
    cout << "Результат пiсля операцiї 'а':" << endl;
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // б) Знайти мінімальний елемент в кожному стовпці і поміняти його місцями з останнім елементом
    for (int j = 0; j < cols; j++) {
        int minVal = matrix[0][j];
        int minIndex = 0;

        // Знайдемо мінімальний елемент в поточному стовпці
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minIndex = i;
            }
        }

        // Поміняємо мінімальний елемент і останній елемент у стовпці
        int temp = matrix[rows - 1][j];
        matrix[rows - 1][j] = matrix[minIndex][j];
        matrix[minIndex][j] = temp;
    }

    // Виведення результату після операції 'б'
    SetConsoleTextAttribute(h, 6);
    cout << "Результат пiсля операцiї 'б':" << endl;
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplicationOfTwoMatrix() {


    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    setlocale(LC_ALL, "rus");

    int numline1, numline2, numcolum1, numcolum2;


    // first matrix
    SetConsoleTextAttribute(h, 5);
    cout << setw(5) << "Перша матриця" << right << endl;
    SetConsoleTextAttribute(h, 7);

    SetConsoleTextAttribute(h, 3);
    cout << "Введiть кiлькiсть рядкiв для першої матрицi: ";
    SetConsoleTextAttribute(h, 7);
    cin >> numline1;
    SetConsoleTextAttribute(h, 3);
    cout << "Введiть кiлькiсть стовпцiв для першої матрицi: ";
    SetConsoleTextAttribute(h, 7);
    cin >> numcolum1;

    // second matrix
    SetConsoleTextAttribute(h, 5);
    cout << setw(5) << "Друга матриця" << right << endl;
    SetConsoleTextAttribute(h, 7);

    SetConsoleTextAttribute(h, 3);
    cout << "Введiть кiлькiсть рядкiв для другої матрицi: ";
    SetConsoleTextAttribute(h, 7);
    cin >> numline2;
    SetConsoleTextAttribute(h, 3);
    cout << "Введiть кiлькість стовпцiв для другої матрицi: ";
    SetConsoleTextAttribute(h, 7);
    cin >> numcolum2;

    if (numcolum1 != numline2) {
        SetConsoleTextAttribute(h, 4);
        cout << "Матрицю не можливо перемножити через неправильнi розмiри." << endl;
        SetConsoleTextAttribute(h, 7);
    }

    double** matrix1 = new double* [numline1];
    for (int i = 0; i < numline1; i++) {
        matrix1[i] = new double[numcolum1];
    }
    SetConsoleTextAttribute(h, 6);
    cout << "Введiть елементи першої матрицi: ";
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < numline1; i++) {
        for (int j = 0; j < numcolum1; j++) {
            cin >> matrix1[i][j];
        }
    }

    double** matrix2 = new double* [numline2];
    for (int i = 0; i < numline2; i++) {
        matrix2[i] = new double[numcolum2];
    }
    SetConsoleTextAttribute(h, 6);
    cout << "Введiть елементи другої матрицi: ";
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < numline2; i++) {
        for (int j = 0; j < numcolum2; j++) {
            cin >> matrix2[i][j];
        }
    }

    double** result = new double* [numline1];
    for (int i = 0; i < numline1; i++) {
        result[i] = new double[numcolum2];
    }

    for (int i = 0; i < numline1; i++) {
        for (int j = 0; j < numcolum2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < numcolum1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    SetConsoleTextAttribute(h, 2);
    cout << "Результат множення матриць:" << endl;
    SetConsoleTextAttribute(h, 7);
    for (int i = 0; i < numline1; i++) {
        for (int j = 0; j < numcolum2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void StartMenu() {

    int menuitem;

    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);

    do {
        SetConsoleTextAttribute(h, 3);
        cout << "1. --- Task1. Matrix sectors" << endl;
        cout << "2. --- Task2. Two dimensional array" << endl;
        cout << "3. --- Task3. Multiplication of two matrix" << endl;
        SetConsoleTextAttribute(h, 4);
        cout << "0.Exit" << endl;
        SetConsoleTextAttribute(h, 7);
        SetConsoleTextAttribute(h, 6);
        cout << "Choise task by his number: ";
        SetConsoleTextAttribute(h, 7);

        cin >> menuitem;

        switch (menuitem)
        {
        case 1:
            matrixSectors();
            break;

        case 2:
            twoDimensionalArray();
            break;

        case 3:
            multiplicationOfTwoMatrix();
            break;

        case 0:
            cout << "Bye-Bye";
            break;

        default:
            cout << "incorrect choice ";
            break;
        }
        cout << "Press anykay";
        system("pause");
        system("cls");


    } while (menuitem != 0);

}


int main() {
    StartMenu();
}


