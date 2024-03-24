#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Space{
	char spectralClass;
	float mass;
	float part;
	int num;
};


void gotoxy(int x, int y);
void fillStructure();
void sortStructure();
void printStructure();


#endif 

