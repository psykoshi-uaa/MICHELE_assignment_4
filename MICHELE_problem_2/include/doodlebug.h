#pragma once
#include "../include/organism.h"

class Dood : public Organism {
private:
	int maxAge;
public:
	Dood();
	Dood(struct position startPos);
	~Dood();
	void findNewSpace(Organism* bugs[SIZE][SIZE], int direction);
	bool getCanMove(Organism* bugs[SIZE][SIZE]);
	void updateCycle();
	
	bool canEat(Organism* bugs[SIZE][SIZE]);
};
