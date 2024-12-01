#include "Header.h"


// STACK 
//#FIXME: додати написи про успішне виконання
bool STACK_OPERATIONS::isEmty(const StackData& stack) {
    return stack.top == -1;
}
bool STACK_OPERATIONS::isFull(const StackData& stack) {
    return stack.top >= MAX_SIZE - 1;
}
void STACK_OPERATIONS::push(StackData& stack, short value) {
    if (!isFull(stack)) {
        stack.data[++stack.top] = value;
    } else {
        cout << RED << "Стек переповнений!" << RESET << endl;
    }
}
short STACK_OPERATIONS::pop(StackData& stack) {
    if (!isEmty(stack)) {
        return stack.data[stack.top--];
    } else {
        cout << RED << "Стек порожній!" << RESET << endl;
        return -1;
    }
}
short STACK_OPERATIONS::peek(const StackData& stack) {
    if(!isEmty(stack)) {
        return stack.data[stack.top];
    } else {
        cout << RED << "Стек порожній" << RESET << endl;
        return -1;
    }
}
void STACK_OPERATIONS::swap_first_last(StackData& stack) {
    if (stack.top < 1) return;

    short first = stack.data[0];
    short last = stack.data[stack.top];

    stack.data[0] = last;
    stack.data[stack.top] = first;
}
void STACK_OPERATIONS::reverse(StackData& stack) {
    for (int i = 0; i < stack.top / 2; ++i) {
        short temp = stack.data[i];
        stack.data[i] = stack.data[stack.top - i];
        stack.data[stack.top - i] = temp;
    }
}
void STACK_OPERATIONS::delete_every_second(StackData& stack) {
    if (stack.top < 1) return; 

    int new_top = 0;  
    for (int i = 0; i <= stack.top; i++) {
        if (i % 2 == 0) {  
            stack.data[new_top++] = stack.data[i];
        }
    }
    stack.top = new_top - 1;
}
void STACK_OPERATIONS::insert_after_max(StackData& stack) {
     if (isEmty(stack)) return;

    short max_val = stack.data[stack.top];
    int max_idx = stack.top;
    
    for (int i = stack.top - 1; i >= 0; --i) {  
        if (stack.data[i] > max_val) {
            max_val = stack.data[i];
            max_idx = i;
        }
    }

    if (isFull(stack)) return;

    for (int i = stack.top + 1; i > max_idx; --i) {
        stack.data[i] = stack.data[i - 1];
    }

    stack.data[max_idx] = 0;
    stack.top++;
}
void STACK_OPERATIONS::delete_min(StackData& stack) {
    if (isEmty(stack)) return;

    short min_val = stack.data[0];
    int min_idx = 0;
    for (int i = 1; i <= stack.top; i++) {
        if (stack.data[i] < min_val) {
            min_val = stack.data[i];
            min_idx = i;
        }
    }

    for (int i = min_idx; i < stack.top; i++) {
        stack.data[i] = stack.data[i + 1];
    }
    stack.top--;
}
void STACK_OPERATIONS::delete_all_except_first(StackData& stack) {
     if (!isEmty(stack)) {
        short first = stack.data[stack.top]; 
        stack.data[0] = first;  
        stack.top = 0;         
    }
}
void STACK_OPERATIONS::delete_all_except_last(StackData& stack) {
    if (isEmty(stack)) {
        cout << RED << "Стек порожній, нічого не можна видалити!" << RESET << endl;
        return; 
    }

    
    short last = stack.data[0]; 
    stack.data[0] = last;       
    stack.top = 0; 
    
}
void STACK_OPERATIONS::print(const StackData& stack) {
    if(isEmty(stack)) {
        cout << RED << "Стек порожній!" << RESET << endl;
    } else {
        cout << "Елементи стека: ";
        for (int i = 0; i <= stack.top; i++) {
            cout << setw(DISTANCE) << stack.data[stack.top - i]; 
        }
        cout << endl;
    }
}

void STACK_OPERATIONS::readDataFromFile(StackData& stack, const string& filename, STACK_OPERATIONS& operations) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка відкриття файлу: " << filename << RESET << endl;
    }

    short value;
    while (file >> value) {
        operations.push(stack, value);
    }

    file.close();
    cout << GREEN << "Дані успішно завантажено з файлу: " << filename << RESET << endl;
}


// QUEUE

