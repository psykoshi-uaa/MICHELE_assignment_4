#pragma once
#include "settings.h"

class Organism {
protected:
	struct position curPos;
	struct position findPos;
	int hp;
	int color;
	int breedCycle, ageToBreed;
	char asciiBody;
	bool canMove, canBreed;

public:
	Organism();
	Organism(int hp, int bC, struct position startPos,
		int col, int atb, char body);
	~Organism();
	void drawSelf(int marginy, int marginx);
	struct position getCurPos();
	struct position getNewPos();
	char getBody();
	int getHp();
	int getBreedCycle();
	bool getCanBreed();
	void setHp(int newHp);
	void findNewSpace(int direction);
	void move();
	void hasBreeded();
	bool die();
	virtual bool getCanMove(Organism* bugs[SIZE][SIZE]);
	virtual void updateCycle();
	virtual bool canEat(Organism* bugs[SIZE][SIZE]);
};
