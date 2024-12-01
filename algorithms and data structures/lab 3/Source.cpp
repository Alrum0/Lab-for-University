#include "Header.h"

void BinaryTree::addPerson(string lastName, int passportNumber, int age) {
    root = insert(root, lastName, passportNumber, age);
}
void BinaryTree::addPersonRec(string lastName, int passportNumber, int age) {
    root = insertRec(root, lastName, passportNumber, age);
}
void BinaryTree::displayPreOrder(Node* node) {
    if (node == nullptr) return;
    cout << node->lastName << " (Паспорт: " << node->passportNumber << ", Вік: " << node->age << ")" << endl;
    displayPreOrder(node->left);
    displayPreOrder(node->right);
}
void BinaryTree::displayInOrder(Node* node) {
    if (node == nullptr) return;
    displayInOrder(node->left);
    cout << node->lastName << " (Паспорт: " << node->passportNumber << ", Вік: " << node->age <<")" << endl;
    displayInOrder(node->right);
}
void BinaryTree::displayPostOrder(Node* node) {
    if (node == nullptr) return;
    displayPostOrder(node->left);
    displayPostOrder(node->right);
    cout << node->lastName << " (Паспорт: " << node->passportNumber << ", Вік: " << node->age << ")" << endl;
}
void BinaryTree::displayTree(Node* node, string prefix, bool isLeft) {
        if (node == nullptr) return;

        if (node->left != nullptr) {
            displayTree(node->left, prefix + (isLeft ? "    " : "     "), true);
            cout << prefix << "   /\n";
        }

        cout << prefix << node->lastName << "(Паспорт: " << node->passportNumber << ", Вік: " << node->age << ")" << endl;

        if (node->right != nullptr) {
            cout << prefix << "   \\\n"; 
            displayTree(node->right, prefix + (isLeft ? "    " : "     "), false);
        }
    }
void BinaryTree::showFullTree() {
    if (root == nullptr) {
            cout << "Дерево порожнє.\n";
        } else {
            cout << "Повне дерево:\n";
            displayTree(root);
        }
}
void BinaryTree::deleteLeftSubtree(Node* node) {
    if (node != nullptr && node->left != nullptr) {
            deleteTree(node->left);
            node->left = nullptr;
            cout << "Ліве піддерево видалено.\n";
        } else {
            cout << "Лівого піддерева не існує.\n";
        }
}
void BinaryTree::deleteRightSubtree(Node* node) {
    if (node != nullptr && node->right != nullptr) {
            deleteTree(node->right);
            node->right = nullptr;
            cout << "Праве піддерево видалено.\n";
        } else {
            cout << "Правого піддерева не існує.\n";
        }
}
double BinaryTree::calculateAverage(Node* node, int& count) {
    if (node == nullptr) return 0;
    double leftSum = calculateAverage(node->left, count);
    double rightSum = calculateAverage(node->right, count);
    count++;
    return leftSum + rightSum + node->age;
}
void BinaryTree::printAverage() {
    int count = 0;
    double sum = calculateAverage(root, count);
    if (count == 0) {
            cout << "Дерево порожнє.\n";
    } else {
            cout << "Середнє значення віку: " << sum / count << "\n";
    }
}
void BinaryTree::deleteTree(Node* node) {
    if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
    }
}
void BinaryTree::clear() {
    deleteTree(root);
    root = nullptr;
}

void BinaryTree::transferData(BinaryTree& newTree, bool byAge) {
     transferData(root, newTree, byAge);
}

void BinaryTree::transferData(Node* node, BinaryTree& newTree, bool byAge) {
  if (node) {
      transferData(node->left, newTree, byAge);
      newTree.addPersonRec(node->lastName, node->passportNumber, node->age);
       transferData(node->right, newTree, byAge);
   }

}


void BinaryTree::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Не вдалося відкрити файл: " << filename << RESET << endl;
        return;
    }

    string lastName;
    int passportNumber, age;
    while (file >> lastName >> passportNumber >> age) {
        addPerson(lastName, passportNumber, age);
    }

    file.close();
    cout << GREEN << "Дані успішно завантажено з файлу " << filename << RESET << endl;
}

void BinaryTree::saveTreeToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Не вдалося відкрити файл для запису: " << filename  << RESET << endl;
        return;
    }

    if (root == nullptr) {
        file << "Дерево порожнє.\n";
    } else {
        writeNodeToFile(root, file);  
    }

    file.close();
    cout << GREEN << "Дерево успішно збережено у файл " << filename << "." << RESET << endl;
}

void BinaryTree::writeNodeToFile(Node* node, ofstream& file, string prefix, bool isLeft) {
    if (node == nullptr) return;

    if (node->left != nullptr) {
        writeNodeToFile(node->left, file, prefix + (isLeft ? "    " : "     "), true);
        file << prefix << "   /\n";
    }

    file << prefix << node->lastName << " (Паспорт: " << node->passportNumber << ", Вік: " << node->age << ")" << endl;

    if (node->right != nullptr) {
        file << prefix << "   \\\n";
        writeNodeToFile(node->right, file, prefix + (isLeft ? "    " : "     "), false);
    }
}



