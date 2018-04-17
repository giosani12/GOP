#include "TABLE.h"
#include "stdlib.h"
#include <iostream>
using namespace std;




TABLE::TABLE(int input)
{
	lenght = input;
	valid = true;
	for (int i = 0; i < lenght; i++) {
		pt[i] = rand() %8;
	}
}

TABLE::~TABLE()
{
	valid = false;
}

int TABLE::getType(int input)
{
	return pt[input-1];
}

void TABLE::printTable()
{
	if (valid) {
		cout << "Formato casella: |Numero Casella| Tipo Casella (vedi traduttore sottostante)|" << endl;
		cout << "+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
		for (int j = 0;j<lenght; j++) {
			cout << "|" << j+1 << "| " << pt[j] << "\t";
			if ((j+1) % 10 == 0) {
				cout << "|" << endl << "+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
			}
		}
		if ((lenght % 10) != 0) cout << "|" << endl;
	}
	else {
		cout << "WTF u doing there's no fucking TABLE to print DUMBASS" << endl;
	}
}