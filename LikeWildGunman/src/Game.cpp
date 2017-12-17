#include "Game.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "ScreenManager.h"
#include "TitleScreen.h"
#include "IntroScreen.h"
#include "GamePlayScreen.h"
#include <string>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
Game::Game()
	: m_running(true)

{
	m_window.create(sf::VideoMode(WINDOW_WIDTH_MAX, WINDOW_HEIGHT_MAX),"M&A I - TP 01");
	m_window.setFramerateLimit(FPS);
	m_window.setMouseCursorVisible(false);
	m_window.setKeyRepeatEnabled(false);

	m_screenManager = new ScreenManager(&m_window);
	m_screenManager->addScreen(new TitleScreen(m_screenManager));
}

Game::~Game()
{
	m_screenManager->removeScreen();
	delete m_screenManager;
}

void Game::loop()
{
	while (m_running)
	{
		while (m_window.pollEvent(m_event))
		{
			if (m_event.type == sf::Event::Closed)
				m_running = false;

			if (m_event.type == sf::Event::KeyPressed)
			{
				if (m_event.key.code == sf::Keyboard::Escape)
					m_running = false;
				else
					m_screenManager->getScreen()->handleEvent(m_event);
			}
		}
		m_elapsedTime = m_clock.restart();
		m_screenManager->getScreen()->update(m_elapsedTime);

		m_window.clear(sf::Color::White);
		m_screenManager->getScreen()->draw(m_window, sf::RenderStates::Default);
		m_window.display();
	}
}

// ----------------------------------------------------------------------------
}