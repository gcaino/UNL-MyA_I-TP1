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
#include "ScreenManager.h"
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <string>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
GamePlayScreen::GamePlayScreen(ScreenManager* screenManager)
	: Screen(screenManager)
	, m_gameOver(false)
	, m_score(0)
	, m_pause(false)
	, m_start(false)
	, m_spawnTime(sf::seconds(3.f))
	, m_waitTime(sf::Time::Zero)
	, m_elapsedSpawnTime(sf::Time::Zero)
	, m_elapsedWaitTime(sf::seconds(4.f))
	, m_spawnPoints{ false, sf::Vector2f() }
{
	m_background = new Background();
	m_player = new Player();

	for (size_t i = 0; i < MAX_NPC; i++)
	{
		// 2 Inocentes y 4 Bandidos, de esa manera evitamos que por probabilidad salgan todos de un s�lo tipo
		if (i == 1 || i == 4)
			m_npcs[i] = new NPC(Type::TYPE_INNOCENT);
		else
			m_npcs[i] = new NPC(Type::TYPE_BANDIT);
	}

	m_hud = new HUD();
	//addDrawableObjects();
	initSpawnPoints();

	m_font.loadFromFile(pathFont);
	m_startText.setFont(m_font);
	m_startText.setFillColor(sf::Color::White);
	m_startText.setStyle(sf::Text::Bold);
	m_startText.setCharacterSize(50);
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
		m_npcs[randomIndex]->resetElapsedActiveTime();
		m_npcs[randomIndex]->resetElapsedTimeShot();
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

void GamePlayScreen::calculateScore()
{
	int tempScore = (m_player->getBanditsKilled() - m_player->getInnocentsKilled()) * 10;
	if (tempScore < 0) tempScore = 0;
	m_score = tempScore;
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
						m_player->addBanditsKilled();
						calculateScore();
						m_player->addScore(m_score);
					}
					else if (m_npcs[index]->getType() == Type::TYPE_INNOCENT)
					{
						m_player->addInnocentKilled();
						calculateScore();
						m_player->loseLife();
					}
					return;
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
		m_gameOver = true;
}

void GamePlayScreen::waitToStart(sf::Time elapsedTime)
{
	m_elapsedWaitTime -= elapsedTime;
	if (m_elapsedWaitTime <= m_waitTime)
	{
		m_start = true;
		m_elapsedWaitTime = sf::Time::Zero;
		m_waitTime = sf::seconds(3.f);
	}
}

void GamePlayScreen::waitToFinish(sf::Time elapsedTime)
{
	m_elapsedWaitTime += elapsedTime;
	if (m_elapsedWaitTime > m_waitTime)
	{
		m_screenManager->changeScreen(new GameOverScreen(m_screenManager, m_player));
		m_elapsedWaitTime = sf::Time::Zero;
	}
}

void GamePlayScreen::showStartText()
{
	m_startText.setString("READY " + std::to_string(static_cast<int>(m_elapsedWaitTime.asSeconds())));
	m_startText.setPosition(WINDOW_WIDTH_MAX / 2 - m_startText.getGlobalBounds().width / 2, WINDOW_HEIGHT_MAX * 0.15f);
}

void GamePlayScreen::showReloadText()
{
	if (m_player->getBullets() <= 0)
		m_hud->getTexts().back()->visible = true;
	else
	{
		if (m_hud->getTexts().back()->visible)
			m_hud->getTexts().back()->visible = false;
	}
}

void GamePlayScreen::handleEvent(sf::Event event)
{
}

void GamePlayScreen::update(sf::Time elapsedTime)
{
	if (!m_start)
	{
		waitToStart(elapsedTime);
		showStartText();
		return;
	}
	if (m_gameOver)
	{
		waitToFinish(elapsedTime);
		return;
	}

	spawnNPC(elapsedTime);
	for (size_t i = 0; i < MAX_NPC; i++)
		m_npcs[i]->update(elapsedTime, *m_player);
	releaseSpawnPoints();

	if (!m_pause)
		m_player->handleRealTimeInput();

	m_player->update(elapsedTime, m_screenManager->getRenderWindow());
	showReloadText();
		
	checkCollision();

	m_hud->updateTexts(*m_player);

	checkGameCondition();
}

void GamePlayScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Funciona pero me quita flexibilidad a la hora de mostrar textos junto a los sprites
	/*for (m_it = m_drawableObjects.begin(); m_it != m_drawableObjects.end(); m_it++)
	m_window.draw((*m_it)->getSprite(), sf::RenderStates::Default);*/
	sf::RenderWindow& window = m_screenManager->getRenderWindow();

	m_background->draw(window, sf::RenderStates::Default);

	for (size_t index = 0; index < MAX_NPC; index++)
		m_npcs[index]->draw(window, sf::RenderStates::Default);

	m_player->getCrooshair()->draw(window, sf::RenderStates::Default);

	if (!m_start)
		window.draw(m_startText);

	for (size_t i = 0; i < m_hud->getTexts().size(); i++)
	{
		if (m_hud->getTexts().at(i)->visible)
			window.draw(m_hud->getTexts().at(i)->text);
	}
		
}
// ----------------------------------------------------------------------------
}



