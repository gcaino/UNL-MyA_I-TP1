#ifndef SCREEN_H
#define SCREEN_H
// ----------------------------------------------------------------------------
#include "DrawableObject.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class Screen : public DrawableObject
{
protected:
	sf::RenderWindow*	m_window;
	Screen*				m_nextScreen;

public:
	Screen();
	virtual ~Screen();

	Screen* getNextScreen() { return m_nextScreen; }
	void	setNextScreen(Screen* nextScreen) { m_nextScreen = nextScreen; }

	virtual void handleEvent(sf::Event event) = 0;
	virtual void update(sf::Time elapsedTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
// ----------------------------------------------------------------------------
}
#endif // SCREEN_H
