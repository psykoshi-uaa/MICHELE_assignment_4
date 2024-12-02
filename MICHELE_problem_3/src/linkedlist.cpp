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

void LinkedList::add(int p) {
	Prisoner* temp = new Prisoner(p, head);
	head = temp;
}

void LinkedList::remove(int p) {
	Prisoner* temp = head;
	Prisoner* prev = nullptr;
	while( temp != nullptr ){
		if( temp->getPlace() == p ){
			if( prev == nullptr ){
				head = head->getNext();
			} else {
				prev->setNext(temp->getNext());
			}
			delete temp;
			break;
		}
	}
	prev = temp;
	temp = temp->getNext();
}

void LinkedList::output() {
	Prisoner* temp = head;
	while( temp != nullptr ){
		std::cout << temp->getPlace() << std::endl;
		temp = temp->getNext();
	}
	std::cout << std::endl;
}
