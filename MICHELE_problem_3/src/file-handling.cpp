#include <stdio.h>
#include <iostream>
#include <string.h>
#include "../include/file-handling.h"
void printFromFile(char* filename){
	std::string curLine;
	std::ifstream file(filename);
	while( std::getline(file, curLine) ){
		if( curLine == "NEXT" ){
			std::cout << "[press enter to continue]" << std::endl;
			std::cin.ignore();
		} else {
			printf("%s\n", curLine.c_str());
		}
	}
	file.close();
	printf("\n");
}
