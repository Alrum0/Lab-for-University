#include <iostream>
#include <vector>
#include <algorithm> 
#include <cassert>

using namespace std;

template <typename T>
T my_min(T a, T b) {
    return (a < b) ? a : b;
}


template <typename T>
void my_sort(vector<T>& arr) {
    sort(arr.begin(), arr.end()); //greater<T>()
}


template <typename T>
T my_sum(const vector<T>& arr) {
    T total = 0;
    for (const auto& item : arr) {
        if (item > 0) {
            total += item;
        }
    }
    return total;
}

void runTests() {

    assert(my_min(3, 5) == 3);          // assert(my_min(3, 5) == 5); // Це повинно викликати помилку
    assert(my_min(-2, -5) == -5);
    assert(my_min(3.3, 2.2) == 2.2);
    assert(my_min('a', 'b') == 'a');   

    vector<int> unsorted = { 5, 3, 8, 1, 2 };        
    vector<int> sorted = { 1, 2, 3, 5, 8 };
    my_sort(unsorted);
    assert(unsorted == sorted);
    


    vector<int> arr = { 1, -2, 3, 4, -5 };
    assert(my_sum(arr) == 8);             // assert(my_sum(arr) == 1); // Це повинно викликати помилку

}

int main() {
    setlocale(LC_ALL, "ukr");
    runTests();
    cout << "Всi тести пройдено успiшно!" << endl;
}
