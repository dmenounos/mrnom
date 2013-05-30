package com.badlogic.androidgames.mrnom;

import java.util.List;

import com.badlogic.androidgames.engine.Input.TouchEvent;
import com.badlogic.androidgames.engine.impl.AndroidGraphics;
import com.badlogic.androidgames.engine.impl.GameContext;
import com.badlogic.androidgames.engine.impl.GameScreen;

public class HelpScreen extends GameScreen {

	public HelpScreen(GameContext context) {
		super(context);
	}

	@Override
	public void update(float deltaTime) {
		List<TouchEvent> touchEvents = mGameContext.getInput().getTouchEvents();
		mGameContext.getInput().getKeyEvents();

		int len = touchEvents.size();
		for (int i = 0; i < len; i++) {
			TouchEvent event = touchEvents.get(i);
			if (event.type == TouchEvent.TOUCH_UP) {
				if (event.x > 256 && event.y > 416) {
					mGameContext.setScreen(new HelpScreen2(mGameContext));
					if (Settings.soundEnabled)
						Assets.click.play(1);
					return;
				}
			}
		}
	}

	@Override
	public void render(float deltaTime) {
		AndroidGraphics g = mGameContext.getGraphics();
		g.drawPixmap(Assets.background, 0, 0);
		g.drawPixmap(Assets.help1, 64, 100);
		g.drawPixmap(Assets.buttons, 256, 416, 0, 64, 64, 64);
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
