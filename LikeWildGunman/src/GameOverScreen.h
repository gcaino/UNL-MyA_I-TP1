#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H
// ----------------------------------------------------------------------------
#include "Screen.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class Player;
// ----------------------------------------------------------------------------
class GameOverScreen : public Screen
{
private:
	Player*		m_player;
	sf::Font	m_font;
	sf::Text	m_text;

public:
	GameOverScreen(ScreenManager* screenManager, Player* player);
	~GameOverScreen();

	virtual void handleEvent(sf::Event event);
	virtual void update(sf::Time elapsedTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
#endif // GAMEOVER_SCREEN_H
