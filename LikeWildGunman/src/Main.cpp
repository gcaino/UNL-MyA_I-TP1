// ----------------------------------------------------------------------------
//	Materia: Modelos y Algoritmos I - TP 01
//	Autor: Germán Daniel Caíno
//	Versión: 1.0.0
//	Fecha: 12/12/2017
// ----------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
// ----------------------------------------------------------------------------
#include "Game.h"
// ----------------------------------------------------------------------------
int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
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