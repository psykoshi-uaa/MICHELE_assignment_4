#include <curses.h>
#include <random>

#include "include/world.h"
#include "include/organism.h"
#include "include/ant.h"
#include "include/doodlebug.h"

int main() {
	initscr();
	curs_set(0);
	cbreak();
	noecho();
	int winh, winw;
	getmaxyx(stdscr, winh, winw);
	int marginy=winh/2 - SIZE/2;
	int marginx=winw/2 - SIZE/2;

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);

	std::random_device rd;
	std::mt19937 RNGine(rd());
	unsigned int seed = RNGine();

	World* world;
	world = new World(seed, 'q');
	world->createBugs(100, 5);
	world->updateBugs('X');
	world->updateBugs('o');
	
	while( !world->shouldExit() ){
		refresh();
		
		world->printWorld(marginy, marginx);
		world->drawBugs(marginy, marginx);
		world->moveBugs('X');
		world->updateBugs('X');
		world->moveBugs('o');
		world->updateBugs('o');
		world->setStoredKey(getch());
	}

	delete world;
	endwin();
	return 0;
}
