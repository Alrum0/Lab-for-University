#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	virtual void print() = 0;
	virtual int who() = 0;
	virtual string ask() = 0;

	string getname();
		int getage();

	void setname(string name) { this->name = name; }
	void setage(string name) { this->name = name; }
};

class Prepod :public Person {
private:
	string subject;
	string quality;
public:
	virtual int who() { return 1; }
	virtual string ask() { return quality; }
	virtual void print() {}
};


class Student :public Person {
private:
	int marks[5];
public:
	virtual int who() { return 2; }
	virtual int ask() {}
	virtual void print() {}
};




#endif
