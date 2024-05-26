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

    Number<int> intNumber(525);
    Number<int> intNumber2(475);

    cout << "Додавання цiлих чисел" << endl;
    Number<int> sumIntNum = intNumber + intNumber2;
    cout << "Number 1 + Number 2 = " << intNumber << " + " << intNumber2 << " = " << sumIntNum << endl;

    Number<float> floatNumber(18.33);
    Number<float> floatNumber2(12.771);

    cout << "Додавання дiйсних чисел" << endl;
    Number<float> floatFloatNum = floatNumber + floatNumber2;
    cout << "Number 1 + Number 2 = " << floatNumber << " + " << floatNumber2 << " = " << floatFloatNum << endl;

    return 0;
}


