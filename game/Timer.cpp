#include "Timer.h"

Timer::Timer() {
	segs = 0;
	mins = 0;

	min_1 = nullptr;
	min_2 = nullptr;
	seg_1 = nullptr;
	seg_2 = nullptr;
}

void Timer::update(){
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

void Timer::create(std::shared_ptr<SceneManager> scene){
	min_1 = scene->createFlatNode("assets/editor/num1", 10.5, 6.2, 0.5, 0.5);
	min_1->getTexture()->setMultiTexture(10);
	
	min_2 = scene->createFlatNode("assets/editor/num2", 11.0, 6.2, 0.5, 0.5);
	min_2->getTexture()->setMultiTexture(10);
	
	seg_1 = scene->createFlatNode("assets/editor/num3", 11.5, 6.2, 0.5, 0.5);
	seg_1->getTexture()->setMultiTexture(10);
	
	seg_2 = scene->createFlatNode("assets/editor/num4", 12.0, 6.2, 0.5, 0.5);
	seg_2->getTexture()->setMultiTexture(10);
}

void Timer::restart() {
	mins = 0;
	segs = 0;
}

void Timer::remove() {
	min_1 = nullptr;
	min_2 = nullptr;
	seg_1 = nullptr;
	seg_2 = nullptr;
}