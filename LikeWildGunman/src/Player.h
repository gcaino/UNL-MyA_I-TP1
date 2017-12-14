#ifndef PLAYER_H
#define PLAYER_H
// ----------------------------------------------------------------------------
#include "Crosshair.h"
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
class Player
{
private:
	Crosshair	m_crosshair;

public:
	Player();
	~Player();

	Crosshair* getCrooshair() { return &m_crosshair; }

	void update(const sf::RenderWindow& window);
};
// ----------------------------------------------------------------------------
}
// ----------------------------------------------------------------------------
#endif // PLAYER_H

