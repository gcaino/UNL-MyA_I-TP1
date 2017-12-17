#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H
// ----------------------------------------------------------------------------
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
/**
 * Clase Base (propia) para los objetos que son dibujables
 */
class DrawableObject : sf::Drawable
{
protected:
	sf::Texture		m_texture;
	sf::Sprite		m_sprite;

public:
	DrawableObject();
	virtual ~DrawableObject();

	sf::Sprite&	getSprite()  { return m_sprite; }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // DRAWABLE_OBJECT_H
