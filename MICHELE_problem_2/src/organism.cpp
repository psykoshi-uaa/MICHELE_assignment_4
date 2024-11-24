#include <curses.h>
#include <iostream>
#include "../include/organism.h"

Organism::Organism() :
    hp(3), color(0), ageToBreed(0), breedCycle(1), asciiBody('b'), canMove(false),
    canBreed(false) {
	curPos = { 0 };
	findPos = { 0 };
}

Organism::Organism(int hp, int bC, struct position startPos, int col, int atb, char body) :
    hp(hp), color(col), ageToBreed(atb), breedCycle(bC), asciiBody(body),
    curPos(startPos), findPos(startPos), canMove(false), canBreed(false) {
}

void Organism::drawSelf(int marginy, int marginx) {
	attron(COLOR_PAIR(color));
	mvaddch(marginy + curPos.y, marginx + curPos.x, asciiBody);
	attroff(COLOR_PAIR(color));
}

Organism::~Organism() {}

struct position Organism::getCurPos() {
	return curPos;
}

struct position Organism::getNewPos() {
	return findPos;
}

char Organism::getBody() {
	return asciiBody;
}

int Organism::getHp() {
	return hp;
}

void Organism::setHp(int newHp) {
	hp = newHp;
}

bool Organism::getCanMove(Organism* bugs[SIZE][SIZE]) {
	if( (canMove) && (bugs[findPos.y][findPos.x] == nullptr) ){
		return true;
	}
	return false;
}

void Organism::move() {
	curPos = findPos;
	canMove = false;
}

int Organism::getBreedCycle() {
	return breedCycle;
}

bool Organism::getCanBreed() {
	return canBreed;
}

void Organism::hasBreeded() {
	breedCycle = 1;
	canBreed = false;
}

void Organism::updateCycle() {
	canMove = true;

	if( breedCycle >= ageToBreed ){
		canBreed = true;
	} else {
		breedCycle++;
	}
}

void Organism::findNewSpace(int direction) {
	switch (direction) {
		case 0:
			if( curPos.y > 0 )
				findPos = {curPos.y - 1, curPos.x};
			break;
		case 1:
			if( curPos.y < SIZE-1 )
				findPos = {curPos.y + 1, curPos.x};
			break;
		case 2:
			if( curPos.x > 0 )
				findPos = {curPos.y, curPos.x - 1};
			break;
		case 3:
			if( curPos.x < SIZE-1 )
				findPos = {curPos.y, curPos.x + 1};
			break;
		default: break;
	}
}

bool Organism::die(){
	if( hp < 0 ){
		return true;
	}
	return false;
}

bool Organism::canEat(Organism* bugs[SIZE][SIZE]) {
	return false;
}
