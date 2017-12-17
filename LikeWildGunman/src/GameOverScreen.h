#ifndef GAMEOVER_SCREEN_H
#define GAMEOVER_SCREEN_H
// ----------------------------------------------------------------------------
#include "Screen.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class GameOverScreen : public Screen
{
public:
	GameOverScreen(sf::RenderWindow* window);
	~GameOverScreen();

	virtual void handleEvent(sf::Event event);
	virtual void update(sf::Time elapsedTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
#endif // GAMEOVER_SCREEN_H