void QUEUE_OPERATIONS::initQueue(Queue& q) {
    q.front = 0;
    q.rear = -1;
    q.size = 0;
}
bool QUEUE_OPERATIONS::isEmty(const Queue& q) {
    return q.size == 0;
}
bool QUEUE_OPERATIONS::isFull(const Queue& q) {
    return q.size == MAX_SIZE;
}
void QUEUE_OPERATIONS::enqueue(Queue& q, short value) {
    if (!isFull(q)) {
        q.rear = (q.rear + 1) % MAX_SIZE;
        q.data[q.rear] = value;
        q.size++;
    } else {
        cout << RED << "Черга переповнена!" << RESET << endl;
    }
}
short QUEUE_OPERATIONS::dequeu(Queue& q) {
    if (!isEmty(q)) {
        short value = q.data[q.front];
        q.front = (q.front + 1) % MAX_SIZE;
        q.size--;
        return value;
    } else {
        cout << RED << "Черга порожня!"  << RESET << endl;
        return -1;
    }
}
void QUEUE_OPERATIONS::printSize(const Queue& q) {
    cout << "Кількість елементів у черзі: " << q.size << endl;
}
void QUEUE_OPERATIONS::printAvarage(const Queue& q) {
    if (isEmty(q)) {
        cout << RED << "Черга порожня" << RESET << endl;
        return;
    }

    short sum = 0;
    for (int i = 0; i < q.size; ++i) {
        sum += q.data[(q.front + i) % MAX_SIZE]; 
    }
    cout << GREEN << "Середнє арифметичне елементів черги: " << static_cast<double>(sum) / q.size << RESET <<endl;
}
void QUEUE_OPERATIONS::printMinMax(const Queue& q) {
    if (isEmty(q)) {
        cout << RED << "Черга порожня" << RESET << endl;
        return;
    }

    short min = q.data[q.front];
    short max = q.data[q.front];

    for (int i = 1; i < q.size; i++) {
        short value = q.data[(q.front + i) % MAX_SIZE];
        if (value < min) min = value;
        if (value > max) max = value;
    }

    cout << "Мінімальний елемент: " << min << endl;
    cout << "Максимальний елемент: " << max << endl;
}
void QUEUE_OPERATIONS::printElementBeforeMin(const Queue& q) {
    if (isEmty(q) || q.size < 2) {
        cout << RED << "Недостатньо елементів у черзі!" << RESET << endl;
        return;
    }

    short min = q.data[q.front];
    int minIndex = 0;

    for (int i = 1; i < q.size; ++i) {
        short value = q.data[(q.front + i) % MAX_SIZE];
        if (value < min) {
            min = value;
            minIndex = i;
        }
    }

    if (minIndex == 0) {
        cout << RED << "Мінімальний елемент є першим, немає попереднього елементу!" << RESET << endl;
    } else {
        int indexBeforeMin = (q.front + minIndex - 1) % MAX_SIZE;
        cout << "Елемент перед мінімальним: " << q.data[indexBeforeMin] << endl;
    }
}
void QUEUE_OPERATIONS::printQueue(const Queue& q) {
    if (isEmty(q)) {
        cout << "Черга порожня!" << endl;
        return;
    }

    cout << "Елементи черги: ";
    for (int i = 0; i < q.size; ++i) {
        cout << q.data[(q.front + i) % MAX_SIZE] << " ";  
    }
    cout << endl;
}
void QUEUE_OPERATIONS::enqueueToFile(const Queue& q, const string& filename) {
     ofstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка відкриття файлу!" << RESET << endl;
        return;
    }

    for (int i = 0; i < q.size; ++i) {
        file << q.data[(q.front + i) % MAX_SIZE] << endl;
    }

    file.close();
    cout << GREEN << "Дані з черги успішно записані у файл." << RESET << endl;
}


void QUEUE_OPERATIONS::enqueueFromFile(Queue& q, const string& filename, QUEUE_OPERATIONS& operations) {
    ifstream file(filename);

    if(!file.is_open()) {
        cout << RED << "Помилка відкриття файлу!" << RESET << endl;
        return;
    }

    short value;
    while (file >> value) {
        operations.enqueue(q, value);
    }

    file.close();
    cout << GREEN << "Дані з файлу успішно додані в чергу." << RESET << endl;
}


// DEQUE

