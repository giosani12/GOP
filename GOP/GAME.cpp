#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GAME.h"
#include "CARD.h"
#include "PLAYER.h"
#include "Source.h"
#include "TABLE.h"

using namespace std;

GAME::GAME() {	
}


void GAME::createPlayerList()
{
	int num = 0, i = 1;
	char tmpName[20];
	ptPLAYER tmp, ptHead;
	tmpName[0] = '\0';
	while (num < 1) {
		cout << "Inserire numero giocatori: ";
		cin >> num;
		if (num < 1) {
			cout << "\nNumero di giocatori invalido, riprova\n";
		}
	}
	NUMERO_GIOCATORI = num;
	cout << "\nInserire nome per giocatore " << i << ": ";
	cin.getline(tmpName, 20, '\n');
	cin.getline(tmpName, 20, '\n');
	playerList = new PLAYER(1, tmpName);
	ptHead = playerList;
	i++;
	while (i <= num) {
		cout << "\nInserire nome per giocatore " << i << ": ";
		cin.getline(tmpName, 20, '\n');
		tmp = new PLAYER(i, tmpName);
		playerList->next = tmp;
		playerList = tmp;
		i++;
	}
	playerList->next = ptHead;
	playerList = ptHead;
}

void GAME::drawCard()
{
	typeTranslate(ptDeck->type);
	ptDeck = ptDeck->next;
}


void GAME::printPlayers() {
	cout << "\n|Num\t|Pos\t|Name\n";
	ptPLAYER tmp = playerList;
	while (playerList->numero < NUMERO_GIOCATORI) {
		cout << "|" << playerList->numero << "\t|" << playerList->position << "\t|" << playerList->name << "\n";
		playerList = playerList->next;
	}
	cout << "|" << playerList->numero << "\t|" << playerList->position << "\t|" << playerList->name;
	playerList = tmp;
}

void GAME::createDeck() {
	ptDeck = new CARD();
	ptCard tmp = ptDeck;
	for (int i = 0; i < 40; i++) {
		tmp->type = tmp->randomCard();
		if (i < 39) {
			tmp->next = new CARD();
			tmp = tmp->next;
		}
	}
	tmp->next = ptDeck;
}

void GAME::printChart() {
	ptPLAYER tmp = playerList;
	bool found = false;
	int pos = 0;
	cout << "\nCLASSIFICA:\n|Posizione\t|Nome Giocatore";
	for (int i = ptTab->lenght; i > 0; i--) {

		for (int j = 0; j<NUMERO_GIOCATORI; j++) {
			if ((i == playerList->position) && !found)
			{
				pos = pos + 1;
				cout << "\n|" << pos << "\t\t|" << playerList->name;
				found = true;
			}
			else if ((i == playerList->position) && found)
			{
				cout << "\n|" << pos << "\t\t|" << playerList->name;
			}
			playerList = playerList->next;
		}
		found = false;
	}
}

void GAME::init() {
	ptTab = new TABLE(60);
	createPlayerList();
	playerList->Throw_Dice();
	printPlayers();
	ptTab->printTable();
	printChart();
	createDeck();
}

void GAME::firstTurn()
{
	cout << "Questo e\' il gioco GOP per il progetto di programmazione\nInserire ora i dati per iniziare una partita:" << endl;
	createPlayerList();
	createDeck();
	ptTab = new TABLE(rand());
	playerList->Throw_Dice;
	typeTranslate(ptTab->getType(playerList->position));
	ptTab->printTable;
	printChart;
	nextTurn();
}

void GAME::nextTurn()
{
}

void GAME::endGame()
{
}
