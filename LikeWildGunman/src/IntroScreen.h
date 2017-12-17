#ifndef INTRO_SCREEN_H
#define INTRO_SCREEN_H
// ----------------------------------------------------------------------------
#include "Screen.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class IntroScreen :
	public Screen
{
public:
	IntroScreen(ScreenManager* screenManager);
	~IntroScreen();

	virtual void handleEvent(sf::Event event);
	virtual void update(sf::Time elapsedTime);
};
// ----------------------------------------------------------------------------
}
#endif // INTRO_SCREEN_H


