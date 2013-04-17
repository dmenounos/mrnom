package com.badlogic.androidgames.framework.impl;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.os.Bundle;
import android.os.PowerManager;
import android.os.PowerManager.WakeLock;
import android.view.Window;
import android.view.WindowManager;

import com.badlogic.androidgames.framework.FileIO;
import com.badlogic.androidgames.framework.Graphics;
import com.badlogic.androidgames.framework.Input;

public abstract class GameContext extends EventLoop {

	private AndroidRenderView mRenderView;
	private Graphics mGraphics;
	private AndroidAudio mAudio;
	private Input mInput;
	private FileIO mFileIO;
	private GameScreen mScreen;
	private WakeLock mWakeLock;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);

		int frameBufferWidth = 320;
		int frameBufferHeight = 480;
		Bitmap frameBuffer = Bitmap.createBitmap(frameBufferWidth, frameBufferHeight, Config.RGB_565);

		float scaleX = (float) frameBufferWidth / getWindowManager().getDefaultDisplay().getWidth();
		float scaleY = (float) frameBufferHeight / getWindowManager().getDefaultDisplay().getHeight();

		mRenderView = new AndroidRenderView(this, frameBuffer);
		mGraphics = new AndroidGraphics(getAssets(), frameBuffer);
		mFileIO = new AndroidFileIO(getAssets());
		mAudio = new AndroidAudio(this);
		mInput = new AndroidInput(this, mRenderView, scaleX, scaleY);
		mScreen = getStartScreen();
		setContentView(mRenderView);

		PowerManager powerManager = (PowerManager) getSystemService(Context.POWER_SERVICE);
		mWakeLock = powerManager.newWakeLock(PowerManager.FULL_WAKE_LOCK, "GLGame");
	}

	@Override
	public void onUpdate(float delta) {
		getScreen().update(delta);
		getScreen().render(delta);
		mRenderView.render();
	}

	@Override
	public void onResume() {
		super.onResume();

		mWakeLock.acquire();
		mScreen.resume();
		resumeRender();
	}

	@Override
	public void onPause() {
		super.onPause();

		mWakeLock.release();
		pauseRender();
		mScreen.pause();

		if (isFinishing()) {
			mScreen.dispose();
		}
	}

	public GameScreen getScreen() {
		return mScreen;
	}

	public void setScreen(GameScreen screen) {
		if (screen == null)
			throw new IllegalArgumentException("Screen must not be null");

		this.mScreen.pause();
		this.mScreen.dispose();

		screen.resume();
		screen.update(0);
		this.mScreen = screen;
	}

	public abstract GameScreen getStartScreen();

	public Input getInput() {
		return mInput;
	}

	public FileIO getFileIO() {
		return mFileIO;
	}

	public Graphics getGraphics() {
		return mGraphics;
	}

	public AndroidAudio getAudio() {
		return mAudio;
	}
}
