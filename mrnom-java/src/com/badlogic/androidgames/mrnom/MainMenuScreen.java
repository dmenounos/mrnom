package com.badlogic.androidgames.mrnom;

import java.util.List;

import com.badlogic.androidgames.engine.Input.TouchEvent;
import com.badlogic.androidgames.engine.impl.AndroidGraphics;
import com.badlogic.androidgames.engine.impl.GameContext;
import com.badlogic.androidgames.engine.impl.GameScreen;

public class MainMenuScreen extends GameScreen {

	public MainMenuScreen(GameContext context) {
		super(context);
	}

	@Override
	public void update(float deltaTime) {
		AndroidGraphics g = mGameContext.getGraphics();
		List<TouchEvent> touchEvents = mGameContext.getInput().getTouchEvents();
		mGameContext.getInput().getKeyEvents();

		int len = touchEvents.size();
		for (int i = 0; i < len; i++) {
			TouchEvent event = touchEvents.get(i);
			if (event.type == TouchEvent.TOUCH_UP) {
				if (inBounds(event, 0, g.getHeight() - 64, 64, 64)) {
					Settings.soundEnabled = !Settings.soundEnabled;
					if (Settings.soundEnabled)
						Assets.click.play(1);
				}
				if (inBounds(event, 64, 220, 192, 42)) {
					mGameContext.setScreen(new LevelScreen(mGameContext));
					if (Settings.soundEnabled)
						Assets.click.play(1);
					return;
				}
				if (inBounds(event, 64, 220 + 42, 192, 42)) {
					mGameContext.setScreen(new HighscoreScreen(mGameContext));
					if (Settings.soundEnabled)
						Assets.click.play(1);
					return;
				}
				if (inBounds(event, 64, 220 + 84, 192, 42)) {
					mGameContext.setScreen(new HelpScreen(mGameContext));
					if (Settings.soundEnabled)
						Assets.click.play(1);
					return;
				}
			}
		}
	}

	private boolean inBounds(TouchEvent event, int x, int y, int width, int height) {
		if (event.x > x && event.x < x + width - 1 && event.y > y && event.y < y + height - 1)
			return true;
		else
			return false;
	}

	@Override
	public void render(float deltaTime) {
		AndroidGraphics g = mGameContext.getGraphics();

		g.drawPixmap(Assets.background, 0, 0);
		g.drawPixmap(Assets.logo, 32, 20);
		g.drawPixmap(Assets.mainMenu, 64, 220);
		if (Settings.soundEnabled)
			g.drawPixmap(Assets.buttons, 0, 416, 0, 0, 64, 64);
		else
			g.drawPixmap(Assets.buttons, 0, 416, 64, 0, 64, 64);
	}

	@Override
	public void pause() {
		Settings.save(mGameContext.getFileIO());
	}

	@Override
	public void resume() {
	}

	@Override
	public void dispose() {
	}
}
