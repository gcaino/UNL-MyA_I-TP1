#include "DrawableObject.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
DrawableObject::DrawableObject()
{
}

DrawableObject::~DrawableObject()
{
}

void DrawableObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
// ----------------------------------------------------------------------------
}