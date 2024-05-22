#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class NAME {
public:
    string first;
    string second;

    NAME(string f = "", string s = "") : first(f), second(s) {}

    bool operator<(const NAME& other) const {
        return first < other.first;
    }

    void get() const {
        
        cout << setw(14) << left << first << " |" << setw(14) << left << second << "  |";
    }
};

class NUMBER {
public:
    string number;

    NUMBER(string n = "") : number(n) {}

    void get() const {
        cout << setw(17) << left << number << " |";
    }
};



void printList(const map<NAME, NUMBER>& phonebook) {
    cout << "------------------------------------------------------\n";
    cout << "| " << setw(14) << left << "First Name" << " | " << setw(14) << left << "Last Name" << " | " << setw(16) << left << "Phone Number" << " |\n";
    cout << "|----------------|----------------|------------------|\n";
    for (const auto& entry : phonebook) {
        cout << "| ";
        entry.first.get();
        entry.second.get();
        cout << "\n";
        cout << "|----------------|----------------|------------------|\n";
    }
}

void searchByName(const map<NAME, NUMBER>& phonebook, const string& name) {
    bool found = false;
    for (const auto& entry : phonebook) {
        
        if (entry.first.first == name) {
            printList({ {entry.first, entry.second} });
            found = true;
            break; 
        }
    }
    if (!found) {
        cout << "Такого iменi немає в списку." << endl;
    }
}

void searchByFirstLetter(const map<NAME, NUMBER>& phonebook, char letter) {
    bool found = false;
    map<NAME, NUMBER> filtered;
    for (const auto& entry : phonebook) {
       
        if (entry.first.second[0] == letter) {
            filtered.insert(entry);
            found = true;
        }
    }
    if (found) {
        printList(filtered);
    }
    else {
        cout << "Немає прiзвищ, що починаються на букву " << letter << "." << endl;
    }
}

void deleteByFirstLetter(map<NAME, NUMBER>& phonebook, char letter) {
    bool found = false;
    for (auto it = phonebook.begin(); it != phonebook.end();) {
        if (it->first.second[0] == letter) {
            it = phonebook.erase(it);
            found = true;
        }
        else {
            it++;
        }
    }
    if (!false) {
        cout << "Немає прiзвищ, що починаються на букву " << letter << "." << endl;
    }
    else {
        cout << "Фамiлiї, що починаються на букву " << letter << " видаленi." << endl;
    }
}

string randomPhoneNumber() {
    string number = "+";
    for (int i = 0; i < 12; ++i) {
        number += to_string(rand() % 10);
    }
    return number;
}

map<NAME, NUMBER> generateRandomPhonebook(size_t size) {
    vector<string> firstNames = { "John", "Jane", "Alice", "Bob", "Michael" };
    vector<string> lastNames = { "Smith", "Johnson", "Williams", "Brown", "Jones" };

    map<NAME, NUMBER> phonebook;
    for (size_t i = 0; i < size; ++i) {
        NAME name(firstNames[rand() % firstNames.size()], lastNames[rand() % lastNames.size()]);
        NUMBER number(randomPhoneNumber());
        phonebook[name] = number;
    }
    return phonebook;
}

class MENU {
protected:
    map<NAME, NUMBER> phonebook;
    bool isGenerated = false;
    int choice;
public:
     void Menu() {
        do {
            cout << "Меню:" << endl;
            cout << "1. Вивести список" << endl;
            cout << "2. Пошук по iменi" << endl;
            cout << "3. Шукати по першiй буквi прiзвища" << endl;
            cout << "4. Видалити всiх на пергу букву прiзвища" << endl;
            cout << "5. Створити новий список" << endl;
            cout << "6. Вийти" << endl;
            cout << "Ваш вибiр: ";
            cin >> choice;

            switch (choice) {
            case 1:
                if (!isGenerated) {
                    phonebook = generateRandomPhonebook(rand() % 10 + 1); // Генеруємо від 1 до 5 записів
                    isGenerated = true;
                }
                printList(phonebook);
                break;
            case 2: {
                string name;
                cout << "Введiть iм'я для пошуку: ";
                cin >> name;
                searchByName(phonebook, name);
                break;
            }
            case 3: {
                char letter;
                cout << "Введiть першу букву прiзвища: ";
                cin >> letter;
                searchByFirstLetter(phonebook, letter);
                break;
            }
            case 4: {
                char letter;
                cout << "Введiть першу букву прiзвища для видалення: ";
                cin >> letter;
                deleteByFirstLetter(phonebook, letter);
                break;
            }
            case 5:
                phonebook = generateRandomPhonebook(rand() % 10 + 1); 
                isGenerated = true;
                break;
            case 6:
                cout << "Вихiд...\n";
                break;
            default:
                cout << "Невiрний вибір, спробуйте ще раз.\n";
            }

            system("pause");
            system("cls");

        } while (choice != 6);
    }
};


int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(NULL));

    MENU menu;
    menu.Menu();
}
