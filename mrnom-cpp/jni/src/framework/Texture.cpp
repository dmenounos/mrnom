#include "Texture.hpp"

Texture::Texture(android_app* application, const char* path) :
	mResource(application, path),
	mTextureId(0),
	mWidth(0),
	mHeight(0) {
}

Texture::~Texture() {
}

int32_t Texture::getWidth() {
	return mWidth;
}

int32_t Texture::getHeight() {
	return mHeight;
}

void Texture::load()
{
}

void Texture::unload()
{
}

void Texture::apply()
{
}

uint8_t* Texture::loadImage()
{
	png_byte header[8];
	png_structp pngPtr = NULL;
	png_infop infoPtr = NULL;
	png_byte* imageBuffer = NULL;
	png_bytep rowPtrs = NULL;
	png_int_32 rowSize;
	bool transparency;

	mResource.open();
	mResource.read(header, sizeof(header));
	if (png_sig_cmp(header, 0, 8) != 0) goto ERROR;

	pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!pngPtr) goto ERROR;

	infoPtr = png_create_info_struct(pngPtr);
	if (!infoPtr) goto ERROR;

	png_set_read_fn(pngPtr, &mResource, callback_read);
	if (setjmp(png_jmpbuf(pngPtr))) goto ERROR;

	ERROR:
	LOG_E("Error while reading PNG file");
	mResource.close();
	delete[] rowPtrs;
	delete[] imageBuffer;

	if (pngPtr != NULL) {
		png_infopp infopp = infoPtr != NULL ? &infoPtr : NULL;
		png_destroy_read_struct(&pngPtr, infopp, NULL);
	}

	return NULL;
}

void Texture::callback_read(png_structp pngStruct, png_bytep pngData, png_size_t pngSize)
{
}
