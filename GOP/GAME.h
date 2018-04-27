#ifndef GAME_H_
#define GAME_H_
class PLAYER;
class CARD;
class TABLE;
class GAME;
typedef TABLE* ptTABLE;
typedef PLAYER* ptPLAYER;
typedef CARD* ptCARD;
typedef GAME* ptGAME;

class GAME
{
protected:
	ptPLAYER playerList;
	int NUMERO_GIOCATORI;
	ptCARD ptDeck;
	ptTABLE ptTab;
	void addToPosition(int);
	void throwDice();
	void tabTypeTranslate();
	void cardTypeTranslate();
	void forwardByTwo();
	void forwardByOne();
	void backwardByTwo();
	void backwardByOne();
	void getFirst(ptPLAYER*);
	void swapWithFirst();
	void backToStart();
	void skipTurn();
	void createPlayerList();
	void deletePlayerList();
	void drawCard();
	void createDeck();
	void deleteDeck();
	void printChart();
	void nextTurn();
	void endGame(bool);
public:
	GAME();
	void firstTurn();
};
#endif
