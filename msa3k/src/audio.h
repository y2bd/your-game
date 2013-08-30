// Audio class
//
// Contains audio and allows other classes to play them

#ifndef AUDIO_H
#define AUDIO_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <cstdio>
#include "helper.h"

class Audio
{
private:
	ALLEGRO_SAMPLE *song_1, *song_2, *sound_1;
	ALLEGRO_SAMPLE_INSTANCE *song_instance;
	int is_playing;

public:

	Audio();
	~Audio();

	void play_song(int song_num);
	void stop_song();
	int get_is_playing();
	void play_sound(int sound_num, float pan);
}; // class Audio

#endif
