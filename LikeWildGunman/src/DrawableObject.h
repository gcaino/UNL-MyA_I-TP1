#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
// ----------------------------------------------------------------------------
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class DrawableObject : sf::Drawable
{
protected:
	sf::Texture		m_texture;
	sf::Sprite		m_sprite;

public:
	DrawableObject();
	virtual ~DrawableObject();

	sf::Sprite	getSprite() const { return m_sprite; }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // DRAWABLE_OBJECT_H