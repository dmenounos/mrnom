package com.badlogic.androidgames.engine.impl;

import android.graphics.Bitmap;

import com.badlogic.androidgames.engine.impl.AndroidGraphics.PixmapFormat;

public class Texture {

	protected Bitmap bitmap;
	protected PixmapFormat format;

	public Texture(Bitmap bitmap, PixmapFormat format) {
		this.bitmap = bitmap;
		this.format = format;
	}

	public int getWidth() {
		return bitmap.getWidth();
	}

	public int getHeight() {
		return bitmap.getHeight();
	}

	public PixmapFormat getFormat() {
		return format;
	}

	public void dispose() {
		bitmap.recycle();
	}
}
