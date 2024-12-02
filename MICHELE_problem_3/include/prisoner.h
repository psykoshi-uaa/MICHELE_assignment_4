#pragma once
class Prisoner {
private:
	int initialPlace, curPlace;
	Prisoner* next;

public:
	Prisoner();
	Prisoner(int place, Prisoner* next);
	int getCurPlace();
	int getInitialPlace();
	Prisoner* getNext();
	void setPlace(int p);
	void setNext(Prisoner* n);
};
