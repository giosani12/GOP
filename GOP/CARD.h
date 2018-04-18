#ifndef CARD_H_
#define CARD_H_

class CARD;
class PLAYER;

typedef PLAYER* ptPLAYER;
typedef CARD* ptCard;

#include "GLOBAL.h"


class CARD : public GLOBAL
{
protected:
	int type ;
	CARD *next ;
		
public:
	int randomCard();
	CARD();
	void drawCard(ptPLAYER, ptCard);
};

#endif