//--------------------




void RBTree::insert(Node* newNode) {
    Node* y = nullptr; 
    Node* x = root;    

    while (x != nullptr) {
        y = x;
        if (newNode->lastName < x->lastName) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    newNode->parent = y;

    if (y == nullptr) {
        root = newNode; 
    } else if (newNode->lastName < y->lastName) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }

    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = true; 

    balanceTree(newNode);
}

void RBTree::balanceTree(Node* node) {
    while (node != root && node->parent != nullptr && node->parent->color == true) { 
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle != nullptr && uncle->color == true) { 
                node->parent->color = false; 
                uncle->color = false;         
                node->parent->parent->color = true; 
                node = node->parent->parent; 
            } else {
                if (node == node->parent->right) { 
                    node = node->parent; 
                    rotateLeft(node);
                }
                node->parent->color = false; 
                node->parent->parent->color = true; 
                rotateRight(node->parent->parent); 
            }
        } else { 
            Node* uncle = node->parent->parent->left;
            if (uncle != nullptr && uncle->color == true) {
                node->parent->color = false;
                uncle->color = false;
                node->parent->parent->color = true;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->color = false;
                node->parent->parent->color = true;
                rotateLeft(node->parent->parent);
            }
        }
    }
    root->color = false; 
}

void RBTree::rotateRight(Node* node) {
    Node* y = node->left;
    node->left = y->right;

    if (y->right != nullptr) {
        y->right->parent = node;
    }

    y->parent = node->parent;

    if (node->parent == nullptr) {
        root = y;
    } else if (node == node->parent->right) {
        node->parent->right = y;
    } else {
        node->parent->left = y;
    }

    y->right = node;
    node->parent = y;
}

void RBTree::rotateLeft(Node* node) {
    Node* y = node->right;
    node->right = y->left;

    if (y->left != nullptr) {
        y->left->parent = node;
    }

    y->parent = node->parent;

    if (node->parent == nullptr) {
        root = y;
    } else if (node == node->parent->left) {
        node->parent->left = y;
    } else {
        node->parent->right = y;
    }

    y->left = node;
    node->parent = y;
}

void RBTree::displayTree(Node* node, string prefix, bool isLeft) {
    if (node == nullptr) return;

    if (node->left != nullptr) {
        displayTree(node->left, prefix + (isLeft ? "    " : "     "), true);
        cout << prefix << "   /\n";
    }

    cout << prefix << (node->color ? RED : BLACK) << node->lastName << "(Паспорт: " << node->passportNumber << ", Вік: " << node->age << ")" << endl;

    if (node->right != nullptr) {
        cout << prefix << "   \\\n"; 
        displayTree(node->right, prefix + (isLeft ? "    " : "     "), false);
    }
}






void RBTree::clear() {
    deleteTree(root);
    root = nullptr;
}

void RBTree::deleteTree(Node* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}


void RBTree::transferTree(Node* node) {
    if (node) {
        transferTree(node->left);
        
        Node* newNode = new Node(node->lastName, node->passportNumber, node->age);
        insert(newNode);  
        
        transferTree(node->right);
    }
}




Node* RBTree::findNodeByLastName(Node* node, const string& lastName) {
    if (node == nullptr || node->lastName == lastName) {
        return node;
    }
    if (lastName < node->lastName) {
        return findNodeByLastName(node->left, lastName);
    } else {
        return findNodeByLastName(node->right, lastName);
    }
}

