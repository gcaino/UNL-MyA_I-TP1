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
	, m_gameOver(false)
	, m_score(0)
	, m_pause(false)
	, m_spawnTime(sf::seconds(3.f))
	, m_elapsedSpawnTime(sf::Time::Zero)
	, m_spawnPoints { false, sf::Vector2f() }
{
	m_window.create(sf::VideoMode(WINDOW_WIDTH_MAX, WINDOW_HEIGHT_MAX),"M&A I - TP 01");
	m_window.setFramerateLimit(FPS);
	m_window.setMouseCursorVisible(false);

	m_background	= new Background();
	m_player		= new Player();
	
	for (size_t i = 0; i < MAX_NPC; i++)
	{
		// 2 Inocentes y 4 Bandidos, de esa manera evitamos que por probabilidad salgan todos de un solo tipo
		if (i == 1 || i == 4)	
			m_npcs[i] = new NPC(Type::TYPE_INNOCENT);
		else
			m_npcs[i] = new NPC(Type::TYPE_BANDIT);
	}
	
	m_hud = new HUD();
	addDrawableObjects();
	initSpawnPoints();
}

Game::~Game()
{
	delete m_background;
	delete m_player;

	for (size_t i = 0; i < MAX_NPC; i++)
		delete m_npcs[i];

	delete m_hud;
}

void Game::addDrawableObjects()
{
	m_drawableObjects.push_back(m_background);

	for (size_t i = 0; i < MAX_NPC; i++)
		m_drawableObjects.push_back(m_npcs[i]);

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

void Game::initSpawnPoints()
{
	m_spawnPoints[0].m_position = sf::Vector2f(120.f, 212.f);
	m_spawnPoints[1].m_position = sf::Vector2f(120.f, 436.f);
	m_spawnPoints[2].m_position = sf::Vector2f(510.f, 210.f);
	m_spawnPoints[3].m_position = sf::Vector2f(510.f, 482.f);
	m_spawnPoints[4].m_position = sf::Vector2f(970.f, 212.f);
	m_spawnPoints[5].m_position = sf::Vector2f(970.f, 436.f);
}

void Game::spawnNPC(sf::Time elapsedTime)
{
	m_elapsedSpawnTime += elapsedTime;
	if (m_elapsedSpawnTime > m_spawnTime)
	{
		uint_t randomPoint = rand() % MAX_SPAWN_POINTS;
		while (m_spawnPoints[randomPoint].m_occupied)
		{
			randomPoint = rand() % MAX_SPAWN_POINTS;
		}

		uint_t randomIndex = rand() % MAX_NPC;
		while (m_npcs[randomIndex]->isActive())
		{
			randomIndex = rand() % MAX_SPAWN_POINTS;
		}

		m_npcs[randomIndex]->setActive(true);
		m_npcs[randomIndex]->getSprite().setPosition(m_spawnPoints[randomPoint].m_position);
		m_spawnPoints[randomPoint].m_occupied = true;
		m_elapsedSpawnTime = sf::Time::Zero;
	}
}

void Game::releaseSpawnPoints()
{
	for (size_t point = 0; point < MAX_SPAWN_POINTS; point++)
	{
		if (m_spawnPoints[point].m_occupied)
		{
			for (size_t index = 0; index < MAX_NPC; index++)
			{
				if ((!m_npcs[index]->isActive()) && 
					(m_npcs[index]->getSprite().getPosition() == m_spawnPoints[point].m_position))
				{
					m_npcs[index]->getSprite().setPosition(sf::Vector2f());
					m_spawnPoints[point].m_occupied = false;
				}
			}
		}
	}
}

void Game::checkCollision()
{
	if (m_player->isShooting())
	{
		for (size_t index = 0; index < MAX_NPC; index++)
		{
			if (m_npcs[index]->isActive())
			{
				if (m_npcs[index]->getSprite().getGlobalBounds().contains(m_player->getCrooshair()->getPosition()))
				{
					m_npcs[index]->setActive(false);
					if (m_npcs[index]->getType() == Type::TYPE_BANDIT)
					{
						m_player->addScore(m_npcs[index]->getPoints());
					}
					else if (m_npcs[index]->getType() == Type::TYPE_INNOCENT)
					{
						m_player->subtractScore(m_npcs[index]->getPoints());
						m_player->loseLife();
					}
				}
			}
		}
	}
}

void Game::checkGameCondition()
{
	if (m_player->getLifes() == 0)
		m_gameOver = true;
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
	spawnNPC(elapsedTime);

	for (size_t i = 0; i < MAX_NPC; i++)
		m_npcs[i]->update(elapsedTime);

	releaseSpawnPoints();

	m_player->update(elapsedTime, m_window);
	checkCollision();
	checkGameCondition();
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