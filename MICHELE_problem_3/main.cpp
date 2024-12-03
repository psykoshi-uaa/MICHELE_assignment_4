#include <iostream>
#include "include/prisoner.h"
#include "include/linkedlist.h"
#include "include/file-handling.h"

int main(){
	int numPrisoners = 234;
	int numWordsInRhyme = 9432;
	char userInp;

	LinkedList deathRow;
	for( int i=numPrisoners; i>0; i-- ){
		deathRow.add(i);
	}
	

	std::cout << "Would you like to skip the intro [y/N]? ";
	std::cin >> userInp;
	std::cin.ignore();
	
	if( userInp != 'y' ){
		char file_intro[] = "textblocks/intro";
		printFromFile(file_intro);
		char file_comp_intro[] = "textblocks/computer-intro";
		printFromFile(file_comp_intro);
	}

	while( deathRow.getTotal() > 1 ){
		deathRow.remove(numWordsInRhyme);
	}

	std::cout << "STH: ah, there will be " << numPrisoners << " prisoners on the ole' chopping block and" << std::endl
		<< "the rhyme will have... " << numWordsInRhyme << " words... The executioner must be" << std::endl
		<< "paid by the hour." << std::endl;
	std::cout << "STH: stand in spot number: ";
	deathRow.output();
	std::cout << ".";

	return 0;
}
