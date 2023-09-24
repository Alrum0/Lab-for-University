#include <iostream>

using namespace std;
int main()
{
    cout << "Execution lab1...\n";
    cout << "Task 1\n";
    cout << "Type int has " << sizeof(int) << " bytes\n";
    cout << "type short has " << sizeof(short) << " bytes\n";
    cout << "type long has " << sizeof(long) << " bytes\n";
    cout << "type char has " << sizeof(char) << " bytes\n";
    cout << "type float has " << sizeof(float) << " bytes\n";
    cout << "type double has " << sizeof(double) << " bytes\n";

    system("pause");
    system("cls");

    cout << "Task 2\n";
    double a, //first side
           b, //second ...
           c; //third ...
    double p, //half perimeter
           s; //square
    cout << "Input sides of triangle:";
    cin >> a >> b >> c;
    if (a < b + c && b < a + c && c < a + b) {
        p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "Square of triangle is " <<s <<endl;
    }
    else {
        cout << "Incorect sides!!!" <<endl;
    }

    system("pause");
    system("cls");
 
    cout << "Task 3\n";
    int num; // beginner number
    long long num2; // 2 exp
    long long num4; // 4 exp
    long long num8; // 8 exp
    cout << "Input source number: ";
    cin >> num;
    num2 = num * num;
    num4 = num2 * num2;
    num8 = num4 * num4;
    cout << num << "^8 = " << num8 <<endl;

    system("pause");
    system("cls");

    cout << "Task 4." << endl;
    int var1,  // first variable
        var2; // second variable
    int temp; // buffer variable
    cout << "Input valuas of two variables: ";
    cin >> var1 >> var2;
    cout << "Method 1. With third variable " << endl;
    cout << "Variables are before changing: "  << var1 <<" and "<< var2 << endl;
    temp = var1;
    var1 = var2;
    var2 = temp;
    cout << "Variables are after changing: " << var1 << " and " << var2 << endl;

    system("pause");

    cout << "Method 2. Without third variable " << endl;
    var1 = var1 + var2; // var1 -> var1 + var2
    var2 = var1 - var2; // var2 -> var1
    var1 = var1 - var2; // var1 -> var2 only ...
    cout << "Variables are after changing: " << var1 << " and " << var2 << endl; // :)

    system("pause");
    system("cls");

    cout << "Task 5." << endl;

}

