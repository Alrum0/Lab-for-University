#include "Header.h"

void fillStructure() {

}

void sortStructure() {

}

void printStructure() {

}

void gotoxy(int x, int y) {
	COORD crds;
	crds.X = x;
	crds.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), crds);
}