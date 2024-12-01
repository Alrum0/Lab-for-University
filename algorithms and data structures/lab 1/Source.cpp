#include "Header.h"

void SINGL_LIST::makeSingleList(int n) {
    if (n > 0) {
        Single_List* newNode = new Single_List(); 
        cout << "Введіть значення для елемента: ";
        cin >> newNode->data; 

        newNode->next = head; 
        head = newNode; 

        makeSingleList(n - 1); 
    }
}
void SINGL_LIST::displayList(Single_List* Head) {
    if (Head != NULL) {
        cout << setw(DISTANCE) << Head->data << "\t";
        displayList(Head->next);
    }
    else cout << "\n";
}
void SINGL_LIST::addElements(int val) {
    Single_List* newNode = new Single_List();

    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Single_List* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void SINGL_LIST::clearList() {
    Single_List* current = head;
    Single_List* next;
    
    while(current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
    cout << GREEN << "Список очищено" << RESET << endl;
}
void SINGL_LIST::removeElements(int val) {
    if (head == nullptr) { 
            cout << RED << "Список порожній, неможливо видалити елемент." << RESET <<endl;
            return;
        }

    Single_List* current = head;
    Single_List* prew = NULL;

    if (current != NULL && current->data == val) {
        head = current->next;
        delete current;
        cout << GREEN << "Елемент " << val << " видалено" << RESET << endl;
        return;
    }

    while (current != NULL && current->data != val) {
        prew = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << RED << "Елемент не знайдено" << RESET << endl;
        return;
    }

    prew->next = current->next;
    delete current;
    cout << GREEN << "Елемент " << RESET << current->data << GREEN << " видалено" << RESET << endl;
}
int SINGL_LIST::countElements() {
    Single_List* current = head;
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}
void SINGL_LIST::swapElements(int pos) {
    if (pos <= 0 || head == NULL || head->next == NULL) {
        cout << RED << "Неможливо поміняти елементи" << RESET << endl;
    }

    Single_List* prew = NULL;
    Single_List* current = head;
    Single_List* next = head->next;

    if (pos == 1) {
        current->next = next->next;
        next->next = current;
        head = next;
        return;
    }

    for (int i = 1; i < pos - 1 && current != NULL && current->next != NULL; i++) {
        prew = current;
        current = current->next;
        next = current->next;
    }

    if (current == NULL || next == NULL) {
        cout << RED << "Неможливо поміняти елементи" << RESET << endl;
        return;
    }

    current->next = next->next;
    next->next = current;

    if(prew != NULL) prew->next = next;
}
void SINGL_LIST::writeToFile(const string& filename) {
    ofstream outFile(filename);

    if(!outFile.is_open()) {cout << RED << "Помилка при відкритті файлу для запису." << RESET << endl; return; }

    Single_List* current = head;

    while (current != NULL) {
        outFile << current->data;
        if (current->next != NULL) {
            outFile << " ";
        }
        current = current->next;
    }

    outFile << "\n";
    outFile.close();
    cout << GREEN << "Список записано у файл: " << RESET << filename << endl;
}


void DOUBLE_LIST::makeDoubleList(int n) {
    if(n > 0) {
        Double_list* newNode = new Double_list();
        cout << "Введіть значення елемента: ";
        cin >> newNode->data;

        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }

        newNode->prev = nullptr;
        head = newNode;

        makeDoubleList(n - 1);
    }
}
void DOUBLE_LIST::displayList(Double_list* Head) {
    if (Head != nullptr) {
        cout << setw(DISTANCE) << Head->data << '\t';
        displayList(Head->next);
    } else {
        cout << "\n";
    }
}
void DOUBLE_LIST::addElements(int val) {
    Double_list* newNode = new Double_list();

    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
    } else {
        Double_list* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void DOUBLE_LIST::clearList() {
    Double_list* current = head;
    Double_list* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    cout << GREEN << "Список очищено" << RESET << endl;
}
void DOUBLE_LIST::removeElements(int val) {
    if (head == nullptr) { 
        cout << RED << "Список порожній, неможливо видалити елемент." << RESET << endl;
        return;
    }

    Double_list* current = head;
    while (current != nullptr) {
        if (current->data == val) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }

            delete current;
            cout << GREEN << "Елемент " << val <<  " видалено" << RESET << endl;
            return;
        }
        current = current->next;
    }

    cout << RED << "Елемент " << val << " не знайдено у списку" << RESET << endl;
}
int DOUBLE_LIST::countElements() {
    int count = 0;
    Double_list* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}
