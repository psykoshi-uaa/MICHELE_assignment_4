#pragma once
#include <random>
#include "organism.h"
#include "settings.h"

const char EMPTY_SPACE_CHAR = ' ';

class World {
private:
	std::mt19937 RNGine;
	Organism* bugs[SIZE][SIZE];
	int bugCtr, maxBugs;
	char exitKey;
	char storedKey;
	void Init();
	char lowercase(char); 
	int getRand(int min, int max);
	
public:
	World(std::mt19937::result_type seed);
	World(std::mt19937::result_type seed, char exitKey);
	~World();
	void setStoredKey(char c);
	char getStoredKey();
	bool shouldExit();
	void printWorld(int marginy, int marginx);
	void createBugs(int numAnts, int numDoods);
	void createAnt(struct position startPos);
	void createDood(struct position startPos);
	void updateBugs(char bugType);
	void moveBugs(char bugType);
	void drawBugs(int marginy, int marginx);
};
