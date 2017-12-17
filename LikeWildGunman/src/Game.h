#ifndef GAME_H
#define GAME_H
// ----------------------------------------------------------------------------
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
const unsigned int	FPS = 60;
// ----------------------------------------------------------------------------
class Game
{
private:
	bool				m_running;
	sf::RenderWindow	m_window;
	sf::Event			m_event;
	sf::Time			m_elapsedTime;
	sf::Clock			m_clock;
	ScreenManager*		m_screenManager;

public:
	Game();
	~Game();

	void loop();
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // GAME_H

