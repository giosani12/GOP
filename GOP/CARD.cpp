#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "CARD.h"
#include "PLAYER."

ptCard CARD::createDeck(int cards) {
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

int CARD::randomCard() {
	int value;

	value = (rand() % 200) +1;
	return value;

void CARD::drawCard(ptPlayer CURRENT, ptCard pt) {
	//typeTranslate(pt->deck.type, input);
	pt = pt->next;
}
