#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_


class PLAYER 
{
private:
	int numero;
	int position;
	char name[20];
public:
	PLAYER(int, char[]);
	~PLAYER();
	void Throw_Dice();
	void printPlayer();
};
#endif
