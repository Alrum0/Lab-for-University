#ifndef HEADER_H
#define HEADER_H


#include <iomanip>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>

#define DISTANCE 19
#define N 10
#define CHOISE 2
#define USE_CONSTRUCTOR 1 // 1 - default, 2 - constructor with arguments 3 - constructor of copy
#define LOW_BOUND 1
#define HIGH_BOUND 100
#define INPUT_TYPE 2 // 1 - from console, 2 - random
#define CHOOSE_TYPE 1 // 1 - work with .txt 2 - work binary


using namespace std;

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


	static void saveObjectToFile(const string& filename);
	static void saveArrayToFile(Space spaces[], int size, const string& filename);
	static vector<Space> readObjectsFromFile(const string& filename);
	void removeInfo(const string& filename);
	void saveObjectToFile(string& filename);

	Space() : spectralClass('A'), mass(0), part(0), num(0) {};
	Space(char spectralClass, float mass, float part, long num) : spectralClass(spectralClass), mass(mass), part(part), num(num) {};
	Space(const Space& other) : spectralClass(other.spectralClass), mass(other.mass), part(other.part), num(other.num) {};

};


class COMP {
private:
	float real;
	float imag;
public:
	COMP(): real(0), imag(0){}
	COMP(float real, float imag) : real(real), imag(imag) {}

	float getReal() const;
	float getImag()const;
	void read(ifstream& inFout);
	void write(ofstream& outFout);
	void add(const COMP& other);
	friend ostream& operator<<(ostream& os, const COMP& c);
};










class Starter {
public:
	static void task1();
	static void task2();
	static void task3();
};

class Menu {
protected:
	int inputNum;
public:
	void MenuActive();
};

#endif
