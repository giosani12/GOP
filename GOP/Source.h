#include <cstdlib>
#include "PLAYER.h"
#include "GAME.h"

using namespace std;


void forwardByTwo();
void forwardByOne();
void backwardByTwo();
void backwardByOne();
void swapWithFirst();
void backToStart();
void jumpTurn();
void doubleDice();
void typeTranslate(int);

void createPlayerList(ptGAME);
void drawCard(ptCard);
void printPlayers(ptGAME);
ptCard createDeck();
void printChart(ptGAME);
void init(ptGAME);



int main();
