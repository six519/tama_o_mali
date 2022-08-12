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

enum game_state
{
	title,
	game_start,
	game_over
};

class Game
{
	private:
		Mix_Music *music;
		Mix_Chunk *right;
		Mix_Chunk *wrong;
		VideoCapture vc;
		Mat cam_image;
		Mat press_image;
		Mat title_image;
		bool music_loaded;
		game_state state;
    public:
		Game();
        void run();
		Size get_image_size(Mat image);
		Mix_Music *load_music(string fname);
		Mix_Chunk *load_sound(string fname);
		Mat load_image(string fname);
		void draw_transparent_image(Mat png, Mat image, int x, int y);
};

#endif