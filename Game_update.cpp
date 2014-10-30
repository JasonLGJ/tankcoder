#include "Game.h"

void Game::update() {
	rotation += 1.0f;

	if (rotation > 180.0f)
		rotation = -180.0f;

	scene.setRotation(rotation);
}