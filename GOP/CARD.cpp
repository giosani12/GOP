#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "CARD.h"
#include "PLAYER.h"

CARD::CARD() {
	ptCard deckIn = new CARD;
	ptCard tmp = deckIn;
	for (int i = 0; i < 40; i++) {
		tmp->deck.type = randomCard();
		if (i < cards - 1) {
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

void CARD::drawCard(ptPLAYER CURRENT, ptCard pt) {
	//typeTranslate(pt->deck.type, input);
	pt = pt->next;
}
