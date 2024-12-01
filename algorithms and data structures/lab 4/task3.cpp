#include "Header.h"

int hash_function1(int k, int m) {
	return k % m;
}
int hash_function2(int k, int m) {
	return 1 + k % (m - 1);
}
void add_linar(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	for (int i = 0; i < size; i++) {
		if (hash_table[h].is_empty) {
			hash_table[h].key = key;
			hash_table[h].is_empty = false;
			return;
		}
		h++;
		h = h % size;
	}
	cout << "Таблиця заповнена" << endl;
}
void add_square(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	int h1 = h;
	int c1 = 1;
	int c2 = 3;
	int i = 0;
	while (!hash_table[h1].is_empty)
	{
		h1 = h + c1 * i + c2 * i * i;
		h1 = h1 % size;
		i++;

	}
	if (hash_table[h1].is_empty) {
		hash_table[h1].key = key;
		hash_table[h1].is_empty = false;
		return;
	}
	cout << "Таблиця заповнена" << endl;
}
void add_double(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	int h1 = hash_function2(key, size);
	int c1 = 1;
	int c2 = 3;
	int i = 0;
	while (!hash_table[h1].is_empty)
	{
		h1 = h + i * h1;
		h1 = h1 % size;
		i++;
	}
	if (hash_table[h1].is_empty) {
		hash_table[h1].key = key;
		hash_table[h1].is_empty = false;
		return;
	}
	cout << "Таблиця заповнена" << endl;
}
void print_hash_table3(hash_node* hash_table, int size) {
	cout << "\nХеш-таблиця:\n";
    cout << "===============================\n";
	for (int i = 0; i < size; i++) {
		cout << i << "\t";
		if (hash_table[i].is_empty) {
			cout << CYAN << "Пусто" << RESET << endl;
		}
		else {
			cout << GREEN << hash_table[i].key << RESET << "\n";
		}
	}
	cout << "===============================\n";
}
int find_linar(hash_node* hash_table, int key, int size) {
    int h = hash_function1(key, size);
    for (int i = 0; i < size; i++) {
        if (hash_table[h].is_empty) {
            return -1;  
        }
        if (hash_table[h].key == key) {
            return h;  
        }
        h = (h + 1) % size;
    }
    return -1; 
}
int find_square(hash_node* hash_table, int key, int size) {
    int h = hash_function1(key, size);
    int c1 = 1;
    int c2 = 3;
    int i = 0;
    int h1 = h;
    while (!hash_table[h1].is_empty) {
        if (hash_table[h1].key == key) {
            return h1;  
        }
        h1 = (h + c1 * i + c2 * i * i) % size;
        i++;
        if (i >= size) break;
    }
    return -1;  
}
int find_double(hash_node* hash_table, int key, int size) {
    int h = hash_function1(key, size);
    int h1 = hash_function2(key, size);
    int i = 0;
    int index = h;
    while (!hash_table[index].is_empty) {
        if (hash_table[index].key == key) {
            return index;  
        }
        index = (h + i * h1) % size;
        i++;
        if (i >= size) break;
    }
    return -1;  
}
void delete_node3(hash_node* hash_table, int key, int size) {
	int h = hash_function1(key, size);
	for (int i = 0; i < size; i++)
	{
		if (hash_table[h].key == key) {
			hash_table[h].is_empty = true;
			return;
		}
		h++;
		h = h % size;
	}
	cout << RED << "Вузол не знайдено." << RESET << endl;
}
void create_hash_table_from_file3(hash_node* hash_table, int size, char* filename, void (*add)(hash_node* , int , int )) {
	ifstream fin;
	fin.open(filename, ifstream::in);
	int ptr;
	while (!fin.eof()) {
		fin >> ptr;
		if (fin.eof()) break;
		add(*&hash_table, ptr, size);
	}
	fin.close();
}
void print_hash_table_to_file3(hash_node* hash_table, int size, char* filename) {
	ofstream fout;
	fout.open(filename, ofstream::out | ofstream::trunc);
	for (int i = 0; i < size; i++) {
		if (!hash_table[i].is_empty) {
			fout << hash_table[i].key << " ";
		}
	}
	fout.close();
}
void task3_menu(void (*add) (hash_node*, int, int)) {
	char filename[] = "File.txt";
	int arr[] = { 21, 31, 24, 10, 40, 41, 9, 2, 20 };
	hash_node* hash_table = new hash_node[11];
	int m = 11;
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
		switch (num_menu)
		{
		case 1:
			for (int i = 0; i < 5; i++)
			{
				add(*&hash_table, arr[i], m);
			}
			print_hash_table3(hash_table, m);
			break;
		case 2:
			create_hash_table_from_file3(*&hash_table, m, filename, add);
			print_hash_table3(hash_table, m);
			break;
		case 3:
			print_hash_table3(hash_table, m);
			break;
		case 4:
			print_hash_table_to_file3(*&hash_table, m, filename);
			cout << GREEN << "Хеш-таблиця успішно записана в файл" << RESET << endl;
			break;
		case 5:
			print_hash_table3(hash_table, m);
			cout << "Введіть вузол: ";
			cin >> num_menu;
			add(*&hash_table, num_menu, m);
			break;
		case 6:
			print_hash_table3(hash_table, m);
			cout << "Введіть вузол: ";
			cin >> num_menu;
			delete_node3(*&hash_table, num_menu, m);
			break;
		case 7:
			cout << "Введіть ключ для пошуку: ";
    		cin >> num_menu;
			if (add == add_linar) {
				index = find_linar(hash_table, num_menu, m);
			} else if (add == add_square) {
				index = find_square(hash_table, num_menu, m);
			} else {
				index = find_double(hash_table, num_menu, m);
			}
			if (index != -1) {
				cout << GREEN << "Ключ " << num_menu << " знайдено в хеш-таблиці на індексі " << index << RESET << endl;
			} else {
				cout << RED << "Ключ " << num_menu << " не знайдено в хеш-таблиці" << RESET << endl;
			}
			break;
		case 8:
			quit = false;
			cout << "\n\n";
			break;
		default:
			cout << "Спробуйте ще раз" << endl;
			break;
		}
	}
}
void task3_help_menu() {
	bool quit = true;
	int num_menu;
	while (quit) {
		cout << TABUL << CYAN << BOLD <<"=== M E N U ===" << RESET << endl;

		cout << "1. Використовувати лінійний алгоритм" << endl;
        cout << "2. Використовувати квадратичний алгоритм" << endl;
        cout << "3. Використовувати подвійне хешування" << endl;
        cout << RED << "4. Вихід" << RESET << endl;
        cout << "Оберіть операцію: ";
		cin >> num_menu;
		switch (num_menu)
		{
		case 1:
			task3_menu(add_linar);
			break;
		case 2:
			task3_menu(add_square);
			break;
		case 3:
			task3_menu(add_double);
			break;
		case 4:
			quit = false;
			break;
		default:
			cout << "Спробуйте ще раз" << endl;
			break;
		}
	}
}