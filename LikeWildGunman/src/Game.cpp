#include "Game.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Crosshair.h"
#include <string>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
Game::Game()
	: m_running(true)
	, m_score(0)
	, m_pause(false)
	, FPS(60)
{
	m_window.create(sf::VideoMode(WINDOW_WIDTH_MAX, WINDOW_HEIGHT_MAX),"SFML - Like Wild Gunman");
	m_window.setFramerateLimit(FPS);
	m_window.setMouseCursorVisible(false);

	m_background	= new Background();
	m_player		= new Player();
	m_hud			= new HUD();
	addDrawableObjects();
}

Game::~Game()
{
	delete m_background;
	delete m_player;
	delete m_hud;
}

void Game::addDrawableObjects()
{
	m_drawableObjects.push_back(m_background);
	m_drawableObjects.push_back(m_player->getCrooshair());
}

void Game::loop()
{
	while (m_running)
	{
		handlerInput();

		if (!m_pause)
		{
			m_elapsedTime = m_clock.restart();
			update(m_elapsedTime);
		}

		draw();
	}
}

void Game::handlerInput()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)	
			m_running = false;

		if (m_event.type == sf::Event::KeyPressed)
		{
			if (m_event.key.code == sf::Keyboard::P)
				m_pause = !m_pause;
			else if (m_event.key.code == sf::Keyboard::Escape)
				m_running = false;
		}
	}

	if (!m_pause)
		m_player->handlerInput();
}

void Game::update(sf::Time	elapsedTime)
{
	m_player->update(elapsedTime, m_window);
	m_hud->updateTexts(*m_player);
}

void Game::draw()
{
	m_window.clear(sf::Color::White);
	
	for (m_it = m_drawableObjects.begin(); m_it != m_drawableObjects.end(); m_it++)
		m_window.draw((*m_it)->getSprite(), sf::RenderStates::Default);

	for (size_t i = 0; i < m_hud->getTexts().size(); i++)
		m_window.draw(*m_hud->getTexts().at(i));

	m_window.display();
}
// ----------------------------------------------------------------------------
}