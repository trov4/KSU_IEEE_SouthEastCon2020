// includes
/**********************************************************************/

// struct definitions
/**********************************************************************/

// global variable definitions
/**********************************************************************/
enum stateMachine {moveToBin, pickUp, moveToEnd, plop} state;

float currX, currY;		// best effor estimations
float diffX, diffY;		// set by diff function
// Piston Functions
/**********************************************************************/

// Low Level Motor Functions
/**********************************************************************/

// Higher Level Wheel Movement Functions -- including throttle
/**********************************************************************/

// Grabber Functions
/**********************************************************************/
void setup() {
	state = moveToBin;

}

void loop() {

	// major differences between moveToBin and moveToEnd is:
	// moveToBin moves in the X direction then Y direction
	// moveToEnd moves in the Y direction then X direction
	switch(state) {
		case moveToBin:
			// perform Bin Movement
			state = pickUp;
			break;
		case pickUp:
			// Pick dat boi up
			state = moveToEnd;
			break;
		case moveToEnd: 
			// perform movement to end
			state = plop;
			break;
		case plop:
			// plop
			state = moveToBin;
			break;
	}
}
