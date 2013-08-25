#include "audio.h"

Audio::Audio():song_instance(NULL)
{
	// Gets path relative to exe
	ALLEGRO_PATH *path;
	const char *path_str;
	char proper_path[128];

	path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	path_str = (path) ? al_path_cstr(path, ALLEGRO_NATIVE_PATH_SEP) : "<none>";
	al_destroy_path(path);

	// Load sounds
	sprintf(proper_path, "%sresources/song.ogg", path_str);

	if(!(song_1 = al_load_sample(proper_path)))
		fprintf(stderr, "[Audio Error] resources/song.ogg not found\n");
	
} // Audio()



Audio::~Audio()
{
	al_destroy_sample(song_1);
	al_destroy_sample_instance(song_instance);
} // ~Audio()



void Audio::play_song(int song_num)
{
	ALLEGRO_SAMPLE *song;

	switch(song_num)
	{
		case 1:
			song = song_1;
			break;
		default:
			break;
	} // case(song_num)

	song_instance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(song_instance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(song_instance, al_get_default_mixer());
	al_play_sample_instance(song_instance);
	printf("Playing Song_%d\n", song_num); // FIXME debug
} // play_song()



void Audio::stop_song()
{
	al_stop_sample_instance(song_instance);
} // stop_song()



void Audio::play_sound(int sound_num)
{
	//al_play_sample(soundeffects)
} // play_sound()
