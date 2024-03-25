#include <iostream>
#include <iomanip>

using namespace std;

#define N 2

auto averageOfNegativeNum(int arr[], int size, int index = 0, int count = 0, int sum = 0) {
    if (index >= size) {
        if (count == 0) {
            cout << "\nУ масивi немає вiд'ємних елементiв" << endl;
            return 0;
        }
        return sum / count;
    }

    if (arr[index] < 0) {
        count++;
        sum += arr[index];
    }

    return averageOfNegativeNum(arr, size, index + 1, count, sum);
}


int main(){

    srand(time(NULL));
    setlocale(LC_ALL, "ukr");

    int arr[N];
    
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 50 - 20;
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            cout << "\x1B[31m"; 
        }
        cout << setw(6) << arr[i];
        if (arr[i] < 0) {
            cout << "\x1B[0m";
        }
    }
    

    auto size = sizeof(arr) / sizeof(arr[0]);

    auto average = averageOfNegativeNum(arr, size);

    cout << endl;
    cout << "Середнє арифметичне негативних елементiв: " <<"\x1B[31m" <<  average << "\x1B[0m" << endl;


    cout << "\n\n\n\n\n\n\n___________________________________";
}


