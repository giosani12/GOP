#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "CARD.h"
#include "PLAYER.h"
#include "GLOBAL.h"
#include "Source.h"

CARD::CARD() {
}

int CARD::randomCard() {
	int value;
	value = (rand() % 200) + 1;
	return value;
}
