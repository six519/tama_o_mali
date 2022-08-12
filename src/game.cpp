#include "game.hpp"
#include "exception.hpp"

Game::Game()
{
	//init sounds
	music_loaded = false;
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048))
	{
		throw OtherException();
	}

	Mix_AllocateChannels(SND_CHANNELS);
	music = load_music("data/bg.ogg");
	right = load_sound("data/tama.wav");
	wrong = load_sound("data/mali.wav");

	//init webcam
	VideoCapture vc(0);
	this->vc = vc;

	if(!this->vc.isOpened())
	{
		throw OtherException();
	}

	//open window
	namedWindow(GAME_TITLE);
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
	Mat tmp_image;

	while(true)
	{
		vc >> cam_image;
		//mirror camera
		flip(cam_image, tmp_image, 1);
		cam_image = tmp_image;

		imshow(GAME_TITLE, cam_image);
		char chr = (char)waitKey(1);

		if ((int)chr == 27) 
		{
			break;
		}

		if(!music_loaded)
		{
			music_loaded = true;
			Mix_PlayMusic(music, -1);
		}
	}
}