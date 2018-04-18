#ifndef CARD_H_
#define CARD_H_

class CARD;
class PLAYER;

typedef PLAYER* ptPLAYER;
typedef CARD* ptCard;

#include "GLOBAL.h"


class CARD : public GLOBAL
{
public:
	CARD *next;
	int type ;
	int randomCard();
	CARD();
};

#endif
