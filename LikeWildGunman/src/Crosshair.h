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

	sf::Vector2f getPosition() const { return m_position; }
	void move(const sf::RenderWindow& window);
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // CROSSHAIR_H
