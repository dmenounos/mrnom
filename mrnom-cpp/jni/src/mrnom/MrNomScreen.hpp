#ifndef MRNOMSCREEN_HPP
#define MRNOMSCREEN_HPP

#include "../engine.h"

using namespace engine;

class MrNomScreen: public GameScreen {

public:

	MrNomScreen(GameContext* context);

	virtual ~MrNomScreen();

	// override
	virtual void resume();
};

#endif
