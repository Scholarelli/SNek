#include <iostream>
#include <ncurses.h>

#include "controls.h"
#include "GameWindow.h"
#include "WindowManager.h"
#include "Menu/MainMenu.h"
#include "Menu/PauseMenu.h"

int main() {
	auto windowmanager = new WindowManager(0, 0);
	windowmanager->initialize();
	windowmanager->run();
	// initscr();
	// raw();
	// noecho();
	// //nodelay(stdscr, TRUE);
	// timeout(1000000);
	// keypad(stdscr, TRUE);
	//
	// start_color();
	// init_pair(1, COLOR_GREEN, COLOR_GREEN);
	// init_pair(2, COLOR_RED, COLOR_BLACK);
	// curs_set(0);
	//
	// int max_x, max_y;
	// getmaxyx(stdscr, max_y, max_x);
	//
	// // auto window = new GameWindow(max_x, max_y);
	// //
	// // window->spawn();
	// // int current_x = 0;
	// // int current_y = 0;
	//
	// auto menu = new MainMenu(0, 7, 30, 10);
	// menu->initializeWindow(stdscr);
	// menu->render(menu->winPointer);
	//
	//
	//
	// while (true) {
	// 	const controls input = get_user_input();
	// 	if (input == QUIT)
	// 		break;
	// 	menu->handleInput(input);
	// 	//
	// 	// if (input == QUIT) {
	// 	// 	break;
	// 	// }
	// 	// if (input == MOVE_LEFT && current_x > 0) {
	// 	// 	current_x--;
	// 	// }
	// 	// if (input == MOVE_RIGHT && current_x < max_x - 1) {
	// 	// 	current_x++;
	// 	// }
	// 	// if (input == MOVE_DOWN && current_y < max_y - 1) {
	// 	// 	current_y++;
	// 	// }
	// 	// if (input == MOVE_UP && current_y > 0) {
	// 	// 	current_y--;
	// 	// }
	// 	//
	// 	// window->setTile(current_x, current_y);
	// 	//
	// 	// window->draw();
	// 	// window->render(stdscr);
	// 	menu->render(menu->winPointer);
	// 	refresh();
	// }
	//
	endwin();
	return 0;
}
