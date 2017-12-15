#include <iostream>
#include <cstdlib>
#include <ctime>
// ----------------------------------------------------------------------------
#include "Game.h"
// ----------------------------------------------------------------------------
int main()
{
	srand(time(NULL));
	try
	{
		lwgm::Game game;
		game.loop();
	}
	catch (const char* exception)
	{
		std::cerr << "Error: " << exception << std::endl;
	}
	return 0;
}