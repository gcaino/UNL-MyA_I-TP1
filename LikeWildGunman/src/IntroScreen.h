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
	IntroScreen(sf::RenderWindow* window);
	~IntroScreen();

	virtual void handleInput();
	virtual void update(sf::Time elapsedTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
#endif // INTRO_SCREEN_H


