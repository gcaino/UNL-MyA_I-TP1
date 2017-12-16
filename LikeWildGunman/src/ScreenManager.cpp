#include "ScreenManager.h"
// ----------------------------------------------------------------------------
#include "TitleScreen.h"
#include "GameOverScreen.h"
#include "IntroScreen.h"
#include "GamePlayScreen.h"
#include <stack>
// ----------------------------------------------------------------------------
namespace lwgm
{
// ----------------------------------------------------------------------------
ScreenManager::ScreenManager()
{
}

ScreenManager::~ScreenManager()
{
	
}

void ScreenManager::pushScreen(Screen* screen)
{
	m_screens.push(screen);
}

void ScreenManager::popScreen()
{
	delete m_screens.top();
	m_screens.pop();
}

Screen* ScreenManager::peekScreen()
{
	if (m_screens.empty()) return nullptr;
	return m_screens.top();
}

void ScreenManager::changeScreen(Screen* screen)
{
	if (!m_screens.empty())
		popScreen();
	pushScreen(screen);
}

// ----------------------------------------------------------------------------
}
