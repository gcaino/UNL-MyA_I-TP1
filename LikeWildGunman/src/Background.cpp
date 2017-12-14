#include "Background.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
Background::Background()
{
	m_texture.loadFromFile(pathBackgroundImage);
	m_sprite.setTexture(m_texture);
}

Background::~Background()
{
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
// ----------------------------------------------------------------------------
}
