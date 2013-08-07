#include "ResourceFactory.hpp"

#include "Resource.hpp"
#include "../core/Bitmap.hpp"

#include <png.h>

using namespace engine;

/**
 * Helper function declaration.
 */
void readCallback(png_structp pngStruct, png_bytep pngData, png_size_t pngSize);

ResourceFactory::ResourceFactory(AAssetManager* assetManager) :
	mAssetManager(assetManager) {
	LOG_D("### ResourceFactory::ResourceFactory()");
}

ResourceFactory::~ResourceFactory() {
	LOG_D("### ResourceFactory::~ResourceFactory()");
}

Bitmap* ResourceFactory::createBitmap(const char* path) {
	LOG_D("--> ResourceFactory::createBitmap(%s)", path);

	Resource resource(mAssetManager, path);

	png_byte header[8];
	png_struct* pngPtr = NULL;
	png_info* infoPtr = NULL;
	png_byte* imageBuffer = NULL;
	png_byte** rowPtrs = NULL;
	png_int_32 rowSize;
	bool transparency;

	resource.read(header, sizeof(header));
	if (png_sig_cmp(header, 0, 8) != 0) goto ERROR;

	/*
	 * Create all structures necessary to read o PNG image.
	 */
	pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!pngPtr) goto ERROR;

	infoPtr = png_create_info_struct(pngPtr);
	if (!infoPtr) goto ERROR;

	/*
	 * Prepare reading operations by giving our callback_read().
	 *
	 * Setup error management with setjmp(). This allows jumping like a goto
	 * but through the call stack. If an error occurs, control flow comes back
	 * at the point where setjmp() has been called first, but enters the if
	 * block instead (here goto ERROR).
	 */
	png_set_read_fn(pngPtr, &resource, readCallback);
	if (setjmp(png_jmpbuf(pngPtr))) goto ERROR;

	/*
	 * Start reading PNG file header, ignoring the first 8 bytes.
	 *
	 * PNG files can be encoded in several formats: RGB, RGBA, 256 colors with
	 * a palette, grayscale... R, G, B color channels can be encoded on up to
	 * 16 bits. Hopefully, libpng provides transformation functions to decode
	 * unusual formats to more classical RGB and luminance formats with 8 bits
	 * per channel with or without an alpha channel.
	 *
	 * Transformations are validated with png_read_update_info().
	 */
	png_set_sig_bytes(pngPtr, 8);
	png_read_info(pngPtr, infoPtr);
	png_int_32 format;
	png_uint_32 width, height;
	png_int_32 depth, colorType;
	png_get_IHDR(pngPtr, infoPtr, &width, &height, &depth, &colorType, NULL, NULL, NULL);

	// Creates a full alpha channel if transparency is encoded as
	// an array of palette entries or a single transparent color.
	transparency = false;

	if (png_get_valid(pngPtr, infoPtr, PNG_INFO_tRNS)) {
		png_set_tRNS_to_alpha(pngPtr);
		transparency = true;
		// goto ERROR;
	}

	if (depth < 8) {
		png_set_packing(pngPtr);
	}
	else if (depth == 16) {
		png_set_strip_16(pngPtr);
	}

	// Indicates that image needs conversion to RGBA if needed.
	switch (colorType) {
	case PNG_COLOR_TYPE_PALETTE:
		png_set_palette_to_rgb(pngPtr);
		format = transparency ? GL_RGBA : GL_RGB;
		break;
	case PNG_COLOR_TYPE_RGB:
		format = transparency ? GL_RGBA : GL_RGB;
		break;
	case PNG_COLOR_TYPE_RGBA:
		format = GL_RGBA;
		break;
	case PNG_COLOR_TYPE_GRAY:
		png_set_expand_gray_1_2_4_to_8(pngPtr);
		format = transparency ? GL_LUMINANCE_ALPHA : GL_LUMINANCE;
		break;
	case PNG_COLOR_TYPE_GA:
		png_set_expand_gray_1_2_4_to_8(pngPtr);
		format = GL_LUMINANCE_ALPHA;
		break;
	}

	png_read_update_info(pngPtr, infoPtr);

	/*
	 * Allocate the necessary temporary buffer to hold image data and
	 * a second one with the address of each output image row for libpng.
	 */
	rowSize = png_get_rowbytes(pngPtr, infoPtr);
	if (rowSize <= 0) goto ERROR;

	imageBuffer = new png_byte[rowSize * height];
	if (!imageBuffer) goto ERROR;

	rowPtrs = new png_byte*[height];
	if (!rowPtrs) goto ERROR;

	/*
	 * Note, row order is inverted because OpenGL uses a different coordinate
	 * system (first pixel at bottom-left) then PNG (first pixel at top-left).
	 */
	for (int32_t i = 0; i < height; ++i) {
		rowPtrs[height - i - 1] = imageBuffer + i * rowSize;
	}

	/*
	 * Start reading image content.
	 */
	png_read_image(pngPtr, rowPtrs);

	/*
	 * Finally, release resources (whether an error occurs on not) and return
	 * loaded data.
	 */
	delete[] rowPtrs;
	png_destroy_read_struct(&pngPtr, &infoPtr, NULL);

	return new Bitmap(width, height, format, imageBuffer);

	ERROR:
	LOG_E("Error while reading PNG file.");

	delete[] rowPtrs;
	delete[] imageBuffer;

	if (pngPtr != NULL) {
		png_struct** pngPtrPtr = &pngPtr;
		png_info** infoPtrPtr = infoPtr != NULL ? &infoPtr : NULL;
		png_destroy_read_struct(pngPtrPtr, infoPtrPtr, NULL);
	}

	return 0;
}

/**
 * Helper function definition.
 */
void readCallback(png_struct* pngPtr, png_byte* pngData, png_size_t pngSize) {
	Resource* reader = (Resource*) (png_get_io_ptr(pngPtr));

	if (reader->read(pngData, pngSize) < 0) {
		png_error(pngPtr, "Error while reading PNG file.");
	}
}
