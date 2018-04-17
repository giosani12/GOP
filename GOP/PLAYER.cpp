#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "PLAYER.h"
using namespace std;

int dice() {

	int value;
	srand((int)time(0));
	value = (rand() % 6) + 1;
	return value;
}

PLAYER::PLAYER(int num, char n[]) {
	numero = num ;
	position = 0 ;
	strcpy_s(name , n) ;
}

PLAYER::~PLAYER()
{
}


void PLAYER::Throw_Dice() {
	position = position + dice() ;
}

void PLAYER::printPlayer()
{
}
