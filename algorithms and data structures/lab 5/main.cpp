#include "Header.h"

int main() {
    setlocale(LC_ALL, "ukr");
    int choose;
    int n;
    int* arr = nullptr;
    string filename;

    do {
        cout << TABUL << CYAN << BOLD << "=== M E N U ===" << RESET << endl; 
        cout << "1. Алгоритм бульбашкового сортування" << endl;
        cout << "2. Алгоритм Шейкер сортування" << endl;
        cout << "3. Алгоритм блочного сортування" << endl;
        cout << RED << "4. Вихід" << RESET << endl;

        cout << "Виберіть опцію: ";
        cin >> choose;

        if (choose >= 1 && choose <= 3) {
            int loadChoice;
            cout << TABUL << CYAN << BOLD << "=== M E N U ===" << RESET << endl; 
            cout << "Оберіть спосіб отримання масиву:" << endl;
            cout << "1. Завантажити з файлу" << endl;
            cout << "2. Згенерувати випадково" << endl;
            cout << "Ваш вибір: ";
            cin >> loadChoice;

            switch (loadChoice) {
                case 1:
                    cout << "Введіть ім'я файлу: ";
                    cin >> filename;
                    loadArrayFromFile(arr, n, filename);
                    cout << "Масив, завантажений з файлу: " << endl;
                    printArray(arr, n);
                    break;

                case 2:
                    cout << "Введіть кількість елементів для генерації: ";
                    cin >> n;
                    delete[] arr; 
                    arr = new int[n];
                    //fillArrayUniqueRandomDescending(arr, n); // зменшення 
                    fillArrayUniqueRandom(arr, n); // випадково
                    //fillArrayUniqueRandomAscending(arr, n); // збільшення
                    cout << "Згенерований випадковий масив: " << endl;
                    printArray(arr, n);
                    break;

                default:
                    cout << RED << "Неправильний вибір. Повернення до головного меню.\n" << RESET;
                    continue;
            }
        }

        switch (choose) {
            case 1:
                bubbleSort(arr, n);
                cout << "Відсортований масив (бульбашкове сортування): " << endl;
                printArray(arr, n);
                break;

            case 2:
                shekerSort(arr, n);
                cout << "Відсортований масив (шейкер сортування): " << endl;
                printArray(arr, n);
                break;

            case 3:
                blockSort(arr, n);
                cout << "Відсортований масив (блочне сортування): " << endl;
                printArray(arr, n);
                break;

            case 4:
                delete[] arr;  
                cout << "Вихід з програми.\n";
                exit(0);

            default:
                cout << RED << "Неправильний вибір. Спробуйте ще раз.\n" << RESET;
                break;
        }

    } while (choose != 4);
}
