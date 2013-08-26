// Audio class
//
// Contains audio and allows other classes to play them

#ifndef AUDIO_H
#define AUDIO_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <cstdio>

class Audio
{
private:
	ALLEGRO_SAMPLE *song_1;
	ALLEGRO_SAMPLE_INSTANCE *song_instance;

public:
	Audio();
	~Audio();

	void play_song(int song_num);
	void stop_song();
	void play_sound(int sound_num);
}; // class Audio

#endif
