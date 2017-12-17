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
	GameOverScreen(ScreenManager* screenManager);
	~GameOverScreen();

	virtual void handleEvent(sf::Event event);
	virtual void update(sf::Time elapsedTime);
};
// ----------------------------------------------------------------------------
}
#endif // GAMEOVER_SCREEN_H