void DEQUE_OPERATIONS::initDeque(Deque& deque) {
    deque.front = 0;
    deque.rear = -1;
    deque.size = 0;
}
bool DEQUE_OPERATIONS::isEmty(const Deque& deque) {
    return deque.size == 0;
}
bool DEQUE_OPERATIONS::isFull(const Deque& deque) {
    return deque.size == MAX_SIZE;
}
void DEQUE_OPERATIONS::addFront(Deque& deque, short value) {
    if (isFull(deque)) {
        cout << RED << "Дек переповнений" << RESET << endl;
    }
    deque.front = (deque.front - 1 + MAX_SIZE) % MAX_SIZE;
    deque.data[deque.front] = value;
    deque.size++;
}
void DEQUE_OPERATIONS::addRear(Deque& deque, short value) {
    if (isFull(deque)) {
        cout << RED << "Дек переповнений" << RESET << endl;
    }
    deque.rear = (deque.rear + 1) % MAX_SIZE;
    deque.data[deque.rear] = value;
    deque.size++;
}
short DEQUE_OPERATIONS::getRear(const Deque& deque) {
    if (isEmty(deque)) {
        cout << RED << "Дек порожній" << RESET << endl;
        return -1;
    }
    return deque.data[deque.rear];
}
void DEQUE_OPERATIONS::writeDequeToFile(const Deque& deque, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Помилка відкриття файлу!" << RESET << endl;
        return;
    }

    if (isEmty(deque)) {
        file << "Дек порожній" << endl;
    } else {
        int i = deque.front;
        while (i != deque.rear) {
            file << deque.data[i] << " ";  
            i = (i + 1) % MAX_SIZE;
        }
        file << deque.data[deque.rear] << " ";  
    }

    file.close();
    cout << GREEN << "Дек успішно записаний у файл." << RESET << endl;
}
void DEQUE_OPERATIONS::printDeque(const Deque& deque) {
    if (isEmty(deque)) {
        cout << RED << "Дек порожній!" << RESET << endl;
        return;
    }

    cout << "Елементи дека: ";
    int i = deque.front;
    while (i != deque.rear) {
        cout << setw(DISTANCE) <<deque.data[i];
        i = (i + 1) % MAX_SIZE;
    }
    cout << setw(DISTANCE) << deque.data[deque.rear] << endl;  
}

void DEQUE_OPERATIONS::readDataFromFile(Deque& deque, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << RED << "Помилка відкриття файлу!" << RESET << endl;
        return;
    }

    short value;
    while (file >> value) {
        addRear(deque, value);
    }

    file.close();
    cout << GREEN << "Дані успішно прочитані з файлу і додано до деку." << RESET << endl;
}


void MENU_DEQUE::menu() {
    do {
        system("clear");

        cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl; 
        cout << "1. Створити дек" << endl;
        cout << "2. Перевірити на порожнечу" << endl;
        cout << "3. Додати елемент в початок" << endl;
        cout << "4. Додати елемент в кінець" << endl;
        cout << "5. Прочитати останній елемент" << endl;
        cout << "6. Вивести дек" << endl;
        cout << "7. Записати в файл" << endl;
        cout << RED << "0. Вихід" << RESET << endl;

        cout << "Твій вибір: ";
        cin >> choose;

        system("clear");

        switch (choose) {
        case 1:

            do {
                cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl; 
                cout << "1. Створити дек" << endl;
                cout << "2. Ввести дані з файлу" << endl;
                cout<< RED << "3. Вихід" << RESET << endl;        

                cout << "Твій вибір: ";
                cin >> a;
                switch (a) {
                case 1:
                    deq.initDeque(deque);
                    cout << GREEN << "Дек створено." << RESET << endl;
                    break;
                case 2:
                    cout << "Введіть назву файлу: ";
                    cin >> filename;
                    deq.readDataFromFile(deque, filename);
                    break;
                case 3:
                    cout << "Вихід..." << endl;
                    break;
                default:
                    cout << RED<< "Неправильний вибір" << RESET <<endl;
                    break;
                }
                cin.ignore();
                cin.get();
                system("clear");
            } while(a != 3);

            break;
        case 2:
            if (deq.isEmty(deque)) {
                cout << "Дек порожній." << endl;
            } else {
                cout << "Дек не порожній." << endl;
            }
            break;
        case 3:
            cout << "Введіть елемент для додавання на початок: ";
            cin >> value;
            deq.addFront(deque, value);
            break;
        case 4:
            cout << "Введіть елемент для додавання в кінець: ";
            cin >> value;
            deq.addRear(deque, value);
            break;
        case 5:
            value = deq.getRear(deque);
            if (value != -1) {
                cout << "Останній елемент: " << value << endl;
            }
            break;
        case 6:
            deq.printDeque(deque);
            break;
        case 7:
            cout << "Введіть назву файлу для запису: ";
            cin >> filename;
            deq.writeDequeToFile(deque, filename);
            break;
        case 0:
            cout << "Вихід..." << endl;
            break;

        
        default:
            cout << "Неправильний вибір. Спробуйте ще раз" << endl;
            break;
        }
        cin.ignore();
        cin.get();
        system("clear");
    } while (choose != 0);
    
}

