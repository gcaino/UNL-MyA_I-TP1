#include "IntroScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "GamePlayScreen.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
IntroScreen::IntroScreen(sf::RenderWindow* window)
{
	m_window = window;
	m_texture.loadFromFile(pathTargetsScreenImage);
	m_sprite.setTexture(m_texture);
}


IntroScreen::~IntroScreen()
{
}

void IntroScreen::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		m_nextScreen = new GamePlayScreen(m_window);
}

void IntroScreen::update(sf::Time elapsedTime)
{
}

void IntroScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_window->clear(sf::Color::White);
	target.draw(m_sprite, states);
	m_window->display();
}
// ----------------------------------------------------------------------------
}



