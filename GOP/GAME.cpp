#include <iostream>
#include <cstdlib>
#include <ctime>
#include "GAME.h"
#include "CARD.h"
#include "PLAYER.h"
#include "TABLE.h"

using namespace std;

GAME::GAME() {
}

void GAME::Throw_Dice() {
	int j = (rand() % 6) + 1;
	playerList->position = playerList->position + j;
	if (playerList->position > ptTab->lenght) playerList->position = ptTab->lenght;
	cout << endl << playerList->name << " tira il dado ed esce " << j << ", ora " << playerList->name << " e\' in posizione " << playerList->position << ".";
}

void GAME::addToPosition(int num)
{
	if ((num + playerList->position) > 0) {
		playerList->position = playerList->position + num;
		if (playerList->position > ptTab->lenght) playerList->position = ptTab->lenght;
	}
	else playerList->position = 1;
}


void GAME::tabTypeTranslate() {
	switch (ptTab->getType(playerList->position)) {
	case 0:
		cout << "\nEffetto casella: casella vuota!";
		break;
	case 1:
		forwardByOne();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato avanti di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 2:
		forwardByTwo();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato avanti di due caselle e ora e\' in posizione " << playerList->position;
		break;
	case 3:
		backwardByOne();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato indietro di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 4:
		backwardByTwo();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato indietro di due caselle ed ora e\' in posizione " << playerList->position;
		break;
	case 5:
		swapWithFirst();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " ha scambiato la sua posizione con il primo in classifica";
		break;
	case 6:
		skipTurn();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " saltera\' il prossimo turno";
		break;
	case 7:
		cout << "\nEffetto casella: il giocatore " << playerList->name << " tira due volte il dado";
		doubleDice();
		break;
	case 8:
		backToStart();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' tornato all'inizio ed ora e\' in posizione 1";
		break;
	case 9:
		cout << "\nEffetto casella: casella vuota!";
		break;
	case 10:
		forwardByOne();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato avanti di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 11:
		forwardByTwo();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato avanti di due caselle e ora e\' in posizione " << playerList->position;
		break;
	case 12:
		backwardByOne();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato indietro di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 13:
		backwardByTwo();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato indietro di due caselle ed ora e\' in posizione " << playerList->position;
		break;
	case 14:
		swapWithFirst();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " ha scambiato la sua posizione con il primo in classifica";
		break;
	case 15:
		skipTurn();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " saltera\' il prossimo turno";
		break;
	case 16:
		cout << "\nEffetto casella: il giocatore " << playerList->name << " tira due volte il dado";
		doubleDice();
		break;
	default:
		cout << "INTERNAL_ERROR -Prego allontanarsi dal computer ";
	}
}

void GAME::cardTypeTranslate() {
	switch (ptTab->getType(playerList->position)) {
	case 0:
		forwardByOne();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " e\' andato avanti di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 1:
		forwardByTwo();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " e\' andato avanti di due caselle e ora e\' in posizione " << playerList->position;
		break;
	case 2:
		backwardByOne();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " e\' andato indietro di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 3:
		backwardByTwo();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " e\' andato indietro di due caselle ed ora e\' in posizione " << playerList->position;
		break;
	case 4:
		swapWithFirst();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " ha scambiato la sua posizione con il primo in classifica";
		break;
	case 5:
		backToStart();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " e\' tornato all'inizio ed ora e\' in posizione 1";
		break;
	case 6:
		skipTurn();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " saltera\' il prossimo turno";
		break;
	case 7:
		cout << "\nEffetto carta: il giocatore " << playerList->name << " tira due volte il dado";
		doubleDice();
		break;
	default:
		cout << "INTERNAL_ERROR -Prego allontanarsi dal computer ";
	}
}

void GAME::forwardByTwo() {
	addToPosition(2);
}

void GAME::forwardByOne() {
	addToPosition(1);
}

void GAME::backwardByTwo() {
	addToPosition(-2);
}

void GAME::backwardByOne() {
	addToPosition(-1);
}

void GAME::doubleDice() {
	Throw_Dice();
}

void GAME::backToStart() {
	playerList->position = 1;
}

void GAME::skipTurn() {
	playerList->jumpTurn = true;
}

