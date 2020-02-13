/*
 * 	File:little_boi.ino
 * 	Authors: Daniel Castle & Spencer Mason
 * 	Description: 
 * 		Implementation of button pusing robot for SouthEastCon 2020
 */

// Arduino servo library
#include <Servo.h>

// pi10000.h: header file containing 100000 digits of Pi
// taken from official SouthEastCon2020 repo
#include "pi10000.h"

const enum START = 0;
const enum PUSH_TO_WALL = 1;
const enum EXECUTE = 2;

Servo myServo;
int degrees = 0; // TODO: figure out angle/degrees value for servo

unsigned long time;
int index = 0;
int currentState = START;
bool masterSwitch;


void setup() {
	
	initPins(); // initialize pins 1 through 10
	
	// initialize pin 11 as input for master switch
	pinMode(11, INPUT);

	// initialize pin 12 and 'attach' to servo
	myServo.attach(12);

}

void loop() {
	// read input from pin 11 each loop to wait for master switch turning on
	masterSwitch = digitalRead(11);
	
	// keep track of time running using millis() function
	time = millis();
	
	
	if(time < 180000) {
		
		switch(currentState) {
			
			
			// START: wait for masterSwitch to turn on then goto PUSH_TO_WALL
			case START:
				{if( masterSwitch = true) {currentState = PUSH_TO_WALL;} }
			break;
			
			
			// PUSH_TO_WALL: launch solenoid on pin 10, which will tip the bot
			case PUSH_TO_WALL:
				{
					pushSolenoid(10);
					delay(1000);
					pullSolenoid(10);
					extendServo();
					currentState = EXECUTE;
				}
			break;
			
			
			// EXECUTE: execute push button logic
			case EXECUTE:
				{
					pushSolenoid(getPiDigit(index));
					holdSolenoid();
					pullSolenoid(getPiDigit(index));
					index++;
				}
			break;
			
			
		}
	}
	
}


/*
 * 	pushSolenoid:
 * 		Sends a LOW signal to a power MOSFET which allows current to
 * 		flow to solenoid which powers the 'pushing' mechanism.
 */
void pushSolenoid(int pin) {
	digitalWrite(pin, LOW);
}


/*
 * 	pullSolenoid:
 * 		Sends a HIGH signal to a power MOSFET which prevents current
 * 		from flowing to solenoid which retracts the 'pushing' mechanism.
 */
void pullSolenoid(int pin) {
	digitalWrite(pin, HIGH);
}


/*
 * 	holdSolenoid:
 * 		Causes a 30ms delay to allow for the recieveing buttons to 
 * 		debounce properly.
 */
void holdSolenoid() {
	delay(30); // 30 input = 30ms
}


/*
 *	extendServo:
 *		Makes servo rotate to specified degree value in order
 *		to extend the button array.
 *		[TODO: find proper degree value for this to work]
 *
 */
void extendServo() {
	myServo.write(degrees); // tell servo to turn according to degrees value
	delay(3000); // wait for 3 seconds, 3000 input = 3s
}


/*
 * 	initPins:
 * 		Initializes all digital pins on UNO using
 * 		a simple for loop. Can be changed later depending
 * 		on pin usage or transition to MEGA board.
 * 		(Pin 13 is not enabled due to issues with LED connetion.)
 * 		(See 'NOTE' here: https://www.arduino.cc/en/Tutorial/DigitalPins)
 * 		[Pin 11 will be used as input for master switch, so it is not 
 * 		initialized here.]
 */
void initPins() {
  // iterate through 0 to 10
  for (int i = 0; i <= 10; i++)
  {
    pinMode(i, OUTPUT);
  }
}

  
/*
 *  getPiDigit:
 *    Takes in an index as a integer and returns the
 *    corresponding Pi digit as an integer.
 * 
 *    This function will fetch the Pi digit from
 *    the pi100000.h file provided by SouthEastCon.
 *    
 */ 
int getPiDigit(int index) {
	/* read byte at the address of pi + index 
	*(address of pi means starting address of pi char array)
	* the "- '0' " part casts this to an integer
	* taken from SouthEastCon implementation 
	*/
	return pgm_read_byte_near(pi + index) - '0';
}
