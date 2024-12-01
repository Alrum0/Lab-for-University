#include "Header.h"

const char* vertexNames[N] = {"V1", "V2", "V3", "V4", "V5", "V6", "V7", "V8", "V9", "V10", "V11", "V12"};

bool readMatrixFromFile(int graph[N][N], const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка відкриття файлу." << RESET << endl;
        return false;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> graph[i][j];
        }
    }

    file.close();
    cout << GREEN << "Граф успішно зчитано з файлу." << RESET << endl;
    return true;
}




void printAdjacencyMatrix(int graph[N][N]) {
    cout << TABUL << CYAN << BOLD << "Матриця суміжності:" << RESET << endl;
    cout << TABLE << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] != 0) {
                cout << GREEN << graph[i][j] << "\t" << RESET;
            } else {
                cout << graph[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << TABLE << endl;
}




void saveAdjacencyMatrixToFile(int graph[N][N], const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка. Неможливо відкрити файл для запису." << RESET << endl;
        return;
    }

    file << TABUL << "Матриця суміжності:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file << graph[i][j] << "\t";
        }
        file << endl;
    }

    file.close();
    cout << GREEN << "Матриця успішно записана у файл: " << filename << endl;
}




void fillIncidenceMatrix(int graph[N][N], int incidence[N][100], int& edgeCount) {
    edgeCount = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 100; ++j) {
            incidence[i][j] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] != 0) {
                incidence[i][edgeCount] = graph[i][j]; 
                incidence[j][edgeCount] = -1 * graph[i][j]; 
                ++edgeCount;
            }
        }
    }
}


void printIncidenceMatrix(int graph[N][N], int incidence[N][100], int& edgeCount) {
    fillIncidenceMatrix(graph, incidence, edgeCount);

    cout << CYAN << INCEN << BOLD << "Матриця інцидентності:" << RESET << endl;
    cout << TABLE2 << endl;

    cout << "\t";
    for (int j = 0; j < edgeCount; ++j) {
        cout << "e" << j + 1 << "\t"; 
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        cout << vertexNames[i] << "\t"; 
        for (int j = 0; j < edgeCount; ++j) {
            if (incidence[i][j] != 0) {
                cout << GREEN << incidence[i][j] << RESET << "\t";
            } else {
                cout << incidence[i][j] << "\t"; 
            }
        }
        cout << endl;
    }
    cout << TABLE2 << endl;
}

void saveIncidenceMatrixToFile(int graph[N][N], int incidence[N][100], int vertexCount, int edgeCount, const string& filename) {
    fillIncidenceMatrix(graph, incidence, edgeCount);
    ofstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка. Неможливо відкрити файл для запису." << RESET << endl;
        return;
    }

    file << INCEN << "Матриця інцидентності" << endl;
    file << "\t"; 

    for (int j = 0; j < edgeCount; j++) {
        file << "e" << j + 1 << "\t";
    }
    file << endl;

    for (int i = 0; i < vertexCount; i++) {
        file << "V" << i + 1 << "\t"; 
        for (int j = 0; j < edgeCount; j++) {
            file << incidence[i][j] << "\t"; 
        }
        file << endl;
    }

    file.close();
    cout << GREEN << "Матриця успішно записана у файл: " << filename << RESET << endl;
}









