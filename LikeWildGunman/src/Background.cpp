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
// ----------------------------------------------------------------------------
}
