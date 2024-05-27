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

        cout << "1. �i�i �����" << endl;
        cout << "2. �i���i �����" << endl;
        cout << "3. ������i �����" << endl;
        cout << "4. ���i�" << endl;
        cout << "����i�� ��� ���i�: ";

        cin >> choose;
        switch (choose){
        case 1:
            cout << "����i�� ����� �����: ";
            cin >> aInt;
            cout << "����i�� ����� �����: ";
            cin >> bInt;

            {
                Number<int> intNumber(aInt);
                Number<int> intNumber2(bInt);
                cout << "��������� �i��� �����" << endl;
                Number<int> sumIntNum = intNumber + intNumber2;
                cout << "Number 1 + Number 2 = " << intNumber << " + " << intNumber2 << " = " << sumIntNum << endl;
            }
            break;
        case 2:
            cout << "����i�� ����� �����: ";
            cin >> aFloat;
            cout << "����i�� ����� �����: ";
            cin >> bFloat;

            {
                Number<float> floatNumber(aFloat);
                Number<float> floatNumber2(bFloat);
                cout << "��������� �i����� �����" << endl;
                Number<float> sumFloatNum = floatNumber + floatNumber2;
                cout << "Number 1 + Number 2 = " << floatNumber << " + " << floatNumber2 << " = " << sumFloatNum << endl;
            }
            break;
        case 3:
            cout << "����i�� ����� �����: ";
            cin >> a;
            cout << "����i�� ����� �����: ";
            cin >> b;

            {
                Number<string> stringNumber(a);
                Number<string> stringNumber2(b);
                cout << "��������� �i����� �����" << endl;
                Number<string> sumStringNum = stringNumber + stringNumber2;
                cout << "Number 1 + Number 2 = " << stringNumber << " + " << stringNumber2 << " = " << sumStringNum << endl;
            }
            break;
        default: cout << "������������ ���i�" << endl;
            break;
        }
        system("pause");
        system("cls");
    } while (choose != 4);
  

    

   

    return 0;
}


