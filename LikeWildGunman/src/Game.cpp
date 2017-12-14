#include "Game.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Crosshair.h"
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

	m_player = new Player();

	addDrawableObjets();
}

Game::~Game()
{
	delete m_player;
}

void Game::addDrawableObjets()
{
	m_drawableObjects.push_back(m_player->getCrooshair());
}

void Game::loop()
{
	while (m_running)
	{
		handlerInput();
		update();
		draw();
	}
}

void Game::handlerInput()
{
	while (m_window.pollEvent(m_event))
	{
		if (m_event.type == sf::Event::Closed)	
			m_running = false;
	}
}

void Game::update()
{
	m_player->update(m_window);
}

void Game::draw()
{
	m_window.clear(sf::Color::White);
	
	for (m_it = m_drawableObjects.begin(); m_it != m_drawableObjects.end(); m_it++)
		m_window.draw((*m_it)->getSprite(), sf::RenderStates::Default);

	m_window.display();
}
// ----------------------------------------------------------------------------
}