#include <iostream>
#include "include/prisoner.h"
#include "include/linkedlist.h"

int main(){
	LinkedList deathRow;

	for( int i=0; i<12; i++ ){
		deathRow.add(i);
	}

	return 0;
}
