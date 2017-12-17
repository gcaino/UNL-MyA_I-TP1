#ifndef GAMEPLAY_SCREEN_H
#define GAMEPLAY_SCREEN_H
// ----------------------------------------------------------------------------
#include "Screen.h"
#include "Constants.h"
#include <SFML\Graphics.hpp>
#include <vector>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
const uint_t		MAX_NPC = 6;
const uint_t		MAX_SPAWN_POINTS = 6;

struct SpawnPoint
{
	bool			m_occupied;
	sf::Vector2f	m_position;
};

class Background;
class Player;
class NPC;
class HUD;
class DrawableObject;
// ----------------------------------------------------------------------------
class GamePlayScreen : public Screen
{
private:
	bool				m_gameOver;
	int					m_score;
	bool				m_pause;

	Background*			m_background;
	Player*				m_player;
	NPC*				m_npcs[MAX_NPC];
	HUD*				m_hud;

	std::vector<DrawableObject*>				m_drawableObjects;
	std::vector<DrawableObject*>::iterator		m_it;

	SpawnPoint			m_spawnPoints[MAX_SPAWN_POINTS];
	sf::Time			m_elapsedSpawnTime;
	sf::Time			m_spawnTime;

	sf::Font			m_font;
	sf::Text			m_startText;
	sf::Time			m_elapsedWaitTime;
	sf::Time			m_waitTime;
	bool				m_start;

	void addDrawableObjects();
	void initSpawnPoints();
	void spawnNPC(sf::Time	elapsedTime);
	void releaseSpawnPoints();
	void checkCollision();
	void checkGameCondition();
	void waitToStart(sf::Time elapsedTime);
	void waitToFinish(sf::Time elapsedTime);
	void showStartText();
	void showReloadText();
	void calculateScore();
	
public:
	GamePlayScreen(ScreenManager* screenManager);
	~GamePlayScreen();

	virtual void handleEvent(sf::Event event);
	virtual void update(sf::Time elapsedTime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
#endif // GAMEPLAY_SCREEN_H


