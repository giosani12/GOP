#ifndef GLOBAL_H_
#define GLOBAL_H_
class PLAYER;
typedef PLAYER* ptPLAYER;

class GLOBAL
{
protected:
	ptPLAYER playerList;
	int NUMERO_GIOCATORI;

public:
	GLOBAL();
	~GLOBAL();
};
#endif

