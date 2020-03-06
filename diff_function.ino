//#include <iostream>
#include <stdlib.h>
// location of lego is equal to a number 

//GOAL: Link the location of the bin between robot
//Subgoal: Obtain location of robot
//Problem: I need to find the current location of the robot, bottom left corner is 0,0.
// At the start of run program, the robot will move to the starting square at 15, 24.
//I need to mark the locations of each line, and use the last known line location to determine robot location 

// Will use the bin class to create and assign each bin an x and y coordinate, in addition to the number of legos inside
struct bin1 {
  int bottomLeftX = 25;
  int bottomLeftY = 40;
  int legosTaken;
};
// Under the assumption we initialize important areas like lines, start, and end as structures with x and y coordinates 
// We can pass this into the diff function to obtain current x and y position coordinates
struct currentLoc
{
  int currentPosX;
  int currentPosY;

};

/*void diff(int legoX, int legoY, int currentX, int currentY)
{
  int nextLegoXLoc = 0;
  int nextLegoYLoc = 0;
  if legoX > currentX{
  nextLegoXLoc = legoX - currentX;
  }
  else
  {
  nextLegoXLoc = currentX - legoX;
  }
  if legoY > currentY{
  nextLegoYLoc = legoY- currentY;
  }
  else
  {
  nextLegoYLoc = currentY - legoY;
  }

  drive_x(nextLegoYLoc);
  drive_y(nextLegoYLoc);
}*/

/*//void start
{
startposx = 15;
startposy = 24;
}
*/
//hypothetical situation: Robot is at start, and needs to go to bin 1

void diff2(bin,currentLoc) {
  // I am getting the location of the bin that I need to go to
  int distanceAwayY = bin::bottomLeftY;
  int distanceAwayX = bin::bottomLeftX;
  // Create a line or square structure and obtain its x and y integer values
  int currentX = currentLoc::currentPosX;
  int currentY = currentLoc::currentPosY;
// this will check the lowerY value passed in, and will 
  int distanceDiffY = distanceAwayY - currentY;
  int distanceDiffX = distanceAwayX - currentX;


}
// there will be a class array variable monitoring the number of each lego left in the bins, assigning each bin an index
//hardware questions, can the robot tell the difference between x and y?
//when digit received, get lego numbers left in bin, 
