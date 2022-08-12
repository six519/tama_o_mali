#include "game.hpp"
#include "exception.hpp"

Game::Game()
{
	//init sounds
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
	{
		throw OtherException();
	}

	Mix_AllocateChannels(SND_CHANNELS);
	music = load_music("data/bg.ogg");
	right = load_sound("data/tama.wav");
	wrong = load_sound("data/mali.wav");
}

Mix_Music *Game::load_music(string fname)
{
	Mix_Music *mus = Mix_LoadMUS(fname.c_str());

	if (mus == NULL)
	{
		throw FileException(fname);
	}

	return mus;
}

Mix_Chunk *Game::load_sound(string fname)
{
	Mix_Chunk *sound = Mix_LoadWAV(fname.c_str());

	if (sound == NULL)
	{
		throw FileException(fname);
	}

	return sound;
}

void Game::run() 
{

}