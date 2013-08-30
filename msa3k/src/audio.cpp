#include "audio.h"

Audio::Audio():song_instance(NULL), is_playing(0)
{
	// Gets path relative to exe
	ALLEGRO_PATH *path;
	const char *path_str;
	char proper_path[128];

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	path_str = (path) ? al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP) : "<none>";

	// Load sounds
	sprintf(proper_path, "%sresources/song.ogg", path_str);

	if(!(song_1 = al_load_sample(proper_path)))
		fprintf(stderr, "[Audio Error] resources/song.ogg not found\n");

	sprintf(proper_path, "%sresources/title.wav", path_str);

	if(!(song_2 = al_load_sample(proper_path)))
		fprintf(stderr, "[Audio Error] resources/title.wav not found\n");

	
	al_destroy_path(path);
} // Audio()



Audio::~Audio()
{
	al_destroy_sample(song_1);
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



void Audio::play_sound(int sound_num)
{
	//al_play_sample(soundeffects)
} // play_sound()

