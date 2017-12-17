#include "GamePlayScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Screen.h"
#include "Background.h"
#include "Player.h"
#include "NPC.h"
#include "HUD.h"
#include "DrawableObject.h"
#include "Crosshair.h"
#include "GameOverScreen.h"
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <string>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
GamePlayScreen::GamePlayScreen(sf::RenderWindow* window)
	: m_gameOver(false)
	, m_score(0)
	, m_pause(false)
	, m_spawnTime(sf::seconds(3.f))
	, m_elapsedSpawnTime(sf::Time::Zero)
	, m_spawnPoints{ false, sf::Vector2f() }
{
	m_window = window;
	m_background = new Background();
	m_player = new Player();

	for (size_t i = 0; i < MAX_NPC; i++)
	{
		// 2 Inocentes y 4 Bandidos, de esa manera evitamos que por probabilidad salgan todos de un solo tipo
		if (i == 1 || i == 4)
			m_npcs[i] = new NPC(Type::TYPE_INNOCENT);
		else
			m_npcs[i] = new NPC(Type::TYPE_BANDIT);
	}

	m_hud = new HUD();
	//addDrawableObjects();
	initSpawnPoints();
}

GamePlayScreen::~GamePlayScreen()
{
	delete m_background;
	delete m_player;

	for (size_t i = 0; i < MAX_NPC; i++)
		delete m_npcs[i];

	delete m_hud;
}

void GamePlayScreen::addDrawableObjects()
{
	m_drawableObjects.push_back(m_background);

	for (size_t i = 0; i < MAX_NPC; i++)
		m_drawableObjects.push_back(m_npcs[i]);

	m_drawableObjects.push_back(m_player->getCrooshair());
}

void GamePlayScreen::initSpawnPoints()
{
	m_spawnPoints[0].m_position = sf::Vector2f(120.f, 212.f);
	m_spawnPoints[1].m_position = sf::Vector2f(120.f, 436.f);
	m_spawnPoints[2].m_position = sf::Vector2f(510.f, 210.f);
	m_spawnPoints[3].m_position = sf::Vector2f(510.f, 482.f);
	m_spawnPoints[4].m_position = sf::Vector2f(970.f, 212.f);
	m_spawnPoints[5].m_position = sf::Vector2f(970.f, 436.f);
}

void GamePlayScreen::spawnNPC(sf::Time elapsedTime)
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

void GamePlayScreen::releaseSpawnPoints()
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

void GamePlayScreen::checkCollision()
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
					m_player->getGunshotSound().play();
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
				else
				{
					m_player->getWhizzingSound().play();
				}
			}
		}
	}
}

void GamePlayScreen::checkGameCondition()
{
	if (m_player->getLifes() == 0)
	{
		m_gameOver = true;
		m_nextScreen = new GameOverScreen(m_window);
	}
}

void GamePlayScreen::handleEvent(sf::Event event)
{
}

void GamePlayScreen::update(sf::Time	elapsedTime)
{
	spawnNPC(elapsedTime);

	for (size_t i = 0; i < MAX_NPC; i++)
		m_npcs[i]->update(elapsedTime, *m_player);

	releaseSpawnPoints();

	if (!m_pause)
		m_player->handleRealTimeInput();

	m_player->update(elapsedTime, *m_window);
	checkCollision();
	checkGameCondition();
	m_hud->updateTexts(*m_player);
}

void GamePlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_window->clear(sf::Color::White);

	// Funciona pero me quita flexibilidad a la hora de mostrar textos junto a los sprites
	/*for (m_it = m_drawableObjects.begin(); m_it != m_drawableObjects.end(); m_it++)
	m_window.draw((*m_it)->getSprite(), sf::RenderStates::Default);*/

	m_background->draw(*m_window, sf::RenderStates::Default);

	for (size_t index = 0; index < MAX_NPC; index++)
		m_npcs[index]->draw(*m_window, sf::RenderStates::Default);

	m_player->getCrooshair()->draw(*m_window, sf::RenderStates::Default);

	for (size_t i = 0; i < m_hud->getTexts().size(); i++)
		m_window->draw(*m_hud->getTexts().at(i));

	m_window->display();
}
// ----------------------------------------------------------------------------
}



