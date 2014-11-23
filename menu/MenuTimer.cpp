#include "MenuTimer.h"
void MenuTimer::update(){
	segs = 0;
	mins = 0;

	segs++;
	if (segs >= 60)
	{
		segs = 0;
		mins++;

	}
	min_1->getTexture()->changeTexture(mins / 10);
	min_2->getTexture()->changeTexture(mins % 10);
	seg_1->getTexture()->changeTexture(segs / 10);
	seg_2->getTexture()->changeTexture(segs % 10);

}

void create(std::shared_ptr<SceneManager> s){

	//meep
}