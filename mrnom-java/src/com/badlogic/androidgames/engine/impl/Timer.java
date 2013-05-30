package com.badlogic.androidgames.engine.impl;

public class Timer {

	private double mLastTime;

	public Timer() {
		mLastTime = 0.0;
	}

	public void update() {
		mLastTime = current();
	}

	public float elapsed(boolean update)
	{
		double currentTime = current();
		float elapsed = (float) (currentTime - mLastTime);
		if (update) mLastTime = currentTime;
		return elapsed;
	}

	public double current()
	{
		long time = System.nanoTime();
		return time / 1000000000.0;
	}
}
