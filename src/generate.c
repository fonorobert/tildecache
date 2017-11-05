#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX_ROWS 30
#define MAX_COLS 30
#define true 1
#define false 0

struct Tile {
	char terrain;
	int blocked; //handled as bool
};

struct Col {
	struct Tile tiles[MAX_ROWS];
};

struct Map {
	struct Col cols[MAX_COLS];
};

typedef struct Tile Tile;
typedef struct Col Col;
typedef struct Map Map;

// trees, rocks, sand, mud, grass
char terrain[5] = {'t', 'r', 's', 'm', 'g'};

void Map_print (struct Map *map);
void Map_create (struct Map *map);
void die (Map *map, char *error);
int blockedcount(Map *map);

int main(int argc, char *argv[]) {
	srand(time(0));
	Map *map = malloc(sizeof(struct Map));

	Map_create(map);

	printf("number of tiles: %d map size (KiB): %d\n", MAX_COLS*MAX_ROWS, sizeof(Map)/1024);
	float blockedchance = (float)blockedcount(map)/(float)(MAX_COLS*MAX_ROWS)*(float)100;
	printf("blocked chance: %f\n", blockedchance);
//	Map_print(map);
//	int rowprint=rand()%MAX_ROWS;
//	int colprint=rand()%MAX_COLS;
//	printf("tile %dx%d terrain: %c\n", colprint, rowprint, map->cols[colprint].tiles[rowprint].terrain);
//	printf("%d\n", rand());

	die(map, "finished successfully");
	return 0;
}

void Map_create (struct Map *map) {
	int c = 0;
	int r = 0;
	int terrlength = sizeof(terrain)/sizeof(char);

	for(int i = 0; i < MAX_COLS; i++) {
		for(int j = 0; j < MAX_ROWS; j++) {
			int blocked = (rand() % 101);
			if(blocked > 75) {
				blocked = true;
			} else {
				blocked = false;
			}

			map->cols[i].tiles[j].terrain = terrain[rand() % terrlength];
			map->cols[i].tiles[j].blocked = blocked;
		}
	}


}

void Map_print (struct Map *map) {

	for(int i = 0; i < MAX_COLS; i++) {
		for(int j = 0; j < MAX_ROWS; j++) {
			Tile tile = map->cols[i].tiles[j];
			printf("col %d row %d terrain %c blocked %d\n", i, j, tile.terrain, tile.blocked);
		}
	}

}

int blockedcount (Map *map) {
	int blocked = 0;
	
	for(int i = 0; i < MAX_COLS; i++) {
		for(int j = 0; j < MAX_ROWS; j++) {
			if(map->cols[i].tiles[j].blocked == 1) {
				blocked++;
			}
		}
	}
	return blocked;
}

void die (Map *map, char *error) {
	free(map);
	printf("%s\n", error);
	exit(0);
}
