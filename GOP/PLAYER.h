#ifndef PLAYER_H_
#define PLAYER_H_
#include "GAME.h"

typedef PLAYER* ptPLAYER;

class PLAYER : public GAME
{
public:
	bool jumpTurn;
	int position;
	int numero;
	char name[20];
	ptPLAYER next;
	PLAYER();
	PLAYER(int, char[]);
	~PLAYER();
	void setName(char[]);
	bool getJmpTrn();
	void setJmpTrn(bool);
};


#endif