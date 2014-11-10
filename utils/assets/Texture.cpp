#include "Texture.h"

Texture::Texture() {
	textureId = NULL;
	multi = false;
	num = 1;
	curtex = 0;
}

void Texture::deleteTex() {
	glDeleteTextures(1, &textureId);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::unbind() {
	glBindTexture(GL_TEXTURE_2D, NULL);
}

std::string Texture::getName() {
	return name;
}

void Texture::setName(std::string name) {
	this->name = name;
}

void Texture::setTextureId(unsigned int id) {
	textureId = id;
}

bool Texture::empty() {
	return textureId == NULL;
}

void Texture::setMultiTexture(int n) {
	multi = true;
	num = n;
}

void Texture::getPositions(float& st_x, float& st_y, float& en_x, float& en_y) {
	if (multi)
	{
		float dy = 1.0f / (float)num;

		st_y = dy * curtex;
		en_y = dy * (curtex + 1);
	}
	else
	{
		st_y = 0.0f;
		en_y = 1.0f;
	}

	st_x = 0.0f;
	en_x = 1.0f;
}

void Texture::changeTexture(int n) {
	curtex = n;
}