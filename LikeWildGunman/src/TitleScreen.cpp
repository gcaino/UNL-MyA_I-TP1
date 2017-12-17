#include "TitleScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "IntroScreen.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
TitleScreen::TitleScreen(sf::RenderWindow* window)
{
	m_window = window;
	m_texture.loadFromFile(pathTitleScreenImage);
	m_sprite.setTexture(m_texture);
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::handleEvent(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Return)
		m_nextScreen = new IntroScreen(m_window);
}

void TitleScreen::update(sf::Time elapsedTime)
{
}

void TitleScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_window->clear(sf::Color::White);
	target.draw(m_sprite, states);
	m_window->display();
}
// ----------------------------------------------------------------------------
}



