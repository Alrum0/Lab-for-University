#include "Header.h"

int main() {
	setlocale(LC_ALL, "ukr");

	Space spaces[N];
	int spectralClass, mass, part, num;

    for (int i = 0; i < N; i++) {
        char spectralClass;
        float mass, part;
        long num;

        cout << "������ ������������ ����: ";
        cin >> spectralClass;
        cout << "������ ����: ";
        cin >> mass;
        cout << "������ ������: ";
        cin >> part;
        cout << "������ �������: ";
        cin >> num;

        spaces[i].setSpectralClass(spectralClass);
        spaces[i].setMass(mass);
        spaces[i].setPart(part);
        spaces[i].setNum(num);
    }

	spaces[0].showUp();

	for (int i = 0; i < N; i++) {
		spaces[i].show();
	}

	spaces[0].showDown();



	/*switchMenuTask();*/

}