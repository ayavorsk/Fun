#include "Window.hpp"

Window::Window(int rows, int columns){
	initscr();
	_w = newwin(rows, columns, 0, 0);
	curs_set(0);
	keypad(_w, TRUE);
	nodelay(_w, FALSE);
	box(_w, 0, 0);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	_row = 2;
	_rows = rows;
	_counter = 0;
	_key = 0;
}

Window::~Window(){
	delwin(_w);
	endwin();
}

void Window::getResponse() {
	_counter++;
	_key = wgetch(_w);
}

bool Window::mouseKey(){
	return (_key == KEY_MOUSE && _key == getmouse(&_e) == OK);
}

bool Window::isSpace(){
	return _key == SPACE;
}

bool Window::isEscape(){
	return _key == ESCAPE;
}

void Window::refreshWindow(){
	wrefresh(_w);
}

void Window::printCounter(){
	wattron(_w, A_BOLD);
	mvwprintw(_w, 1, 1, "Cycle %i        ", _counter);
	wattroff(_w, A_BOLD);
}

void Window::printPositionOfCursor(){
	mvwprintw(_w, _row, 1, "%i/%i        ", _e.y, _e.x);
	_row = (_row < _rows - 2) ? _row + 1 : 2;
}

void Window::printSpace(){
	mvwprintw(_w, _row, 1, "Space is hit ");
	_row = (_row < _rows - 2) ? _row + 1 : 2;
}
