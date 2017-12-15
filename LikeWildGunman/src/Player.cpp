#include "Player.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
Player::Player()
	: MAX_BULLETS(10)
	, MAX_LIFES(5)
	, m_bullets(MAX_BULLETS)
	, m_lifes(MAX_LIFES)
	, m_score(0)
	, m_isShooting(false)
	, m_speedShot(sf::seconds(0.5f))
	, m_elapsedTimeShot(sf::Time::Zero)
{
}

Player::~Player()
{
}

void Player::handlerInput()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !m_isShooting)
		m_isShooting = true;
	else
		m_isShooting = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		reloadBullets();
}

void Player::update(sf::Time elapsedTime, const sf::RenderWindow& window)
{
	m_crosshair.move(window);

	m_elapsedTimeShot += elapsedTime;
	if (m_isShooting && (m_elapsedTimeShot.asSeconds() > m_speedShot.asSeconds()))
	{
		shoot();
		m_isShooting = false;
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
// ----------------------------------------------------------------------------
}