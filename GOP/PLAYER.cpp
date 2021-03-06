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

PLAYER::PLAYER(int num, char n[])//costruttore della struttura giocatore, riempi i campi del giocatore corrente,
{								 //usata dal costruttore della lista playerList
	numero = num ;
	position = 1 ;
	strcpy_s(name , n) ;
	jumpTurn = false;
	next = NULL;
}

PLAYER::~PLAYER()
{
}

void PLAYER::setName(char newName[])//riempie il campo del nome
{
	strcpy_s(name, newName);
}