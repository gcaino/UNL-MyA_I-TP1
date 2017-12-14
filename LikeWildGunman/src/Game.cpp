#include "Game.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
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
	//m_window.setMouseCursorVisible(false);

	m_shape.setRadius(100.f);
	m_shape.setFillColor(sf::Color::Green);
}

Game::~Game()
{
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

}

void Game::draw()
{
	m_window.clear();
	m_window.draw(m_shape);
	m_window.display();
}
// ----------------------------------------------------------------------------
}