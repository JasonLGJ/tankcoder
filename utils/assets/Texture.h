#pragma once

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#endif

#include <string>


class Texture {
	public:
		Texture();
		~Texture();
		//
		void bind();
		void unbind();
		std::string getName();
		void setName(std::string name);
		void setTextureId(unsigned int id);
		bool empty();
	private:
		std::string name;
		unsigned int textureId;
};