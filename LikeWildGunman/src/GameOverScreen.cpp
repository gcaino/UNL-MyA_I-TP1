#include "GameOverScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "TitleScreen.h"
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
GameOverScreen::GameOverScreen(ScreenManager* screenManager)
	: Screen(screenManager)
{
	m_texture.loadFromFile(pathGameOverScreenImage);
	m_sprite.setTexture(m_texture);
}


GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::handleEvent(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Return)
		m_screenManager->changeScreen(new TitleScreen(m_screenManager));
}

void GameOverScreen::update(sf::Time elapsedTime)
{
}

// ----------------------------------------------------------------------------
}



