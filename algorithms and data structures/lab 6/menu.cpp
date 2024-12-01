#include "Header.h"

void menu() {
    int choose;
    int n;
    int* arr = nullptr;

    int key;
    int result;
    string text;
    string pattern;
    string filename;

    do {
        cout << TABUL << CYAN << BOLD << "=== M E N U ===" << RESET << endl; 
        cout << "1. Роздрукувати масив" << endl;
        cout << "2. Відсортувати масив" << endl;
        cout << "3. Лінійний пошук " << endl;
        cout << "4. Пошук з бар'єром " << endl;
        cout << "5. Бінарний пошук " << endl;
        cout << "6. Прямий пошук підрядка " << endl;
        cout << "7. Алгоритм Кнута-Морріса-Пратта " << endl;
        cout << "8. Алгоритм Бойера-Мура " << endl;
        cout << "9. Алгоритм Рабина-Карпа " << endl;
        cout << "10. Записати масив у файл " << endl;
        cout << RED << "0. Вихід" << RESET << endl;

        cout << "Виберіть опцію: ";
        cin >> choose;

        switch (choose) {
        case 1:
            cout << "Введіть кількість елементів для генерації: ";
            cin >> n;
            delete[] arr; 
            arr = new int[n];
            fillArrayRandom(arr, n);
            cout << "Згенерований випадковий масив: " << endl;
            printArray(arr, n);
            break;
        case 2:
            if (arr == nullptr) {
                cout << RED << "Масив не створено! Спочатку згенеруйте масив." << RESET << endl;
                break;
            }
            blockSort(arr, n);
            cout << "Відсортований масив (блочне сортування): " << endl;
            printArray(arr, n);
            break;
        case 3:
            cout << "Введіть значення для пошуку: ";
            cin >> key;
            linearSearch(arr, n, key, result);
            break;
        case 4:
            cout << "Введіть значення для пошуку: ";
            cin >> key;
            searchWithBarrier(arr, n, key, result);            
            break;
        case 5:
            cout << "Введіть значення для пошуку: ";
            cin >> key;
            binarySearch(arr, n, key, result);
            break;
        case 6:
            cout << "Введіть текст: ";
            cin.ignore();
            getline(cin, text);
            cout << "Введіть підрядок для пошуку: ";
            getline(cin, pattern);
            directSubstringSearch(text, pattern, result);
            break;
        case 7:
            cout << "Введіть текст: ";
            cin.ignore();
            getline(cin, text);
            cout << "Введіть підрядок для пошуку: ";
            getline(cin, pattern);        
            knutMorrisPrattSearch(text, pattern, result);
            break;
        case 8:
            cout << "Введіть текст: ";
            cin.ignore();
            getline(cin, text);
            cout << "Введіть підрядок для пошуку: ";
            getline(cin, pattern);
            boyerMooreSearch(text, pattern, result);
            break;
        case 9:
            cout << "Введіть текст: ";
            cin.ignore();
            getline(cin, text);
            cout << "Введіть підрядок для пошуку: ";
            getline(cin, pattern);
            rabinKarpSearch(text, pattern, result);
            break;
        case 10:
            if (arr == nullptr) {
                cout << RED << "Масив не створено! Спочатку згенеруйте масив." << RESET << endl;
                break;
            }
            cout << "Введіть назву файлу: ";
            cin >> filename;
            writeArrayToFile(arr, n, filename);
            break;
        case 11:
            runTests();
            break;
        case 12:
            runTests2();
            break;
        default:
            break;
        }
    } while (choose != 0);

}