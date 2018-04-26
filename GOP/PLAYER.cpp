#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "PLAYER.h"
#include "GAME.h"
#include "TABLE.h"
using namespace std;


PLAYER::PLAYER()
{
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





void PLAYER::setName(char newName[])
{
	strcpy_s(name, newName);
}


bool PLAYER::getJmpTrn()
{
	return jumpTurn;
}

void PLAYER::setJmpTrn(bool set)
{
	jumpTurn = set;
}

