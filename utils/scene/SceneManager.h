#pragma once
#include "../../Constants.h"
#include "../data/OctTree.h"
#include "../assets/Loader.h"
#include "SceneNode.h"
#include "StaticNode.h"
#include "FlatNode.h"
#include "AnimatedNode.h"
#include <memory>

#ifdef _WIN32
#include <SDL.h>
#include <SDL_opengl.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#endif

class SceneManager {
	public:
		SceneManager();
		void init(std::shared_ptr<Loader> l);
		std::shared_ptr<StaticNode> createStaticNode(std::string filename, float x, float y, float z);
		std::shared_ptr<FlatNode> createFlatNode(std::string filename, float x, float y, float w, float h);
		void drawAll();
		void draw();
		void setRotation(float r);
	private:
		OctTree tree;
		std::shared_ptr<Loader> loader;
		//
		void drawStaticNode(std::shared_ptr<StaticNode> n);
		void drawFlatNode(std::shared_ptr<FlatNode> n);
		float rotation;
};
