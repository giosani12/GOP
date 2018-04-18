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



void forwardByTwo(ptPLAYER);
void forwardByOne(ptPLAYER);
void backwardByTwo(ptPLAYER);
void backwardByOne(ptPLAYER);
void swapWithFirst(ptPLAYER);
void backToStart(ptPLAYER);
void jumpTurn(ptPLAYER);
void doubleDice(ptPLAYER);
//void typeTranslate(int, PLAYER);
PLAYER* getFirst(ptPLAYER);
void createPlayerList();


int main();
