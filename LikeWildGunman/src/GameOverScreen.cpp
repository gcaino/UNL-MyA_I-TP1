#include "GameOverScreen.h"
// ----------------------------------------------------------------------------
#include "Constants.h"
#include "Player.h"
#include "TitleScreen.h"
#include "ScreenManager.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
GameOverScreen::GameOverScreen(ScreenManager* screenManager, Player* player)
	: Screen(screenManager)
	, m_player(player)
{
	m_texture.loadFromFile(pathGameOverScreenImage);
	m_sprite.setTexture(m_texture);
	m_font.loadFromFile(pathFont);
	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::White);
	m_text.setStyle(sf::Text::Bold);
	m_text.setCharacterSize(30);
	m_text.setString("YOUR SCORE IS: " + std::to_string(m_player->getScore()));
	m_text.setPosition(WINDOW_WIDTH_MAX / 2 - m_text.getGlobalBounds().width / 2, WINDOW_HEIGHT_MAX * 0.6f);
}


GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::handleEvent(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Return)
		m_screenManager->changeScreen(new TitleScreen(m_screenManager));
}

void GameOverScreen::update(sf::Time elapsedTime)
{
}

void GameOverScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
	target.draw(m_text, states);
}
// ----------------------------------------------------------------------------
}



