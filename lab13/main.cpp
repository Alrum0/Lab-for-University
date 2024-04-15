#include "Header.h"

int main() {
	setlocale(LC_ALL, "ukr");

	Space spaces[N];
	int spectralClass, mass, part, num;

    for (int i = 0; i < N; i++) {
        char spectralClass;
        float mass, part;
        long num;

        cout << "¬вед≥ть спектральний клас: ";
        cin >> spectralClass;
        cout << "¬вед≥ть масу: ";
        cin >> mass;
        cout << "¬вед≥ть частку: ";
        cin >> part;
        cout << "¬вед≥ть к≥льк≥сть: ";
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