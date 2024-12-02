#include "../include/prisoner.h"

Prisoner::Prisoner() : initialPlace(0), curPlace(0), next(nullptr) {}

Prisoner::Prisoner(int place, Prisoner* next) :
	initialPlace(place), curPlace(place), next(next) {}

int Prisoner::getCurPlace() {
	return curPlace;
}

int Prisoner::getInitialPlace() {
	return initialPlace;
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
