
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <windows.h>
#include <cstdlib>

using namespace std;



void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    setlocale(LC_ALL, "rus");

        int arr[10] = { 0, 1, 2, 3, 4, 5 };
        int n = 6; // Розмір початкового масиву

        // Вставка елементів
        int positionInsert, Numinsert;
        cout << "Введіть позицію для вставки: ";
        cin >> positionInsert;
        cout << "Введіть кількість елементів для вставки: ";
        cin >> Numinsert;

        if (positionInsert >= 0 && positionInsert <= n && Numinsert > 0 && n + Numinsert <= 10) {
            cout << "Введіть " << Numinsert << " елемент(-ів) для вставки: ";
            for (int i = n - 1; i >= positionInsert; i--) {
                arr[i + Numinsert] = arr[i];
            }
            for (int i = 0; i < Numinsert; i++) {
                int val;
                cin >> val;
                arr[positionInsert + i] = val;
            }
            n += Numinsert;
            cout << "Масив після вставки:" << endl;
            printArray(arr, n);
        }
        else {
            cout << "Некоректне введення для вставки." << endl;
        }

        // Видалення елементів
        int positionDelete, numberDelete;
        cout << "Введіть позицію для видалення: ";
        cin >> positionDelete;
        cout << "Введіть кількість елементів для видалення: ";
        cin >> numberDelete;

        if (positionDelete >= 0 && positionDelete < n && numberDelete > 0 && positionDelete + numberDelete <= n) {
            for (int i = positionDelete + numberDelete; i < n; i++) {
                arr[i - numberDelete] = arr[i];
            }
            n -= numberDelete;
            cout << "Масив після видалення:" << endl;
            printArray(arr, n);
        }
        else {
            cout << "Некоректне введення для видалення." << endl;
        }

        return 0;
    }
