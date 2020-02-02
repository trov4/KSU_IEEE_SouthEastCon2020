#include "iostream"
#include "stdlib.h"
// each hash is 1"x4" -- this assumes every coordinate in the array is .5"
// assumes the bottom left corner is passed in
void fill_hash(double start_x, double start_y, int &map[][]) {
	// start x + 1" is the end of the hash
	for (int x = start_x; x < start_x+2; x++) {
		// starty + 4" is the end of the hash
		for (int y = start_y; y < start_y+8; y++) {
			// this assumes the # 3 represents hashes
			map[x][y] = 3;
		}
	}
}

// center line is 1"x 65"
void fill_center(double start_x, double start_y, int &map[][]) {
	// startx + 65" is the end of the row
	for (int x = start_x; x < start_x+(65*2); x++) {
		// starty + 1" is the height of the line
		for (int y = start_y; y < start_y+(2)) {
			// this assumes the # 2 represents the center line
			map[x][y] = 2;
		}
	}
}
// ce
void cubbyBoundary(double start_x, double start_y, int @map[][]){
	for (int x = start_x; x < start_x+(10); x++)
	{
		for(int y = start_y; y < start_y+(10))
		{
			map[x][y] = 0;
		}
	}
}

void startBox(double start_x, double start_y, int @map[][]){
	//startBox is going to be 0,0
	for(int x = start_x; x < start_x+(24); x++)
	{
		for(int y = start_y; y < start_y+(24))
		{
			map[x][y] = 0;
		}
	}
}
void buttons(double start_x, double start_y, int @map[][])
{
	for(int x = start_x; x < start_x+(2); x++)
	{
		for(int y = start_y; y < start_y+(2.4))
		{
			map[x][y] = 5;
		}
	}
}
void endBox(double start_x, double start_y, int @map[][])
{
	for(int x = start_x; x < start_x+(5); x++)
	{
		for(int y + start_y; y < start_y+(5))
		{
			map[x][y] = 4;
		}
		
	}
}

void printf(@map[][]);

void main(int argc, char const *argv[])
{
	int arenaMap[][];
	fill_center(2,25,arenaMap);
	startBox(0,25,arenaMap);
	endBox(88,25,arenaMap);
	for(int i = 10; i <= 100;)
	{
		fill_hash(i,25,arenaMap);
		i+=10;
	}
	for(int j = 10; j <= 50;)
	{
		cubbyBoundary(j,0,arenaMap);
		j+=10;
	}
	for(int k = 10; k <= 50;)
	{
		cubbyBoundary(k,50,arenaMap);
		k+=10;
	}
	for(int l = 18; l<=78;)
	{
		buttons(0,l,arenaMap);
		l+=6;
	}
printf(arenaMap);


}
		

