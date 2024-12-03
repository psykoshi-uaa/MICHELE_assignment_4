#include "../include/prisoner.h"

Prisoner::Prisoner() : curPlace(0), next(nullptr) {}

Prisoner::Prisoner(int place, Prisoner* next) :
	curPlace(place), next(next) {}

int Prisoner::getPlace() {
	return curPlace;
}

Prisoner* Prisoner::getNext() {
	return next;
}

void Prisoner::setPlace(int p) {
	curPlace = p;
}

void Prisoner::setNext(Prisoner* n) {
	next = n;
}
