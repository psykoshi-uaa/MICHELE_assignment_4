#include "../include/ant.h"

Ant::Ant() : Organism() {}

Ant::Ant(struct position startPos) :
    Organism(3, 1, startPos, 1, 3, 'o') {}

Ant::~Ant() {}
