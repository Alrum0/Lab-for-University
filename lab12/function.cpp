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
    cout << "Введiть розмiр масиву: ";
    cin >> size;
    if (size <= 0) {
        cout << "Розмiр масиву повинен бути бiльшим за 0." << endl;
        return;
    }

    int* arr = new int[size];

    cout << "Введiть елементи масиву: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

#elif PRINT_TYPE == 2
    
    srand(time(NULL));

    cout << "Введiть розмiр масиву: ";
    cin >> size;

    if (size <= 0) {
        cout << "Розмiр масиву повинен бути бiльшим за 0." << endl;
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

    /*if (firstNegativeNumber != nullptr && secondNegativeNumber != nullptr) {
        for (int* ptr = firstNegativeNumber + 1; ptr < secondNegativeNumber; ptr++) {
            sum += *ptr;
        }
    }*/
    if (firstNegativeNumber != nullptr && secondNegativeNumber != nullptr && secondNegativeNumber > firstNegativeNumber + 1) {
        for (int* ptr = firstNegativeNumber + 1; ptr < secondNegativeNumber; ptr++) {
            sum += *ptr;
        }
    }



    for (int i = 0; i < size; i++) {
        cout << setw(5) <<arr[i];
    }
    cout << endl;

    cout << "Сума мiж першим i другим вiд'ємними числами: " << sum << endl;

    delete[] arr;
}
void searchSumBetweenNegativeNum2() {
    int size;

#if PRINT_TYPE == 1
    cout << "Введiть розмiр масиву: ";
    cin >> size;
    if (size <= 0) {
        cout << "Розмiр масиву повинен бути бiльшим за 0." << endl;
        return;
    }

    int* arr = new int[size];

    cout << "Введiть елементи масиву: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

#elif PRINT_TYPE == 2

    srand(time(NULL));

    cout << "Введiть розмiр масиву: ";
    cin >> size;

    if (size <= 0) {
        cout << "Розмiр масиву повинен бути бiльшим за 0." << endl;
        return;
    }

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 41 - 20;
    }

#endif

    int& firstNegativeNumberIndex = size; 
    int& secondNegativeNumberIndex = size; 
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            if (firstNegativeNumberIndex == size) {
                firstNegativeNumberIndex = i;
            }
            else {
                secondNegativeNumberIndex = i;
                break;
            }
        }
    }

    if (firstNegativeNumberIndex != size && secondNegativeNumberIndex != size && secondNegativeNumberIndex > firstNegativeNumberIndex + 1) {
        for (int i = firstNegativeNumberIndex + 1; i < secondNegativeNumberIndex; i++) {
            sum += arr[i];
        }
    }


    for (int i = 0; i < size; i++) {
        cout << setw(7) << arr[i];
    }
    cout << endl;

    cout << "Сума мiж першим i другим вiд'ємними числами: " << sum << endl;

    delete[] arr;
}


int f(int lenght, int width = -1) {
    if (width == -1) {
        return lenght * lenght;
    }
    else {
        return lenght * width;
    }
}

void swapMaxMinNumberRef(int& a, int& b, int& c) {
    int minVal = a, maxVal = a;
    int* minPtr = &a, * maxPtr = &a;

    if (b < minVal) { minVal = b; minPtr = &b; }
    else if (b > maxVal) { maxVal = b; maxPtr = &b; }

    if (c < minVal) { minVal = c; minPtr = &c; }
    else if (c > maxVal) { maxVal = c; maxPtr = &c; }

    *minPtr = maxVal;
    *maxPtr = minVal;
} 
void swapMaxMinNumberPtr(int *a, int *b, int *c) {
    int minVal = *a, maxVal = *a;
    int* minPtr = a, * maxPtr = a;

    if (*b < minVal) { minVal = *b; minPtr = b; }
    else if (*b > maxVal) { maxVal = *b; maxPtr = b; }

    if (*c < minVal) { minVal = *c; minPtr = c; }
    else if (*c > maxVal) { maxVal = *c; maxPtr = c; }

    *minPtr = maxVal;
    *maxPtr = minVal;
}

int* f(int** A, int n, int m, int* min, int* max, int* S, int* P) {
    for (int j = 0; j < m; j++) {
        min[j] = A[0][j];
        for (int i = 1; i < n; i++) {
            if (A[i][j] < min[j]) {
                min[j] = A[i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        max[i] = A[i][0];
        for (int j = 1; j < m; ++j) {
            if (A[i][j] > max[i]) {
                max[i] = A[i][j];
            }
        }
    }

    *S = 0;
    *P = 1;
    for (int i = 0; i < n; i++) {
        *S += A[i][i];
        *P *= A[i][m - 1 - i];
    }

    int* res = new int[2];
    res[0] = *S;
    res[1] = *P;
    return res;

}

int sumPositiveNum(int arr[], int a) {
    int sum = 0;

    for (int i = 0; i < a; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}
int productNegativeNum(int arr[], int a) {
    int product = 1;

    for (int i = 0; i < a; i++) {
        if (arr[i] < 0) {
            product *= arr[i];
        }
    }
    return product;
}


