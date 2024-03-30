#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

#define PRINT_TYPE 1 // 1 - input user, 2 - random generation
#define distance 16


struct Space {
    char spectralClass;
    float mass;
    float part;
    long long num;
};


void gotoxy(int x, int y);
void fillStructure();
void sortStructure();
void printSpaceStructure(Space galaxy[], int size);


#endif 

