#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>

using namespace std;

#define PRINT_TYPE 2 // 1 - input user, 2 - random generation
#define distance 16


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

