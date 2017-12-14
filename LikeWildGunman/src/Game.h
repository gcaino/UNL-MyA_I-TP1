#ifndef GAME_H
#define GAME_H
// ----------------------------------------------------------------------------
#include "Constants.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class Game
{
private:
	const uint_t		FPS;

	bool				m_running;
	uint_t				m_score;
	bool				m_pause;

	sf::RenderWindow	m_window;
	sf::Font			m_font;
	sf::Text			m_text;
	sf::Event			m_event;
	sf::Clock			m_clock;
	sf::Time			m_deltaTime;

	sf::CircleShape		m_shape;
	
	//std::vector<DrawableObject>				m_gameObjects;
	//std::vector<DrawableObject>::iterator	m_it;

	void handlerInput();
	void update();
	void draw();

public:
	Game();
	~Game();

	void loop();
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // GAME_H

