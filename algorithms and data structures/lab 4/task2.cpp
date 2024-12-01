#include "Header.h"

int hash_function_2(int k, int m) {
	return k % m;
}
void add_2(hash_node_2* hash_table, int key, int size) {
	int h = hash_function_2(key, size);
	if (hash_table[h].is_empty) {
		hash_table[h].key = key;
		hash_table[h].is_empty = false;
		return;
	}
	else {
		hash_node_2* ptr;
		ptr = &hash_table[h];
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = new hash_node_2;
		ptr->next->key = key;
	}
}
void print_hash_table_2(hash_node_2* hash_table, int size) {
    cout << "\nХеш-таблиця:\n";
    cout << "===============================\n";
    for (int i = 0; i < size; i++) {
        cout << i << ": ";
        
        if (hash_table[i].is_empty) {
            cout << CYAN << "Пусто" << RESET << endl;
        } else {
            hash_node_2* ptr = &hash_table[i];
            cout << "{ ";
            while (ptr != NULL) {
                cout << GREEN << ptr->key << RESET;
                if (ptr->next != NULL) {
                    cout << " -> ";
                }
                ptr = ptr->next;
            }
            cout << " }" << endl;
        }
    }
	cout << "===============================\n";
}
void search_node_2(hash_node_2* hash_table, int key, int size) {
    int h = hash_function_2(key, size);
    hash_node_2* ptr = &hash_table[h];
    int position = 0;

    while (ptr != NULL) {
        if (!ptr->is_empty && ptr->key == key) {
            cout << GREEN << "Ключ " << key << " знайдено в хеш-таблиці на індексі " << h 
                 << ", позиція в ланцюжку: " << position << RESET << endl;
            return;
        }
        ptr = ptr->next;
        position++;
    }

    cout << RED << "Ключ " << key << " не знайдено в хеш-таблиці" << RESET << endl;
}
void delete_node_2(hash_node_2* hash_table, int key, int size) {
	int h = hash_function_2(key, size);
	hash_node_2* ptr;
	ptr = &hash_table[h];
	if (ptr->next == NULL) {
		if (ptr->key == key) {
			ptr->is_empty = true;
			return;
		}
		else {
			cout << RED << "Вузол не знайдено" << RESET <<endl;
			return;
		}
	}
	if (ptr->key == key) {
		ptr->key = ptr->next->key;
		ptr = ptr->next;
		hash_table[h].next = ptr->next;
		delete ptr;
		return;
	}
	hash_node_2* tmp = NULL;
	while(ptr != NULL)
	{
		if (ptr->key == key) {
			tmp->next = ptr->next;
			delete ptr;
			return;
		}
		tmp = ptr;
		ptr = ptr->next;
	}
	cout << RED << "Вузол не знайдено" << RESET << endl;
}
void create_hash_table_from_file_2(hash_node_2* hash_table, int size, char* filename) {
	ifstream fin;
	fin.open(filename, ifstream::in);
	int ptr;
	while (!fin.eof()) {
		fin >> ptr;
		if (fin.eof()) break;
		add_2(*&hash_table, ptr, size);
	}
	fin.close();
}
void print_hash_table_to_file_2(hash_node_2* hash_table, int size, char* filename) {
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	for (int i = 0; i < size; i++) {
		if (!hash_table[i].is_empty) {
			hash_node_2* ptr;
			ptr = &hash_table[i];
			fout << hash_table[i].key << " ";
			while (ptr->next != NULL) {
				ptr = ptr->next;
				fout << ptr->key << " ";
			}
		}
	}
	fout.close();
}
void task2_menu() {
	char filename[] = "File.txt";
	int arr[] = { 21, 31, 24, 10, 40, 41, 9, 2, 20 };
	hash_node_2* hash_table = new hash_node_2[9];
	int m = 9;
	int search_key;
	bool quit = true;
	int num_menu;
	int index;
	while (quit) {
		cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl;

		cout << "1. Створити хеш-таблицю" << endl;
		cout << "2. Завантажити хеш-таблицю з файлу" << endl;
		cout << "3. Показати хеш-таблицю" << endl;
		cout << "4. записати хеш-таблицю в файл" << endl;
		cout << "5. Додати вузл" << endl;
		cout << "6. Видалити вузл" << endl;
		cout << "7. Пошук по ключу" << endl;
		cout << RED <<"8. Вихід" << RESET << endl;

		cout << "Оберіть опцію: ";
		cin >> num_menu;

		switch (num_menu) {
		case 1:
			for (int i = 0; i < 9; i++) {
				add_2(*&hash_table, arr[i], m);
			}
			print_hash_table_2(hash_table, m);
			break;
		case 2:
			create_hash_table_from_file_2(*&hash_table, m, filename);
			print_hash_table_2(hash_table, m);
			break;
		case 3:
			print_hash_table_2(hash_table, m);
			break;
		case 4:
			print_hash_table_to_file_2(*&hash_table, m, filename);
			cout << GREEN << "Хеш-таблиця успішно записана в файл" << RESET << endl;
			break;
		case 5:
			print_hash_table_2(hash_table, m);
			cout << "Введіть вузол: ";
			cin >> num_menu;
			add_2(*&hash_table, num_menu, m);
			break;
		case 6:
			print_hash_table_2(hash_table, m);
			cout << "Введіть вузол: ";
			cin >> num_menu;
			delete_node_2(*&hash_table, num_menu, m);
			break;
		case 7:
			cout << "Введіть ключ для пошуку: ";
    		cin >> search_key;
    		search_node_2(hash_table, search_key, m);
			break;
		case 8:
			quit = false;
			break;
		default:
			cout << RED << "Неправильний вибір, спробуйте ще раз." << RESET << endl;
			break;
		}

	}
}