package com.badlogic.androidgames.engine.impl;

import android.annotation.SuppressLint;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Rect;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

@SuppressLint("ViewConstructor")
public class AndroidRenderView extends SurfaceView {

	private Bitmap mFramebuffer;
	private SurfaceHolder mHolder;

	public AndroidRenderView(GameContext game, Bitmap framebuffer) {
		super(game);
		this.mFramebuffer = framebuffer;
		this.mHolder = getHolder();
	}

	/**
	 * Called from the render thread.
	 */
	public void render() {
		if (!mHolder.getSurface().isValid()) {
			return;
		}

		Rect dstRect = new Rect();
		Canvas canvas = mHolder.lockCanvas();
		canvas.getClipBounds(dstRect);
		canvas.drawBitmap(mFramebuffer, null, dstRect, null);
		mHolder.unlockCanvasAndPost(canvas);
	}
}
