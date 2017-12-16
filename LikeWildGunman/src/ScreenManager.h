#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
// ----------------------------------------------------------------------------
#include <stack>
// ----------------------------------------------------------------------------
namespace lwgm
{
class Screen;
// ----------------------------------------------------------------------------
class ScreenManager
{
private:
	std::stack<Screen*>		m_screens;
	
public:
	ScreenManager();
	~ScreenManager();

	void pushScreen(Screen* screen);
	void popScreen();
	Screen* peekScreen();
	void changeScreen(Screen* screen);
};
// ----------------------------------------------------------------------------
}
#endif // SCREEN_MANAGER_H