void DOUBLE_LIST::swapElements(int pos) {
    if (pos <= 0 || head == nullptr || head->next == nullptr) {
        cout << RED << "Неможливо поміняти елементи" << RESET << endl;
        return;
    }

    Double_list* prev = nullptr;
    Double_list* current = head; 
    Double_list* next = head->next;

    if (pos == 1) {
        current->next = next->next;
        if (next->next != nullptr) {
            next->next->prev = current;
        }
        next->prev = nullptr;
        next->next = current;
        current->prev = next;
        head = next;
        return;
    }

    for (int i = 1; i < pos - 1 && current != nullptr && current->next != nullptr; i++) {
        current = current->next;
        next = current->next;
    }

    if (current == nullptr || next == nullptr) {
        cout << RED << "Не можливо поміняти елементи" << RESET << endl;
        return;
    }

    prev = current->prev;

    current->next = next->next;
    if (next->next != nullptr) {
        next->next->prev = current;
    }

    next->prev = prev;
    next->next = current;
    current->prev = next;

    if (prev != nullptr) {
        prev->next = next;
    } else {
        head = next;
    }
}
void DOUBLE_LIST::writeToFile(const string& filename) {
    ofstream outFile(filename);

    if(!outFile.is_open()) {cout << RED << "Помилка при відкритті файлу для запису." << RESET << endl; return; }

    Double_list* current = head;
    while (current != nullptr) {
        outFile << current->data;
        if(current->next != nullptr) {
            outFile << " ";
        }
        current = current->next;
    }

    outFile << "\n";
    outFile.close();
    cout << GREEN << "Список записано у файл: " << RESET << filename << endl;
}

///
void MENU_SINGL_LIST::writeMyself() {
    cout << "Введіть кількість елементів для списку: ";
    cin >> n;
    list.makeSingleList(n); 
    cout << GREEN << "Список сформовано" << RESET << endl;
}
void MENU_SINGL_LIST::scanWithFile() {
    cout << "Введіть назву файлу: ";
    cin  >> fileName;

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << RED << "Не вдалося відкрити файл." << RESET << endl;
        return;
    }

    while(file >> value) {
        list.addElements(value);
    }

    cout << GREEN << "Cписок сформовано з файлу: " << fileName << RESET << endl;  
    file.close();   
}
//FIXME: не працює зчитування з файлу
void MENU_DOUBLE_LIST::writeMyself() {
    cout << "введіть кількість елементів для списку: ";
    cin >> n;
    list.makeDoubleList(n);
    cout << GREEN << "Список сформовано" << RESET << endl;
}
void MENU_DOUBLE_LIST::scanWithFile() {
    cout << "Введіть назву файлу: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << RED << "Помилка відкриття файлу" << RESET << endl;
        return;
    }

    while (file >> value) {
        list.addElements(value);
    }

    file.close();
    cout << GREEN << "Список зчитано з файлу" << RESET << endl;


}
///


void MENU_SINGL_LIST::menu() {
       do {
        cout << CYAN << BOLD <<"Обери пункт:" << RESET << endl; 
        cout << "1. Сформувати список" << endl; 
        cout << "2. Додати елемент до списку" << endl;
        cout << "3. Вилучити елемент зі списку" << endl;
        cout << "4. Кількість елементів у списку" << endl;
        cout << "5. Поміняти два сусідні елементи місцями" << endl;
        cout << "6. Записати список у файл" << endl;
        cout << "7. Вивести список" << endl;
        cout << "8. Очистити список" << endl;
        cout << RED <<"0. Вихід" << RESET <<endl;

        cout << "Твій вибір: ";
        cin >> choose; 

        system("clear");

        switch (choose) {
            case 1:
                do{
                    cout << CYAN << BOLD <<"Обери пункт:" << RESET << endl; 
                    cout << "1. Сформувати список вручну" << endl;
                    cout << "2. Сформувати список з файлу" << endl;
                    cout << RED << "3. Вихід" << RESET << endl;

                    cout << "Твій вибір: ";
                    cin >> a;
                    switch (a) {
                    case 1:
                        MENU_SINGL_LIST::writeMyself();
                        break;
                    case 2:
                        MENU_SINGL_LIST::scanWithFile();
                        break;
                    case 3:
                        cout << "Вихід...";
                        break;
                    default:
                        cout << "Неправильний вибір";
                        break;
                    }
                    cin.ignore();
                    cin.get();
                    system("clear");

                } while(a != 3);
                break;
            case 2:
                cout << "Введіть знвчення для нового елемента: ";
                cin >> val;
                list.addElements(val);
                cout << GREEN << "Елемент додано в кінець списку" << RESET << endl;
                break;
            case 3:
                cout << "Введіть значення елемента, який треба видалити: ";
                cin >> value;
                list.removeElements(value);
                break;
            case 4:
                cout << "Кількість елементів у списку: " << list.countElements() << endl;
                break;
            case 5:
                cout << "Введіть позицію першого елемента для обміну: ";
                cin >> pos;
                list.swapElements(pos);
                cout << GREEN <<"Елементи поміняно місцями." << RESET << endl;
                break;
            case 6:
                cout << "Введіть ім`я файлу для запису: ";
                cin >> fileName;
                list.writeToFile(fileName);
                break;
            case 7:
                cout << "Список елементів: ";
                list.displayList(list.getHead());
                break;
            case 8:
                list.clearList(); 
                break;
           
            case 0:
                cout << "Вихід..." << endl; 
                break;
            default:
                cout << "Неправильний вибір" << endl; 
                break;
        }
        cin.ignore();
        cin.get();
        system("clear");
    } while (choose != 0); 
}

