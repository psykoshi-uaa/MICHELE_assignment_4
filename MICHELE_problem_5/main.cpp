#include "include/movierating.h"

int main() {
	MovieRating movies;
	char filename[] = "textfile/movies";
	movies.updateListFromFile(filename);
	movies.print();
	return 0;
}
