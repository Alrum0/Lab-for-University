#include "Header.h"

void blockSort(int arr[], int n) {
    int blockSize = 10;
    for (int i = 0; i < n; i += blockSize) {
        int end = (i + blockSize < n) ? i + blockSize : n;

        for (int j = i + 1; j < end; j++) {
            int key = arr[j];
            int k = j - 1;

            while (k >= i && arr[k] > key) {
                arr[k + 1] = arr[k];
                k--;
            }
            arr[k + 1] = key;
        }
    }
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(DISTANCE) << arr[i];
    }
    cout << endl;
}

void fillArrayRandom(int arr[], int n) {
    int minValue = 1;  
    int maxValue = 100; 

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (maxValue - minValue + 1) + minValue; 
    }
}

void linearSearch(int arr[], int n, int key, int& operations) {
    operations = 0;
    for (int i = 0; i < n; i++) {
        operations++;
        if (arr[i] == key) {
            cout << GREEN << "Елемент " << key << " був знайдений на позицї " << i + 1 << RESET <<endl;
            return;
        }
    }
    cout << RED << "Елемент " << key << " не знайдено." << RESET << endl;
}

void searchWithBarrier(int arr[], int n, int key, int& operations) {
    operations = 0;
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;

    while (arr[i] != key) {
        operations++;
        i++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == key) {
        cout << GREEN << "Елемент " << key << " знайдено на позиції: " << i + 1 << RESET << endl;
    } else {
        cout << RED << "Елемент " << key <<" не знайдено." << RESET << endl;
    }
}

void binarySearch(int arr[], int n, int key, int& operations) {
    int left = 0;
    int right = n - 1;
    operations = 0;

    while (left <= right) {
        operations++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {

            cout << GREEN << "Елемент " << key << " знайдено на позиції: " << mid + 1 << RESET <<endl;
            return;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << RED << "Елемент " << key << " не знайдено." << endl;
}

void directSubstringSearch(const string& text, const string& pattern, int& operations) {
    int textLength = text.length();
    int patternLength = pattern.length();
    operations = 0;

    if (patternLength == 0) {
        cout << "Підрядок пустий!" << endl;
        return;
    }

    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;

        for (j = 0; j < patternLength; j++) {
            operations++;
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patternLength) {
            cout << GREEN << "Підрядок " << pattern << " знайдено на позиції " << i + 1 << RESET << endl;
            return;
        }
    }
    cout << RED << "Підрядок " << pattern << " не знайдено в тексті." << RED << endl;
}

void knutMorrisPrattSearch(const string& text, const string& pattern, int& operations) {
    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength == 0) {
        cout << "Підрядок пустий!" << endl;
        return;
    }

    int lps[patternLength];
    lps[0] = 0;
    int length = 0;
    int i = 1;
    operations = 0;

    while (i < patternLength) {
        operations++;
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if ( length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    i = 0;
    int j = 0;

    while (i < textLength) {
        operations++;
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == patternLength) {
            cout << GREEN << "Підрядок " << pattern << " знайдено на позиції " << (i - j) + 1 << RESET << endl;
            return;
        } else if (j != 0) {
            j = lps[j - 1];
        } else {
            i++;
        }
    }
    cout << RED << "Підрядок " << pattern << " не знайдено в тексті." << RESET << endl;
}

void boyerMooreSearch(const string& text, const string& pattern, int& operations) {
    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength == 0) {
        cout << "Підрядок пустий!" << endl;
        return;
    }

    const int ASCII_SIZE = 256;
    int badChar[ASCII_SIZE];
    memset(badChar, -1, sizeof(badChar));

    for (int i = 0; i < patternLength; i++) {
        badChar[pattern[i]] = i;
    }

    int shift = 0;

    while (shift <= (textLength - patternLength)) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            cout << GREEN << "Підрядок " << pattern << " знайдено на позиції " << shift + 1 << RESET << endl;
            return;
        }
        int badCharShift = max(1, j - badChar[text[shift + j]]);
        operations++;
        shift += badCharShift;
    }
    cout << RED << "Підрядок " << pattern << " не знайдено в тексті." << RED << endl;
}

unsigned long long hashFunction(const string& str, int end) {
    unsigned long long hashValue = 0;
    for (int i = 0; i < end; i++) {
        hashValue = (hashValue * 256 + str[i]) % 1000000007; 
    }
    return hashValue;
}

void rabinKarpSearch(const string& text, const string& pattern, int& operations) {
    int textLength = text.length();
    int patternLength = pattern.length();
    unsigned long long textHash = hashFunction(text, patternLength);  
    unsigned long long patternHash = hashFunction(pattern, patternLength);  

    for (int i = 0; i <= textLength - patternLength; i++) {
        operations++;
        if (patternHash == textHash) {
            int j;
            for (j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == patternLength) {
                cout << GREEN << "Підрядок " << pattern << " знайдено на позиції " << i + 1 << RESET << endl;
                return;
            }
        }

        if (i < textLength - patternLength) {
            textHash = (textHash - text[i] * pow(256, patternLength - 1)) * 256 + text[i + patternLength];
            textHash = textHash % 1000000007; 
        }
    }

    cout << RED << "Підрядок " << pattern << " не знайдено в тексті." << RED << endl;
}

void writeArrayToFile(int arr[], int n, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << RED << "Не вдалося відкрити файл для запису!" <<  RESET << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        outFile << arr[i] << " ";
    }

    outFile.close();
    cout << GREEN << "Масив успішно записано в файл: " << filename << RESET << endl;
}

void generateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  
    }
}

void runTests() {
    const int sizes[] = {10, 100, 500, 1000};
    int keyPositions[] = {0, -1, -2};  
    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        int arr[n];
        generateArray(arr, n);

        cout << "Розмір масиву: " << n << endl;
        for (int p = 0; p < 3; p++) {
            int key = (keyPositions[p] == 0) ? arr[0] : (keyPositions[p] == -1 ? arr[n / 2] : arr[n - 1]);
            int operations = 0;

            cout << "Тест " << (p == 0 ? "на початку" : (p == 1 ? "у середині" : "в кінці")) << endl;

            linearSearch(arr, n, key, operations);
            cout << "Лінійний пошук: " << operations << " операцій" << endl;

            searchWithBarrier(arr, n, key, operations);
            cout << "Пошук із бар'єром: " << operations << " операцій" << endl;

            binarySearch(arr, n, key, operations);
            cout << "Бінарний пошук: " << operations << " операцій" << endl;

            cout << endl;
        }
    }
}

void runTests2() {
    const int sizes[] = {10, 30, 50, 100}; // розміри рядків
    string text = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // тестовий текст
    string patterns[] = {"AB", "XYZ", "MN", "WXYZ"}; // тестові підрядки

    for (int s = 0; s < 4; s++) {
        int n = sizes[s];
        cout << "Розмір тексту: " << n << endl;

        for (int p = 0; p < 4; p++) {
            string pattern = patterns[p];
            int operations;

            cout << "Тест для підрядка: " << pattern << endl;
            
            directSubstringSearch(text, pattern, operations);
            cout << "Прямий пошук: " << operations << " операцій" << endl;

            knutMorrisPrattSearch(text, pattern, operations);
            cout << "Кнут-Морріс-Пратт: " << operations << " операцій" << endl;

            boyerMooreSearch(text, pattern, operations);
            cout << "Бойер-Мура: " << operations << " операцій" << endl;

            rabinKarpSearch(text, pattern, operations);
            cout << "Рабіна-Карпа: " << operations << " операцій" << endl;

            cout << endl;
        }
    }
}