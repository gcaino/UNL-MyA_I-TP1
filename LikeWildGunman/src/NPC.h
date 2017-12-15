#ifndef NPC_H
#define NPC_H
// ----------------------------------------------------------------------------
#include "DrawableObject.h"
#include "Constants.h"
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

	void setTexture();
	void setType();
	void showNPC(sf::Time elapsedTime);

public:
	NPC();
	~NPC();

	bool isActive() const { return m_active; }
	void setActive(bool active) { m_active = active; }
	uint_t getPoints() const { return m_points; }
	Type getType() const { return m_type; }

	void update(sf::Time elapsedTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // NPC_H