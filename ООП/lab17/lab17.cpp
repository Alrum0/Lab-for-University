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

 
    int choose;
    do {

        int aInt, bInt;
        float aFloat, bFloat;
        string a, b;

        cout << "1. Цiлi числа" << endl;
        cout << "2. Дiйснi числа" << endl;
        cout << "3. Рядковi числа" << endl;
        cout << "4. Вихiд" << endl;
        cout << "Введiть ваш вибiр: ";

        cin >> choose;
        switch (choose){
        case 1:
            cout << "Введiть перше число: ";
            cin >> aInt;
            cout << "Введiть друге число: ";
            cin >> bInt;

            {
                Number<int> intNumber(aInt);
                Number<int> intNumber2(bInt);
                cout << "Додавання цiлих чисел" << endl;
                Number<int> sumIntNum = intNumber + intNumber2;
                cout << "Number 1 + Number 2 = " << intNumber << " + " << intNumber2 << " = " << sumIntNum << endl;
            }
            break;
        case 2:
            cout << "Введiть перше число: ";
            cin >> aFloat;
            cout << "Введiть друге число: ";
            cin >> bFloat;

            {
                Number<float> floatNumber(aFloat);
                Number<float> floatNumber2(bFloat);
                cout << "Додавання дiйсних чисел" << endl;
                Number<float> sumFloatNum = floatNumber + floatNumber2;
                cout << "Number 1 + Number 2 = " << floatNumber << " + " << floatNumber2 << " = " << sumFloatNum << endl;
            }
            break;
        case 3:
            cout << "Введiть перше число: ";
            cin >> a;
            cout << "Введiть друге число: ";
            cin >> b;

            {
                Number<string> stringNumber(a);
                Number<string> stringNumber2(b);
                cout << "Додавання дiйсних чисел" << endl;
                Number<string> sumStringNum = stringNumber + stringNumber2;
                cout << "Number 1 + Number 2 = " << stringNumber << " + " << stringNumber2 << " = " << sumStringNum << endl;
            }
            break;
        default: cout << "Неправильний вибiр" << endl;
            break;
        }
        system("pause");
        system("cls");
    } while (choose != 4);
  

    

   

    return 0;
}


