// block

#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "constants.h"
#include "init.h"
#include "game.h"
#include "render.h"
#include "audio.h"

#define MAX_FRAMESKIP 5
  
void game_loop(ALLEGRO_EVENT_QUEUE **event_queue, ALLEGRO_TIMER **timer,
	ALLEGRO_DISPLAY **display, bool *done)
{
	bool redraw = true; // True means we need to redraw screen
	int mode = 2, loaded = 0; // mode 2 is in game.
	al_start_timer(*timer);

	Game engine;
	Render render;
	Audio audio;
	ALLEGRO_EVENT event;

	audio.play_song(1);
	printf("\nClick Close Window Button to quit.\n");

	while (!*done)
	{
		al_wait_for_event(*event_queue, &event);
		
		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			engine.update(); 		 // Update engine
			
			if(loaded == 0 && mode == 2)
			{
				render.load_ingame(&engine); // Load resources for graphics
				loaded = 1;
			} // if in game and not loaded

		} // if timer ticked (update phase)
		else
		{
			if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) // close window clicked
				break;

			//engine.inputs.gather(&event);
		} // else collect inputs

 		if (redraw && al_is_event_queue_empty(*event_queue))
		{
			redraw = false;
			render.draw_ingame(&engine, display); // Draws graphics.
		} // if engine updated and even queye is empty (output phase)

  } // while

	audio.stop_song();

} // game_loop()
		  
int main(int argc, char* argv[])
{
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* timer;
	ALLEGRO_DISPLAY* display;

	bool done; // game keeps running when false

	init(&event_queue, &timer, &display, &done);
	game_loop(&event_queue, &timer, &display, &done);
	shutdown(&event_queue, &timer, &display);

	return 0;
} // main()
