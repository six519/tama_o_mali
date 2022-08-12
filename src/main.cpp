#include <iostream>
#include "exception.hpp"
#include "game.hpp"

int main()
{
    try 
	{
		Game game;
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