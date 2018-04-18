#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "PLAYER.h"
#include "GAME.h"
using namespace std;

int dice() {
	int value;
	srand((int)time(0));
	value = (rand() % 6) + 1;
	return value;
}

PLAYER::PLAYER(int num, char n[]) {
	numero = num ;
	position = 1 ;
	strcpy_s(name , n) ;
	jumpTurn = false;
	next = NULL;
}

PLAYER::~PLAYER()
{
}


void PLAYER::Throw_Dice() {
	position = position + dice() ;
}

void PLAYER::setName(char newName[])
{

	strcpy_s(name, newName);
}

void PLAYER::addToPosition(int num)
{
	if ((num + position) > 0) {
		position = position + num;
	}
	else position = 1;
}

void PLAYER::printPlayer()
{

}

bool PLAYER::getJmpTrn()
{
	return jumpTurn;
}

void PLAYER::setJmpTrn(bool set)
{
	jumpTurn = set;
}

ptPLAYER PLAYER::getFirst()
{
	int i = 0, count = 0;
	char name[20];
	ptPLAYER ptTMP = playerList;
	ptPLAYER *out = new ptPLAYER[NUMERO_GIOCATORI], *tmp;
	strcpy_s(name, playerList->name);
	while ((name != playerList->name) || (count != 0)) {
		if (count < playerList->position) {
			count = playerList->position;
			delete out;
			i = 0;
			out = new ptPLAYER[NUMERO_GIOCATORI];
			out[0] = playerList;
			i++;
		}
		else if (count == playerList->position) {
			out[i] = playerList;
			i++;
		}
		playerList = playerList->next;
	}
	out[i] = NULL;
	tmp = new ptPLAYER[i];
	for (i = 0; out[i] != NULL; i++) tmp[i] = out[i];
	delete out;
	playerList = ptTMP;
	return tmp;
}
