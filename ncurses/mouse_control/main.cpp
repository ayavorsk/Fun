#include "Window.hpp"

int main()
{
	Window mainWindow(30, 22);
	while(1)
	{
		mainWindow.printCounter();
		mainWindow.getResponse();
		if (mainWindow.mouseKey())
			mainWindow.printPositionOfCursor();
		else if (mainWindow.isSpace())
			mainWindow.printSpace();
		else if (mainWindow.isEscape())
			break ;
		mainWindow.refreshWindow();
		
	}
	return 0;
}
