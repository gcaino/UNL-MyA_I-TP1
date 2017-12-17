#ifndef INTRO_SCREEN_H
#define INTRO_SCREEN_H
// ----------------------------------------------------------------------------
#include "Screen.h"
#include <SFML\Audio.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class IntroScreen : public Screen
{
private:
	sf::SoundBuffer		m_policeChatterSoundBuffer;
	sf::Sound			m_policeChatterSound;

public:
	IntroScreen(ScreenManager* screenManager);
	~IntroScreen();

	virtual void handleEvent(sf::Event event);
	virtual void update(sf::Time elapsedTime);
};
// ----------------------------------------------------------------------------
}
#endif // INTRO_SCREEN_H


