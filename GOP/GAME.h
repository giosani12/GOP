<<<<<<< HEAD
#include "PLAYER.h"
#include "TABLE.h"
=======
#include "GLOBAL.h"
>>>>>>> aadce5972afb08f3647b504ee3d06bbd66830194
#ifndef GAME_H_
#define GAME_H_

class GAME : public GLOBAL
{
	friend class PLAYER;
	friend class TABLE;
protected:
	
public:
		GAME() ;
};

#endif
