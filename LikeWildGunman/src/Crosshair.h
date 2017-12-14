#ifndef CROSSHAIR_H
#define CROSSHAIR_H
// ----------------------------------------------------------------------------
#include "DrawableObject.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class Crosshair : public DrawableObject
{
private:
	sf::Vector2f	m_position;

public:
	Crosshair();
	~Crosshair();

	void move(const sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // CROSSHAIR_H
