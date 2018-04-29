#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ncurses.h>
#include <string>
#include <map>

#define SPACE 32
#define ESCAPE 27
#define NB_OF_BUTTONS 3
enum {A, B, C };

struct Point{
	int y;
	int x;
};

class Window
{
	public:
	
		Window(int rows, int columns);
		~Window();
		void getResponse();
		bool mouseKey();
		bool isEscape() const;
		void refreshWindow();
		void printCounter() const;
		void printPositionOfCursor() const;
		void defineMousePos();
		bool withinWindow() const;
		bool buttonHit();
		void printHit();
		void printMessage(std::string str) const;
		void createButtons(int nbOfButtons);
		void printButtons();

	private:
	
		WINDOW* _w;
		MEVENT _e;
		int _key;
		int _row;
		int _rows;
		int _columns;
		int _counter;
		Point _mousePos;
		int _nbOfButtons;
		std::map<int, Point> _buttons;
};

#endif
