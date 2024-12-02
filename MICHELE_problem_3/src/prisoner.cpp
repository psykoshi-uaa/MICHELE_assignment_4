#include "../include/prisoner.h"

Prisoner::Prisoner() : place(0), next(nullptr) {}
Prisoner::Prisoner(int place, Prisoner* next) :
	place(place), next(next) {}

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
