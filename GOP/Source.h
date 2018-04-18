#include <cstdlib>
#include "PLAYER.h"

using namespace std;

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



void forwardByTwo(PLAYER);
void forwardByOne(PLAYER);
void backwardByTwo(PLAYER);
void backwardByOne(PLAYER);
void swapWithFirst(PLAYER);
void backToStart(PLAYER);
void jumpTurn(PLAYER);
void doubleDice(PLAYER);
//void typeTranslate(int, PLAYER);
void createPlayerList();


int main();
