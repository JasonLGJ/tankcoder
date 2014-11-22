#include "Sound.h"

Sound::Sound() {
	playing = false;
	sfx = NULL;
	music = NULL;
	type = SOUND_TYPE_NONE;
}

Sound::~Sound() {
	if (type == SOUND_TYPE_SFX)
		Mix_FreeChunk(sfx);
	else
		Mix_FreeMusic(music);
}

void Sound::add_sfx(Mix_Chunk* s) {
	sfx = s;
	type = SOUND_TYPE_SFX;
}

void Sound::add_music(Mix_Music* m) {
	music = m;
	type = SOUND_TYPE_MUSIC;
}

void Sound::play() {
	if (!playing)
	{
		if (type == SOUND_TYPE_SFX)
		{
			Mix_PlayChannel(-1, sfx, 0);
		}
		else if (type == SOUND_TYPE_SFX)
		{
			if(Mix_PausedMusic() == 1)
			{
				Mix_ResumeMusic();
			}
			else
			{
				Mix_PlayMusic(music, -1);
			}
		}
		playing = true;
	}
}

void Sound::stop() {
	if (playing)
	{
		if (type == SOUND_TYPE_MUSIC)
		{
			Mix_PauseMusic();
		}

		playing = false;
	}
}

void Sound::setName(std::string n) {
	name = n;
}

std::string Sound::getName() {
	return name;
}

sound_type Sound::getType() {
	return type;
}
