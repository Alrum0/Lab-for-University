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



typedef int (*func_ptr)(int arr[], int a);
typedef bool (*CompareFunction)(int a, int b);

void switchMenuTask();
void gotoxy(int x, int y);
void searchSumBetweenNegativeNum();
void searchSumBetweenNegativeNum2();
void swapMaxMinNumberRef(int& a, int& b, int& c);
void swapMaxMinNumberPtr(int* a, int* b, int* c);
int f(int lenght, int width);
int* f(int** A, int n, int m, int* min, int* max, int* S, int* P);
int sumPositiveNum(int arr[], int a);
int productNegativeNum(int arr[], int a);
void sortArray(int arr[], int size, CompareFunction cmp);
bool ascending(int a, int b);
bool descending(int a, int b);


#endif 
