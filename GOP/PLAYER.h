#ifndef PLAYER_H_
#define PLAYER_H_


class PLAYER 
{
protected:
	bool jumpTurn;
public:
	int position;
	int numero;
	char name[20];
	PLAYER * next;
	PLAYER(int, char[]);
	~PLAYER();
	void Throw_Dice();
	void setName(char[]);
	void addToPosition(int);
	void printPlayer();
	bool getJmpTrn();
	void setJmpTrn(bool);

};

#endif