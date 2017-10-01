#include <stdio.h>
#include <stdlib.h>

void die(char *msg) {
	printf("Error: %s\n", msg);
	exit(1);
}

int main(int argc, char *argv[]) {
	if(argc != 5) { 
		die("Expecting exactly 4 arguments!"); 
	}
	// args: playerX, playerY, cacheX, cacheY
	int player[2] = {atoi(argv[1]), atoi(argv[2])};
	int cache[2] = {atoi(argv[3]), atoi(argv[4])};

	if (player[0] == cache[0] && player[1] == cache[1]) {
		printf("here\n");
		return 0;
	}
	if (player[1] < cache[1]) {
		printf("S");
	} else if (player[1] > cache[1]) {
		printf("N");
	}

	if (player[0] < cache[0]) {
		printf("E");
	} else if (player[0] > cache[0]) {
		printf("W");
	}
	printf("\n");
	return 0;
}
