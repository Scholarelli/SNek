#include <iostream>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

#include "controls.h"
#include "GameWindow.h"
#include "WindowManager.h"
#include "Menu/MainMenu.h"
#include "Menu/PauseMenu.h"

int main() {
	auto windowmanager = new WindowManager(0, 0);
	std::srand(std::time(nullptr));
	windowmanager->initialize();
	windowmanager->run();


	endwin();
	return 0;
}
