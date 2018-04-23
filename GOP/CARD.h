#ifndef CARD_H_
#define CARD_H_

class CARD;
class PLAYER;

typedef PLAYER* ptPLAYER;
typedef CARD* ptCard;

#include "GAME.h"


class CARD : public GAME
{
public:
	CARD *next;
	int type ;
	int randomCard();
	CARD();
};

#endif
