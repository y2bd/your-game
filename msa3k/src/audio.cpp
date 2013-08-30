#include "audio.h"

Audio::Audio():song_instance(NULL), is_playing(0)
{
	ALLEGRO_PATH *exe_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	int error_exists = 0;

	error_exists += resolve_load(&song_1, &exe_path, "resources/song.ogg");
	error_exists += resolve_load(&song_2, &exe_path, "resources/title.wav");

	error_exists += resolve_load(&sound_1, &exe_path, "resources/coin.wav");

	al_destroy_path(exe_path);

	if(error_exists)
		abort_game("Could not find all the audio resources!");
} // Audio()



Audio::~Audio()
{
	al_destroy_sample(song_1);
	al_destroy_sample(song_2);
	al_destroy_sample(sound_1);
	al_destroy_sample_instance(song_instance);
} // ~Audio()



void Audio::play_song(int song_num)
{
	if(is_playing == 1)
		return;

	ALLEGRO_SAMPLE *song;
	double gain;

	switch(song_num)
	{
		case 1:
			song = song_1;
			gain = 0.7;
			break;
		case 2:
			song = song_2;
			gain = 1.2;
			break;
		default:
			return;
			break;
	} // case(song_num)

	song_instance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(song_instance, ALLEGRO_PLAYMODE_LOOP);
	al_set_sample_instance_gain(song_instance, gain);
	al_attach_sample_instance_to_mixer(song_instance, al_get_default_mixer());

	al_play_sample_instance(song_instance);

	printf("Playing Song_%d\n", song_num); // FIXME debug
	is_playing = 1;
} // play_song()



void Audio::stop_song()
{
	if(!is_playing)
		return;

	al_stop_sample_instance(song_instance);
	is_playing = 0;
} // stop_song()



int Audio::get_is_playing()
{
	return is_playing;
} // get_is_playing()



void Audio::play_sound(int sound_num, float pan)
{
	ALLEGRO_SAMPLE *sound;
	//double gain;
	switch(sound_num)
	{
		case 1:
		sound = sound_1;
		break;
		default:
			return;
			break;
	} // case(song_num)

	if(!(al_play_sample(sound, 1.6, pan, 1.0, ALLEGRO_PLAYMODE_ONCE, 0)))
		fprintf(stderr, "[Audio Error] Could not play sample %d!\n", sound_num);
} // play_sound()

