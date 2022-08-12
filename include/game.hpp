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
#define GAME_TITLE "Tama o Mali"

using namespace std;
using namespace cv;

class Game
{
	private:
		Mix_Music *music;
		Mix_Chunk *right;
		Mix_Chunk *wrong;
		VideoCapture vc;
		Mat cam_image;
		bool music_loaded;
    public:
		Game();
        void run();
		Mix_Music *load_music(string fname);
		Mix_Chunk *load_sound(string fname);
};

#endif