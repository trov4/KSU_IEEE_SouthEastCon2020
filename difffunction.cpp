	#include "iostream"
	#include "stdlib.h"


// IMPORTANT: SYNTAX MAY BE FUCKY, IMPLEMENT AT YOUR OWN RISK
	// location of lego is equal to a number 
	//GOAL: Link the location of the bin between robot
	//Subgoal: Obtain location of robot
	//Problem: I need to find the current location of the robot, bottom left corner is 0,0.
	// At the start of run program, the robot will move to the starting square at 15, 24.
	//I need to mark the locations of each line, and use the last known line location to determine robot location 

	// Will use the bin class to create and assign each bin an x and y coordinate, in addition to the number of legos inside
// Under the assumption we initialize important areas like lines, start, and end as structures with x and y coordinates 
	// We can pass this into the diff function to obtain current x and y position coordinates
	struct location {
		int bottomLeftX;
		int bottomLeftY;
		int legosTaken;
		int binIndex;
		bool onTop;
		bool bin;
	};
	// Under the assumption we initialize important areas like lines, start, and end as structures with x and y coordinates 
	// We can pass this into the diff function to obtain current x and y position coordinates
	
	
// The global float variables percentDiffX and percentDiffY 
	void diff2(areaD) {
		// I am getting the location of the bin that I need to go to
		int distanceAwayY = areaD.bottomLeftY;
		int distanceAwayX = areaD.bottomLeftX;
		//int binDex = bin::binIndex;
		int diffdistanceX = 0;
		int diffdistanceY = 0;
		bool topRow = areaD.onTop;
		// Create a line or square structure and obtain its x and y integer values
		int currentX = currX;
		int currentY = currY;
		int legosLeft = areaD:legosTaken;
		//Do target coordinates minus current coordinates to find difference
		

		// diffdistanceY = distanceAwayY - currentY;
		// diffdistanceX = distanceAwayX - currentX;
		// if (bin != true)
		// 	{
		// 		diffdistanceY = distanceAwayY - currentY;
		// 		diffdistanceX = distanceAwayX - currentX;
		// 		diffY = diffdistanceY;
		// 		diffX = diffdistanceX;
		// 	}
		else if (currentX >areaD.bottomLeftX)
		{
			diffdistanceX = (currentX - distanceAwayX) * -1;
				if(legosLeft == 4 || legosLeft == 2)
			{
				diffdistanceX +=1;
			}
			else
			{
				diffdistanceX+=5;
			}
		}
		else
		{
			diffdistanceX = distanceAwayX - currentX;
				if(legosLeft == 4 || legosLeft == 2)
			{
				diffdistanceX +=1;
			}
			else
			{
				diffdistanceX+=5;
			}

		}
		//set global variable diffx = diffdistancex;
		if (areaD.bottomLeftY == 12)
		{
			distanceDiffY = -12;
			if(legosLeft == 4 || legosLeft == 3)
			{
				distanceDiffY -= 1;
			}
			else
			{
				distanceDiffY -= 6;
			}
			//percentDiffX = diffidistanceX/2;
			//percentDiffY = diffdistanceY/2;
			//diffY = diffdistanceY;
			//diffX = diffdistanceX;
		}
		//set global variable diffy = diffdistancey;

		/*// diff for x
		if (areaD.legosTaken %2 = 0) {
			diffDistanceX += 1;
		} else {
			diffDistanceX += 5;
		}

		//diff for y
		if (legosLeft< 2) {
			diffDistanceY +=  areaD.onTop? 12 : -12;
		} else {
			diffDistanceY += areaD.onTop? 17 : -17;
		}*/



	}
	
void percent_difference(location target) {
	// handle end location
	int endX = target.bottomLeftX;
	int endY = target.bottomLeftY;
	if(target.bin) {
		// X the same for Top and Bottom
		if (target.legosTaken%2==0) endX += 2;
		else endX += 7;

		// hand Y -- different for Top and Bottom
		// assuming that no more than 4 being taken
		if (target.onTop) {
			 if (target.legosTaken>2) endY += 2;
		} else {
			if (target.legosTaken<3) endY += 12;
			else endY += 10;
		}
	}

	// diffs
	int deltaX = endX - currX;
	int deltaY = endY - currY;

	// averages
	int xBar = (endX + currX)/2;
	int yBar = (endY + currY)/2;

	// set global variables 
	percentX = deltaX/xBar;
	percentY = deltaY/yBar;
}