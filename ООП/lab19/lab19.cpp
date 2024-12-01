#include <iostream>
#include <vector>
#include <algorithm> 
#include <cassert>

using namespace std;

template <typename T>
T myMin(T a, T b) {
    return (a < b) ? a : b;
}


template <typename T>
void mySort(vector<T>& arr) {
    sort(arr.begin(), arr.end()); //greater<T>()
}


template <typename T>
T mySum(const vector<T>& arr) {
    T total = 0;
    for (const auto& item : arr) {
        if (item > 0) {
            total += item;
        }
    }
    return total;
}

void runTests() {

    assert(myMin(3, 5) == 3);          // assert(myMin(3, 5) == 5); // Це повинно викликати помилку
    assert(myMin(-2, -5) == -5);
    assert(myMin(3.3, 2.2) == 2.2);
    assert(myMin('a', 'b') == 'a');

    vector<int> unsorted = { 5, 3, 8, 1, 2 };        
    vector<int> sorted = { 1, 2, 3, 5, 8 };
    mySort(unsorted);
    assert(unsorted == sorted);
    


    vector<int> arr = { 1, -2, 3, 4, -5 };
    assert(mySum(arr) == 8);             // assert(mySum(arr) == 1); // Це повинно викликати помилку

}

int main() {
    setlocale(LC_ALL, "ukr");
    runTests();
    cout << "Всi тести пройдено успiшно!" << endl;
}
