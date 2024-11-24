#pragma once
#include "../include/organism.h"

class Ant : public Organism {
public:
	Ant();
	Ant(struct position startPos);
	~Ant();
};
