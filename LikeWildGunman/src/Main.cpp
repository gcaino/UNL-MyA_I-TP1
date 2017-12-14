#include <iostream>
// ----------------------------------------------------------------------------
#include "Game.h"
// ----------------------------------------------------------------------------
int main()
{
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