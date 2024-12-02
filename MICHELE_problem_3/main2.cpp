#include <iostream>
#include "include/prisoner.h"
#include "include/file-handling.h"

int main(){
	char file_intro[] = "textblocks/intro";

	printFromFile(file_intro);
	
	Prisoner deathrowInmates;

	for( int i=0; i<12; i++ ){
		deathrowInates.add(i);
	}

	return 0;
}
