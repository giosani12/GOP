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
	void tabTypeTranslate();
	void cardTypeTranslate();
	void forwardByTwo();
	void forwardByOne();
	void backwardByTwo();
	void backwardByOne();
	ptPLAYER* getFirst();
	void swapWithFirst();
	void backToStart();
	void skipTurn();
	void doubleDice();
	void createPlayerList();
	void deletePlayerList();
	void drawCard();
	void createDeck();
	void deleteDeck();
	void printChart();
	void firstTurn();
	void nextTurn();
	void endGame(bool);
};
#endif
