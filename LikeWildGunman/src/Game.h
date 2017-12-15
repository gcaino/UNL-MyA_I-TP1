#ifndef GAME_H
#define GAME_H
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Background.h"
#include "Player.h"
#include "NPC.h"
#include "HUD.h"
#include "DrawableObject.h"
#include <SFML\Graphics.hpp>
#include <vector>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
const uint_t		FPS = 60;
const uint_t		MAX_NPC = 6;
const uint_t		MAX_SPAWN_POINTS = 6;

struct SpawnPoint
{
	bool			m_occupied;
	sf::Vector2f	m_position;
};
// ----------------------------------------------------------------------------
class Game
{
private:
	bool				m_running;
	bool				m_gameOver;
	uint_t				m_score;
	bool				m_pause;

	sf::RenderWindow	m_window;
	sf::Event			m_event;
	sf::Time			m_elapsedTime;
	sf::Clock			m_clock;

	Background*			m_background;
	Player*				m_player;
	NPC*				m_npcs[MAX_NPC];
	HUD*				m_hud;

	std::vector<DrawableObject*>				m_drawableObjects;
	std::vector<DrawableObject*>::iterator		m_it;

	SpawnPoint			m_spawnPoints[MAX_SPAWN_POINTS];
	sf::Time			m_elapsedSpawnTime;
	sf::Time			m_spawnTime;

	void addDrawableObjects();
	void initSpawnPoints();
	void spawnNPC(sf::Time	elapsedTime);
	void releaseSpawnPoints();
	void checkCollision();
	void checkGameCondition();
	void handlerInput();
	void update(sf::Time elapsedTime);
	void draw();

public:
	Game();
	~Game();

	void loop();
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // GAME_H

