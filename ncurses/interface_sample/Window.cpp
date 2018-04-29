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
	_columns = columns;
	_counter = 0;
	_key = 0;
	_mousePos.y = 0;
	_mousePos.x = 0;
	_nbOfButtons = 0;
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

bool Window::isEscape() const{
	return _key == ESCAPE;
}

void Window::refreshWindow(){
	wrefresh(_w);
}

void Window::printCounter() const{
	wattron(_w, A_BOLD);
	mvwprintw(_w, 1, 1, "Cycle %i        ", _counter);
	wattroff(_w, A_BOLD);
}

void Window::printPositionOfCursor() const{
	mvwprintw(_w, _row, 1, "%i/%i        ", _mousePos.y, _mousePos.x);
}

void Window::defineMousePos(){
	_mousePos.y = _e.y;
	_mousePos.x = _e.x;
}

bool Window::withinWindow() const{
	return _mousePos.y < _rows && _mousePos.x < _columns;
}

bool Window::buttonHit(){
	for (int i = 0; i < _nbOfButtons; i++){
		if (_buttons[i].y == _mousePos.y && _buttons[i].x == _mousePos.x)
			return true;
	}
	return false;
}

void Window::printMessage(std::string str) const{
	wattron(_w, A_BOLD);
	mvwprintw(_w, 3, 1, "%-7.7s", str.c_str());
	wattroff(_w, A_BOLD);
}

void Window::printHit(){
	wattron(_w, A_BOLD);
	for (int i = 0; i < _nbOfButtons; i++){
		if (_buttons[i].y == _mousePos.y && _buttons[i].x == _mousePos.x)
		{
			std::string str(1, static_cast<char>('A' + i));
			printMessage(str);
			break ;
		}
	}
	wattroff(_w, A_BOLD);
}

void Window::createButtons(int nbOfButtons){
	_nbOfButtons = nbOfButtons;
	for (int i = 0; i < _nbOfButtons; i++){
		Point p;
		p.y = i + 5;
		p.x = 5;
		_buttons[i] = p;
	}
}

void Window::printButtons(){
	for (int i = 0; i < _nbOfButtons; i++){
		mvwprintw(_w, _buttons[i].y, _buttons[i].x, "%c", 'A' + i);
	}
}
