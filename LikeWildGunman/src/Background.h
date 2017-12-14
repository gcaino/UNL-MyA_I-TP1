#ifndef BACKGROUND_H
#define BACKGROUND_H
// ----------------------------------------------------------------------------
#include "DrawableObject.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
#include "DrawableObject.h"
class Background : public DrawableObject
{
public:
	Background();
	~Background();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // BACKGROUND_H

