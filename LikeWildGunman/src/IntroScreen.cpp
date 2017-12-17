#include "IntroScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "GamePlayScreen.h"
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
IntroScreen::IntroScreen(ScreenManager* screenManager)
	: Screen(screenManager)
{
	m_texture.loadFromFile(pathTargetsScreenImage);
	m_sprite.setTexture(m_texture);

	m_policeChatterSoundBuffer.loadFromFile(pathPoliceChatterAudio);
	m_policeChatterSound.setBuffer(m_policeChatterSoundBuffer);
	m_policeChatterSound.play();
}


IntroScreen::~IntroScreen()
{
}

void IntroScreen::handleEvent(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Return)
		m_screenManager->changeScreen(new GamePlayScreen(m_screenManager));
}

void IntroScreen::update(sf::Time elapsedTime)
{
}

// ----------------------------------------------------------------------------
}



