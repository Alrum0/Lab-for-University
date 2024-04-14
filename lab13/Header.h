#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

#define distance 16
#define N 3

void switchMenuTask();
void gotoxy(int x, int y);



class Space {
private:
	char spectralClass;
	float mass;
	float part;
	long num;
public:
	char getSpectralClass();
	float getMass();
	float getPart();
	auto getNum();

	void setSpectralClass(char SpectralClass);
	void setMass(float mass);
	void setPart(float part);
	void setNum(long num);

	void showUp();
	void showDown();
	void show();
};


#endif 
