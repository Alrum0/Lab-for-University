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
        cout << "������ i���i ���� � ������." << endl;
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
        cout << "���� ��i����, �� ����������� �� ����� " << letter << "." << endl;
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
        cout << "���� ��i����, �� ����������� �� ����� " << letter << "." << endl;
    }
    else {
        cout << "���i�i�, �� ����������� �� ����� " << letter << " �������i." << endl;
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
            cout << "����:" << endl;
            cout << "1. ������� ������" << endl;
            cout << "2. ����� �� i���i" << endl;
            cout << "3. ������ �� ����i� ����i ��i�����" << endl;
            cout << "4. �������� ��i� �� ����� ����� ��i�����" << endl;
            cout << "5. �������� ����� ������" << endl;
            cout << "6. �����" << endl;
            cout << "��� ���i�: ";
            cin >> choice;

            switch (choice) {
            case 1:
                if (!isGenerated) {
                    phonebook = generateRandomPhonebook(rand() % 10 + 1); // �������� �� 1 �� 5 ������
                    isGenerated = true;
                }
                printList(phonebook);
                break;
            case 2: {
                string name;
                cout << "����i�� i�'� ��� ������: ";
                cin >> name;
                searchByName(phonebook, name);
                break;
            }
            case 3: {
                char letter;
                cout << "����i�� ����� ����� ��i�����: ";
                cin >> letter;
                searchByFirstLetter(phonebook, letter);
                break;
            }
            case 4: {
                char letter;
                cout << "����i�� ����� ����� ��i����� ��� ���������: ";
                cin >> letter;
                deleteByFirstLetter(phonebook, letter);
                break;
            }
            case 5:
                phonebook = generateRandomPhonebook(rand() % 10 + 1); 
                isGenerated = true;
                break;
            case 6:
                cout << "���i�...\n";
                break;
            default:
                cout << "���i���� ����, ��������� �� ���.\n";
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
