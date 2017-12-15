#ifndef PLAYER_H
#define PLAYER_H
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Crosshair.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class Player
{
private:
	const uint_t MAX_BULLETS;
	const uint_t MAX_LIFES;

	Crosshair	m_crosshair;
	uint_t		m_score;
	uint_t		m_lifes;
	uint_t		m_bullets;

	bool		m_shooting;
	sf::Time	m_elapsedTimeShot;
	sf::Time	m_speedShot;

	void shoot();
	void subtractBullet();
	void reloadBullets();

public:
	Player();
	~Player();

	Crosshair* getCrooshair() { return &m_crosshair; }
	bool isShooting() const { return m_shooting; }
	uint_t getBullets() const { return m_bullets; }
	uint_t getLifes() const { return m_lifes; }
	uint_t getScore() const { return m_score; }
	void addScore(uint_t points);
	void subtractScore(uint_t points);
	void loseLife();
	void obtainLife();

	void handlerInput();
	void update(sf::Time elapsedTime, const sf::RenderWindow& window);
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // PLAYER_H