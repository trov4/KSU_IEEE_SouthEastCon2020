// includes
/**********************************************************************/


// struct definitions
/**********************************************************************/

// global variable definitions
/**********************************************************************/
enum stateMachine {next, moveToBin, pickUp, moveToEnd, plop} state;

struct location {
		int bottomLeftX;
		int bottomLeftY;
		int legosTaken;
		int binIndex;
		bool onTop;
	};
location one, two, three, four, five, six, seven, eight, nine, zero, end;

int pistonR, pistonL;

float currX, currY;		// best effor estimations
float percentX, percentY;		// set by diff function
// Piston Functions
/**********************************************************************/
void pushSolenoid(int pin) {
	digitalWrite(pin, LOW);
}

void pullSolenoid(int pin) {
	digitalWrite(pin, HIGH);
}

void grab() {
	pushSolenoid(pistonR);
	pushSolenoid(pistonL);
}

void yeet() {
	pushSolenoid(pistonR);
	pushSolenoid(pistonL);
}
// Low Level Motor Functions
/**********************************************************************/

// Higher Level Wheel Movement Functions -- including throttle
/**********************************************************************/
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

// Grabber Functions
/**********************************************************************/
void setup() {
	state = next;

}

void loop() {

	// major differences between moveToBin and moveToEnd is:
	// moveToBin moves in the X direction then Y direction
	// moveToEnd moves in the Y direction then X direction
	switch(state) {
		case moveToBin:
			percentDiff()
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
