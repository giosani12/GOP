#include "PLAYER.h"
#include "TABLE.h"
#include "Source.h"
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
using namespace std;

extern ptPLAYER playerList;
extern int NUMERO_GIOCATORI;


/*void typeTranslate(int type, PLAYER foo) {
	if ((type >= 0) && (type < 10)) {
		forwardByTwo();
	}
	else if ((type >= 10) && (type < 40)) {
		forwardByOne();
	}
	else if ((type >= 40) && (type < 60)) {
		backwardByTwo();
	}
	else if ((type >= 60) && (type < 80)) {
		backwardByOne();
	}
	else if ((type >= 80) && (type < 90)) {
		swapWithFirst();
	}
	else if ((type >= 95) && (type < 100)) {
		backToStart();
	}
}*/

void forwardByTwo(ptPLAYER input) {
	input.addToPosition(2);
}

void forwardByOne(ptPLAYER input) {
	input.addToPosition(1);
}

void backwardByTwo(ptPLAYER input) {
	input.addToPosition(-2);
}

void backwardByOne(ptPLAYER input) {
	input.addToPosition(-1);
}

ptPLAYER * getFirst()
{
	int i = 0, count = 0;
	char name[20];
	ptPLAYER *out = new ptPLAYER[NUMERO_GIOCATORI], *tmp;
	strcpy_s(name, playerList->name);
	while ((name != playerList->name) || (count != 0)) {
		if (count < playerList->position) {
			count = playerList->position;
			delete out;
			i = 0;
			out = new ptPLAYER[NUMERO_GIOCATORI];
			out[0] = playerList;
			i++;
		}
		else if (count == playerList->position) {
			out[i] = playerList;
			i++;
		}
		playerList = playerList->next;
	}
	out[i] = NULL;
	tmp = new ptPLAYER[i];
	for (i = 0; out[i] != NULL; i++) tmp[i] = out[i];
	delete out;
	return tmp;
}


void swapWithFirst(ptPLAYER  other) {
	ptPLAYER *first = getFirst();
	int temp = first[0]->position, i=0;
	while (first[i] != NULL) {
		first[i]->position = 1;
		i++;
	}
	other.position = temp;
	delete first;
}

void backToStart(ptPLAYER loser) {
	loser.position = 1;
}

void jumpTurn(ptPLAYER input) {
	input.setJmpTrn(true);
}

void doubleDice(ptPLAYER input) {
	input.Throw_Dice();
}

void createPlayerList()
{
	int num=0, i=1;
	char tmpName[20];
	ptPLAYER tmp;
	while (num < 1) {
		cout << "Inserire numero giocatori: ";
		cin >> num;
		if (num < 1) {
			cout << "\nNumero di giocatori invalido, riprova\n";
		}
	}
	cout << "\nInserire nome per giocatore " << i << ": ";
	cin >> tmpName;
	playerList = new PLAYER(1,tmpName);
	tmp = playerList;
	while (i <= num) {
		cout << "\nInserire nome per giocatore " << i << ": ";
		cin >> tmpName;
		playerList->next = playerList;
		playerList = new PLAYER(i, tmpName);
	}
	playerList->next = tmp;
}


