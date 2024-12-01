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

struct Node {
    string lastName;
    int passportNumber;
    int age;
    Node* left;
    Node* right;
    Node* parent;
    bool color; // true - red, false - black

    Node(string n, int p, int a)
        : lastName(n), passportNumber(p), age(a), left(nullptr), right(nullptr), parent(nullptr), color(true) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    Node* insert(Node* node, string lastName, int passportNumber, int age) {
        if (node == nullptr) {
            return new Node(lastName, passportNumber, age);
        }
        if (lastName < node->lastName) {
            node->left = insert(node->left, lastName, passportNumber, age);
        } else {
            node->right = insert(node->right, lastName, passportNumber, age);
        }
        return node;
    }

     Node* insertRec(Node* node, string lastName, int passportNumber, int age) {
        if (node == nullptr) {
            return new Node(lastName, passportNumber, age);
        }
        if (age < node->age) {
            node->left = insertRec(node->left, lastName, passportNumber, age);
        } else {
            node->right = insertRec(node->right, lastName, passportNumber, age);
        }
        return node;
    }

    void addPerson(string lastName, int passportNumber, int age);
    void addPersonRec(string lastName, int passportNumber, int age);
    void displayPreOrder(Node* node);
    void displayInOrder(Node* node);
    void displayPostOrder(Node* node);
    void displayTree(Node* node, string prefix = "", bool isLeft = true);
    void showFullTree();
    void deleteLeftSubtree(Node* node);
    void deleteRightSubtree(Node* node);
    double calculateAverage(Node* node, int& count);
    void printAverage();
    void deleteTree(Node* node);
    void clear();

    void transferData(BinaryTree& newTree, bool byAge);
    void transferData(Node* node, BinaryTree& newTree, bool byAge);

    void loadFromFile(const string& filename);
    void saveTreeToFile(const string& filename);
    void writeNodeToFile(Node* node, ofstream& file, string prefix = "", bool isLeft = true);

//---------------

};
    

class RBTree {
public:
    Node* root;

    RBTree() : root(nullptr) {}

    void transferTree(Node* node);
    void insert(Node* node);
    void balanceTree(Node* node);
    void displayTree(Node* node, string prefix = "", bool isLeft = true);
    void rotateRight(Node* node);
    void rotateLeft(Node* node);
    void clear();
    void deleteTree(Node* node);

    Node* findNodeByLastName(Node* node, const string& lastName);
    void deleteNode(Node* node);
    void balanceDelete(Node* x, Node* xParent);
    void transplant(Node* u, Node* v);
    Node* minimum(Node* node);
};



class Menu {
public:
    BinaryTree tree;
    BinaryTree newTree;
    RBTree rbTree;
    int choose;
    int a;

    string filename;
    string surname;
    int passportNumber, age;
    int criteria;
    Node* nodeToDelete;

    void menu();

};

#endif