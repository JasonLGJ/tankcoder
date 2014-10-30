#include "Texture.h"

Texture::Texture() {
	textureId = NULL;
}

Texture::~Texture() {}


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