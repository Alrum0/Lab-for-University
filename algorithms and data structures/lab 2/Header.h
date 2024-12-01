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
#define TABUL "\t\t\t\t"
#define MAX_SIZE 100

using namespace std;


struct StackData {
    short data[MAX_SIZE];
    int top;

    StackData() : top(-1) {}
};

struct Queue {
    short data[MAX_SIZE];
    short front;
    short rear;
    short size;

     Queue() : front(0), rear(-1), size(0) {}
};

struct Deque {
    short data[MAX_SIZE];
    int front;
    int rear;
    int size;

    Deque() : front(0), rear(-1), size(0) {}
};

class STACK_OPERATIONS {
public:
    bool isEmty(const StackData& stack);
    bool isFull(const StackData& stack);
    void push(StackData& stack, short value);
    short pop(StackData& stack);
    short peek(const StackData& stack);
    void swap_first_last(StackData& stack);
    void reverse(StackData& stack);
    void delete_every_second(StackData& stack);
    void insert_after_max(StackData& stack);
    void delete_min(StackData& stack);
    void delete_all_except_first(StackData& stack);
    void delete_all_except_last(StackData& stack);
    void print(const StackData& stack);
    void readDataFromFile(StackData& stack, const string& filename, STACK_OPERATIONS& operations);

};


class QUEUE_OPERATIONS {
public:
    void initQueue(Queue& q);
    bool isEmty(const Queue& q);
    bool isFull(const Queue& q);
    void enqueue(Queue& q, short value);
    short dequeu(Queue& q);
    void printSize(const Queue& q);
    void printAvarage(const Queue& q);
    void printMinMax(const Queue& q);
    void printElementBeforeMin(const Queue& q);
    void printQueue(const Queue& q);
    void enqueueFromFile(Queue& q, const string& filename, QUEUE_OPERATIONS& operations);
    void enqueueToFile(const Queue& q, const string& filename);
};


class DEQUE_OPERATIONS {
public:
    void initDeque(Deque& deque);
    bool isEmty(const Deque& deque);
    bool isFull(const Deque& deque);
    void addFront(Deque& deque, short value);
    void addRear(Deque& deque, short value);
    short getRear(const Deque& deque);
    void readDataFromFile(Deque& deque, const string& filename);
    void writeDequeToFile(const Deque& deque, const string& filename);
    void printDeque(const Deque& deque);
};

class MENU_STACK {
public:
    STACK_OPERATIONS stk;
    StackData stack;
    int a;
    short value;
    int choose;
    string filename;

    void menu();
};

class MENU_QUEUE {
public:
    QUEUE_OPERATIONS que;
    Queue q;
    short value;
    int a;
    int choose;
    string filename;

    void menu();
};

class MENU_DEQUE {
public:
    Deque deque;
    DEQUE_OPERATIONS deq;
    short value;
    int a;
    int choose;
    string filename;

    void menu();
};


class MENU {
public:
    MENU_STACK menu;
    MENU_QUEUE menu2;
    MENU_DEQUE menu3;
    int choose;
    void menuAct();
};

#endif