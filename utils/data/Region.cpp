#include "Region.h"

Region::Region() {
	x = y = z = 0.0f;
	width = height = depth = 0.0f;	
}

Region::Region(float x, float y, float z, float width, float height, float depth) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->width = width;
	this->height = height;
	this->depth = depth;
}

std::vector<Region> Region::split() {
	std::vector<Region> regions;
	point p = getMidPoint();

	regions.push_back( Region(     x,     y,     z, width/2, height/2, depth/2) );
	regions.push_back( Region(     x,     y, p.z+z, width/2, height/2, depth/2) );
	regions.push_back( Region(     x, p.y+y,     z, width/2, height/2, depth/2) );
	regions.push_back( Region(     x, p.y+y, p.z+z, width/2, height/2, depth/2) );
	regions.push_back( Region( p.x+x,     y,     z, width/2, height/2, depth/2) );
	regions.push_back( Region( p.x+x,     y, p.z+z, width/2, height/2, depth/2) );
	regions.push_back( Region( p.x+x, p.y+y,     z, width/2, height/2, depth/2) );
	regions.push_back( Region( p.x+x, p.y+y, p.z+z, width/2, height/2, depth/2) );

	return regions;
}

bool Region::inside(float x, float y, float z) {
	return  (x >= this->x && x <= this->x + width) &&
		(y >= this->y && y <= this->y + height) &&
		(z >= this->z && z <= this->z + depth);
}

bool Region::inside(point p) {
	return  (p.x >= x && p.x <= x + width) &&
		(p.y >= y && p.y <= y + height) &&
		(p.z >= z && p.z <= z + depth);
}

point Region::getMidPoint() {
	point p;
	p.x = x + width/2.0f;
	p.y = y + height/2.0f;
	p.z = z + depth/2.0f;

	return p;
}
