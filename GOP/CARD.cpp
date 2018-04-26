#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "CARD.h"
#include "PLAYER.h"

CARD::CARD() {
}

int CARD::randomCard() {//Restituisce un 
	int value;
	value = rand() % 8;
	return value;
}