/*
  Drive.cpp - Library for handling vehicle speed, direction, and tracking.
  Created by Tyler H. Davison and ***** Spring semester, 2020
*/

#include "Arduino.h"
#include "Drive.h"

#define UNUSED -1


String travelState;

//The below two variables represent PWM vales that control the four 
//wheel motors. all four elements will have the same absolute value, 
//but will be either positive or negative, depending on the spin 
//direction for each wheel.
//(positive = forward, negative = backwards).
//[FRONT LEFT, FRONT RIGHT, BACK LEFT, BACK RIGHT]
int desiredMotorOutput[4];
int currentMotorOutput[4];

//The below variables represent the XY coordinates for when the robot
//is in a cubby. These values equal -1 whenever the robot isn't in a
//cuby. 
//[X, Y]
int cubbyPresentPos[2];
int cubbyNextPos[2];

//The below variables represent the robot's position with respect to the course's
//center path. The first element represents how many lines are between the robot 
//and button wall, while the second value represents the distance between the robot 
//and the closest line betwen the robot and the button wall.  
int linePresentPos[2];
int lineDesiredPos[2];

drive()
{
  desiredMotorOutput  = {0,0,0,0};
  currentMotorOutput  = {0,0,0,0};
  cubbyPresentPos     = {UNUSED,UNUSED};
  cubbyNextPos        = {UNUSED,UNUSED};
  linePresentPos      = {0, 6};//"Line" zero is the edge of the starting box that is
  //closest to the button wall.
  lineDesiredPos      = {0,0};
  travelState         = "Start";
}


void throttle(int presentLocation, int DesiredLocation)
{
//This function is designed to gradually increase the speed of the robot, allowing
//for the robot to have better handling. A logarythmic function will probably be used
//here
}


void PathNavigate(int _coordinate[3][2])
{
//This function will handle the movement of the robot while it is on the center path
}

void CubbyNavigate(int _coordinate[3][2])
{
//This function will handle the movement of the robot while it is in a cubby
}

void StartNavigate(int _coordinate[3][2])
{
  //Navigates the robot within the starting box
}

void ButtonNavigate()
{
  //navigates button boi along the button wall
}

void DoNavigate(int _coordinate[3][2])
{
  switch(travelState)
  {
    case "Start"
    StartNavigate(_coordinate);
    break;

    case "Path"
    PathNavigate(_coordinate);
    break;

    case "Cubby"
    CubbyNavigate(_coordinate);
    break;
  }
}
