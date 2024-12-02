#include <iostream>
#include "include/prisoner.h"
#include "include/linkedlist.h"
#include "include/file-handling.h"

int main(){
	int numPrisoners = 12;
	int numWordsInRhyme = 4;
	char userInp;

	LinkedList deathRow;
	for( int i=numPrisoners; i>0; i-- ){
		deathRow.add(i);
	}
	
	std::cout << "Would you like to skip the intro? [y/N]" << std::endl;
	std::cin >> userInp;
	std::cin.ignore();
	
	if( userInp != 'y' ){
		char file_intro[] = "textblocks/intro";
		printFromFile(file_intro);
		char file_comp_intro[] = "textblocks/computer-intro";
		printFromFile(file_comp_intro);
	}

	int prisonerTracker = deathRow.getTotal();
	/*
	while( prisonerTracker >= 1 ){
		deathRow.remove(numWordsInRhyme);
		prisonerTracker--;
	}
	*/
	deathRow.remove(2);

	deathRow.outputInitialPlaces();

	return 0;
}
