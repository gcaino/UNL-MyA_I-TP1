#ifndef HUD_H
#define HUD_H
// ----------------------------------------------------------------------------
#include "Player.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
struct Text
{
	sf::Text	text;
	bool		visible;
};
// ----------------------------------------------------------------------------
class HUD
{
private:
	sf::Font		m_font;		
	Text			m_bulletsText;
	Text			m_reloadText;
	Text			m_lifesText;
	Text			m_scoreText;

	std::vector<Text*>	m_texts;

	void initTexts();
	void addTextsToDraw();

public:
	HUD();
	~HUD();

	std::vector<Text*> getTexts() const { return m_texts; }
	void updateTexts(const Player& player);
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // HUD_H