#include "MainMenuScreen.hpp"
#include "World.hpp"

MainMenuScreen::MainMenuScreen(GameContext* context) :
	GameScreen(context), mWorld(new World()) {

	LOG_D("### MainMenuScreen::MainMenuScreen()");

	GLfloat vertices[] = {
		100.0f, 100.0f, 0.0f, 1.0f,
		220.0f, 100.0f, 1.0f, 1.0f,
		220.0f, 400.0f, 1.0f, 0.0f,
		100.0f, 400.0f, 0.0f, 0.0f
	};

	size_t verticesBytes = sizeof(vertices);
	size_t floatBytes = sizeof(GLfloat);

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	size_t indicesBytes = sizeof(indices);
	size_t shortBytes = sizeof(GLushort);

	mAnimationVertices = new Vertices(false, true);
	mAnimationVertices->loadVertices(vertices, verticesBytes / floatBytes);
	mAnimationVertices->loadIndices(indices, indicesBytes / shortBytes);

	mAnimationTexture = new Texture(context, "anim_512x512.png");

	mAnimationSprite = new Sprite(mAnimationTexture, mAnimationVertices);
	mAnimationSprite->getAnimation().setContinuous(true);     // continuous
	mAnimationSprite->getAnimation().setTickDuration(15.0f);  // 15 seconds
	mAnimationSprite->getAnimation().setLength(30);           // 30 frames
}

MainMenuScreen::~MainMenuScreen() {
	LOG_D("### MainMenuScreen::~MainMenuScreen()");

	delete mAnimationSprite;
	delete mAnimationTexture;
	delete mWorld;
}

void MainMenuScreen::update(float deltaTime) {
	GameScreen::update(deltaTime);

	mWorld->update(deltaTime);
	mAnimationSprite->update(deltaTime);
}

void MainMenuScreen::render(float deltaTime) {
	GameScreen::render(deltaTime);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// left, right, bottom, top, near, far
	glOrthof(0.0f, 320.0f, 0.0f, 480.0f, 1.0f, -1.0f);

	mAnimationSprite->render(deltaTime);

	if (isTickComplete()) {
		LOG_D("--- animation cursor: %d", mAnimationSprite->getAnimation().getCursor());
	}
}

void MainMenuScreen::resume() {
	GameScreen::resume();
	LOG_D("--> MainMenuScreen::resume()");

	mAnimationSprite->reload();
}

void MainMenuScreen::pause() {
	mAnimationSprite->unload();

	LOG_D("--> MainMenuScreen::pause()");
	GameScreen::pause();
}

void MainMenuScreen::dispose() {
	LOG_D("--> MainMenuScreen::dispose()");
	GameScreen::dispose();
}
