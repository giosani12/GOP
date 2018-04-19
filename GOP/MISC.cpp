#include "GLOBAL.h"
#include "PLAYER.h"
#include "TABLE.h"
#include "Source.h"
#include "CARD.h"
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
using namespace std;

extern ptPLAYER playerList;
extern int NUMERO_GIOCATORI;


void typeTranslate(int type) {
	if ((type >= 0) && (type < 15)) {
		forwardByTwo();
	}
	else if ((type >= 15) && (type < 45)) {
		forwardByOne();
	}
	else if ((type >= 45) && (type < 60)) {
		backwardByTwo();
	}
	else if ((type >= 60) && (type < 75)) {
		backwardByOne();
	}
	else if ((type >= 70) && (type < 75)) {
		swapWithFirst();
	}
	else if ((type >= 75) && (type < 80)) {
		backToStart();
	}
	else if ((type >= 80) && (type < 95)) {
		jumpTurn();
	}
	else if ((type >= 95) && (type < 110)) {
		doubleDice();
	}
	 else cout << "INTERNAL_ERROR -Prego allontanarsi dal computer ";
}

void forwardByTwo() {
	playerList->addToPosition(2);
}

void forwardByOne() {
	playerList->addToPosition(1);
}

void backwardByTwo() {
	playerList->addToPosition(-2);
}

void backwardByOne() {
	playerList->addToPosition(-1);
}

void doubleDice() {
	playerList->Throw_Dice();
}

void backToStart() {
	playerList->position = 1;
}

void jumpTurn() {
	playerList->setJmpTrn(true);
}



void swapWithFirst() {
	ptPLAYER *first = (playerList->getFirst());
	int temp = first[0]->position, i=0;
	while (first[i] != NULL) {
		first[i]->position = playerList->position;
		i++;
	}
	playerList->position = temp;
	delete first;
}


void createPlayerList(GLOBAL *glob)
{
	int num=0, i=1;
	char tmpName[20];
	ptPLAYER tmp, ptHead;
	tmpName[0] = '\0';
	while (num < 1) {
		cout << "Inserire numero giocatori: ";
		cin >> num;
		if (num < 1) {
			cout << "\nNumero di giocatori invalido, riprova\n";
		}
	}
	glob->NUMERO_GIOCATORI = num;
	cout << "\nInserire nome per giocatore " << i << ": ";
	cin.getline(tmpName, 20, '\n');
	cin.getline(tmpName, 20, '\n');
	glob->playerList = new PLAYER(1,tmpName);
	ptHead = glob->playerList;
	i++;
	while (i <= num) {
		cout << "\nInserire nome per giocatore " << i << ": ";
		cin.getline(tmpName, 20, '\n');
		tmp = new PLAYER(i, tmpName);
		glob->playerList->next = tmp;
		glob->playerList = tmp;
		i++;
	}
	glob->playerList->next = ptHead;
	glob->playerList = ptHead;
}

void drawCard(ptCard current)
{
	typeTranslate(current->type);
	current = current->next;
}

void printPlayers(GLOBAL *glob) {
	cout << "\n|Num\t|Pos\t|Name\n";
	ptPLAYER tmp = glob->playerList;
	while (glob->playerList->numero < glob->NUMERO_GIOCATORI) {
		cout << "|" << glob->playerList->numero << "\t|"<< glob->playerList->position << "\t|" << glob->playerList->name << "\n";
		glob->playerList = glob->playerList->next;
	}
	cout << "|" << glob->playerList->numero << "\t|" << glob->playerList->position << "\t|" << glob->playerList->name;
	glob->playerList = tmp;
}

ptCard createDeck() {
	ptCard deckIn = new CARD();
	ptCard tmp = deckIn;
	for (int i = 0; i < 40; i++) {
		tmp->type = tmp->randomCard();
		if (i < 39) {
			tmp->next = new CARD();
			tmp = tmp->next;
		}
	}
	tmp->next = deckIn;
	return deckIn;
}

void init(GLOBAL *start) {
	start->ptTab = new TABLE(60);
	createPlayerList(start);
	start->playerList->Throw_Dice();
	printPlayers(start);
	start->ptTab->printTable();
	start->ptDeck = createDeck();
	cout << endl << start->NUMERO_GIOCATORI << " " << start->playerList << " " << start->ptDeck << " " << start->ptTab;
}
