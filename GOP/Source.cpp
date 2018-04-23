#include "GAME.h"
#include "TABLE.h"
#include "Source.h"
#include "PLAYER.h"
#include "CARD.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

ptPLAYER playerList = NULL;

int NUMERO_GIOCATORI = 1;

int main() {
	int drop;
	ptGAME GLOB= new GAME();
	init(GLOB);
	drop = 0;
	while (drop != 61) {
		cout << "\nInserisci numero casella ";
		cin >> drop;
		if ((0 < drop) && (drop < 61)) {
			cout << GLOB->ptTab->getType(drop) << endl;
		}
		else
		{
			cout << "Casella invalida, inserire numero di casella valido" << endl;
		}
	}
	cin >> drop;
}