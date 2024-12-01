#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <functional>
#include <chrono>

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
#define DISTANCE 4

using namespace std;

void bubbleSort(int arr[], int n) ;
void printArray(int arr[], int n);
void fillArrayUniqueRandom(int arr[], int n);
void fillArrayUniqueRandomDescending(int arr[], int n);
void fillArrayUniqueRandomAscending(int arr[], int n);
void shekerSort(int arr[], int n);
void blockSort(int arr[], int n);
void loadArrayFromFile(int*& arr, int& n, const string& filename);

#endif