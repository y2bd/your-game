# include "init.h"

void init(ALLEGRO_EVENT_QUEUE **event_queue, ALLEGRO_TIMER **timer,
	ALLEGRO_DISPLAY **display, bool *done)
{
	if (!al_init())                                // Initialize Allegro
		abort_game("Failed to initialize allegro");

	if(!al_init_image_addon())                     // Initialize Image
		abort_game("Failed to initialize image engine");
									  
	if (!al_install_keyboard())                    // Install Keyboard
		abort_game("Failed to install keyboard");
	
	if(!al_install_mouse())                        // Install Mouse
		abort_game("Failed to install mouse");

	if (!(*timer = al_create_timer (PHYSICS_TIMESTEP)))// Game tick at 60Hz
	  abort_game("Failed to create timer");

	if(!al_init_acodec_addon())                    // Initialize Audio Codecs
		abort_game("Failed to initilize audio codecs");

	if(!al_install_audio())                        // Initialize Audio
		abort_game("Failed to initialize audio engine");
	
	if(!al_reserve_samples(20))                    // Reserve audio mixer
		abort_game("Failed to reserve samples");
	
		// Display set to fixed window
	al_set_new_display_flags(ALLEGRO_WINDOWED);    

		// Display sized 800 x 400
	if (!(*display = al_create_display(GAME_WIDTH, GAME_HEIGHT)))
		abort_game("Failed to create display");
																																			 
	if (!(*event_queue = al_create_event_queue())) // Initialize Event Queue
		abort_game("Failed to create event queue");
	
	// Register Timer and Keyboard to Event Queue
	al_register_event_source(*event_queue, al_get_keyboard_event_source());
	al_register_event_source(*event_queue, al_get_mouse_event_source());
	al_register_event_source(*event_queue, al_get_timer_event_source(*timer));
	al_register_event_source(*event_queue, al_get_display_event_source(*display));

	al_set_window_title(*display, "Mystery Space Adventure 3000");
	*done = false; // Initialized Succesfully!
} // init()



void abort_game(const char* message) // initialization failed
{
  printf("Initialization Failed:\n%s \n", message);
	printf("Aborting...\n");
  exit(1);
} // abort_game()



void shutdown(ALLEGRO_EVENT_QUEUE **event_queue, ALLEGRO_TIMER **timer,
	ALLEGRO_DISPLAY **display)
{
  if (*timer)
    al_destroy_timer(*timer);
		 
  if (*display)
	  al_destroy_display(*display);
														  
	if (*event_queue)
	  al_destroy_event_queue(*event_queue);
} // shutdown()
