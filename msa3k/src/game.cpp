#include "game.h"
#include "audio.h"

Game::Game(Audio *audio, Render *render):
	gamestate_mode(TITLE_SCREEN), audio_manager(audio), render_manager(render)
{
	gamedata.load_map("new.txt");
} // Game()



void Game::update()
{

	audio_manager->play_song(2);
	if (inputs.wild_down == 67 && gamestate_mode == TITLE_SCREEN)
	{
		audio_manager->play_sound(1, -1.0);
		al_rest(0.25);
		audio_manager->play_sound(1, 1.0);
		inputs.wild_down = 0;
		audio_manager->stop_song();
		audio_manager->play_song(1);
		gamestate_mode = PLATFORM_SCREEN;
	} // if switch to platform
	
	if (inputs.wild_down == 67 && gamestate_mode == PLATFORM_SCREEN)
	{
		audio_manager->play_sound(1, 1.0);
		al_rest(0.25);
		audio_manager->play_sound(1, -1.0);
		inputs.wild_down = 0;
		audio_manager->stop_song();
		audio_manager->play_song(2);
		gamestate_mode = TITLE_SCREEN;
	} // if switch to Title
} // update()



void Game::draw()
{
	switch(gamestate_mode)
	{
		case TITLE_SCREEN:
			render_manager->draw_title();
			break;
		case PLATFORM_SCREEN:
			render_manager->draw_ingame(&inputs);
			break;
		default:
			break;
	}; // case(gamestate_mode)

} // draw()

