#include "HUD.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Player.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
HUD::HUD()
{
	initTexts();
	addTextsToDraw();
}

HUD::~HUD()
{
}

void HUD::initTexts()
{
	m_font.loadFromFile(pathFont);
	m_scoreText.setFont(m_font);
	m_scoreText.setFillColor(sf::Color::Red);
	m_scoreText.setStyle(sf::Text::Bold);
	m_scoreText.setCharacterSize(30);
	m_scoreText.setPosition(WINDOW_WIDTH_MAX * 0.12f, WINDOW_HEIGHT_MAX * 0.83f);

	m_lifesText.setFont(m_font);
	m_lifesText.setFillColor(sf::Color::Red);
	m_lifesText.setStyle(sf::Text::Bold);
	m_lifesText.setCharacterSize(30);
	m_lifesText.setPosition(WINDOW_WIDTH_MAX * 0.44f, WINDOW_HEIGHT_MAX * 0.83f);

	m_bulletsText.setFont(m_font);
	m_bulletsText.setFillColor(sf::Color::Red);
	m_bulletsText.setStyle(sf::Text::Bold);
	m_bulletsText.setCharacterSize(30);
	m_bulletsText.setPosition(WINDOW_WIDTH_MAX * 0.7f, WINDOW_HEIGHT_MAX * 0.83f);
}

void HUD::addTextsToDraw()
{
	m_texts.push_back(&m_scoreText);
	m_texts.push_back(&m_lifesText);
	m_texts.push_back(&m_bulletsText);
}

void HUD::updateTexts(const Player& player)
{
	m_scoreText.setString("SCORE: " + std::to_string(player.getScore()));
	m_lifesText.setString("LIFES: " + std::to_string(player.getLifes()));
	m_bulletsText.setString("BULLETS: " + std::to_string(player.getBullets()));
}
// ----------------------------------------------------------------------------
}
