#include "GAME.h"
#include "TABLE.h"
#include <cstdlib>
#include <iostream>
using namespace std;




TABLE::TABLE(int input)
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

int TABLE::getType(int input)
{
	if ((input >= 0) && (input < lenght))	return pt[input - 1];
	else return 8;
}

void TABLE::printTable()
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
	cout << "\nTraduttore:\n0-10=casellavuota\t	1-11=vai avanti di uno\t2-12=vai avanti di due\t3-13=vai indietro di 1\n4-14=vai indietro di 2\t5-15=ti scambi col primo giocatore\t6-16=salti il turno\n7-17=tiri di nuovo il dado\t8-18=pesca una carta\t9= torna all'inizio";
}
