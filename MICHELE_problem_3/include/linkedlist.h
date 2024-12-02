#pragma once
#include "prisoner.h"

class LinkedList {
private:
	Prisoner* head;
	Prisoner* tail;

public:
	LinkedList();
	~LinkedList();
	void add(int p);
	void remove(int p);
	void output();
};
