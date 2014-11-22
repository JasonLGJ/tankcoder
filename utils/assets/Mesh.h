#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Texture.h"

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

struct polygon {
	short a;
	short b;
	short c;
};

struct vertex {
	float x;
	float y;
	float z;
};

struct coord {
	float u;
	float v;
};

class Mesh {
	public:
		Mesh();
		std::string getFileName();
		std::string getName();
		int getPolygonsQty();
		int getVerticesQty();
		int getCoordsQty();
		//
		void setFileName(std::string fn);
		void setTexture(Texture t);
		void setName(std::string n);
		void setPolygonsQty(int qty);
		void setVerticesQty(int qty);
		void setCoordsQty(int qty);
		//
		void addPolygon(polygon p);
		void addVertex(vertex v);
		void addCoord(coord c);
		//
		polygon getPolygon(int index);
		vertex getVertex(int index);
		coord getCoord(int index);
		Texture* getTexture();
		//
		bool empty();
	private:
		Texture texture;
		std::string name;
		std::string fileName;
		int polygons;
		int vertices;
		int coords;
		std::vector<polygon> polygon_list;
		std::vector<vertex> vertex_list;
		std::vector<coord> coord_list;
};
