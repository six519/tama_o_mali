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

	//load images
	press_image = load_image("data/enter.png");
	title_image = load_image("data/title.png");
	right_orange_image = load_image("data/tama_orange.png");
	right_green_image = load_image("data/tama_green.png");
	right_red_image = load_image("data/tama_red.png");

	wrong_orange_image = load_image("data/mali_orange.png");
	wrong_green_image = load_image("data/mali_green.png");
	wrong_red_image = load_image("data/mali_red.png");

	press_image_size = get_image_size(press_image);
	title_image_size = get_image_size(title_image);
	right_image_size = get_image_size(right_orange_image);
	wrong_image_size = get_image_size(wrong_orange_image);

	//init webcam
	VideoCapture vc(0);
	this->vc = vc;

	if(!this->vc.isOpened())
	{
		throw OtherException();
	}

	//open window
	namedWindow(GAME_TITLE);

	//other
	state = title;
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

Mat Game::load_image(string fname)
{
	Mat img = imread(fname, IMREAD_UNCHANGED);

	if (img.empty())
	{
		throw FileException(fname);
	}

	return img;
}

void Game::draw_transparent_image(Mat png, Mat image, int x, int y)
{
	Mat mask;
	vector<Mat> layers;

	split(png, layers);
	Mat rgb[3] = { layers[0],layers[1],layers[2] };
	mask = layers[3];
	merge(rgb, 3, png);
	png.copyTo(image.rowRange(y, y + png.rows).colRange(x, x + png.cols), mask);
}

void Game::run() 
{
	Mat tmp_image;
	vc >> cam_image;
	cam_image_size = get_image_size(cam_image);

	while(true)
	{
		vc >> cam_image;
		//mirror camera
		flip(cam_image, tmp_image, 1);
		cam_image = tmp_image;

		
		switch(state)
		{
			case game_start:
				handle_game();
			break;
			case game_over:
			break;
			default:
				// title
				draw_transparent_image(press_image, cam_image, (cam_image_size.width / 2) - (press_image_size.width / 2), cam_image_size.height - (press_image_size.height + 20));
				break;
		}

		draw_transparent_image(title_image, cam_image, cam_image_size.width - (title_image_size.width + 20), 20);

		imshow(GAME_TITLE, cam_image);
		char chr = (char)waitKey(1);

		if ((int)chr == 13 && state == title) 
		{
			state = game_start;
		}

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

Size Game::get_image_size(Mat image)
{
	Size s = image.size();
	return s;
}

void Game::handle_game()
{
	int right_x = ((cam_image_size.width / 2) / 2) - (right_image_size.width / 2);
	int wrong_x = (((cam_image_size.width / 2) / 2) - (wrong_image_size.width / 2)) + (cam_image_size.width / 2);
	int button_y = cam_image_size.height - (right_image_size.height + 20);

	draw_transparent_image(right_orange_image, cam_image, right_x, button_y);
	draw_transparent_image(wrong_orange_image, cam_image, wrong_x, button_y);
}

int Game::generate_random_number(int min, int max)
{
	return rand()%(max-min) + min;
}