ptPLAYER * GAME::getFirst()
{
	int i, counter = 0, j = 0;
	bool found = false;
	ptPLAYER ptTMP = playerList;
	ptPLAYER *out = new ptPLAYER[NUMERO_GIOCATORI+1], *tmp;
	for (i = ptTab->lenght; ((i > 0) && !found); i--)
	{
		for (int j = 0; j<NUMERO_GIOCATORI; j++)
		{
			if ((i == playerList->position) && !found)
			{
				out[0] = playerList;
				found = true;
				counter++;
				out[counter] = NULL;
			}
			else if ((i == playerList->position) && found)
			{
				out[counter] = playerList;
				counter++;
				out[counter] = NULL;
			}
			playerList = playerList->next;
		}
	}
	tmp = new ptPLAYER[counter];
	for (i = 0; out[i] != NULL; i++) tmp[i] = out[i];
	tmp[i] = NULL;
	delete out;
	playerList = ptTMP;
	return tmp;
}


void GAME::swapWithFirst() {
	ptPLAYER *first;
	first= getFirst();
	int temp = first[0]->position, i = 0;
	while (first[i] != NULL) {
		first[i]->position = playerList->position;
		i++;
	}
	playerList->position = temp;
}

void GAME::createPlayerList()//Inizializza il puntatore alla lista di giocatori (lista circolare) prendendo da input numero e nome dei giocatori.
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

void GAME::deletePlayerList()//Distrugge la lista di giocatori partendo dal puntatore al giocatore attuale
{
	ptPLAYER tmp;
	for (int i = 0; i < NUMERO_GIOCATORI; i++) {
		tmp = playerList->next;
		delete playerList;
		playerList = tmp;
	}
}
	


void GAME::drawCard()//pesca una carta casuale dal mazzo e ne esegue l'effetto.
{
	cardTypeTranslate();
	ptDeck = ptDeck->next;
}

void GAME::createDeck() {//Crea lista circolare di carte con testa in ptDeck
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

void GAME::deleteDeck()//Distrugge la sovrastante
{
	ptCard tmp;
	for (int i = 0; i < NUMERO_GIOCATORI; i++) {
		tmp = ptDeck->next;
		delete ptDeck;
		ptDeck = tmp;
	}
}

void GAME::printChart()//Stampa la lista dei giocatori ordinati per posizione in classifica con altre info utili
{
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

void GAME::firstTurn()//Esegue routine del primo turno inizializzando tutte i puntatori a giocatori, mazzo e tabella
{
	cout << "Questo e\' il gioco GOP per il progetto di programmazione\nInserire ora i dati per iniziare una partita:" << endl;
	createPlayerList();
	createDeck();
	ptTab = new TABLE(rand() % 40 + 40);
	Throw_Dice();
	tabTypeTranslate();
	drawCard();
	ptTab->printTable();
	printChart();
	nextTurn();
}

void GAME::nextTurn()//Esegue la routine di un turno standard offrendo la possibilita\' di uscire o ricominciare
{
	char loop;
	playerList = playerList->next;
	if (!playerList->jumpTurn)
	{
		Throw_Dice();
		if (playerList->position >= ptTab->lenght) endGame(true
		);
		tabTypeTranslate();
		if (playerList->position >= ptTab->lenght) endGame(true);
		drawCard();
	}
	else
	{
		cout << "\nIl giocatore " << playerList->name << " salta il turno.";
		playerList->jumpTurn = false;
	}
	ptTab->printTable();
	printChart();
	if (playerList->position >= ptTab->lenght) endGame(true);
	cout << "Vuoi finire la partita?:";
	do {
		cout << "\nSe vuoi finire la partita scrivi Y, se vuoi continuare scrivi N\n";
		cin >> loop;
	} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
	if ((loop == 'Y') || (loop == 'y')) endGame(true);
	else GAME::nextTurn();
}


void GAME::endGame(bool end)//Fa pulizia del gioco appena finito
{
	char loop;
	if (end) {
		cout << "La partita e\' terminata, consulta qua sotto la classifica finale per scoprire il vincitore\n";
		printChart();
		delete ptTab;
		deleteDeck();
		deletePlayerList();
		do {
			cout << "Se vuoi ricominciare scrivi Y, se vuoi uscire scrivi N";
			cin >> loop;
		} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
		if ((loop == 'Y') || (loop == 'y')) firstTurn();
	}
	else if ((!end)&&(playerList->position>=ptTab->lenght)){
		cout << "\nCongratualzioni " << playerList->name << " hai vinto la partita\nOra non cliccare invio cosi\' sembra che funzioni bene\n";
		cin >> loop;
	}
}