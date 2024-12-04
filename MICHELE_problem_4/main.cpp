#include <stdio.h>
#include "src/checkedarray.cpp"

int main() {
	CheckedArray<int> intArr(4);

	printf("\nCreated an int array of size 4");
	
	printf("\n\n\nTrying to access array index 3: ");
	try {
		printf("\n%i", intArr[3]);
	} catch (std::runtime_error& ArrayOutOfBounds) {
		printf("\n%s", ArrayOutOfBounds.what());
	}
	
	printf("\n\nTrying to access array index 6: ");
	try {
		printf("\n%i\n\n", intArr[6]);
	} catch (std::runtime_error& ArrayOutOfBounds) {
		printf("\n%s\n\n", ArrayOutOfBounds.what());
	}

	printf("\n");
}
