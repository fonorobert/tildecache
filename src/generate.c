#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define true 1
#define false 0

int cacheset = false; // var to track if we have a cache yet

struct Tile {
	struct Tile *neighbour[4];
	int terrain;
	int blocked; //handled as bool
	int cache; //handled as bool
};


struct Row {
	int width;
	struct Tile tiles[MAX_COLUMNS];
};

struct Map {
	int width;
	int height;
	struct Row rows[MAX_ROWS];
};

void Map_create (struct Map *map) {
	int r = 0;
	int c = 0;

	for(r = 0; r<MAX_ROWS; r++) {
		//new row
		struct Row row = { .width = MAX_COLUMNS};

		for(c = 0; c<MAX_COLUMNS;c++) {
			//new tile in row
			int terrain = rand() % 5;
			int blocked = rand() % 2;
			int cache = rand() % 2;

			if(cache) {

				if(cacheset == true) {
					cache = true;
				} else {
					cache = true;
					cacheset = true;
				} 
			} else if(c == MAX_COLUMNS-1 && r == MAX_ROWS && cacheset == false) {
				cache = true;
				cacheset = true;
			}

			struct Tile tile = { .terrain = terrain, .blocked = blocked, .cache = cache, };

			row.tiles[c] = tile;
		}

		map->rows[r] = row;

	}
}

int main(int argc, char *argv[]) {
	srand(time(0));
	struct Map *map = malloc(sizeof(struct Map));

	Map_create(map);

	int rowprint=rand()%MAX_ROWS;
	int colprint=rand()%MAX_COLUMNS;
	printf("tile %dx%d terrain: %d\n", rowprint, colprint, map->rows[rowprint].tiles[colprint].terrain);
	printf("%d\n", rand());

	free(map);
	return 0;
}
