#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

#define distance 19
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
	void setSpectralClass(char SpectralClass);

	float getMass();
	void setMass(float mass);

	float getPart();
	void setPart(float part);

	auto getNum();
	void setNum(long num);
	
	void showUp();
	void showDown();
	void show();

	void input();

	/*Space(char spectralClass = 'M', float mass = 0.2, double part = 73.2, long num = 23000000);*/
};


#endif 
