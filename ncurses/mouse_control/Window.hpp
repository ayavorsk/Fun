#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ncurses.h>
#define SPACE 32
#define ESCAPE 27

class Window
{
	public:
	
		Window(int rows, int columns);
		~Window();
		void getResponse();
		bool mouseKey();
		bool isSpace();
		bool isEscape();
		void refreshWindow();
		void printCounter();
		void printPositionOfCursor();
		void printSpace();

	private:
	
		WINDOW* _w;
		MEVENT _e;
		int _key;
		int _row;
		int _rows;
		int _counter;
};

#endif
