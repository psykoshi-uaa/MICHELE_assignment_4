#pragma once
#include "prisoner.h"

class LinkedList {
private:
	int total;
	Prisoner* head;
	Prisoner* tail;
	Prisoner* curPrisoner;

public:
	LinkedList();
	~LinkedList();
	int getTotal();
	void add(int p);
	void remove(int p);
	int getPlace(int p);
	void output();
	void outputCurPrisoner();
};