void RBTree::deleteNode(Node* node) {
    if (node == nullptr) {
        return;
    }

    Node* y = node;
    Node* x = nullptr;
    Node* xParent = nullptr;
    bool originalColor = y->color;

    if (node->left == nullptr) {
        x = node->right;
        transplant(node, node->right);
    } else if (node->right == nullptr) {
        x = node->left;
        transplant(node, node->left);
    } else {
        y = minimum(node->right);
        originalColor = y->color;
        x = y->right;
        if (y->parent == node) {
            if (x != nullptr) x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    
    delete node;


    if (originalColor == false) {
        balanceDelete(x, xParent);
    }
}

void RBTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}

Node* RBTree::minimum(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void RBTree::balanceDelete(Node* x, Node* xParent) {
    while (x != root && (x == nullptr || x->color == false)) {
        if (x == xParent->left) {
            Node* sibling = xParent->right;
            if (sibling->color == true) {
                sibling->color = false;
                xParent->color = true;
                rotateLeft(xParent);
                sibling = xParent->right;
            }
            if ((sibling->left == nullptr || sibling->left->color == false) &&
                (sibling->right == nullptr || sibling->right->color == false)) {
                sibling->color = true;
                x = xParent;
                xParent = x->parent;
            } else {
                if (sibling->right == nullptr || sibling->right->color == false) {
                    if (sibling->left != nullptr) sibling->left->color = false;
                    sibling->color = true;
                    rotateRight(sibling);
                    sibling = xParent->right;
                }
                sibling->color = xParent->color;
                xParent->color = false;
                if (sibling->right != nullptr) sibling->right->color = false;
                rotateLeft(xParent);
                x = root;
            }
        } else {
            Node* sibling = xParent->left;
            if (sibling->color == true) {
                sibling->color = false;
                xParent->color = true;
                rotateRight(xParent);
                sibling = xParent->left;
            }
            if ((sibling->right == nullptr || sibling->right->color == false) &&
                (sibling->left == nullptr || sibling->left->color == false)) {
                sibling->color = true;
                x = xParent;
                xParent = x->parent;
            } else {
                if (sibling->left == nullptr || sibling->left->color == false) {
                    if (sibling->right != nullptr) sibling->right->color = false;
                    sibling->color = true;
                    rotateLeft(sibling);
                    sibling = xParent->left;
                }
                sibling->color = xParent->color;
                xParent->color = false;
                if (sibling->left != nullptr) sibling->left->color = false;
                rotateRight(xParent);
                x = root;
            }
        }
    }
    if (x != nullptr) x->color = false;
}






void Menu::menu() {
     do {
         cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl; 
        cout << "1. Додати громадянина" << endl;
        cout << "2. Вивести дерево (прямий обхід)" << endl;;
        cout << "3. Вивести дерево (симетричний обхід)" << endl;
        cout << "4. Вивести дерево (зворотний обхід)" << endl;
        cout << "5. Показати все дерево\n";
        cout << "6. Знайти середнє значення віку" << endl;
        cout << "7. Видалити ліве піддерево" << endl;
        cout << "8. Видалити праве піддерево" << endl;
        cout << "9. Видалити все дерево" << endl;
        cout << "10. Пересипати дані з першого дерева в друге" << endl;
        cout << "11. Перефарбування дерева в червоно-чорне" << endl;
        cout << "12. Показати червоно-чорне дерево" << endl;
        cout << "13. Видалити вузл з червоно-чорного дерева" << endl;
        cout << "14. Зберегти дерево у файл" << endl;
        cout << RED <<"0. Вийти" << RESET << endl;
        cout << "Виберіть опцію: ";
        cin >> choose;

        bool byAge = false;
        
        switch (choose) {
            case 1: {

                do {
                    cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl;
                    cout << "1. Додати громадянина" << endl;
                    cout << "2. Додати громадянина з файлу" << endl;
                    cout << RED <<"0. Вийти" << RESET << endl;
                    cout << "Виберіть опцію: ";
                    cin >> a;

                    switch (a) {
                    case 1:
                        cout << "Введіть прізвище: ";
                        cin >> surname;
                        cout << "Введіть номер паспорта: ";
                        cin >> passportNumber;
                        cout << "Введіть вік: ";
                        cin >> age;
                        tree.addPerson(surname, passportNumber, age);
                        break;
                    case 2:
                        cout << "Введіть ім'я файлу: ";
                        cin >> filename;
                        tree.loadFromFile(filename);
                        break;
                    case 3:
                        break;
                    default:
                        cout << "Неправильний вибір. Спробуйте ще раз." << endl;
                        break;
                    }
                } while ( a != 0);
                break;
            }
            case 2:
                cout << "Дерево (прямий обхід):\n";
                tree.displayPreOrder(tree.root);
                break;
            case 3:
                cout << "Дерево (симетричний обхід):\n";
                tree.displayInOrder(tree.root);
                break;
            case 4:
                cout << "Дерево (зворотний обхід):\n";
                tree.displayPostOrder(tree.root);
                break;
            case 5:
                tree.showFullTree();
                break;
            case 6:
                tree.printAverage();  
                break;
            case 7:
                tree.deleteLeftSubtree(tree.root);
                break;
            case 8:
                tree.deleteRightSubtree(tree.root);
                break;
            case 9:
                tree.clear();
                cout << "Все дерево видалено.\n";
                break;
            case 10:
                cout << "Пересипати дані за:\n1. Вік\n2. Номер паспорта\nВиберіть опцію: ";
                cin >> criteria;
                byAge = (criteria == 1);
                newTree.clear(); 
                tree.transferData(newTree, byAge);
                cout << "Пересипані дані:\n";
                newTree.displayTree(newTree.root);
                break;
            case 11:
                rbTree.clear();
                rbTree.transferTree(tree.root); 
                cout << "Дані перенесені до червоно-чорного дерева.\n";
                break;
            case 12:
                cout << "Червоно-чорне дерево:\n";
                rbTree.displayTree(rbTree.root);
                break;
            case 13: 
                cout << "Введіть прізвище для видалення: ";
                cin >> surname;
                nodeToDelete = rbTree.findNodeByLastName(rbTree.root, surname);
                if (nodeToDelete != nullptr) {
                    rbTree.deleteNode(nodeToDelete);
                    cout << "Вузол з прізвищем " << surname << " видалено.\n";
                } else {
                    cout << "Вузол з прізвищем " << surname << " не знайдено.\n";
                }
                break;
            case 14:
                cout << "Введіть ім'я файлу для збереження: ";
                cin >> filename;
                tree.saveTreeToFile(filename);
                break;
            case 0:
                cout << "Завершення програми.\n";
                break;
            default:
                cout << "Неправильний вибір. Спробуйте ще раз.\n";
        }
    } while (choose != 0);
};
