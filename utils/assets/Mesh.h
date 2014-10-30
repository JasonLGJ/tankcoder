#pragma once
#include <string>
#include <vector>
#include "Texture.h"

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
		Texture getTexture();
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
