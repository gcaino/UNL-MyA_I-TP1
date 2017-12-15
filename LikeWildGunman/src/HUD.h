#ifndef HUD_H
#define HUD_H
// ----------------------------------------------------------------------------
#include "Player.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class HUD
{
private:
	sf::Font			m_font;
	sf::Text			m_bulletsText;
	sf::Text			m_lifesText;
	sf::Text			m_scoreText;

	std::vector<sf::Text*>	m_texts;

	void initTexts();
	void addTextsToDraw();

public:
	HUD();
	~HUD();

	std::vector<sf::Text*> getTexts() const { return m_texts; }
	void updateTexts(const Player& player);
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // HUD_H