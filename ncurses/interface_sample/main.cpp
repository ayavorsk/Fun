#include "Window.hpp"

#define ROWS 10
#define COLUMNS 22

int main()
{
	Window mainWindow(ROWS, COLUMNS);
	mainWindow.createButtons(NB_OF_BUTTONS);
	while(1)
	{
		mainWindow.printCounter();
		mainWindow.printButtons();
		mainWindow.getResponse();
		if (mainWindow.mouseKey())
		{
			mainWindow.defineMousePos();
			mainWindow.printPositionOfCursor();
			
			mainWindow.buttonHit()
			? mainWindow.printHit()
			:
				mainWindow.withinWindow()
				? mainWindow.printMessage("Within!")
				: mainWindow.printMessage("Out!");
		}
		else if (mainWindow.isEscape())
			break ;
		mainWindow.refreshWindow();
	}
	return 0;
}
