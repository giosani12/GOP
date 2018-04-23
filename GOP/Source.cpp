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
	ptGAME GIOCO= new GAME();
	GIOCO->firstTurn();
	drop = 0;
}