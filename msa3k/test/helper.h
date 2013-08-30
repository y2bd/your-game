// General Helper Functions
#ifndef HELPER_H
#define HELPER_H

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>

#include <cstdio>
#include <cstdlib>

int resolve_load(ALLEGRO_BITMAP **image, ALLEGRO_PATH **exe_path,
	const char *filename);

int resolve_load(ALLEGRO_SAMPLE **sample, ALLEGRO_PATH **exe_path,
	const char *filename);

void abort_game(const char *error_type, const char* message);

#endif
