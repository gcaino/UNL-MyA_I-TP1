#include "GameOverScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "TitleScreen.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
GameOverScreen::GameOverScreen(sf::RenderWindow* window)
{
	m_window = window;
	m_texture.loadFromFile(pathGameOverScreenImage);
	m_sprite.setTexture(m_texture);
}


GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::handleEvent(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Return)
		m_nextScreen = new TitleScreen(m_window);
}

void GameOverScreen::update(sf::Time elapsedTime)
{
}

void GameOverScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_window->clear(sf::Color::White);
	target.draw(m_sprite, states);
	m_window->display();
}
// ----------------------------------------------------------------------------
}



