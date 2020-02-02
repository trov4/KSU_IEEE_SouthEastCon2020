Little boi

This folder contains the class for the robot little boi. Little boi will be pressing buttons in order of pie.

Little boi inherits the wheel class.

___________________________________________________________________________________________________________________
Merge into Master on 2/2/2020:

Design for Button boi has changed so the robot tips instead of moves
	- There are 11 solenoid pistons being driven by the arduino
		- 1 solenoid to tip the robot
		- 10 solenoids to press 10 different digits
	- The bot tips, leans against the outside, then extends two arms with 5 pistons on each arm
	- Then loops through pi and presses a each button, holds for 30 ms, pulls the piston back, waits 30 ms

TODO:
- Make servo design to extend arms
