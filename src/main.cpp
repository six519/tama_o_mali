#include <iostream>
#include "exception.hpp"
#include "game.hpp"

int main()
{
    Game game;

    try 
	{
        game.run();
    }
	catch(OtherException exception)
	{
        cout << exception.message();
        return EXIT_FAILURE;
    } 
	catch(FileException exception)
	{
        cout << exception.message();
        return EXIT_FAILURE;
    }

	return EXIT_SUCCESS;
}