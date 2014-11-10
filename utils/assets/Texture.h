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
		//
		void setTexture(int n);
		void bind();
		void unbind();
		std::string getName();
		void setName(std::string name);
		void setTextureId(unsigned int id);
		bool empty();
		//
		void setMultiTexture(int n);
		void getPositions(float& st_x, float& st_y, float& en_x, float& en_y);
		void changeTexture(int n);
		//
		void deleteTex();
	private:
		bool multi;
		int num;
		int curtex;
		std::string name;
		unsigned int textureId;
};