#include "GAME.h"
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