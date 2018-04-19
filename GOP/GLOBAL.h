#ifndef GLOBAL_H_
#define GLOBAL_H_
class PLAYER;
class CARD;
class TABLE;
class GLOBAL;
typedef TABLE* ptTABLE;
typedef PLAYER* ptPLAYER;
typedef CARD* ptCard;
typedef GLOBAL* ptGLOBAL;
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

