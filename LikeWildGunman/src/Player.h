#ifndef PLAYER_H
#define PLAYER_H
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Crosshair.h"
#include <SFML\Audio.hpp>
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
	uint_t		m_banditsKilled;
	uint_t		m_innocentKilled;
	uint_t		m_lifes;
	uint_t		m_bullets;

	bool		m_shooting;
	sf::Time	m_elapsedTimeShot;
	sf::Time	m_speedShot;

	sf::SoundBuffer m_gunshotSoundBuffer;
	sf::SoundBuffer m_reloadSoundBuffer;
	sf::SoundBuffer m_whizzingSoundBuffer;
	sf::Sound		m_gunshotSound;
	sf::Sound		m_reloadSound;
	sf::Sound		m_whizzingSound;

	void shoot();
	void subtractBullet();
	void reloadBullets();

public:
	Player();
	~Player();

	Crosshair* getCrooshair() { return &m_crosshair; }
	bool isShooting() const { return m_shooting; }
	void setShooting(bool shooting) { m_shooting = shooting; }
	uint_t getBullets() const { return m_bullets; }
	uint_t getLifes() const { return m_lifes; }
	uint_t getScore() const { return m_score; }
	void addScore(uint_t points);
	void addBanditsKilled() { ++m_banditsKilled; }
	uint_t getBanditsKilled() const { return m_banditsKilled; }
	uint_t getInnocentsKilled() const { return m_innocentKilled; }
	void addInnocentKilled() { ++m_innocentKilled; }
	void loseLife();
	void obtainLife();
	sf::Sound& getGunshotSound() { return m_gunshotSound; }
	sf::Sound& getWhizzingSound() { return m_whizzingSound; }

	void handleRealTimeInput();
	void update(sf::Time elapsedTime, const sf::RenderWindow& window);
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // PLAYER_H