package com.badlogic.androidgames.mrnom;

import java.util.List;

import com.badlogic.androidgames.engine.Input.TouchEvent;
import com.badlogic.androidgames.engine.impl.AndroidGraphics;
import com.badlogic.androidgames.engine.impl.GameContext;
import com.badlogic.androidgames.engine.impl.GameScreen;

public class HighscoreScreen extends GameScreen {
	String lines[] = new String[5];

	public HighscoreScreen(GameContext context) {
		super(context);

		for (int i = 0; i < 5; i++) {
			lines[i] = "" + (i + 1) + ". " + Settings.highscores[i];
		}
	}

	@Override
	public void update(float deltaTime) {
		List<TouchEvent> touchEvents = mGameContext.getInput().getTouchEvents();
		mGameContext.getInput().getKeyEvents();

		int len = touchEvents.size();
		for (int i = 0; i < len; i++) {
			TouchEvent event = touchEvents.get(i);
			if (event.type == TouchEvent.TOUCH_UP) {
				if (event.x < 64 && event.y > 416) {
					if (Settings.soundEnabled)
						Assets.click.play(1);
					mGameContext.setScreen(new MainMenuScreen(mGameContext));
					return;
				}
			}
		}
	}

	@Override
	public void render(float deltaTime) {
		AndroidGraphics g = mGameContext.getGraphics();

		g.drawPixmap(Assets.background, 0, 0);
		g.drawPixmap(Assets.mainMenu, 64, 20, 0, 42, 196, 42);

		int y = 100;
		for (int i = 0; i < 5; i++) {
			drawText(g, lines[i], 20, y);
			y += 50;
		}

		g.drawPixmap(Assets.buttons, 0, 416, 64, 64, 64, 64);
	}

	public void drawText(AndroidGraphics g, String line, int x, int y) {
		int len = line.length();
		for (int i = 0; i < len; i++) {
			char character = line.charAt(i);

			if (character == ' ') {
				x += 20;
				continue;
			}

			int srcX = 0;
			int srcWidth = 0;
			if (character == '.') {
				srcX = 200;
				srcWidth = 10;
			}
			else {
				srcX = (character - '0') * 20;
				srcWidth = 20;
			}

			g.drawPixmap(Assets.numbers, x, y, srcX, 0, srcWidth, 32);
			x += srcWidth;
		}
	}

	@Override
	public void pause() {
	}

	@Override
	public void resume() {
	}

	@Override
	public void dispose() {
	}
}
