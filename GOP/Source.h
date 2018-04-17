#include <cstdlib>
#include "PLAYER.h"

using namespace std;

typedef PLAYER* ptPLAYER;

struct FOO
{
	int type;
};

struct CARD
{
	FOO deck;
	CARD *next;
};

typedef CARD* ptCard;


int randomCard();
ptCard createDeck(int);
void drawCard(PLAYER, ptCard);
void forwardByTwo(PLAYER);
void forwardByOne(PLAYER);
void backwardByTwo(PLAYER);
void backwardByOne(PLAYER);
void swapWithFirst(PLAYER);
void backToStart(PLAYER);
void jumpTurn(PLAYER);
void doubleDice(PLAYER);
//void typeTranslate(int, PLAYER);
PLAYER* getFirst(ptPLAYER);
void createPlayerList();


int main();
