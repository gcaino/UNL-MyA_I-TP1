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
	m_scoreText.text.setFont(m_font);
	m_scoreText.text.setFillColor(sf::Color::Red);
	m_scoreText.text.setStyle(sf::Text::Bold);
	m_scoreText.text.setCharacterSize(30);
	m_scoreText.text.setPosition(WINDOW_WIDTH_MAX * 0.12f, WINDOW_HEIGHT_MAX * 0.83f);
	m_scoreText.visible = true;

	m_bulletsText.text.setFont(m_font);
	m_bulletsText.text.setFillColor(sf::Color::Red);
	m_bulletsText.text.setStyle(sf::Text::Bold);
	m_bulletsText.text.setCharacterSize(23);
	m_bulletsText.text.setPosition(WINDOW_WIDTH_MAX * 0.43f, WINDOW_HEIGHT_MAX * 0.81f);
	m_bulletsText.visible = true;

	m_reloadText.text.setFont(m_font);
	m_reloadText.text.setFillColor(sf::Color::Red);
	m_reloadText.text.setStyle(sf::Text::Bold);
	m_reloadText.text.setCharacterSize(15);
	m_reloadText.text.setPosition(WINDOW_WIDTH_MAX * 0.41f, WINDOW_HEIGHT_MAX * 0.86f);
	m_reloadText.text.setString("PRESS 'R' TO RELOAD");
	m_reloadText.visible = false;

	m_lifesText.text.setFont(m_font);
	m_lifesText.text.setFillColor(sf::Color::Red);
	m_lifesText.text.setStyle(sf::Text::Bold);
	m_lifesText.text.setCharacterSize(30);
	m_lifesText.text.setPosition(WINDOW_WIDTH_MAX * 0.73f, WINDOW_HEIGHT_MAX * 0.83f);
	m_lifesText.visible = true;
}

void HUD::addTextsToDraw()
{
	m_texts.push_back(&m_scoreText);
	m_texts.push_back(&m_lifesText);
	m_texts.push_back(&m_bulletsText);
	m_texts.push_back(&m_reloadText);
}

void HUD::updateTexts(const Player& player)
{
	m_scoreText.text.setString("SCORE: " + std::to_string(player.getScore()));
	m_lifesText.text.setString("LIFES: " + std::to_string(player.getLifes()));
	m_bulletsText.text.setString("BULLETS: " + std::to_string(player.getBullets()));
}
// ----------------------------------------------------------------------------
}
