#pragma once

#ifdef _WIN32
#include <SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

#include <string>

enum sound_type {
	SOUND_TYPE_NONE,
	SOUND_TYPE_MUSIC,
	SOUND_TYPE_SFX
};

class Sound {
	public:
		Sound();
		~Sound();
		void play();
		void stop();
		void add_sfx(Mix_Chunk* s);
		void add_music(Mix_Music* m);
		void setName(std::string n);
		std::string getName();
		sound_type getType();
	private:
		Mix_Chunk* sfx;
		Mix_Music* music;
		bool playing;
		sound_type type;
		std::string name;
};
