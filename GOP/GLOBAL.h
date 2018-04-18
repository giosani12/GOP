#ifndef GLOBAL_H_
#define GLOBAL_H_
class PLAYER;
class CARD;
class TABLE;
typedef TABLE* ptTABLE;
typedef PLAYER* ptPLAYER;
typedef CARD* ptCard;
class GLOBAL
{
public:
	ptPLAYER playerList;
	int NUMERO_GIOCATORI;
	ptCard ptDeck;
	ptTABLE ptTab;
	GLOBAL();
	~GLOBAL();
};
#endif

