package com.badlogic.androidgames.mrnom;

import com.badlogic.androidgames.engine.impl.AndroidGraphics.PixmapFormat;
import com.badlogic.androidgames.engine.impl.GameContext;
import com.badlogic.androidgames.engine.impl.GameScreen;
import com.badlogic.androidgames.engine.impl.ResourceFactory;

public class LoadingScreen extends GameScreen {

	public LoadingScreen(GameContext context) {
		super(context);
	}

	@Override
	public void update(float deltaTime) {
		ResourceFactory resourceFactory = mGameContext.getResourceFactory();

		// @formatter:off

		Assets.background = resourceFactory.newPixmap("background.png", PixmapFormat.RGB565);
		Assets.logo       = resourceFactory.newPixmap("logo.png",       PixmapFormat.ARGB4444);
		Assets.mainMenu   = resourceFactory.newPixmap("mainmenu.png",   PixmapFormat.ARGB4444);
		Assets.buttons    = resourceFactory.newPixmap("buttons.png",    PixmapFormat.ARGB4444);
		Assets.help1      = resourceFactory.newPixmap("help1.png",      PixmapFormat.ARGB4444);
		Assets.help2      = resourceFactory.newPixmap("help2.png",      PixmapFormat.ARGB4444);
		Assets.help3      = resourceFactory.newPixmap("help3.png",      PixmapFormat.ARGB4444);
		Assets.numbers    = resourceFactory.newPixmap("numbers.png",    PixmapFormat.ARGB4444);
		Assets.ready      = resourceFactory.newPixmap("ready.png",      PixmapFormat.ARGB4444);
		Assets.pause      = resourceFactory.newPixmap("pausemenu.png",  PixmapFormat.ARGB4444);
		Assets.gameOver   = resourceFactory.newPixmap("gameover.png",   PixmapFormat.ARGB4444);
		Assets.headUp     = resourceFactory.newPixmap("headup.png",     PixmapFormat.ARGB4444);
		Assets.headLeft   = resourceFactory.newPixmap("headleft.png",   PixmapFormat.ARGB4444);
		Assets.headDown   = resourceFactory.newPixmap("headdown.png",   PixmapFormat.ARGB4444);
		Assets.headRight  = resourceFactory.newPixmap("headright.png",  PixmapFormat.ARGB4444);
		Assets.tail       = resourceFactory.newPixmap("tail.png",       PixmapFormat.ARGB4444);
		Assets.stain1     = resourceFactory.newPixmap("stain1.png",     PixmapFormat.ARGB4444);
		Assets.stain2     = resourceFactory.newPixmap("stain2.png",     PixmapFormat.ARGB4444);
		Assets.stain3     = resourceFactory.newPixmap("stain3.png",     PixmapFormat.ARGB4444);

		Assets.click      = mGameContext.getAudio().newSound("click.ogg");
		Assets.eat        = mGameContext.getAudio().newSound("eat.ogg");
		Assets.bitten     = mGameContext.getAudio().newSound("bitten.ogg");
		
		// @formatter:on

		Settings.load(mGameContext.getFileIO());
		mGameContext.setScreen(new MainMenuScreen(mGameContext));
	}

	@Override
	public void render(float deltaTime) {
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
