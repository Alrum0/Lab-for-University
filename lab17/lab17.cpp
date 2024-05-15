#include <iostream>

using namespace std;

template<class Type1, class Type2>
class Str {
protected:
    Type1 a;
    Type2 b;
public:
    Str(Type1 a, Type2 b) : a(a), b(b){}
    void show() {
        cout << a << " " << b << endl;
    }
};

template<class Sum>
class Number {
protected:
    Sum value;
public:
    Number(Sum value): value(value){}

    void print() const {
        cout << value << endl;
    }
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }
};


int main(){
    Number<int> intNumber(5);
    Number<int> intNumber2(10);
    Number<float> floatNumber(5.5);
    Number<float> floatNumber2(4.4);

    Number<int> sumIntNum = intNumber + intNumber2;
    sumIntNum.print();

    Number<float> sumFloatNum = floatNumber + floatNumber2;
    sumFloatNum.print();

    cout << "__________________________________________" << endl;
    Str<char, string> obj('F', "WARNING");
    obj.show();
}