void MENU_QUEUE::menu() {
    do {
        system("clear");

        cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl; 
        cout << "1. Додати елемент у чергу" << endl;
        cout << "2. Кількість елементів" << endl;
        cout << "3. Середнє арифметичне елементів" << endl;
        cout << "4. Вивести мінімальний та максимальний елемент" << endl;
        cout << "5. Вивести елемент, що йде перед мінімальним елементом" << endl;
        cout << "6. Вивести елементи черги" << endl;
        cout << "7. Записати в файл" << endl;
        cout << RED << "0. Вихід" << RESET << endl;

        cout << "Твій вибір: ";
        cin >> choose;

        system("clear");

        switch (choose) {
        case 1:

            do {
                cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl; 
                cout << "1. Ввести дані вручну" << endl;
                cout << "2. Ввести дані з файлу" << endl;
                cout<< RED << "3. Вихід" << RESET << endl;        

                cout << "Твій вибір: ";
                cin >> a;
                switch (a) {
                case 1:
                    cout << "Введіть елемент для додавання: ";
                    cin >> value;
                    que.enqueue(q, value);
                    break;
                case 2:
                    cout << "Введіть назву файлу: ";
                    cin >> filename;
                    que.enqueueFromFile(q, filename, que);
                    break;
                case 3:
                    cout << "Вихід..." << endl;
                    break;
                default:
                    cout << RED<< "Неправильний вибір" << RESET <<endl;
                    break;
                }
                cin.ignore();
                cin.get();
                system("clear");
            } while(a != 3);

            break;
        case 2:
            que.printSize(q);
            break;
        case 3:
            que.printAvarage(q);
            break;
        case 4:
            que.printMinMax(q);
            break;
        case 5:
            que.printElementBeforeMin(q);
            break;
        case 6:
            que.printQueue(q);
            break;
        case 7:
            cout << "Введіть назву файлу для запису: ";
            cin >> filename;
            que.enqueueToFile(q, filename);
            break;
        case 0:
            cout << "Вихід..." << endl;
            break;

        
        default:
            cout << "Неправильний вибір. Спробуйте ще раз" << endl;
            break;
        }

        cin.ignore();
        cin.get();
        system("clear");
    } while (choose != 0);
    
}

void MENU_STACK::menu() {
    
    do {
        system("clear");

        cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl; 
        cout << "1. Додати елемент до стека" << endl;
        cout << "2. Поміняти перший і останній елемент" << endl;
        cout << "3. Розгорнути стек" << endl;
        cout << "4. Видалити кожен другий елемент стеку" << endl;
        cout << "5. Знайти максимальний елемент і поставити після нього 0" << endl;
        cout << "6. Видалити мінімальний елемент" << endl;
        cout << "7. Видалити всі елементи, крім першого" << endl;
        cout << "8. Видалити всі елементи, крім останнього" << endl;
        cout << "9. Записати в файл" << endl;
        cout << "10. Вивести елементи стека" << endl;
        cout << RED << "0. Вихід" << RESET << endl;

        cout << "Твій вибір: ";
        cin >> choose;

    
        system("clear");

        switch (choose) {
        case 1:

            do {
                cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl; 
                cout << "1. Ввести дані вручну" << endl;
                cout << "2. Ввести дані з файлу" << endl;
                cout<< RED << "3. Вихід" << RESET << endl;        

                cout << "Твій вибір: ";
                cin >> a;
                switch (a) {
                case 1:
                    cout << "Введіть значення для додавання: ";
                    cin >> value;
                    stk.push(stack, value);
                    break;
                case 2:
                    cout << "Введіть ім`я файлу: ";
                    cin >> filename;
                    stk.readDataFromFile(stack, filename, stk);
                    break;
                case 3:
                    cout << "Вихід..." << endl;
                    break;
                default:
                    cout << RED<< "Неправильний вибір" << RESET <<endl;
                    break;
                }
                cin.ignore();
                cin.get();
                system("clear");
            } while(a != 3);

            break;
        case 2:
            stk.swap_first_last(stack);
            break;
        case 3:
            stk.reverse(stack);
            break;
        case 4:
            stk.delete_every_second(stack);
            break;
        case 5:
            stk.insert_after_max(stack);
            break;
        case 6:
            stk.delete_min(stack);
            break;
        case 7:
            stk.delete_all_except_first(stack);
            break;
        case 8:
            stk.delete_all_except_last(stack);
            break;
        case 9:
            break;
        case 10:
            stk.print(stack);
            break;
        case 0:
            cout << "Вихід..." << endl;
            break;

        
        default:
            cout << "Неправильний вибір. Спробуйте ще раз" << endl;
            break;
        }
        cin.ignore();
        cin.get();
        system("clear");

    } while (choose != 0);
    
}

void MENU::menuAct() {

    do {
        system("clear");

        cout << TABUL <<CYAN << BOLD <<"=== M E N U ===" << RESET << endl;
        cout << "1. Робота з стеком" << endl; 
        cout << "2. Робота з чергою" << endl;
        cout << "3. Робота з деком" << endl;
        cout << RED <<"4. Вихід" << RESET << endl;

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
                menu3.menu();
                break;

            case 4:
                cout <<"Вихід..." << endl;
                break;

            default:
                cout << "Неправильний вибір." << endl; 
                break;
        }
        cin.ignore();
        cin.get();
        system("clear");
    } while (choose != 4); 
}

