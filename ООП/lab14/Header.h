#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>

using namespace std;

#define DISTANCE 19
#define N 3
#define CHOISE 2
#define USE_CONSTRUCTOR 1 // 1 - default, 2 - constructor with arguments 3 - constructor of copy
#define LOW_BOUND 1
#define HIGH_BOUND 100
#define INPUT_TYPE 1 // 1 - from console, 2 - random

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


	Space() : spectralClass('A'), mass(0), part(0), num(0) {};
	Space(char spectralClass, float mass, float part, long num) : spectralClass(spectralClass), mass(mass), part(part), num(num) {};
	Space(const Space& other) : spectralClass(other.spectralClass), mass(other.mass), part(other.part), num(other.num) {};

	Space& operator=(const Space& space);
	bool operator==(const Space& space) const;
	Space operator+(const Space& space) const;
	friend Space operator+(const Space& space1, const Space& space2);
	friend bool operator==(const Space& space1, const Space& space2);
	friend ostream& operator<<(ostream& out, const Space& space);
	friend istream& operator>>(istream& in, Space& space);
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
	Complex(int m, int i) : material(m), imaginary(i) {}

	void add(int r, int m);
	Complex add(const Complex& othter);
	void print();
};


class Dog {
private:
	string name;
	double weight;
	int age;
public:
	Dog() : name(""), weight(0), age(0) {}
	Dog(string name, double weight, int age) : name(name), weight(weight), age(age) {}

	string getName();
	double getWeight();
	int getAge();

	void setName(string name);
	void setWeight(double weight);
	void setAge(int age);
};

class Master {
private:
	string name;
	const int ID;
	Dog* dogs;
	int dogCount;
	Master* owner1;
public:
	static int count;

	Master() : name(""), ID(0), dogs(nullptr), dogCount(0) {}
	Master(string name, int ID) : name(name), ID(ID), dogs(nullptr), dogCount(0) {}
	~Master();

	int getID();
	void addDog(const Dog& dog);
	void removeDog(int index);
	void displayDogs();

	void addToOwner(Master& owner);
	void removeDogFromOwner(Master& owner);
	void editDog(int index);


};

class Menu {
private:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	
	void menuShowGeneral();
	void menuForTask4();
};

class Task1 {
private:
	char spectralClass;
	float mass, part;
	long num;
	Space spaces[N];
	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
	void activeTask();
};

class Task2 {
private:
	Figure kr;
	Figure tr;
public:
	Task2(double radius, double height, double base) : kr(radius), tr(height, base) {}

	double activeTask2();
};

class Task3 {
private:
	Complex num1;
	Complex num2;
	Complex sum;
public:
	Task3() : num1(11, 4), num2(2, 3), sum(num1.add(num2)) {}

	void activeTask3();
};

//class Task {
//private:
//	char spectralClass;
//	float mass, part;
//	long num;
//	Space spaces[N];
//	string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//
//	Figure kr;
//	Figure tr;
//
//	Complex num1;
//	Complex num2;
//	Complex sum = num1.add(num2);;
//public:
//	void activeTask();
//
//	Task(double radius, double height, double base) : kr(radius), tr(height, base) {}
//	double activeTask2();
//
//	Task() : num1(11, 4), num2(2, 3), sum(num1.add(num2)) {}
//	void activeTask3();
//};

#endif 
