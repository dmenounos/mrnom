package com.badlogic.androidgames.framework.impl;

public abstract class GameScreen {

	protected final GameContext mGameContext;

	public GameScreen(GameContext gameContext) {
		mGameContext = gameContext;
	}

	public abstract void update(float deltaTime);

	public abstract void render(float deltaTime);

	public abstract void resume();

	public abstract void pause();

	public abstract void dispose();
}
