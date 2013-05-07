package com.badlogic.androidgames.framework.impl;

import android.app.Activity;
import android.util.Log;

public abstract class EventLoop extends Activity {

	public static final float INTERVAL_30FPS = 0.0333333333333f;
	public static final float INTERVAL_60FPS = 0.0166666666667f;

	private Timer mTimer;
	private Thread mThread;
	private boolean mActive;

	public EventLoop() {
		mTimer = new Timer();
		mActive = false;
	}

	/**
	 * Resumes the render loop.
	 */
	public void resumeRender() {
		mActive = true;
		mTimer.update();
		mThread = new RenderThread();
		mThread.start();
	}

	/**
	 * Pauses the render loop.
	 */
	public void pauseRender() {
		mActive = false;

		while (true) {
			try {
				mThread.join();
				break;
			}
			catch (InterruptedException e) {
			}
		}
	}

	/**
	 * Called from the render thread.
	 */
	public abstract void onUpdate(float delta);

	private class RenderThread extends Thread {

		@Override
		public void run() {
			Log.d("MrNom", "ENTERING EVENT LOOP");

			while (mActive) {
				// get time delta since last cycle
				float deltaTime = mTimer.elapsed(true);

				onUpdate(deltaTime);

				// get time delta since this cycle
				float frameTime = mTimer.elapsed(false);

				if (frameTime < INTERVAL_30FPS) {
					// running faster than fps interval
					// put thread to sleep to save energy
					float sleepTime = INTERVAL_30FPS - frameTime;
					// Log.d("MrNom", "frameTime: " + frameTime + " sleepTime: " + sleepTime);

					try {
						sleep((long) (sleepTime * 1000)); // milliseconds
					}
					catch (InterruptedException e) {
					}
				}
			}

			Log.d("MrNom", "EXITING EVENT LOOP");
		}
	}
}
