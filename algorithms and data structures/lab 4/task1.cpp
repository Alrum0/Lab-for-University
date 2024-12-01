#include "Header.h"
const double A = (sqrt(5) - 1) / 2; 

int hash_function(int k, int m) {
	double y, n;
	y = modf(A * k, &n); 
	return (int)(m * y);
}


void add(hash_node* hash_table, int key, int size) {
	int h = hash_function(key, size);
	for (int i = 0; i < size; i++) {
		if (hash_table[h].is_empty) { // Знаходження вільної позиції
			hash_table[h].key = key;
			hash_table[h].is_empty = false;
			return;
		}
		h = (h + 1) % size; // Лінійне зондування
	}
	cout << "Таблиця заповнена!" << endl;
}


void print_hash_table(hash_node* hash_table, int size) {
    cout << "\nХеш-таблиця:\n";
    cout << "===============================\n";
    for (int i = 0; i < size; i++) {
        cout << i << ":\t";
        if (hash_table[i].is_empty) {
            cout << CYAN << "Пусто" << RESET << endl;
        } else {
            cout << GREEN << hash_table[i].key << RESET << endl;
        }
    }
    cout << "===============================\n";
}

void delete_node(hash_node* hash_table, int key, int size) {
	int h = hash_function(key, size);
	for (int i = 0; i < size; i++) {
		if (hash_table[h].key == key && !hash_table[h].is_empty) {
			hash_table[h].is_empty = true; 
			return;
		}
		h = (h + 1) % size;
	}
	cout << RED << "Вузол не знайдено" << RESET << endl;
}

void search_node(hash_node* hash_table, int key, int size) {
    int h = hash_function(key, size);
    for (int i = 0; i < size; i++) {
        if (hash_table[h].key == key && !hash_table[h].is_empty) {
            cout << GREEN << "Вузол з ключем " << key << " знайдений в позиції " << h << RESET << endl;
            return;
        }
        if (hash_table[h].is_empty) {
            break; 
        }
        h = (h + 1) % size;
    }
    cout << RED << "Вузол з ключем " << key << " не знайдений" << RESET << endl;
}

void create_hash_table_from_file(hash_node* hash_table, int size, const char* filename) {
	ifstream fin(filename);
	if (!fin) {
		cout << RED << "Помилка відкриття файлу" << RESET << endl;
		return;
	}
	int ptr;
	while (fin >> ptr) {
		add(hash_table, ptr, size);
	}
	fin.close();
}


void print_hash_table_to_file(hash_node* hash_table, int size, const char* filename) {
	ofstream fout(filename);
	if (!fout) {
		cout << RED << "Помилка відкриття файлу для запису" << RESET << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		if (!hash_table[i].is_empty) {
			fout << hash_table[i].key << " ";
		}
	}
	fout.close();
	cout << GREEN << "Хеш-таблиця успішно записана в файл" << RESET << endl;
}


void task1_menu() {
	const char filename[] = "File.txt";
	int arr[] = { 51, 52, 53, 54, 55};
	const int m = 20;
	hash_node* hash_table = new hash_node[m]; 
	bool quit = false;
	int num_menu;

	while (!quit) {
		cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl;

		cout << "1. Створити хеш-таблицю\n";
		cout << "2. Завантажити хеш-таблицю з файлу\n";
		cout << "3. Показати хеш-таблицю\n";
		cout << "4. Записати хеш-таблицю в файл\n";
		cout << "5. Додати вузл\n";
		cout << "6. Видалити вузл\n";
		cout << "7. Пошук по ключу" << endl;
		cout << RED << "8. Вихід" << RESET << endl;

		cout << "Оберіть опцію: ";
		cin >> num_menu;

		switch (num_menu) {
			case 1:
				for (int i = 0; i < 5; i++) {
					add(hash_table, arr[i], m);
				}
				print_hash_table(hash_table, m);
				break;
			case 2:
				create_hash_table_from_file(hash_table, m, filename);
				print_hash_table(hash_table, m);
				break;
			case 3:
				print_hash_table(hash_table, m);
				break;
			case 4:
				print_hash_table_to_file(hash_table, m, filename);
				break;
			case 5:
				cout << "Введіть ключ для додавання: ";
				cin >> num_menu;
				add(hash_table, num_menu, m);
				break;
			case 6:
				cout << "Введіть ключ для видалення: ";
				cin >> num_menu;
				delete_node(hash_table, num_menu, m);
				break;
			case 7:
				cout << "Введіть ключ для пошуку: ";
                cin >> num_menu;
                search_node(hash_table, num_menu, m);
				break;
			case 8:
				quit = true;
				break;
			default:
				cout << RED << "Неправильний вибір. Спробуйте ще раз." << RESET << endl;
				break;
		}

	}
	delete[] hash_table; 
}