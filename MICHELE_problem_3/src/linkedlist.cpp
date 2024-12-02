#include <iostream>
#include "../include/prisoner.h"
#include "../include/linkedlist.h"

LinkedList::LinkedList()
	: head(nullptr), tail(nullptr) {}
LinkedList::~LinkedList() {
	Prisoner* temp;
	while (head != nullptr) {
		temp = head;
		head = head->getNext();
		delete temp;
	}
}

int LinkedList::getTotal() {
	int counter = 0;
	Prisoner* temp = head;

	while( temp != nullptr ){
		counter++;
		temp = temp->getNext();
	}
	return counter;
}

void LinkedList::add(int p) {
	Prisoner* temp = new Prisoner(p, head);
	head = temp;
}

void LinkedList::remove(int p) {
	int place;
	Prisoner* temp = head;
	Prisoner* prev = nullptr;
	if( p % getTotal() == 0 ){
		place = getTotal();
	} else {
		place = p % getTotal();
	}
	
	while( temp != nullptr ){
		if( temp->getCurPlace() == place ){
			Prisoner* next = temp->getNext();
			if( prev == nullptr ){
				head = head->getNext();
			} else {
				prev->setNext(temp->getNext());
			}
			delete temp;
			temp = next;
			//temp->setPlace(temp->getCurPlace() - 1);
		} else if( temp->getCurPlace() > place ){
			temp->setPlace(temp->getCurPlace() - 1);
		}
		
		if( temp != nullptr ){
			prev = temp;
			temp = temp->getNext();
		}
	}
}

void LinkedList::outputCurPlaces() {
	Prisoner* temp = head;
	while( temp != nullptr ){
		std::cout << temp->getCurPlace() << std::endl;
		temp = temp->getNext();
	}
	std::cout << std::endl;
}

void LinkedList::outputInitialPlaces() {
	Prisoner* temp = head;
	while( temp != nullptr ){
		std::cout << temp->getInitialPlace() << std::endl;
		temp = temp->getNext();
	}
	std::cout << std::endl;
}
