#include "TABLE.h"
#include "PLAYER.h"
#include "Source.h"
#include <cstdlib>
#include <ctime>
using namespace std;


int randomCard() {
	int value;

	value = rand() % 10;
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


void typeTranslate(int type) {
	if ((type >= 0) && (type < 10)) {
		function_0();
	}
	else if ((type >= 10) && (type < 40)) {
		function_1();
	}
	else if ((type >= 40) && (type < 60)) {
		function_2();
	}
	else if ((type >= 60) && (type < 80)) {
		function_3();
	}
	else if ((type >= 80) && (type < 90)) {
		function_4();
	}
	else if ((type >= 90) && (type < 100)) {
		function_5();
	}
}