#include "Header.h"


void menu() {
    int choose;
    string filename;
    int edgeCount = 0;
    int incidence[N][100] = {0};

    int startVertex;
    int adjacencyMatrix[N][N];

    int graph[N][N] = {
        0,5,0,0,0,0,0,0,0,0,0,0,
        0,0,12,0,0,2,0,0,0,0,0,0,
        0,0,0,9,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,2,0,
        0,0,0,12,0,0,0,0,0,0,0,0,
        0,0,0,0,8,0,0,0,0,0,0,5,
        0,0,0,0,0,7,0,10,0,0,0,0,
        0,0,0,0,0,6,0,0,11,0,0,0,
        0,0,0,0,0,0,0,0,0,6,0,0,
        0,0,0,0,0,0,0,0,0,0,5,0,
        0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,7,2,0,0,4,0,9,0,0
   };

    do {
        cout << TABUL << CYAN << BOLD << "=== M E N U ===" << RESET << endl; 
        cout << "1. За матрицею суміжності побудувати побудувати матрицю інцидентності" << endl;
        cout << "2. За маторицею інцидентності побудувати матрицю суміжності" << endl;
        cout << "3. За маторицею суміжності побудувати список суміжності" << endl;
        cout << "4. За маторицею інцидентності побудувати список ребер" << endl;
        cout << "5. Обхід в ширину" << endl;
        cout << "6. Обхід в глубину" << endl;
        cout << "7. Знайти найкоротші шляхи до всіх вершин від заданої (Дейкстри)" << endl;
        cout << "8. Знайти найкоротші між усіма парами вершин (Флойда)" << endl;
        cout << "9. Записати матрицю суміжності в файл" << endl;
        cout << "10. Записати матрицю інцидентності в файл" << endl;
        cout << "11. Записати список суміжності в файл" << endl;
        cout << "12. Записати список ребер в файл" << endl;
        cout << RED << "0. Вихід" << RESET << endl;

        cout << "Виберіть опцію: ";
        cin >> choose;

        switch (choose) {
        case 1:
            printIncidenceMatrix(graph, incidence, edgeCount);
            break;
        case 2:
            incidenceToAdjacencyMatrix(incidence, adjacencyMatrix, edgeCount);
            cout << "Матриця суміжності побудована за матрицею інцидентності:" << endl;
            printAdjacencyMatrix(graph);
            break;
        case 3:
            printAdjacencyList(graph);
            break;
        case 4:
            printEdgeListFromIncidenceMatrix(incidence, edgeCount);           
            break;
        case 5:
            cout << "Введіть номер початкової вершини для обходу в ширину (1 - " << N << "): ";
            cin >> startVertex;
            breadthFirstSearch(graph, startVertex - 1);
            break;
        case 6:
            cout << "Введіть номер початкової вершини для обходу в глибину (1 - " << N << "): ";
            cin >> startVertex;
            depthFirstSearchWrapper(graph, startVertex - 1);
            break;
        case 7:
            cout << "Введіть номер початкової вершини для Дейкстри (1 - " << N << "): ";
            cin >> startVertex;
            dijkstra(graph, startVertex - 1);
            break;
        case 8:
            floydWarshall(graph);
            break;
        case 9:
            cout << "Введіть назву файлу: ";
            cin >> filename;
            saveAdjacencyMatrixToFile(graph, filename);
            break;
        case 10:
            cout << "Введіть назву файлу: ";
            cin >> filename;
            saveIncidenceMatrixToFile(graph, incidence, N, edgeCount, filename);
            break;
        case 11:
            cout << "Введіть назву файлу: ";
            cin >> filename;
            saveAdjacencyListToFile(graph, filename);
            break;
        case 12:
            cout << "Введіть назву файлу: ";
            cin >> filename;
            saveEdgeListToFile(incidence, edgeCount, filename);
            break;
        default:
            break;
        }
    } while (choose != 0);

}