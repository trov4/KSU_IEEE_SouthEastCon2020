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
	
// Let's create a global boolean variable called insideBin, which will be checked in diff function
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
		/*
		if (insideBin == true)
		{
			if (currentY < 24)
			{
				diffdistanceY = 24 - currentY;
			}
			else
			{
				diffdistanceY = (currentY - 24) * -1;
			}
			diffY = diffdistanceY;

			diffdistanceX = 89-currentX;
			diffX = diffdistanceX
		}

		*/
	// this will check the lowerY value passed in, and will 
	//	int distanceDiffY = distanceAwayY - currentY;
		//int distanceDiffX = distanceAwayX - currentX;
		if (currentX >areaD.bottomLeftX)
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
			//diffX = diffdistanceX;

		}
		//set global variable diffx = diffdistancex;
		if (areaD.bottomLeftY == 12)
		{
			topRow= false;
			distanceDiffY = -12;
			if(legosLeft == 4 || legosLeft == 3)
			{
				distanceDiffY -= 1;
			}
			else
			{
				distanceDiffY -= 6;
			}
			//diffY = diffdistanceY;
			//insideBin = true;

		}
		//set global variable diffy = diffdistancey;

		// diff for x
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
		}

	}
	//Needs an insert class variables assignment 
	// there will be a class array variable monitoring the number of each lego left in the bins, assigning each bin an index
	//hardware questions, can the robot tell the difference between x and y?
	//when digit received, get lego numbers left in bin, 
