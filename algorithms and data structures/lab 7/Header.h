#ifndef HEADER_H
#define HEADER_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <functional>
#include <chrono>
#include <string>
#include <sstream>

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
#define INCEN "\t\t\t\t\t\t\t"
#define DISTANCE 4
#define TABLE "========================================================================================="
#define TABLE2 "==================================================================================================================================================="

using namespace std;

#define N 12


void saveAdjacencyMatrixToFile(int graph[N][N], const string& filename);
void printIncidenceMatrix(int graph[N][N], int incidence[N][100], int& edgeCount);
void saveIncidenceMatrixToFile(int graph[N][N], int incidence[N][100], int vertexCount, int edgeCount, const string& filename);
//==============================
void menu();
bool readMatrixFromFile(int graph[N][N], const string& filename);

void printIncidenceMatrixx(int graph[N][N]);
void printAdjacencyMatrix(int graph[N][N]);
void printMatrix(int graph[N][N]);

void loadAndPrintIncidenceMatrix(const string& filename);





void breadthFirstSearch(int graph[N][N], int start);
void depthFirstSearchWrapper(int graph[N][N], int start);
void dijkstra(int graph[N][N], int start);
void floydWarshall(int graph[N][N]);
void printAdjacencyList(int graph[N][N]);
void saveAdjacencyListToFile(int graph[N][N], const string& filename);
void printEdgeListFromIncidenceMatrix(int incidence[N][100], int edgeCount);
void saveEdgeListToFile(int incidence[N][100], int edgeCount, const string& filename);
void incidenceToAdjacencyMatrix(int incidence[N][100], int adjacency[N][N], int edgeCount);
#endif