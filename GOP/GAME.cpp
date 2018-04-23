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
	//typeTranslate(ptDeck->type);
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
	cout << "\nCLASSIFICA:\n|Posizione\t|Posizione in Tabella\t|Nome Giocatore";
	for (int i = ptTab->lenght; i > 0; i--) {

		for (int j = 0; j<NUMERO_GIOCATORI; j++) {
			if ((i == playerList->position) && !found)
			{
				pos = pos + 1;
				cout << "\n|" << pos << "\t\t|" << playerList->position << "\t\t\t|" << playerList->name;
				found = true;
			}
			else if ((i == playerList->position) && found)
			{
				cout << "\n|" << pos << "\t\t|" << playerList->position << "\t\t\t|" << playerList->name;
			}
			playerList = playerList->next;
		}
		found = false;
	}
	cout << endl;
}

void GAME::firstTurn()
{
	cout << "Questo e\' il gioco GOP per il progetto di programmazione\nInserire ora i dati per iniziare una partita:" << endl;
	createPlayerList();
	createDeck();
	ptTab = new TABLE(40);
	playerList->Throw_Dice();
	//typeTranslate(ptTab->getType(playerList->position));
	ptTab->printTable();
	printChart();
	nextTurn();
}

void GAME::nextTurn()
{
	char loop;
	playerList->Throw_Dice();
	//typeTranslate(ptTab->getType(playerList->position));
	ptTab->printTable();
	printChart();
	drawCard();
	if (playerList->position >= ptTab->lenght) endGame(false);
	playerList = playerList->next;
	cout << "Vuoi finire la partita?:";
	do {
		cout << "\nSe vuoi finire la partita scrivi Y, se vuoi continuare scrivi N\n";
		cin >> loop;
	} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
	if ((loop == 'Y') || (loop == 'y')) endGame(true);
	else GAME::nextTurn();
}


void GAME::endGame(bool end) 
{
	char loop;
	if (end) {
		ptTab->printTable();
		playerList->printChart();
		do {
			cout << "Se vuoi ricominciare scrivi Y, se vuoi uscire scrivi N";
			cin >> loop;
		} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
		if (loop == 'Y') firstTurn();
	}
	else if ((!end)&&(playerList->position>=ptTab->lenght)){
		cout << "\nCongratualzioni " << playerList->name << " hai vinto la partita, ora suicidati\nOra non cliccare invio cosi\' sembra che funzioni bene\n";
		cin >> loop;
	}
}
