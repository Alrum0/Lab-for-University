#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>

using namespace std;

#define distance 19
#define N 3
#define CHOISE 2

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


class Dog {
private:
	string name;
	double weight;
	int age;
public:
	Dog() : name(""), weight(0), age(0){}
	Dog(string name, double weight, int age) : name(name), weight(weight), age(age){}

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

	Master() : name(""), ID(0), dogs(nullptr), dogCount(0){}
	Master(string name, int ID) : name(name), ID(ID), dogs(nullptr), dogCount(0){}
	~Master();

	int getID();
	void addDog(const Dog& dog);
	void removeDog(int index);
	void displayDogs();

	void addToOwner(Master& owner);
	void removeDogFromOwner(Master& owner);

	void menuDog(Master& owner);

};

#endif 
