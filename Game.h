#pragma once

#ifdef _WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#endif

#include <GL/glu.h>
#include <string>
#include "utils/scene/SceneManager.h"
#include "Constants.h"

class Game {
	public:
		Game();
		//
		int execute();
	private:
		//
		bool init();
		bool initSDL();
		bool initGL();
		bool initTest();
		//
		void event(SDL_Event* e);
		void update();
		void draw();
		void cleanUp();
		//
		SDL_Window* window;
		SDL_Event ev;
		SDL_GLContext context;
		SceneManager scene;
		//
		Loader loader;
		Mesh mesh;
		//
		bool running;
		float rotation;
};