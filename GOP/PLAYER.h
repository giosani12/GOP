#ifndef PLAYER_H_
#define PLAYER_H_
#include "GLOBAL.h"

typedef PLAYER* ptPLAYER;

class PLAYER : public GLOBAL
{
protected:
	bool jumpTurn;
public:
	int position;
	int numero;
	char name[20];
	ptPLAYER next;
	PLAYER(int, char[]);
	~PLAYER();
	void Throw_Dice();
	void setName(char[]);
	void addToPosition(int);
	void printPlayer();
	bool getJmpTrn();
	void setJmpTrn(bool);
	ptPLAYER* getFirst();
};


#endif