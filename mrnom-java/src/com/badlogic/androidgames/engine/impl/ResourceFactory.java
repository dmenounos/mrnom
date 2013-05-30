package com.badlogic.androidgames.engine.impl;

import java.io.IOException;
import java.io.InputStream;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.BitmapFactory;
import android.graphics.BitmapFactory.Options;

import com.badlogic.androidgames.engine.impl.AndroidGraphics.PixmapFormat;

public class ResourceFactory {

	private GameContext mGameContext;

	public ResourceFactory(GameContext gameContext) {
		mGameContext = gameContext;
	}

	private AssetManager getAssetManager() {
		return mGameContext.getAssets();
	}

	public Texture newPixmap(String fileName, PixmapFormat format) {
		Config config = null;
		if (format == PixmapFormat.RGB565)
			config = Config.RGB_565;
		else if (format == PixmapFormat.ARGB4444)
			config = Config.ARGB_4444;
		else
			config = Config.ARGB_8888;

		Options options = new Options();
		options.inPreferredConfig = config;

		InputStream in = null;
		Bitmap bitmap = null;

		try {
			in = getAssetManager().open(fileName);
			bitmap = BitmapFactory.decodeStream(in);

			if (bitmap == null) {
				throw new RuntimeException("Couldn't load bitmap from asset '" + fileName + "'");
			}
		}
		catch (IOException e) {
			throw new RuntimeException("Couldn't load bitmap from asset '" + fileName + "'");
		}
		finally {
			if (in != null) {
				try {
					in.close();
				}
				catch (IOException e) {
				}
			}
		}

		if (bitmap.getConfig() == Config.RGB_565)
			format = PixmapFormat.RGB565;
		else if (bitmap.getConfig() == Config.ARGB_4444)
			format = PixmapFormat.ARGB4444;
		else
			format = PixmapFormat.ARGB8888;

		return new Texture(bitmap, format);
	}
}
