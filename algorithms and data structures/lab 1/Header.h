#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <fstream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define CYAN "\033[36m"      // Блакитний
#define MAGENTA "\033[35m"   // Пурпуровий
#define WHITE "\033[37m"   
#define BLACK "\033[30m"     
#define BOLD "\033[1m"       // Жирний текст
#define UNDERLINE "\033[4m"

#define DISTANCE 3


using namespace std;



struct Single_List {
    int data;
    Single_List *next;

};


struct Double_list {
    int data;
    Double_list* next;
    Double_list* prev;

};



class SINGL_LIST {
protected:
    Single_List* head;
public:
    SINGL_LIST() : head(nullptr) {}

    Single_List* getHead() const { return head; }

    void makeSingleList(int n);
    void addElements(int val);
    void removeElements(int val);
    void swapElements(int pos);
    int countElements();
    void clearList();
    void displayList(Single_List* Head);
    void writeToFile(const string& filename);

//    ~SINGL_LIST();
};

class DOUBLE_LIST {
protected:
    Double_list* head;
public:
    DOUBLE_LIST() : head(nullptr) {}

    Double_list* getHead() const { return head; }

    void makeDoubleList(int n);
    void addElements(int val);
    void removeElements(int val);
    void swapElements(int pos);
    int countElements();
    void clearList();
    void displayList(Double_list* Head);
    void writeToFile(const string& filename);
};


class MENU_SINGL_LIST : public SINGL_LIST {
public:
    int n;
    int a;
    int value;
    int val;
    int choose;
    int pos;
    string fileName;
    SINGL_LIST list;
    

    void menu();
    void writeMyself();
    void scanWithFile();
};

class MENU_DOUBLE_LIST : public DOUBLE_LIST {
public:
    int n;
    int a;
    int val;
    int pos;
    int choose;
    int value;
    string fileName;
    DOUBLE_LIST list;

    
    void menu();
    void writeMyself();
    void scanWithFile();
};

class MENU {
public:
    MENU_SINGL_LIST menu;
    MENU_DOUBLE_LIST menu2;
    int choose;
    void menuAct();
};



#endif