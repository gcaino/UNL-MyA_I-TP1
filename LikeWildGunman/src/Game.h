#ifndef GAME_H
#define GAME_H
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Player.h"
#include "DrawableObject.h"
#include <SFML\Graphics.hpp>
#include <vector>
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

	Player*				m_player;

	std::vector<DrawableObject*>			m_drawableObjects;
	std::vector<DrawableObject*>::iterator	m_it;

	void addDrawableObjets();
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

