#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#define MAX_COUNT 15
#define MIN_COUNT 5
#define MAX_AGE 50
#define MIN_AGE 20
#define TYPE 3
#define DEGREE 3
#define MAX_NAMES 10
#define MAX_LAST_NAMES 10
#define MAX_DISCIPLINES 10



using namespace std;


class B {
private:
	string b_p = "I`m private B";
protected:
	string b_pr = "I`m protected B";
public:
	string b_pub = "I`m public B";
	virtual void show() {
		cout << "class B: " << b_p << " " << b_pr << " " << b_pub <<endl;
		cout << "_______________________________________________" <<endl;
	}
	string getB_p() { return b_p; }
};
class D1 :public B{
private:
	string d_p = "I`m private D";
protected:
	string d_pr = "I`m protected D";
public:
	string d_pub = "I`m public D";
	void show() override{
		cout << "Class B:" << getB_p() << b_pr << b_pub <<endl;
		cout << "Class D1: " << d_p << " " << d_pr << " " << d_pub <<endl;
		cout << "_______________________________________________" <<endl;
	}
	string getD_p() { return d_p; }
};
class D2 :private B {
private:
	string d2_p = "I`m private D2";
protected:
	string d2_pr = "I`m protected D2";
public:
	string d2_pub = "I`m public D2";
	void show() override{
		cout << "Class B: " << getB_p() << b_pr << b_pub <<endl;
		cout << "Class D2: " << d2_p << " " << d2_pr << " " << d2_pub <<endl;
		cout << "_______________________________________________" <<endl;
	}
	string getD2_p() { return d2_p; }

	string get2Db_p() { return getB_p(); }
	string getB_pr() { return b_pr; }
	string getB_pub() { return b_pub; }
};
class D3 :private B {
private:
	string d3_p = "I`m private D3";
protected:
	string d3_pr = "I`m protected D3";
public:
	string d3_pub = "I`m public D3";
	void show() override{
		cout << "Class B: " << getB_p() << b_pr << b_pub <<endl;
		cout << "Class D3: " << d3_p << " " << d3_pr << " " << d3_pub <<endl;
		cout << "_______________________________________________" <<endl;
	}
	string getD3_p() { return d3_p; }
};
class D4 :private D1 {
private:
	string d4_p = "I`m private D4";
protected:
	string d4_pr = "I`m protected D4";
public:
	string d4_pub = "I`m public D4";
	void show() override{
		cout << "class B: " << getB_p() << " " << b_pr << " " << b_pub << endl;
		cout << "Class D1: " << getD_p() << " " << d_pr << " " << d_pub <<endl;
		cout << "Class D4: " << d4_p << " " << d4_pr << " " << d4_pub <<endl;
		cout << "_______________________________________________" <<endl;
	}
};


class D5 :public D2, private D3 {
private:
	string d5_p = "I`m private D5";
protected:
	string d5_pr = "I`m protected D5";
public:
	string d5_pub = "I`m public D5";
	void show() override{
		cout << "class B: " << get2Db_p() << " " << getB_pr() << " " << getB_pub() << endl;
		cout << "Class D2: " << getD2_p() << " " << d2_pr << " " << d2_pub <<endl;
		cout << "Class D3: " << getD3_p() << " " << d3_pr << " " << d3_pub <<endl;
		cout << "Class D5: " << d5_p << " " << d5_pr << " " << d5_pub <<endl;
	}
};

class SOBAKA {
protected:
	double weight;
	int age;
public:
	SOBAKA(double weight, int age) : weight(weight), age(age){}
	void show();
	void K();
	void D();
	virtual void golos();
};

class SPANIEL :public SOBAKA {
protected:
	string color;
public:
	SPANIEL(double weight, int age, string color) : SOBAKA(weight, age), color(color){}
	void show();
	void golos() override;
	void K();
	void D();
};

class DOG :public SOBAKA {
protected:
	double height;
public:
	DOG(double weight, int age, double height) : SOBAKA(weight, age), height(height){}
	void show();
	void golos() override;
	void K();
	void D();
};

class BOOK {
protected:
	string title;
	string author;
	int pages;
	bool available; 
public:
	BOOK(string title, string author, int pages) : title(title), author(author), pages(pages), available(true) {}

	void printInfo() const;

	string getTitle() const { return title; }
	bool isAvailable() const { return available; } 
	void borrowBook() { available = false; } 
	void returnBook() { available = true; } 
};

class LIBRARY {
public:
	void printLibraryBooks(const vector<BOOK>& books) const;
	void borrowBook(vector<BOOK>& books);
	void returnBook(vector<BOOK>& books);
};

class Persona {
protected:
	string name;
	int age;
public:
	Persona(string n, int a) : name(n), age(a) {}
	virtual void print() const = 0;
	virtual int who() const = 0;
	virtual int ask() const = 0;
	int getAge() const;
};


class Prepod : public Persona {
protected:
	string discipline;
	int degree;
public:
	Prepod(string n, int a, string d, int deg) : Persona(n, a), discipline(d), degree(deg) {}
	void print() const override;
	int who() const override;
	int ask() const override;
};

class Student : public Persona {
protected:
	int marks[5];
public:
	Student(string n, int a) : Persona(n, a) {
		for (int i = 0; i < 5; ++i) {
			marks[i] = rand() % 4 + 2;
		}
	}
	void print() const override;
	int who() const override;
	int ask() const override;
};


class Zav_kaf : public Prepod {
	string position;
public:
	Zav_kaf(string n, int a, string d, int deg, string pos) : Prepod(n, a, d, deg), position(pos) {}
	void print() const override;
	int who() const override;
	int ask() const override;
};

class VUZ {
public:
	vector<Persona*> Shtat;
	vector<string> Names;
	void addPersona(Persona* p) {
		Shtat.push_back(p);
	}
	void generateRandomData();
	void printTeachersUnder50() const;
	void printStudents() const;
	void printTeachers() const;
	void printStudentsWithDebt() const;
};


class Starter {
public:
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	static void main();
	static void task1();
	static void task3();
	static void task4();
};

class Menu {
protected:
	int choose;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
public:
	void MenuAct();
};






#endif
