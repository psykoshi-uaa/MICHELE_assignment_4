#include <iostream>
#include <fstream>
#include <string>
#include "../include/movierating.h"

MovieRating::MovieRating() {}

MovieRating::~MovieRating() {}

void MovieRating::updateListFromFile(char* filename) {
	std::string curLine;

	std::ifstream file(filename);

	while( std::getline(file, curLine) ){
		std::string movieName = curLine;
		std::getline(file, curLine);
		int rating = std::stoi(curLine);
		movies[movieName].push_back(rating);
	}

	file.close();
}

void MovieRating::print() {
	for( const auto &l : movies ){
		int total=0;
		int num=0;

		for( auto m : l.second ){
			total += m;
			num++;
		}
		std::cout << l.first << ": " << total/num << "\n";
	}
}
