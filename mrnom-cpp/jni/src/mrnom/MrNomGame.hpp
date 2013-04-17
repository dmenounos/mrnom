#ifndef MRNOMGAME_HPP
#define MRNOMGAME_HPP

#include "../framework.h"
#include "LoadingScreen.hpp"

class MrNomGame : public GameContext
{
	public:

	virtual ~MrNomGame();

	virtual GameScreen* getStartScreen();
};

#endif
