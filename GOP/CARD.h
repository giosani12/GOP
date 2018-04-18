#ifndef CARD_H_
#define CARD_H_

typedef CARD *ptCard;

Class CARD {
	protected:
		int type ;
		CARD *next ;
		
	public:
		int randomCard();
		ptCard createDeck(int);
		void drawCard(PLAYER, ptCard);
};

#endif
