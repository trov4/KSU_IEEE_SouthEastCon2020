/* Truth Table for Drivers
  PinA   PinB  PWM   Spin Direction
  L   H   >0    Counter ClockWise
  H   L   >0    ClockWise
*/
//////////////////////////////
float percentX = 0.2;
float percentY = 0.8;
//////////////////////////////

struct motor {
  int pinA;
  int pinB;
  int pwmPin;
} ;

void throttleX()
{


float scaledPWM;

//get the percentage of max PWM duty cycle
  scaledPWM = percentX * 255;

//FLOW//

//start of error check

  if(scaledPWM < 25){ //Check to set no less than 10% duty cycle, to not have robot slow when it gets 
      scaledPWM = 25;   //25 ~= 10% duty cycle
      move_backward(scaledPWM);  
  return;

  }else if(scaledPWM == 0){   //check for if robot is at desired location
    scaledPWM = 0;            //stop, 0% duty cycle
    allHalt();
    return;

  }else if (scaledPWM > 255){       //correct for greater than 100% duty cycle
    scaledPWM = 255;            //scaled PWM set to 100% duty cycle
    move_backward(scaledPWM);
  return;

  }else{  // all other conditions, with exception of error causing ones
    move_backward(scaledPWM);
  return;
} 
}

void throttleY()
{


float scaledPWM;

//get the percentage of max PWM duty cycle
  scaledPWM = percentY * 255;

//FLOW//

//start of error check

  if(scaledPWM < 25){ //Check to set no less than 10% duty cycle, to not have robot slow when it gets 
    scaledPWM = 25;   //25 ~= 10% duty cycle
    move_left(scaledPWM);
  return;

  }else if(scaledPWM == 0){   //check for if robot is at desired location
    scaledPWM = 0;            //stop, 0% duty cycle
    allHalt();
    return;

  }else if (scaledPWM > 255){       //correct for greater than 100% duty cycle
    scaledPWM = 255;            //scaled PWM set to 100% duty cycle
    move_left(scaledPWM);
  return;

  }else{  // all other conditions, with exception of error causing ones
    move_left(scaledPWM);
  return;
} 
}

motor frontR, backR, frontL, backL;

void motor_clockwise(motor target, uint8_t scaledPWM) {
  digitalWrite(target.pinA, HIGH);
  digitalWrite(target.pinB, LOW);
  analogWrite(target.pwmPin, scaledPWM);  // for now just full speed
}

void motor_cclockwise(motor target,uint8_t scaledPWM) {
  digitalWrite(target.pinA, LOW);
  digitalWrite(target.pinB, HIGH);
  analogWrite(target.pwmPin, scaledPWM);  // for now just full speed
}

void halt(motor target) {
  analogWrite(target.pwmPin, 0); // should stop if no PWM
}

void allHalt() {
  halt(frontR);
  halt(backR);
  halt(frontL);
  halt(backL);
}

void pin_init(motor target) {
  pinMode(target.pinA, OUTPUT);
  pinMode(target.pinB, OUTPUT);
  pinMode(target.pwmPin, OUTPUT);
}

/*
   pins taken:
   2,3,4,5
   14, 15, 16, 17, 18, 19, 20, 21
*/

void wait_micros (int time) {
  delay(time/1000);
  //long startTime = micros();
  //while (micros() - startTime < time);
}


// High level functions
/****************************************************************************************/
// see diagram in "Mecanum Wheel Diagram" page in one note for wheel directions
void move_forward(uint8_t scaledPWM) {
  motor_clockwise(frontR, scaledPWM);
  motor_clockwise(backR, scaledPWM);
  motor_cclockwise(frontL, scaledPWM);
  motor_cclockwise(backL, scaledPWM);
  }

void move_backward(uint8_t scaledPWM) {
  motor_cclockwise(frontR, scaledPWM);
  motor_cclockwise(backR, scaledPWM);
  motor_clockwise(frontL, scaledPWM);
  motor_clockwise(backL, scaledPWM);
}

void move_right(uint8_t scaledPWM) {
  motor_clockwise(frontR, scaledPWM);
  motor_cclockwise(backR, scaledPWM);
  motor_cclockwise(frontL, scaledPWM);
  motor_clockwise(backL, scaledPWM);
}

void move_left(uint8_t scaledPWM) {
  motor_cclockwise(frontR, scaledPWM);
  motor_clockwise(backR, scaledPWM);
  motor_clockwise(frontL, scaledPWM);
  motor_cclockwise(backL, scaledPWM);
}

void setup() {
  // setup each motor struct
  frontR.pwmPin = 2;
  backR.pwmPin = 3;
  frontL.pwmPin = 4;
  backL.pwmPin = 5;

  frontR.pinA = 14;
  frontR.pinB = 15;

  backR.pinA = 16;
  backR.pinB = 17;

  frontL.pinA = 18;
  frontL.pinB = 19;

  backL.pinA = 20;
  backL.pinB = 21;

  pin_init(frontR);
  pin_init(backR);
  pin_init(frontL);
  pin_init(backL);
}
void loop() {
  // loop through each for 5 seconds each
  throttleX();
  throttleY();
}