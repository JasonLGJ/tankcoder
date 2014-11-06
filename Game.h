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
#include "menu/Menu.h"
#include "game/World.h"
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
		bool initManagers();
		//
		void event(SDL_Event* e);
		void update();
		void draw();
		void cleanUp();
		//
		SDL_Window* window;
		SDL_Event ev;
		SDL_GLContext context;
		//
		std::shared_ptr<SceneManager> scene;
		std::shared_ptr<Loader> loader;
		std::shared_ptr<Menu> menu;
		std::shared_ptr<World> world;
		//
		bool running;
		float rotation;
};