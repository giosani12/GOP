#include "PLAYER.h"
#ifndef CARD_H_
#define CARD_H_

typedef CARD *ptCard;

class CARD {
protected:
	int type ;
	CARD *next ;
		
public:
	int randomCard();
	ptCard createDeck(int);
	void drawCard(ptPLAYER, ptCard);
};

#endif
