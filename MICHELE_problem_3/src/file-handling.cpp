#include <iostream>
#include <string.h>
#include "../include/file-handling.h"

void printFromFile(char* filename){
	std::string curLine;

	std::ifstream file(filename);

	while( std::getline(file, curLine) ){
		std::cout << curLine;
	}

	file.close();

	std::cout << std::endl;
}
