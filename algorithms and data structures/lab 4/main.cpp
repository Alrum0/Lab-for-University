#include "Header.h"

int main(void) {
    int choose;
    do {
        cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl;
        cout << "1. Хеш-таблиця (методом відкритої адресації)" << endl; 
        cout << "2. Хеш-таблиця (методом ланцюжків)" << endl; 
        cout << "3. Хеш-таблиця" << endl; 
        cout << RED << "0. Вихід" << RESET << endl;

        cout << "Ваш вибір: ";
        cin >> choose;
        switch (choose) {
        case 1:
            task1_menu();
            break;
        case 2:
            task2_menu();
            break;
        case 3:
            task3_help_menu();
            break;
        case 0:
            exit(1);
        default:
            cout << "Спробуйте ще раз." << endl;
            break;
        }
    } while (choose != 0);
    
}