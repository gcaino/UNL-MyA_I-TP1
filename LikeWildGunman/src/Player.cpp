#include "Player.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include <SFML/Audio.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
Player::Player()
	: MAX_BULLETS(10)
	, MAX_LIFES(3)
	, m_bullets(MAX_BULLETS)
	, m_lifes(MAX_LIFES)
	, m_score(0)
	, m_banditsKilled(0)
	, m_innocentKilled(0)
	, m_shooting(false)
	, m_speedShot(sf::seconds(0.5f))
	, m_elapsedTimeShot(sf::Time::Zero)
{
	m_gunshotSoundBuffer.loadFromFile(path9mmGunshotAudio);
	m_gunshotSound.setBuffer(m_gunshotSoundBuffer);

	m_reloadSoundBuffer.loadFromFile(pathShotgunReloadAudio);
	m_reloadSound.setBuffer(m_reloadSoundBuffer);

	m_whizzingSoundBuffer.loadFromFile(pathBulletWhizzingAudio);
	m_whizzingSound.setBuffer(m_whizzingSoundBuffer);
}

Player::~Player()
{
}

void Player::handleRealTimeInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
		!m_shooting &&
		m_bullets > 0)
	{
		m_shooting = true;
	}
	else
	{
		m_shooting = false;
	}
		
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		reloadBullets();
}

void Player::update(sf::Time elapsedTime, const sf::RenderWindow& window)
{
	m_crosshair.move(window);

	m_elapsedTimeShot += elapsedTime;
	if (m_shooting && (m_elapsedTimeShot.asSeconds() > m_speedShot.asSeconds()))
	{
		shoot();
		m_shooting = false;
		m_elapsedTimeShot = sf::Time::Zero;
	}
}

void Player::shoot()
{
	subtractBullet();
}

void Player::subtractBullet()
{
	if (m_bullets == 0)
		return;

	--m_bullets;
}

void Player::reloadBullets()
{
	m_reloadSound.play();
	m_bullets = MAX_BULLETS;
}

void Player::loseLife()
{
	if (m_lifes == 0)
		return;

	--m_lifes;
}

void Player::obtainLife()
{
	++m_lifes;
}

void Player::addScore(uint_t points)
{
	m_score += points;
}

void Player::subtractScore(uint_t points)
{
	if (m_score == 0)
		return;

	m_score -= points;
}
// ----------------------------------------------------------------------------
}