package com.badlogic.androidgames.framework.impl;

public abstract class GameScreen {

	protected final GameContext context;

	public GameScreen(GameContext game) {
		this.context = game;
	}

	public abstract void update(float deltaTime);

	public abstract void render(float deltaTime);

	public abstract void resume();

	public abstract void pause();

	public abstract void dispose();
}
