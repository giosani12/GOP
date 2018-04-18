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

int randomCard() {
	int value;

	value = rand() % 200;
	return value;
}

ptCard createDeck(int cards) {
	ptCard deckIn = new CARD;
	ptCard tmp = deckIn;
	srand((int)time(0));
	for (int i = 0; i < cards; i++) {
		tmp->deck.type = randomCard();
		if (i < cards - 1) {
			tmp->next = new CARD;
			tmp = tmp->next;
		}
	}
	tmp->next = deckIn;
	return deckIn;
}

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

void drawCard(PLAYER input, ptCard pt) {
	//typeTranslate(pt->deck.type, input);
	pt = pt->next;
}

void forwardByTwo(PLAYER input) {
	input.addToPosition(2);
}

void forwardByOne(PLAYER input) {
	input.addToPosition(1);
}

void backwardByTwo(PLAYER input) {
	input.addToPosition(-2);
}

void backwardByOne(PLAYER input) {
	input.addToPosition(-1);
}



void swapWithFirst(PLAYER  other) {
	ptPLAYER *first = getFirst();
	int temp = first[0]->position, i=0;
	while (first[i] != NULL) {
		first[i]->position = 1;
		i++;
	}
	other.position = temp;
	delete first;
}

void backToStart(PLAYER loser) {
	loser.position = 1;
}

void jumpTurn(PLAYER input) {
	input.setJmpTrn(true);
}

void doubleDice(PLAYER input) {
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


