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





void PLAYER::Throw_Dice() {
	int j = dice();
	position = position + j ;
	cout << endl << name << " tira il dado ed esce " << j << ", ora " << name << " e\' in posizione " << position << ".";
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


bool PLAYER::getJmpTrn()
{
	return jumpTurn;
}

void PLAYER::setJmpTrn(bool set)
{
	jumpTurn = set;
}

