#include <iostream>

using namespace std;



#include <iostream>

using namespace std;

template<class T>
class Number {
protected:
    T value;
public:
    Number(T value) : value(value) {}
    void print() const {
        cout << value << endl;
    }
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }
    friend ostream& operator<<(ostream& os, const Number<T>& num) {
        os << num.value;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ukr"); 

    Number<int> intNumber(5);
    Number<int> intNumber2(10);

    cout << "Додавання цiлих чисел" << endl;
    Number<int> sumIntNum = intNumber + intNumber2;
    cout << "Number 1 + Number 2 = " << intNumber << " + " << intNumber2 << " = " << sumIntNum << endl;

    Number<float> floatNumber(5.3);
    Number<float> floatNumber2(3.5);

    cout << "Додавання дiйсних чисел" << endl;
    Number<float> sumFloatNum = floatNumber + floatNumber2;
    cout << "Number 1 + Number 2 = " << floatNumber << " + " << floatNumber2 << " = " << sumIntNum << endl;

    return 0;
}


