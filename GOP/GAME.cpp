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

void GAME::throwDice()//funzione del lancio dado
{
	int j = (rand() % 6) + 1;
	playerList->position = playerList->position + j;
	if (playerList->position > ptTab->lenght) playerList->position = ptTab->lenght;
	cout << "\nIl giocatore " << playerList->name << " tira il dado ed esce " << j << ", ora " << playerList->name << " e\' in posizione " << playerList->position << ".";
}

void GAME::addToPosition(int num)//funzione utile per gli effetti di movimento sulla tabella, somma alla posione del giocatore il numero in input
{
	if ((num + playerList->position) > 0)
	{
		playerList->position = playerList->position + num;
		if (playerList->position > ptTab->lenght) playerList->position = ptTab->lenght;
	}
	else playerList->position = 1;
}

//possiamo scambiare le varie forward e backward con chimate dirette di addToPosition
void GAME::tabTypeTranslate()//chiamante per gli effetti della tabella
{
	switch (ptTab->getType(playerList->position))
	{
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
		throwDice();
		break;
	case 8:
		cout << "\nEffetto casella: il giocatore " << playerList->name << " pesca una carta.";
		cardTypeTranslate();
		break;
	case 9:
		backToStart();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' tornato all'inizio ed ora e\' in posizione 1";
		break;
	case 10:
		cout << "\nEffetto casella: casella vuota!";
		break;
	case 11:
		forwardByOne();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato avanti di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 12:
		forwardByTwo();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato avanti di due caselle e ora e\' in posizione " << playerList->position;
		break;
	case 13:
		backwardByOne();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato indietro di una casella e ora e\' in posizione " << playerList->position;
		break;
	case 14:
		backwardByTwo();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " e\' andato indietro di due caselle ed ora e\' in posizione " << playerList->position;
		break;
	case 15:
		swapWithFirst();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " ha scambiato la sua posizione con il primo in classifica";
		break;
	case 16:
		skipTurn();
		cout << "\nEffetto casella: il giocatore " << playerList->name << " saltera\' il prossimo turno";
		break;
	case 17:
		cout << "\nEffetto casella: il giocatore " << playerList->name << " tira due volte il dado";
		throwDice();
		break;
	case 18:
		cout << "\nEffetto casella: il giocatore " << playerList->name << " pesca una carta.";
		cardTypeTranslate();
		break;
	default:
		cout << "INTERNAL_ERROR -Prego allontanarsi dal computer ";
	}
}

void GAME::cardTypeTranslate()//chiamante per gli effetti del mazzo di carte
{
	switch (ptDeck->type)
	{
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
		skipTurn();
		cout << "\nEffetto carta: il giocatore " << playerList->name << " saltera\' il prossimo turno";
		break;
	case 6:
		cout << "\nEffetto carta: il giocatore " << playerList->name << " tira di nuovo il dado";
		throwDice();
		break;
	default:
		cout << "INTERNAL_ERROR -Prego allontanarsi dal computer ";
	}
	ptDeck = ptDeck->next;
}

void GAME::forwardByTwo()//avanti di due
{
	addToPosition(2);
}

void GAME::forwardByOne()//avanti di uno
{
	addToPosition(1);
}

void GAME::backwardByTwo()//indietro di due
{
	addToPosition(-2);
}

void GAME::backwardByOne()//indietro di uno
{
	addToPosition(-1);
}

void GAME::backToStart()//effetto molto destabilizzante che reimposta la posizione del giocatore a 1
{
	playerList->position = 1;
}

void GAME::skipTurn()//salta il prossimo turno
{
	playerList->jumpTurn = true;
}



void GAME::getFirst(ptPLAYER *out)//funzione che restituisce un array di puntatori al (o ai) giocatore primo in classifica 
{
	int i, counter = 0, j = 0;
	bool found = false;
	ptPLAYER ptTMP = playerList;
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
	playerList = ptTMP;
}


void GAME::swapWithFirst()//scambia la posizione del giocatore corrente con il primo e viceversa (funziona anche con più giocatori a pari merito)
{
	ptPLAYER *first = new ptPLAYER[NUMERO_GIOCATORI + 1];
	getFirst(first);
	int temp = first[0]->position, i = 0;
	while (first[i] != NULL)
	{
		first[i]->position = playerList->position;
		i++;
	}
	delete first;
	playerList->position = temp;
}

