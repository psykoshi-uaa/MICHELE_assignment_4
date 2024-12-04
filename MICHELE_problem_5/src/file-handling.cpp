#include <stdio.h>
#include <iostream>
#include <string.h>
#include "../include/movierating.h"

void MovieRating::assignFromFile(char* filename){
	int lineNum=1;
	std::string curLine;

	std::ifstream file(filename);

	while( std::getline(file, curLine) ){
		if( lineNum == 1 ){
			numRatings = int(curLine + '0');
		} else if( lineNum % 2 == 0 ){
			if( std::find(movieNames.begin(), jmovieNames.end(), curLine) == movieNames.end() ){
				movieNames.pushBack(curLine);
				std::getline(file, curline);
				movieRatings.pushBack(int(curLine + '0'));

			} else {
				std::getline(file, curline);
			}

		}
		lineNum++;
	}

	file.close();

	printf("\n");
}
