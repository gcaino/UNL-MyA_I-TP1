#ifndef SCREEN_H
#define SCREEN_H
// ----------------------------------------------------------------------------
#include "DrawableObject.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class ScreenManager;
// ----------------------------------------------------------------------------
/**
* Clase Abstracta de la cual heredan todas las clases que representan pantallas
* en el flow del juego.
*/
class Screen : public DrawableObject
{
protected:
	ScreenManager*	m_screenManager;

public:
	Screen(ScreenManager* screenManager);
	virtual ~Screen();

	virtual void handleEvent(sf::Event event) = 0;
	virtual void update(sf::Time elapsedTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
#endif // SCREEN_H
