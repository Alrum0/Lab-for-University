#include <iostream>
#include <windows.h>


using namespace std;

void gotoxy(int x, int y) {
    COORD crds;
    crds.X = x;
    crds.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds );
}


int main()
{
    gotoxy(41, 11);
    cout << "Hello world";
    system("pause");
}

