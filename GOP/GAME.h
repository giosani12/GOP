#ifndef GAME_H_
#define GAME_H_

class GAME
{
	friend class PLAYER;
	friend class TABLE;
	friend class CARD;
protected:
	ptPLAYER playerList ;
	int NUMERO_GIOCATORI ;
	
public:
		GAME() ;
};

#endif
