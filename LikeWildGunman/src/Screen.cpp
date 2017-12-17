#include "Screen.h"
// ----------------------------------------------------------------------------
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
Screen::Screen(ScreenManager* screenManager)
	: m_screenManager(screenManager)
{
}

Screen::~Screen()
{
}

void Screen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
// ----------------------------------------------------------------------------
}



