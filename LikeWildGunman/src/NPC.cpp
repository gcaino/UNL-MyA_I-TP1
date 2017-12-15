#include "NPC.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Player.h"
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <cstdlib>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
NPC::NPC()
	: m_points(10)
	, m_active(false)
	, m_activeTime(sf::seconds(4.f))
	, m_elapsedActiveTime(sf::Time::Zero)
	, m_speedShot(sf::seconds(3.f))
	, m_elapsedTimeShot(sf::Time::Zero)
	, m_showText(false)
{
	setType();
	setTexture();
	if (m_type == Type::TYPE_BANDIT)
		setText();

	m_gunshotSoundBuffer.loadFromFile(pathM1GunshotAudio);
	m_gunshotSound.setBuffer(m_gunshotSoundBuffer);
}

NPC::NPC(Type type)
	: m_points(10)
	, m_active(false)
	, m_activeTime(sf::seconds(4.f))
	, m_elapsedActiveTime(sf::Time::Zero)
	, m_type(type)
	, m_speedShot(sf::seconds(3.f))
	, m_elapsedTimeShot(sf::Time::Zero)
	, m_showText(false)
{
	setTexture();
	if (m_type == Type::TYPE_BANDIT)
		setText();

	m_gunshotSoundBuffer.loadFromFile(pathM1GunshotAudio);
	m_gunshotSound.setBuffer(m_gunshotSoundBuffer);
}

NPC::~NPC()
{
}

void NPC::setTexture()
{
	m_texture.loadFromFile(pathTagetsImage);

	const uint_t MAX_IMAGES = 6;
	int leftPositions[MAX_IMAGES];
	sf::IntRect rect;
	rect.height = m_texture.getSize().y;
	rect.width = m_texture.getSize().x / MAX_IMAGES;
	rect.top = 0;

	for (size_t i = 0; i < MAX_IMAGES; i++)
		leftPositions[i] = i * rect.width;

	uint_t randomPosition;
	if (m_type == TYPE_BANDIT)
	{
		randomPosition  = rand() % (MAX_IMAGES - MAX_IMAGES / 2);
	}
	else if (m_type == TYPE_INNOCENT)
	{
		randomPosition = (rand() % (MAX_IMAGES - MAX_IMAGES / 2)) + MAX_IMAGES / 2;
	}
	rect.left = leftPositions[randomPosition];

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(rect);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height));
}

void NPC::setType()
{
	uint_t probability = rand() % 10 + 1; // Probabilidad entre 1 y 10
	if (probability > 4)
		m_type = TYPE_BANDIT;
	else
		m_type = TYPE_INNOCENT;
}

void NPC::setText()
{
	m_font.loadFromFile(pathFont);
	m_textShot.setFont(m_font);
	m_textShot.setPosition(sf::Vector2f());
	m_textShot.setFillColor(sf::Color::White);
	m_textShot.setStyle(sf::Text::Bold);
	m_textShot.setString("BANNG!");
	m_textShot.setCharacterSize(20);
}

void NPC::showNPC(sf::Time elapsedTime)
{
	m_elapsedActiveTime += elapsedTime;
	if (m_elapsedActiveTime > m_activeTime)
	{
		m_active = false;
		m_elapsedActiveTime = sf::Time::Zero;
	}
}

void NPC::shoot(sf::Time elapsedTime, Player& player)
{
	m_elapsedTimeShot += elapsedTime;
	if (m_elapsedTimeShot.asSeconds() > m_speedShot.asSeconds())
	{
		player.loseLife();
		m_gunshotSound.play();
		m_showText = true;
		m_textShot.setPosition(m_sprite.getPosition().x - (m_sprite.getGlobalBounds().width * 0.5f),
			m_sprite.getPosition().y - (m_sprite.getGlobalBounds().height * 1.3f));
		m_elapsedTimeShot = sf::Time::Zero;
	}
}

void NPC::update(sf::Time elapsedTime, Player& player)
{
	if (m_active)
	{
		showNPC(elapsedTime);
		if (m_type == Type::TYPE_BANDIT)
			shoot(elapsedTime, player);
	}
	else
	{
		if (m_showText)
			m_showText = false;
	}
		
}

void NPC::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_active)
	{ 
		target.draw(m_sprite);
		if (m_showText)
			target.draw(m_textShot);
	}
}
// ----------------------------------------------------------------------------
}