#include <iostream>

int main() {
    const int size = 5; // Розмір квадратної матриці

    // Створення та ініціалізація квадратної матриці розміром size x size
    int matrix[size][size] = { 0 };

    // Заповнення сектора вище та нижче головної діагоналі
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j > i) {
                matrix[i][j] = 1; // Встановлюємо значення 1 у секторі вище головної діагоналі
            }
            else if (j < i) {
                matrix[i][j] = -1; // Встановлюємо значення -1 у секторі нижче головної діагоналі
            }
        }
    }

    // Виведення матриці
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
