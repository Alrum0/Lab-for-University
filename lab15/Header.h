#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
#include <iostream>
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

class Starter {
public:
	static void main() {
		D4 d4;
		D5 d5;
		cout << "CONTENT OF CLASS D4:" << endl;
		d4.show();
		cout << "CONTENT OF CLASS D5:" << endl;
		d5.show();
	}
};





















//class Person {
//private:
//	string name;
//	int age;
//public:
//	virtual void print() = 0;
//	virtual int who() = 0;
//	virtual string ask() = 0;
//
//	string getname();
//		int getage();
//
//	void setname(string name) { this->name = name; }
//	void setage(string name) { this->name = name; }
//};
//
//class Prepod :public Person {
//private:
//	string subject;
//	string quality;
//public:
//	virtual int who() { return 1; }
//	virtual string ask() { return quality; }
//	virtual void print() {}
//};


//class Student :public Person {
//private:
//	int marks[5];
//public:
//	virtual int who() { return 2; }
//	virtual int ask() {}
//	virtual void print() {}
//};




#endif
