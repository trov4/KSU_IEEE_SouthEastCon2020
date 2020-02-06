
#include <stdio.h>
// each hash is 1"x4" -- this assumes every coordinate in the array is .5"
// assumes the bottom left corner is passed in

void buttons(double start_x, double start_y, int arenaMap[48][96])
{
  for(int x = start_x; x < start_x+(2); x++)
  {
    for(int y = start_y; y < start_y+(2.4); y++)
    {
      arenaMap[x][y] = 5;
    }
  }
}

void cubbyBoundary(double start_x, double start_y, int arenaMap[48][96]){
  for (int x = start_x; x < start_x+(10); x++)
  {
    for(int y = start_y; y < start_y+(10); y++)
    {
      arenaMap[x][y] = 0;
    }
  }
}
void endBox(double start_x, double start_y, int arenaMap[48][96])
{
  for(int x = start_x; x < start_x+(5); x++)
  {
    for(int y = start_y; y < start_y+(5); y++)
    {
      arenaMap[x][y] = 4;
    }
    
  }
}


void fill_center(double start_x, double start_y, int arenaMap[48][96]) {
  // startx + 65" is the end of the row
  for (int x = start_x; x < start_x+(65*2); x++) {
    // starty + 1" is the height of the line
    for (int y = start_y; y < start_y+(2);) {
      // this assumes the # 2 represents the center line
      arenaMap[x][y] = 2;
    }
  }
}

void fill_hash(double start_x, double start_y, int arenaMap[48][96]) {
  // start x + 1" is the end of the hash
  for (int x = start_x; x < start_x+2; x++) {
    // starty + 4" is the end of the hash
    for (int y = start_y; y < start_y+8; y++) {
      // this assumes the # 3 represents hashes
      arenaMap[x][y] = 3;
    }
  }
}

void startBox(double start_x, double start_y, int arenaMap[48][96]){
  //startBox is going to be 0,0
  for(int x = start_x; x < start_x+(24); x++)
  {
    for(int y = start_y; y < start_y+(24);)
    {
      arenaMap[x][y] = 0;
    }
  }
}


int main()
{
  int arenaMap[48][96];
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

return arenaMap;
}
    
