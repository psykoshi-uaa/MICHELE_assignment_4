#pragma once
class Prisoner {
private:
	int place;
	Prisoner* next, headPtr, tailPtr;

public:
	Prisoner();
	Prisoner(int place);
	int getPlace();
	Prisoner* getNext();
	void setPlace(int p);
	void setNext(Prisoner* n);
	void add(int p);
	void remove(int p);
};
