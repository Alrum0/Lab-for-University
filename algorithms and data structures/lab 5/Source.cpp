#include "Header.h"

void bubbleSort(int arr[], int n) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int swaps = 0; // кількість перестановок
    int comparisons = 0; // кількість порівнянь
    int operations = 0; // загальна кількість операцій

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
            operations++;
        }
    }

    auto stop = high_resolution_clock::now();  
    auto duration = duration_cast<seconds>(stop - start); 
    double seconds = duration.count() / 1000000.0; 
    double milliseconds = duration.count() / 1000.0;

    cout << endl;
//    cout << "Час виконання бульбашкового сортування: " << milliseconds << " мікросекунд\n";
    cout << "Кількість перестановок: " << swaps << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;
    cout << "Кількість операцій: " << operations << endl;
    cout << endl;
}

void shekerSort(int arr[], int n) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int swaps = 0; // кількість перестановок
    int comparisons = 0; // кількість порівнянь
    int operations = 0; // загальна кількість операцій

    int left = 0;
    int right = n - 1;
    int flag = 1;

    while (left < right && flag > 0) {
        flag = 0;

        for (int i = left; i < right; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps++;
                flag = 1; 
            }
            operations++;
        }
        right--;

        for (int i = right; i > left; i--) {
            comparisons++;
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swaps++;
                flag = 1; 
            }
            operations++;
        }
        left++;

    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl;
//    cout << "Час виконання шейкерного сортування: " << duration.count() * 10000 << " мікросекунд (помножено на 10000)\n";
    cout << "Кількість перестановок: " << swaps << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;
    cout << "Кількість операцій: " << operations << endl;
    cout << endl;
}

void blockSort(int arr[], int n) {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int swaps = 0; // кількість перестановок
    int comparisons = 0; // кількість порівнянь
    int operations = 0; // загальна кількість операцій

    int blockSize = 10;
    for (int i = 0; i < n; i += blockSize) {
        int end = (i + blockSize < n) ? i + blockSize : n;

        for (int j = i + 1; j < end; j++) {
            int key = arr[j];
            int k = j - 1;

            while (k >= i && arr[k] > key) {
                comparisons++;
                arr[k + 1] = arr[k];
                k--;
                swaps++;
                operations++;
            }
            arr[k + 1] = key;
            operations++;
        }
    }
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
            operations++;
        }
        arr[j + 1] = key;
        operations++;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    cout << endl;
//    cout << "Час виконання блочного сортування: " << duration.count() * 10000 << " мікросекунд (помножено на 10000)\n";
    cout << "Кількість перестановок: " << swaps << endl;
    cout << "Кількість порівнянь: " << comparisons << endl;
    cout << "Кількість операцій: " << operations << endl;
    cout << endl;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << setw(DISTANCE) << arr[i];
    }
    cout << endl;
}

void fillArrayUniqueRandom(int arr[], int n) {
    srand(time(NULL));

    int minValue = 1;
    int maxValue = n;

    for (int i = 0; i < n; i++) {
        int num;
        bool isUnique;

        do {
            num = rand() % maxValue + minValue;
            isUnique = true;

            for (int j = 0; j < i; j++) {
                if(arr[j] == num) {
                    isUnique = false;
                    break;
                }
            }
        } while (!isUnique);

        arr[i] = num;
    }
}

void fillArrayUniqueRandomDescending(int arr[], int n) {
    srand(time(NULL));

    int minValue = 1;
    int maxValue = n;
    bool used[n + 1]; 

    for (int i = 0; i <= n; i++) {
        used[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int num;
        bool isUnique;

        do {
            num = rand() % maxValue + minValue;
            isUnique = true;

            if (!used[num]) {
                used[num] = true;  
            } else {
                isUnique = false;  
            }
        } while (!isUnique);
        arr[i] = num;  
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void fillArrayUniqueRandomAscending(int arr[], int n) {
    srand(time(NULL));

    int minValue = 1;
    int maxValue = n;

    bool used[n + 1];  

    for (int i = 0; i <= n; i++) {
        used[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int num;
        bool isUnique;

        do {
            num = rand() % maxValue + minValue;
            isUnique = true;

            if (!used[num]) {
                used[num] = true;  
            } else {
                isUnique = false;  
            }
        } while (!isUnique);
        arr[i] = num;  
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void loadArrayFromFile(int*& arr, int& n, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка відкриття файлу." << RESET <<endl;
        return;
    }
    vector<int> tempArr;  
    int number;
    while (file >> number) {  
        tempArr.push_back(number);  
    }
    file.close();
    n = tempArr.size();  
    delete[] arr;  
    arr = new int[n];  

    for (int i = 0; i < n; ++i) {  
        arr[i] = tempArr[i];
    }
    cout << GREEN << "Успішно завантажено масив з файлу!" << RESET << endl;
}
