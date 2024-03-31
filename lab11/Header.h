#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>

using namespace std;

#define distance 16

#define PRINT_TYPE 2 // 1 - input user, 2 - random generation
#define DEBUG

#ifdef DEBUG
    #define PRINT_DEBUG_INFO() \
        cout << "Дата та час: " << __TIME__ << endl; \
        cout <<"Файл: " << __FILE__ << ", Функцiя: " << __func__ <<endl;
#else
    #define PRINT_DEBUG_INFO()
#endif





struct Space {
    char spectralClass;
    float mass;
    float part;
    long long num;
};


void gotoxy(int x, int y);
void fillStructure(Space* galaxy, int size);
void sortStructure(Space *galaxy, int size);
void printSpaceStructure(Space* galaxy, int size);


#endif 

