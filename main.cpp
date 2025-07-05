#include <iostream>
#include <ncurses.h>

#include "controls.h"
#include "GameWindow.h"


int main() {
	int max_x, max_y;

	GameWindow::initialize();
	getmaxyx(stdscr, max_y, max_x);

	auto window = new GameWindow(max_x, max_y);

	window->spawn();
	int current_x = 0;
	int current_y = 0;
	while (true) {
		const controls input = get_user_input();

		if (input == QUIT) {
			break;
		}
		if (input == MOVE_LEFT && current_x > 0) {
			current_x--;
		}
		if (input == MOVE_RIGHT && current_x < max_x - 1) {
			current_x++;
		}
		if (input == MOVE_DOWN && current_y < max_y - 1) {
			current_y++;
		}
		if (input == MOVE_UP && current_y > 0) {
			current_y--;
		}

		window->setTile(current_x, current_y);

		window->draw();
		window->render(stdscr);


		refresh();
	}

	endwin();
	return 0;
}
