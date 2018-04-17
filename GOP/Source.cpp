#include "TABLE.h"
#include "Source.h"
#include "PLAYER.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

ptPLAYER playerList = NULL;

int NUMERO_GIOCATORI = 1;

int main() {
	int drop;
	TABLE test = TABLE(60);
	test.printTable();
	drop = 0;
	while (drop != 61) {
		cout << "Inserisci numero casella ";
		cin >> drop;
		if ((0 < drop) && (drop < 61)) {
			cout << test.getType(drop) << endl;
		}
		else
		{
			cout << "Casella invalida, inserire numero di casella valido" << endl;
		}
	}
	ptCard temp=createDeck(3);
	for (int i = 0; i < 30; i++) {

		cout << temp->deck.type << "	";
		temp = temp->next;
		cout << temp->deck.type << "	";
		temp = temp->next;
		cout << temp->deck.type << endl;
		temp = temp->next;
	}



	cin >> drop;
}