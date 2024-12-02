#pragma once
class Prisoner {
private:
	int place;
	Prisoner* next;

public:
	Prisoner();
	Prisoner(int place, Prisoner* next);
	int getPlace();
	Prisoner* getNext();
	void setPlace(int p);
	void setNext(Prisoner* n);
};
