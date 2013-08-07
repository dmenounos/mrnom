#include "MrNomScreen.hpp"

MrNomScreen::MrNomScreen(GameContext* context) :
	GameScreen(context) {
}

MrNomScreen::~MrNomScreen() {
}

void MrNomScreen::resume() {
	GameScreen::resume();

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// left, right, bottom, top, near, far
	glOrthof(0.0f, 320.0f, 0.0f, 480.0f, 1.0f, -1.0f);
}