void GAME::createPlayerList()//Inizializza il puntatore alla lista di giocatori (lista circolare) prendendo da input numero e nome dei giocatori.
{
	int num = 0, i = 1;
	char tmpName[20];
	ptPLAYER tmp, ptHead;
	tmpName[0] = '\0';
	while (num < 1)//da cambiare con do while come negli altri casi
	{
		cout << "Inserire numero giocatori: ";
		cin >> num;
		if (num < 1)
		{
			cout << "\nNumero di giocatori invalido, riprova ";
		}
	}
	NUMERO_GIOCATORI = num;
	cout << "\nInserire nome per giocatore " << i << ": ";
	cin.getline(tmpName, 20, '\n');//questo non va bene, il problema è che sta leggendo il \n dell'input precedente
	cin.getline(tmpName, 20, '\n');//o ci facciamo una funzione che lo fa o troviamo un altro modo(eventualmente possiamo passare alle stringhe)
	playerList = new PLAYER(1, tmpName);
	ptHead = playerList;
	i++;
	while (i <= num)
	{
		cout << "\nInserire nome per giocatore " << i << ": ";
		cin.getline(tmpName, 20, '\n');
		tmp = new PLAYER(i, tmpName);
		playerList->next = tmp;
		playerList = tmp;
		i++;
	}
	playerList->next = ptHead;//in uscita playerlist punta all'ultimo giocatore perchè il primo turno inizia con un playerlist=playerlist->next
}

void GAME::deletePlayerList()//Distrugge la lista di giocatori partendo dal puntatore al giocatore attuale
{
	ptPLAYER tmp;
	for (int i = 0; i < NUMERO_GIOCATORI; i++)
	{
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

void GAME::createDeck()//Crea lista circolare di carte con testa in ptDeck
{
	ptDeck = new CARD();
	ptCARD tmp = ptDeck;
	for (int i = 0; i < 40; i++)//lasciamo il mazzo fisso a 40 o rand anche qua?
	{
		tmp->type = tmp->randomCard();
		if (i < 39)
		{
			tmp->next = new CARD();
			tmp = tmp->next;
		}
	}
	tmp->next = ptDeck;
}

void GAME::deleteDeck()//Distrugge la sovrastante
{
	ptCARD tmp;
	for (int i = 0; i < NUMERO_GIOCATORI; i++)
	{
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
	for (int i = ptTab->lenght; i > 0; i--)
	{
		for (int j = 0; j<NUMERO_GIOCATORI; j++)
		{
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

void GAME::firstTurn()//Inizializza la lista di giocatori, il mazzo e la tabella
{
	cout << "Questo e\' il gioco GOP per il progetto di programmazione\nInserire ora i dati per iniziare una partita:" << endl;
	createPlayerList();
	createDeck();
	ptTab = new TABLE(rand() % 20 + 55);
	nextTurn();
	return;
}

void GAME::nextTurn()//Esegue la routine di un turno standard offrendo la possibilita\' di uscire o ricominciare
{
	char loop;
	playerList = playerList->next;
	if (!playerList->jumpTurn)
	{
		throwDice();
		if (playerList->position >= ptTab->lenght)
		{
			endGame(true); //True quando il gioco finisce in modo normale
			return;
		}
		tabTypeTranslate();
		if (playerList->position >= ptTab->lenght)//True quando il gioco finisce in modo normale
		{
			endGame(true); //True quando il gioco finisce in modo normale
			return;
		}
		drawCard();
	}
	else
	{
		cout << "\nIl giocatore " << playerList->name << " salta il turno.";
		playerList->jumpTurn = false;
	}
	ptTab->printTable();
	if (playerList->position >= ptTab->lenght)//True quando il gioco finisce in modo normale
	{
		endGame(true);
		return;
	}
	printChart();
	do
	{
		cout << "\nSe vuoi finire la partita scrivi Y, se vuoi continuare scrivi N (non case sensitive)\n";
		cin >> loop;
	} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
	if ((loop == 'Y') || (loop == 'y'))//False quando il gioco è interrotto dall'utente
	{
		endGame(false);
		return;
	}
	else GAME::nextTurn();
	return;
}


void GAME::endGame(bool end)//Fa pulizia del gioco appena finito
{
	char loop;
	if (end)
	{
		cout << "\nLa partita e\' terminata, consulta qua sotto la classifica finale per scoprire il vincitore";
		printChart();
		delete ptTab;
		deleteDeck();
		deletePlayerList();
		do
		{
			cout << "Se vuoi ricominciare scrivi Y, se vuoi uscire scrivi N (non case sensitive)";
			cin >> loop;
		} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
		if ((loop == 'Y') || (loop == 'y')) firstTurn();
		else return;
	}
	else if (!end)
	{
		cout << "\nLa partita e\' stata terminata, consulta qua sotto la classifica finale\n " ;
		printChart();
		delete ptTab;
		deleteDeck();
		deletePlayerList();
		do 
		{
			cout << "Se vuoi ricominciare scrivi Y, se vuoi uscire scrivi N (non case sensitive)";
			cin >> loop;
		} while (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n');
		if ((loop == 'Y') || (loop == 'y')) firstTurn();
		else return;
	}
}