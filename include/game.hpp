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
#include <vector>
#include "questions.hpp"

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
		Mat right_green_image;
		Mat wrong_green_image;
		Mat right_red_image;
		Mat wrong_red_image;
		Mat right_orange_image;
		Mat wrong_orange_image;
		bool music_loaded;
		game_state state;
		Size cam_image_size;
		Size press_image_size;
		Size title_image_size;
		Size right_image_size;
		Size wrong_image_size;
    public:
		Game();
        void run();
		Size get_image_size(Mat image);
		Mix_Music *load_music(string fname);
		Mix_Chunk *load_sound(string fname);
		Mat load_image(string fname);
		void draw_transparent_image(Mat png, Mat image, int x, int y);
		void handle_game();
};

#endif