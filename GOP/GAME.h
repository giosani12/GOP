#ifndef GAME_H_
#define GAME_H_
class PLAYER;
class CARD;
class TABLE;
class GAME;
typedef TABLE* ptTABLE;
typedef PLAYER* ptPLAYER;
typedef CARD* ptCard;
typedef GAME* ptGAME;

class GAME
{
protected:
	
public:
	ptPLAYER playerList;
	int NUMERO_GIOCATORI;
	ptCard ptDeck;
	ptTABLE ptTab;
	GAME();
	void createPlayerList();
	void drawCard();
	void printPlayers();
	void createDeck();
	void printChart();
	void init();
	void firstTurn();
	void nextTurn();
	void endGame();
};
#endif
