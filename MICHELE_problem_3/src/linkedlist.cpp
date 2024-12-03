#include <iostream>
#include "../include/prisoner.h"
#include "../include/linkedlist.h"

LinkedList::LinkedList()
	: total(0), head(nullptr), tail(nullptr), curPrisoner(nullptr) {
}
LinkedList::~LinkedList() {
/*
	Prisoner* temp;
	while (head != nullptr) {
		temp = head;
		head = head->getNext();
		delete temp;
	}
*/
}

int LinkedList::getTotal() {
	return total;
}

void LinkedList::add(int p) {
	Prisoner* temp = new Prisoner(p, head);
	if( tail == nullptr ){
		tail = temp;
		curPrisoner = temp;
	}
	head = temp;
	tail->setNext(head);
	total++;
}

void LinkedList::remove(int p) {
	Prisoner* temp = curPrisoner->getNext();
	Prisoner* prev = curPrisoner;
	int i=1;
	
	while( true ){
		if( i == p){
			if( temp == head ){
				head = head->getNext();
				tail->setNext(head->getNext());
			} else if( temp == tail ){
				prev->setNext(temp->getNext());
				tail = prev;
			} else {
				prev->setNext(temp->getNext());
			}
			curPrisoner = prev;
			delete temp;
			temp = nullptr;
			total--;
			break;
		}

		prev = temp;
		temp = temp->getNext();
		i++;
	}
}

void LinkedList::output() {
	Prisoner* temp = head;
	for( int i=0; i<total; i++ ){
		std::cout << temp->getPlace();
		temp = temp->getNext();
	}
}
