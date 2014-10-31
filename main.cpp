#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Game.h"
#include "libs/json/gason.h"

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	Loader lod;

	lod.getResource("test.json");

	int x;
	cin >> x;

	return x;
}
