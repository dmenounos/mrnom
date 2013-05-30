package com.badlogic.androidgames.mrnom;

import com.badlogic.androidgames.engine.impl.GameContext;
import com.badlogic.androidgames.engine.impl.GameScreen;

public class MrNomGame extends GameContext {

	@Override
	public GameScreen getStartScreen() {
		return new LoadingScreen(this);
	}
}