void MENU_DOUBLE_LIST::menu() {
     do {
        cout << CYAN << BOLD <<"Обери пункт:" << RESET << endl; 
        cout << "1. Сформувати список" << endl; 
        cout << "2. Додати елемент до списку" << endl;
        cout << "3. Вилучити елемент зі списку" << endl;
        cout << "4. Кількість елементів у списку" << endl;
        cout << "5. Поміняти два сусідні елементи місцями" << endl;
        cout << "6. Записати список у файл" << endl;
        cout << "7. Вивести список" << endl;
        cout << "8. Очистити список" << endl;

        cout << RED <<"0. Вихід" << RESET <<endl;

        cout << "Твій вибір: ";
        cin >> choose; 

        system("clear");

        switch (choose) {
             case 1:
                do{
                    cout << CYAN << BOLD <<"Обери пункт:" << RESET << endl; 
                    cout << "1. Сформувати список вручну" << endl;
                    cout << "2. Сформувати список з файлу" << endl;
                    cout << RED << "3. Вихід" << RESET << endl;

                    cout << "Твій вибір: ";
                    cin >> a;
                    switch (a) {
                    case 1:
                        MENU_DOUBLE_LIST::writeMyself();
                        break;
                    case 2:
                        MENU_DOUBLE_LIST::scanWithFile();
                        break;
                    case 3:
                        cout << "Вихід...";
                        break;
                    default:
                        cout << "Неправильний вибір";
                        break;
                    }
                    cin.ignore();
                    cin.get();
                    system("clear");

                } while(a != 3);
                break;

            case 2:
                cout << "Введіть значення для нового елемента: ";
                cin >> val;
                list.addElements(val);
                cout << GREEN << "Елемент додано в кінець списку" << RESET << endl;
                break;

            case 3:
                cout << "Введіть значення елемента, який треба видалити: ";
                cin >> value;
                list.removeElements(value);
                break;

            case 4:
                cout << "Кількість елементів у списку: " << list.countElements() << endl;
                break;

            case 5:
                cout << "Введіть позицію першого елемента для обміну: ";
                cin >> pos;
                list.swapElements(pos);
                cout << GREEN <<"Елементи поміняно місцями." << RESET << endl;
                break;

            case 6:
                cout << "Введіть ім`я файлу для запису: ";
                cin >> fileName;
                list.writeToFile(fileName);
                break;

            case 7:
                cout << "Cписок елементів: ";
                list.displayList(list.getHead());
                break;

            case 8:
                list.clearList();
                break;

            case 0:
                cout << "Вихід..." << endl;
                break;


            default:
                cout << "Incorrect choice." << endl; 
                break;
        }
        cin.ignore();
        cin.get();
        system("clear");
    } while (choose != 0); 
};

void MENU::menuAct() {
     

    do {
        cout << CYAN << BOLD <<"Обери пункт:" << RESET << endl; 
        cout << "1. Робота з однозв`язковим списком" << endl; 
        cout << "2. Робота з двозв`язковим списком" << endl;
        cout << RED <<"3. Вихід" << RESET << endl;

        cout <<"Твій вибір: ";
        
        cin >> choose; 
        system("clear");

        switch (choose) {
            case 1:
                menu.menu();
                break;

            case 2:
                menu2.menu();
                break;

            case 3:
                cout <<"Вихід..." << endl;
                break;

            default:
                cout << "Неправильний вибір." << endl; 
                break;
        }
        cin.ignore();
        cin.get();
        system("clear");
    } while (choose != 3); 
}