#include "TitleScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "IntroScreen.h"
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
TitleScreen::TitleScreen(ScreenManager* screenManager)
	: Screen(screenManager)
{
	m_texture.loadFromFile(pathTitleScreenImage);
	m_sprite.setTexture(m_texture);
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::handleEvent(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Return)
		m_screenManager->changeScreen(new IntroScreen(m_screenManager));
}

void TitleScreen::update(sf::Time elapsedTime)
{
}

// ----------------------------------------------------------------------------
}



