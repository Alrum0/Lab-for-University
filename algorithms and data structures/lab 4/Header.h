#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <functional>

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
#define TABUL "\t\t\t\t"
#define DISTANCE 3

using namespace std;


struct hash_node_2 {
	int key;
	bool is_empty;
	hash_node_2* next;

    hash_node_2() : is_empty(true), next(NULL) {}
};

struct hash_node {
	int key;
	bool is_empty;

    hash_node() : is_empty(true) {}
};

void task1_menu();
void task2_menu();
void task3_help_menu();


#endif // HEADER_H