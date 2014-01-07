#include "Image.hpp"

#include "./opengl/Texture.hpp"
#include "./opengl/Vertices.hpp"

using namespace engine;

Image::Image(Texture* texture) :
	_texture(texture), _vertices(0),
	_horTextureRatio(0), _verTextureRatio(0) {
}

Image::~Image() {
	if (_vertices) {
		delete _vertices;
	}
}

void Image::init(int32_t x, int32_t y, int32_t w, int32_t h) {

	// VERTEX coordinates are non-normalized
	// and are based on "camera" units, i.e. glOrthof(...).

	float frameWPixels = w; // default: texture width
	float frameHPixels = h; // default: texture height

	// TEXTURE coordinates are normalized.

	float frameXCoords = x * _horTextureRatio; // default: 0
	float frameYCoords = y * _verTextureRatio; // default: 0
	float frameWCoords = w * _horTextureRatio; // default: 1
	float frameHCoords = h * _verTextureRatio; // default: 1

	frameWCoords += frameXCoords; // default: 1
	frameHCoords += frameYCoords; // default: 1

	GLfloat vertices[] = {
		0.0f,         0.0f,          0.0f,         0.0f,          // lower left
		frameWPixels, 0.0f,          frameWCoords, 0.0f,          // lower right
		frameWPixels, frameHPixels,  frameWCoords, frameHCoords,  // upper right
		0.0f,         frameHPixels,  0.0f,         frameHCoords   // upper left
	};

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	if (_vertices) {
		delete _vertices;
	}

	_vertices = new Vertices(false, true);
	_vertices->copyVertices(vertices, sizeof(vertices));
	_vertices->copyIndices(indices, sizeof(indices));
}

void Image::upload() {
	LOG_D("--> Image::upload()");
	_texture->upload();

	// coords / pixel
	_horTextureRatio = 1.0f / _texture->getWidth();
	_verTextureRatio = 1.0f / _texture->getHeight();

	// Initialize the vertices from the whole texture area.
	init(0, 0, _texture->getWidth(), _texture->getHeight());

	// vertices reside on cpu ram
	// so no need to upload
}

void Image::unload() {
	LOG_D("--> Image::unload()");
	_texture->unload();

	// vertices reside on cpu ram
	// so no need to unload
}

void Image::render(float deltaTime) {
	_texture->rebind();

	_vertices->rebind();
	_vertices->render(0, 6);
	_vertices->unbind();

	_texture->unbind();
}

Texture* Image::getTexture() const {
	return _texture;
}

Vertices* Image::getVertices() const {
	return _vertices;
}

float Image::getHorTextureRatio() const {
	return _horTextureRatio;
}

float Image::getVerTextureRatio() const {
	return _verTextureRatio;
}
