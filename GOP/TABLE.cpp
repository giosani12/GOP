#include "GAME.h"
#include "TABLE.h"
#include <cstdlib>
#include <iostream>
using namespace std;

TABLE::TABLE(int input)//costruttore tabella, inizializza tutti i campi e prende in input la lunghezza
{
	lenght = input;
	valid = true;
	pt = new int[lenght];
	for (int i = 0; i < lenght-1; i++) {
		pt[i] = rand() %19;
	}
	pt[lenght - 1] = 0;
}

TABLE::~TABLE()
{
	valid = false;
}

int TABLE::getType(int input)//traduttore da numero casella a tipo di casella
{
	if ((input >= 0) && (input < lenght))	return pt[input - 1];
	else return 8;
}

void TABLE::printTable()//stampa la tabella
{
	if (valid) {
		cout << "\nFormato casella: |Numero Casella| Tipo Casella (vedi traduttore sottostante)|" << endl;
		cout << "+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+" << endl;
		for (int j = 0;j<lenght; j++) {
			cout << "|" << j+1 << "| " << pt[j]%10 << "\t";
			if ((j+1) % 14 == 0) {
				cout << "|" << endl << "+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+"<< endl;
			}
		}
		if ((lenght % 14) != 0) cout << "|" << endl;
	}
	else {
		cout << "WTF u doing there's no fucking TABLE to print DUMBASS" << endl;
	}
}