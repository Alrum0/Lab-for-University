#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

void processArray(int* inputArray, int size) {
    int* positiveElements = new int[size];
    int positiveCount = 0;

    for (int i = 1; i < size - 1; ++i) {
        if (inputArray[i] < inputArray[i - 1] && inputArray[i] < inputArray[i + 1]) {
            std::cout << "Елемент " << inputArray[i] << " менший за попередній та наступний." << std::endl;
            inputArray[i] *= -1;  // Позначаємо підсвічуваний елемент (можна використати інші маркери)
        }
        if (inputArray[i] > 0) {
            positiveElements[positiveCount] = inputArray[i];
            positiveCount++;
        }
    }

    std::cout << "Одновимірний масив з позитивними та підсвіченими елементами:";
    for (int i = 0; i < size; ++i) {
        if (inputArray[i] < 0) {
            std::cout << " \033[1;31m" << -inputArray[i] << "\033[0m";  // Відновлюємо позитивне значення
        }
        else {
            std::cout << " " << inputArray[i];
        }
    }
    std::cout << std::endl;

    std::cout << "Одновимірний масив з позитивними елементами:";
    for (int i = 0; i < positiveCount; ++i) {
        std::cout << " " << positiveElements[i];
    }
    std::cout << std::endl;

    delete[] positiveElements;
}

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    std::cout << "Введіть кількість елементів ->: ";
    std::cin >> size;

    if (size < 3) {
        std::cout << "Некоректний ввід. Кількість елементів повинна бути мінімум 3";
        return 1;
    }

    int* inputArray = new int[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        inputArray[i] = rand() % 21 - 10;
    }

    for (int i = 0; i < size; i++) {
        std::cout << inputArray[i] << std::setw(4);
    }
    std::cout << std::endl;

    processArray(inputArray, size);

    delete[] inputArray;

    return 0;
}
