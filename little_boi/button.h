#ifndef _BUTTON_H
#define _BUTTON_H
/*
 * File: button.h
 * Authors: Daniel Castle & Spencer Mason
 * Description: top level header file for button
 * 				function declarations
 */


// keep previous Pi digit for distance calculations
int previousPiDigit;
// store current Pi digit for distance calcuations
int currentPiDigit;


/*
 * getX & getY:
 * 		These functions take in the previous and
 * 		current Pi digits and returns a X or Y
 * 		coordinate for the robot to move to.
 * 		
 * 		The coordinates will be internally calculated
 * 		by the functions based on predefined measurements
 * 		taken from the SouthEastCon rules/resources.
 */ 
int getX(int priorPiDigit, int currentPiDigit);
int getY(int priorPiDigit, int currentPiDigit);


/*
 *	getPiDigit:
 * 		Takes in an index as a integer and returns the
 * 		corresponding Pi digit as an integer.
 * 
 * 		This function will fetch the Pi digit from
 * 		the pi100000.h file provided by SouthEastCon.
 * 		This value is a char, so the function will cast
 * 		it to an integer and return it. 
 */
int getPiDigit(int index);


#endif
