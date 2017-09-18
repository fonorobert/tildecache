#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int player[2] = {atoi(argv[1]), atoi(argv[2])};
	int cache[2] = {atoi(argv[3]), atoi(argv[4])};

	if (player[1] < cache[1]) {
		printf("S");
	} else {
		printf("N");
	}

	if (player[0] < cache[0]) {
		printf("E\n");
	} else {
		printf("W\n");
	}
	return 0;
}
