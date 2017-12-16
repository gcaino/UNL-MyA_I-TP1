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
	m_screenManager.pushScreen(new TitleScreen(&m_window));
}

Game::~Game()
{
	m_screenManager.popScreen();
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
				else if (m_event.key.code == sf::Keyboard::Return)
					m_screenManager.peekScreen()->setNextScreen(new IntroScreen(&m_window));
			}
		}
		if (m_screenManager.peekScreen()->getNextScreen() != nullptr)
			m_screenManager.changeScreen(m_screenManager.peekScreen()->getNextScreen());

		m_screenManager.peekScreen()->handleInput();

		m_elapsedTime = m_clock.restart();
		m_screenManager.peekScreen()->update(m_elapsedTime);

		m_screenManager.peekScreen()->draw(m_window, sf::RenderStates::Default);
	}
}

// ----------------------------------------------------------------------------
}