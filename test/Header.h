#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <ctime>

using namespace std;

#define DISTANCE 19
#define N 3
#define CHOISE 2
#define USE_CONSTRUCTOR 1 // 1 - default, 2 - constructor with arguments 3 - constructor of copy
#define LOW_BOUND 1
#define HIGH_BOUND 100
#define INPUT_TYPE 2 // 1 - from console, 2 - random

void gotoxy(int x, int y);

class Space {
private:
	char spectralClass;
	float mass;
	float part;
	long num;

public:
	static Space originalSpaces[N];

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

	void activeTask();

	Space() : spectralClass('B'), mass(0), part(0), num(0) {};
	Space(char spectralClass, float mass, float part, long num) : spectralClass(spectralClass), mass(mass), part(part), num(num) {};
	Space(const Space& other) : spectralClass(other.spectralClass), mass(other.mass), part(other.part), num(other.num) {};

	Space& operator=(const Space& space);
	bool operator==(const Space& space) const;
	Space operator+(const Space& space) const;
	/*friend Space operator+(const Space& space1, const Space& space2);*/
	/*friend bool operator==(const Space& space1, const Space& space2);*/
	friend ostream& operator<<(ostream& out, const Space& space);
	friend istream& operator>>(istream& in, Space& space);
	Space operator()(char spectralClass, float mass, float part, long num);
	char operator[](int num);
	
	bool operator!=(const Space& space) const {
		return !(*this == space);
	}


};

#endif
