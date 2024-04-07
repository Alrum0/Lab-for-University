#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

#define PRINT_TYPE 2 //1. Input user, 2. Random
#define CHOISE 1 // 1. using indx, 2. using link



void switchMenuTask();
void gotoxy(int x, int y);
void searchSumBetweenNegativeNum();
void searchSumBetweenNegativeNum2();
int searchArea(int lenght, int width);
void swapMaxMinNumberRef(int& a, int& b, int& c);
void swapMaxMinNumberPtr(int* a, int* b, int* c);



#endif 
