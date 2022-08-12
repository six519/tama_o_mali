#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <SDL_mixer.h>

#define SND_CHANNELS 4

using namespace std;

class Game
{
	private:
		Mix_Music *music;
    public:
		Game();
        void run();
		Mix_Music *load_music(string fname);
};

#endif