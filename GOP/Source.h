struct FOO
{
	int type;

};

struct CARD
{
	FOO deck;
	CARD *next;
};

typedef CARD* ptCard;

int randomCard();
ptCard createDeck(int cards);
void typeTranslate(int type);


int main();
