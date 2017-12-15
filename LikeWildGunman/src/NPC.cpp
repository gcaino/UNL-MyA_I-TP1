#include "NPC.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include <SFML\Graphics.hpp>
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
{
	setType();
	setTexture();
}

NPC::NPC(Type type)
	: m_points(10)
	, m_active(false)
	, m_activeTime(sf::seconds(4.f))
	, m_elapsedActiveTime(sf::Time::Zero)
	, m_type(type)
{
	setTexture();
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

void NPC::showNPC(sf::Time elapsedTime)
{
	m_elapsedActiveTime += elapsedTime;
	if (m_elapsedActiveTime > m_activeTime)
	{
		m_active = false;
		m_elapsedActiveTime = sf::Time::Zero;
	}
}

void NPC::update(sf::Time elapsedTime)
{
	if (m_active)
		showNPC(elapsedTime);
}

void NPC::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_active)
		target.draw(m_sprite);
}
// ----------------------------------------------------------------------------
}