void breadthFirstSearch(int graph[N][N], int start) {
    bool visited[N] = {false};
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "Обхід в ширину від вершини " << vertexNames[start] << ": ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << vertexNames[v] << " ";

        for (int i = 0; i < N; ++i) {
            if (graph[v][i] != 0 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

void depthFirstSearch(int graph[N][N], int start, bool visited[N]) {
    visited[start] = true;
    cout << vertexNames[start] << " ";

    for (int i = 0; i < N; ++i) {
        if (graph[start][i] != 0 && !visited[i]) {
            depthFirstSearch(graph, i, visited);
        }
    }
}

void depthFirstSearchWrapper(int graph[N][N], int start) {
    bool visited[N] = {false};
    cout << "Обхід в глибину від вершини " << vertexNames[start] << ": ";
    depthFirstSearch(graph, start, visited);
    cout << endl;
}



void dijkstra(int graph[N][N], int start) {
    int dist[N];
    bool visited[N] = {false};
    int prev[N];

    for (int i = 0; i < N; ++i) {
        dist[i] = INT_MAX;
        prev[i] = -1; 
    }
    dist[start] = 0;

    for (int i = 0; i < N; ++i) {
        int minDist = INT_MAX, u = -1;
        for (int j = 0; j < N; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;

        visited[u] = true;
        for (int v = 0; v < N; ++v) {
            if (graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u; 
            }
        }
    }

    cout << "Найкоротші шляхи від вершини " << vertexNames[start] << ":" << endl;
    for (int i = 0; i < N; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Вершина " << vertexNames[i] << ": Немає шляху" << endl;
        } else {
            vector<int> path;
            for (int at = i; at != -1; at = prev[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            
            cout << "Вершина ";
            for (size_t j = 0; j < path.size(); ++j) {
                cout << vertexNames[path[j]];
                if (j < path.size() - 1) cout << " -> ";
            }
            cout << " (Вага: " << dist[i] << ")" << endl;
        }
    }
}

void floydWarshall(int graph[N][N]) {
    int dist[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = graph[i][j] == 0 ? INT_MAX : graph[i][j];
        }
    }

    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Матриця найкоротших шляхів між усіма парами вершин:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "NO\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void printAdjacencyList(int graph[N][N]) {
    for (int i = 0; i < N; ++i) {
        cout << "Вершина " << i + 1 << ": ";
        for (int j = 0; j < N; ++j) {
            if (graph[i][j] != 0) {
                cout << j + 1 << " ";
            }
        }
        cout << endl;
    }
}

void saveAdjacencyListToFile(int graph[N][N], const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < N; ++i) {
            file << "Вершина " << i + 1 << ": ";
            for (int j = 0; j < N; ++j) {
                if (graph[i][j] != 0) {
                    file << j + 1 << " ";
                }
            }
            file << endl;
        }
        file.close();
         cout << GREEN << "Матриця успішно записана у файл: " << filename << RESET << endl;
    } else {
        cout << "Не вдалося відкрити файл для запису." << endl;
    }
}

void printEdgeListFromIncidenceMatrix(int incidence[N][100], int edgeCount) {
    cout << "Список ребер графа:" << endl;
    for (int e = 0; e < edgeCount; ++e) {
        int vertex1 = -1, vertex2 = -1;
        for (int i = 0; i < N; ++i) {
            if (incidence[i][e] != 0) {
                if (vertex1 == -1) {
                    vertex1 = i; 
                } else {
                    vertex2 = i; 
                    break; 
                }
            }
        }
        
        if (vertex1 != -1 && vertex2 != -1) {
            int weight = abs(incidence[vertex1][e]); 
            cout << "Ребро " << vertex1 + 1 << " -> " << vertex2 + 1 << " (вага: " << weight << ")" << endl;
        }
    }
}

void saveEdgeListToFile(int incidence[N][100], int edgeCount, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка: не вдалося відкрити файл для запису." << RESET << endl;
        return;
    }

    file << "Список ребер графа:" << endl;
    for (int e = 0; e < edgeCount; ++e) {
        int vertex1 = -1, vertex2 = -1;
        for (int i = 0; i < N; ++i) {
            if (incidence[i][e] != 0) {
                if (vertex1 == -1) {
                    vertex1 = i; 
                } else {
                    vertex2 = i; 
                    break;
                }
            }
        }

        if (vertex1 != -1 && vertex2 != -1) {
            int weight = abs(incidence[vertex1][e]); 
            file << "Ребро " << vertex1 + 1 << " -> " << vertex2 + 1 << " (вага: " << weight << ")" << endl;
        }
    }

    file.close();
    cout << GREEN << "Список ребер успішно записано у файл: " << filename << RESET << endl;
}

void incidenceToAdjacencyMatrix(int incidence[N][100], int adjacency[N][N], int edgeCount) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            adjacency[i][j] = 0;
        }
    }

    for (int e = 0; e < edgeCount; ++e) {
        int startVertex = -1, endVertex = -1;

        for (int i = 0; i < N; ++i) {
            if (incidence[i][e] == 1) {
                startVertex = i; 
            } else if (incidence[i][e] == -1) {
                endVertex = i; 
            }
        }

        if (startVertex != -1 && endVertex != -1) {
            adjacency[startVertex][endVertex] = 1; 
        } else if (startVertex != -1) {
            adjacency[startVertex][startVertex] = 1; 
        }
    }
}