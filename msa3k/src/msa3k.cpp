// block

#include <allegro5/allegro5.h>
#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "constants.h"
#include "helper.h"
#include "init.h"
#include "game.h"
#include "render.h"
#include "audio.h"

#define MAX_FRAMESKIP 5
  
void game_loop(ALLEGRO_EVENT_QUEUE **event_queue, ALLEGRO_TIMER **timer,
	ALLEGRO_DISPLAY **display, bool *done)
{
	bool redraw = true; // True means we need to redraw screen
	//int mode = 2, loaded = 0; // mode 2 is in game.
	al_start_timer(*timer);

	Render render(display);
	Audio audio;
	ALLEGRO_EVENT event;

	Game engine(&audio, &render);

	printf("\nClick Close Window Button to quit.\n");

	while (!*done)
	{
		al_wait_for_event(*event_queue, &event);
		
		if (event.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;
			engine.update(); 		 // Update engine
		} // if timer ticked (update phase)
		else
		{
			if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) // close window clicked
				break;

			engine.inputs.gather(&event);
		} // else collect inputs

 		if (redraw && al_is_event_queue_empty(*event_queue))
		{
			redraw = false;
			engine.draw();
		} // if engine updated and even queye is empty (output phase)

  } // while

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
