#ifndef GAME_H
#define GAME_H
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Background.h"
#include "Player.h"
#include "HUD.h"
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
	sf::Event			m_event;
	sf::Time			m_elapsedTime;
	sf::Clock			m_clock;

	Background*			m_background;
	Player*				m_player;
	HUD*				m_hud;

	std::vector<DrawableObject*>				m_drawableObjects;
	std::vector<DrawableObject*>::iterator		m_it;

	void addDrawableObjects();
	void handlerInput();
	void update(sf::Time elapsedTime);
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

