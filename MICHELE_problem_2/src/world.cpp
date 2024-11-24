#include <curses.h>
#include <iostream>
#include <random>

#include "../include/world.h"
#include "../include/organism.h"
#include "../include/ant.h"
#include "../include/doodlebug.h"

World::World(std::mt19937::result_type seed) :
    RNGine(seed), exitKey('q'), storedKey(' '),
    bugCtr(0), maxBugs(SIZE*SIZE) {
	Init();
}

World::World(std::mt19937::result_type seed, char exitKey) :
    RNGine(seed), exitKey(exitKey), storedKey(' '),
    bugCtr(0), maxBugs(SIZE*SIZE) {
	Init();
}

World::~World(){
	for( int y=0; y<SIZE; y++ ){
		for( int x=0; x<SIZE; x++ ){
			if( bugs[y][x] != nullptr ){
				delete bugs[y][x];
				bugs[y][x] = nullptr;
			}
		}
	}
}

void World::Init(){
	for( int x=0; x<SIZE; x++ ){
		for( int y=0; y<SIZE; y++ ){
			bugs[y][x] = nullptr;
		}
	}
}

char World::lowercase(char c){
	if( (int(c) >= 65) && (int(c) <= 90) ){
		return char(int(c) + 32);
	}
	return c;
}

int World::getRand(int min, int max){
	std::uniform_int_distribution<int> rand(min, max);
	return rand(RNGine);
}

void World::setStoredKey(char c){
	storedKey = c;
}

char World::getStoredKey(){
	return storedKey;
}

bool World::shouldExit(){
	if( lowercase(storedKey) == 'q' ){
		return true;
	}
	return false;
}

void World::printWorld(int marginy, int marginx){
	for( int y=0; y<SIZE; y++ ){
		for( int x=0; x<SIZE; x++ ){
			attron(COLOR_PAIR(3));
			mvaddch(marginy + y, marginx + x, ' ');
			attroff(COLOR_PAIR(3));
		}
	}
}

void World::createBugs(int numAnts, int numDoods){
	int antsCreated=0, doodsCreated=0;

	while( antsCreated + doodsCreated < numAnts + numDoods ){
		if( bugCtr >= maxBugs ){
			break; 
		}

		int y = getRand(1, SIZE - 2);
		int x = getRand(1, SIZE - 2);

		if( bugs[y][x] != nullptr ){
			continue;
		} else {
			struct position startPos = { y, x };
			if( antsCreated < numAnts ){
				bugs[y][x] = new Ant(startPos);
				antsCreated++;
				bugCtr++;
			} else if ( doodsCreated < numDoods ){
				bugs[y][x] = new Dood(startPos);
				doodsCreated++;
				bugCtr++;
			}
		}
	}
}

void World::createAnt(struct position startPos){
	if( bugCtr < maxBugs ){
		bugs[startPos.y][startPos.x] = new Ant(startPos);
		bugCtr++;
	}
}

void World::createDood(struct position startPos){
	if( bugCtr < maxBugs ){
		bugs[startPos.y][startPos.x] = new Dood(startPos);
		bugCtr++;
	}
}

void World::updateBugs(char bugType){
	for( int y=0; y<SIZE; y++ ){
		for( int x=0; x<SIZE; x++ ){
			Organism* curBug = bugs[y][x];

			if( (curBug != nullptr) && (curBug->getBody() == bugType) ){
				curBug->updateCycle();

				if( bugs[y][x]->die() ){
					delete bugs[y][x];
					bugs[y][x] = nullptr;
					bugCtr--;
					break;
				}

				for( int i=0; i<4; i++ ){
					curBug->findNewSpace(i);
					if( (bugs[curBug->getNewPos().y][curBug->getNewPos().x] == nullptr) &&
					    (curBug->getCanBreed() == true) &&
					    (bugCtr < maxBugs) ){
						if( bugType == 'o' ){
							createAnt(curBug->getNewPos());
						} else if( bugType == 'X' ){
							createDood(curBug->getNewPos());
						} else {
							break;
						}

						curBug->hasBreeded();
						break;
					}
				}
			}
		}
	}
}

void World::moveBugs(char bugType){ 
	for( int y=0; y<SIZE; y++ ){
		for( int x=0; x<SIZE; x++ ){
			if( bugs[y][x] != nullptr ){
				Organism* curBug = bugs[y][x];

				curBug->findNewSpace(getRand(0, 3));

				if( (curBug->getCanMove(bugs)) &&
				    (curBug->getBody() == bugType) ){
					if( bugs[y][x]->canEat(bugs) ){
						delete bugs[curBug->getNewPos().y][curBug->getNewPos().x];
						bugCtr--;
					}
					bugs[curBug->getNewPos().y][curBug->getNewPos().x] = curBug;
					bugs[y][x]->move();
					bugs[y][x] = nullptr;
				}
			}
		}
	}
}

void World::drawBugs(int marginy, int marginx){
	for( int y=0; y<SIZE; y++ ){
		for( int x=0; x<SIZE; x++ ){
			if( bugs[y][x] != nullptr ){
				bugs[y][x]->drawSelf(marginy, marginx);
			}
		}
	}
}
