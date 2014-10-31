#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <vector>

#include "../../libs/json/gason.h"

#include "Mesh.h"
#include "Texture.h"
#include "Resource.h"

//const int max_vertices = 8000;
//const int max_polygons = 8000;

enum Model3DSChunks {
	M3DS_UNUSED =					0x0000,
	M3DS_MAIN_CHUNK =				0x4D4D,
	M3DS_EDITOR_CHUNK =				0x3D3D,
	M3DS_OBJECT_BLOCK =				0x4000,
	M3DS_TRIANGULAR_MESH =			0x4100,
	M3DS_VERTICES_LIST =			0x4110,
	M3DS_FACES_DESCRIPTION =		0x4120,
	M3DS_MAPPING_COORDINATES_LIST = 0x4140
};

class Loader {
	public:
		Loader();
		Mesh getMesh(std::string filename);
		Texture getTexture(std::string filename);
		Resource getResource(std::string filename);
	private:
		bool loadMesh(Mesh& mesh, std::string filename);
		bool loadTexture(Texture& text, std::string filename);
		bool loadResource(Resource& res, std::string filename);
		bool parse_json(Resource& res, char* data);
		void create_resource(Resource& res, JsonValue obj);
		std::vector<Mesh> mesh_list;
		std::vector<Texture> text_list;
		std::vector<Resource> res_list;
};
