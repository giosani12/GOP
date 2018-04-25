#ifndef PLAYER_H_
#define PLAYER_H_
#include "GAME.h"

typedef PLAYER* ptPLAYER;

class PLAYER : public GAME
{
protected:
	bool jumpTurn;
public:
	int position;
	int numero;
	char name[20];
	ptPLAYER next;
	PLAYER();
	PLAYER(int, char[]);
	~PLAYER();
	void Throw_Dice();
	void setName(char[]);
	void addToPosition(int);
	bool getJmpTrn();
	void setJmpTrn(bool);
	ptPLAYER* getFirst();
};


#endif