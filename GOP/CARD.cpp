#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "CARD.h"
#include "PLAYER.h"
#include "GLOBAL.h"
#include "Source.h"

CARD::CARD() {
	ptCard deckIn = new CARD;
	ptCard tmp = deckIn;
	for (int i = 0; i < 40; i++) {
		tmp->type = randomCard();
		if (i < 39) {
			tmp->next = new CARD;
			tmp = tmp->next;
		}
	}
	tmp->next = deckIn;
}

int CARD::randomCard() {
	int value;
	value = (rand() % 200) + 1;
	return value;
}
