#ifndef MRNOMGAME_HPP
#define MRNOMGAME_HPP

#include "../engine.h"
#include "LoadingScreen.hpp"

using namespace engine;

class MrNomGame : public GameContext {

public:

	virtual ~MrNomGame();

	virtual GameScreen* getStartScreen();
};

#endif
