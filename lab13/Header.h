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

	Space() : spectralClass('A'), mass(0), part(0), num(0) {}; //конструктор за умовченням
	Space(char spectralClass, float mass, float part, long num) : spectralClass(spectralClass), mass(mass), part(part), num(num) {};// конструктор з аргументами
	Space(const Space& other) : spectralClass(other.spectralClass), mass(other.mass), part(other.part), num(other.num) {}; //конструктор копіювання
};

class Figure {
private:
	float radius;
	const double PI = 3.14159;
	float height;
	float l;
public:
	double circleArea() const;
	double triangleArea() const;

	Figure(double r = 0, double h = 0, double b = 0) : radius(r), height(h), l(b) {}

};



#endif 
