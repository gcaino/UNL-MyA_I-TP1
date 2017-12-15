#ifndef NPC_H
#define NPC_H
// ----------------------------------------------------------------------------
#include "DrawableObject.h"
#include "Constants.h"
#include "Player.h"
#include <SFML\Graphics.hpp>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
enum Type
{
	TYPE_BANDIT,
	TYPE_INNOCENT,
	TYPE_TOTAL
};
// ----------------------------------------------------------------------------
class NPC : public DrawableObject
{
private:
	Type			m_type;
	uint_t			m_points;
	bool			m_active;
	sf::Time		m_activeTime;
	sf::Time		m_elapsedActiveTime;
	sf::Time		m_elapsedTimeShot;
	sf::Time		m_speedShot;

	sf::Font		m_font;
	sf::Text		m_textShot;
	bool			m_showText;

	void setTexture();
	void setType();
	void showNPC(sf::Time elapsedTime);
	void setText();

public:
	NPC();
	NPC(Type type);
	~NPC();

	bool isActive() const { return m_active; }
	void setActive(bool active) { m_active = active; }
	uint_t getPoints() const { return m_points; }
	Type getType() const { return m_type; }
	sf::Text getTextShot() const { return m_textShot; }
	bool getShowText() const { return m_showText; }


	void shoot(sf::Time elapsedTime, Player& player);
	void update(sf::Time elapsedTime, Player& player);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // NPC_H