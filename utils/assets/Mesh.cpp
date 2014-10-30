#include "Mesh.h"

Mesh::Mesh() {
	polygons = vertices = coords = 0;
	name = fileName = "";
}

std::string Mesh::getFileName() {
	return fileName;
}

std::string Mesh::getName() {
	return name;
}

int Mesh::getPolygonsQty() {
	return polygons;
}

int Mesh::getVerticesQty() {
	return vertices;
}

int Mesh::getCoordsQty() {
	return coords;
}

void Mesh::setFileName(std::string fn) {
	fileName = fn;
}

void Mesh::setName(std::string n) {
	name = n;
}

void Mesh::setPolygonsQty(int qty) {
	polygons = qty;
}

void Mesh::setVerticesQty(int qty) {
	vertices = qty;
}

void Mesh::setCoordsQty(int qty) {
	coords = qty;
}

void Mesh::addPolygon(polygon p) {
	polygon_list.push_back(p);
}

void Mesh::addVertex(vertex v) {
	vertex_list.push_back(v);
}

void Mesh::addCoord(coord c) {
	coord_list.push_back(c);
}

polygon Mesh::getPolygon(int index) {
	return polygon_list[index];
}

vertex Mesh::getVertex(int index) {
	return vertex_list[index];
}

coord Mesh::getCoord(int index) {
	return coord_list[index];
}

bool Mesh::empty() {
	//printf("%d,%d,%d\n", polygons, vertices, coords);

	return polygons == 0 && vertices == 0 && coords == 0;
}

void Mesh::setTexture(Texture t) {
	texture = t;
}

Texture Mesh::getTexture() {
	return texture;
}