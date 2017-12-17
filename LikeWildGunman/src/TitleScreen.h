#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H
// ----------------------------------------------------------------------------
#include "Screen.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class TitleScreen : public Screen
{
public:
	TitleScreen(sf::RenderWindow* window);
	~TitleScreen();

	virtual void handleEvent(sf::Event event);
	virtual void update(sf::Time elapsedTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
#endif // TITLE_SCREEN_H


