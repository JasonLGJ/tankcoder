#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <vector>

#include "Mesh.h"
#include "Texture.h"
#include "Resource.h"
#include "Sound.h"

//const int max_vertices = 8000;
//const int max_polygons = 8000;

class Loader {
	public:
		Loader();
		~Loader();
		Mesh getMesh(std::string filename);
		Texture getTexture(std::string filename);
		std::shared_ptr<Resource> getResource(std::string filename);
		std::shared_ptr<Sound> getSound(std::string filename, sound_type type);
	private:
		bool loadMesh(Mesh& mesh, std::string filename);
		bool loadTexture(Texture& text, std::string filename);
		bool loadResource(std::shared_ptr<Resource> res, std::string filename);
		bool loadSound(std::shared_ptr<Sound> snd, std::string filename, sound_type type);
		bool parse_json(std::shared_ptr<Resource> res, char* data);
		bool construct_resource(std::shared_ptr<Resource> res, JsonValue obj);
		std::vector<Mesh> mesh_list;
		std::vector<Texture> text_list;
		std::vector<std::shared_ptr<Resource>> res_list;
		std::vector<std::shared_ptr<Sound>> snd_list;
};
