#include "../include/doodlebug.h"
#include "../include/ant.h"

Dood::Dood() : Organism() {}

Dood::Dood(struct position startPos) :
    Organism(3, 1, startPos, 2, 8, 'X') {}

Dood::~Dood() {}

void Dood::updateCycle() {
	canMove = true;
	hp--;

	if( breedCycle >= ageToBreed ){
		canBreed = true;
	} else {
		breedCycle++;
	}
}

bool Dood::getCanMove(Organism* bugs[SIZE][SIZE]) {
	if( canMove ) {
		if( bugs[findPos.y][findPos.x] == nullptr ){
			return true;
		} else if( canEat(bugs) ){
			hp = 3;
			return true;
		}
	}
	return false;
}

bool Dood::canEat(Organism* bugs[SIZE][SIZE]) {
	if( (bugs[findPos.y][findPos.x] != nullptr) && (bugs[findPos.y][findPos.x]->getBody() == 'o') ){
		return true;
	}
	return false;
}
