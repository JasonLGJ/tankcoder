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

	std::shared_ptr<Resource> res = lod.getResource("test.json");


	if (res != nullptr)
	{
		std::shared_ptr<Resource> res2 = res->get("mainmenu");

		if (res2 != nullptr)
		{
			std::shared_ptr<Resource> res3 = res2->get("playbtn");

			if (res3 != nullptr)
			{
				float xs = res3->getNumber("x");
				printf("%f", xs);
			}
		}
	}

	int x;
	cin >> x;

	return x;
}
