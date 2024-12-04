#pragma once
#include <string>
#include <vector>
#include <map>

class MovieRating {
private:
	std::map<std::string, std::vector<int>> movies;
public:
	MovieRating();
	~MovieRating();
	void updateListFromFile(char* filename);
	void print();
};
