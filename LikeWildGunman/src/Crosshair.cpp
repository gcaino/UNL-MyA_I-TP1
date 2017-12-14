#include "Crosshair.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
Crosshair::Crosshair()
{
	m_texture.loadFromFile(pathCrooshairImage);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

Crosshair::~Crosshair()
{
}

void Crosshair::move(const sf::RenderWindow& window)
{
	m_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	m_sprite.setPosition(m_position);
}

void Crosshair::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite);
}
// ----------------------------------------------------------------------------
}
