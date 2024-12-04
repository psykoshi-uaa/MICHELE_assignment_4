#pragma once
#include <string>
#include <vector>
#include <map>

class MovieRating {
private:
	vector<std::string> movieNames;
	vector<int> movieRatings;
	map<int, std::string> movies;
public:
	void printFromFile(char* filename);
}
