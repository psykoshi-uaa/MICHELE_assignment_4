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
	tail->setNext(head);
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
	Prisoner* temp = head;
	Prisoner* prev = nullptr;
	int place = p % getTotal();
	if( place == 0 ){
		place = getTotal();
	}
	
	while( temp != nullptr ){
		if( temp->getCurPlace() == place){
			if( prev == nullptr || prev == tail ){
				head = head->getNext();
			} else {
				prev->setNext(temp->getNext());
			}
			delete temp;
			temp = nullptr;
			break;
		}
		prev = temp;

		if( prev == tail ){
			temp = head;
		} else {
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
