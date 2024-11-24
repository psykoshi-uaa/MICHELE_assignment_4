#include "../include/prisoner.h"

Prisoner::Prisoner() : place(0), next(nullptr), headPtr(nullptr), tailPtr(nullptr) {}
Prisoner::Prisoner(int place) :
place(place), next(nullptr), headPtr(nullptr), tailPtr(nullptr) {}

int Prisoner::getPlace() {
	return place;
}

Prisoner* Prisoner::getNext() {
	return next;
}

void Prisoner::setPlace(int p) {
	place = p;
}

void Prisoner::setNext(Prisoner* n) {
	next = n;
}

void add(int p) {
	
}

void remove(int p) {}
