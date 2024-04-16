#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>

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
	double radius; 
	double height; 
	double base;   
public:
	
	Figure(double r) : radius(r), height(0), base(0) {}
	Figure(double h, double b) : radius(0), height(h), base(b) {}

	double circleArea();

	double triangleArea();
};

class Complex {
private:
	int material;
	int imaginary;
public:
	Complex(int m, int i) : material(m), imaginary(i){}

	void add(int r, int m);
	Complex add(const Complex& othter);
	void print();
};

#endif 
