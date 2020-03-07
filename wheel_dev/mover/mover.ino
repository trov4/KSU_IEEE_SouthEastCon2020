/* Truth Table for Drivers
  PinA   PinB  PWM   Spin Direction
  L   H   >0    Counter ClockWise
  H   L   >0    ClockWise
*/

struct motor {
  int pinA;
  int pinB;
  int pwmPin;
} ;

motor frontR, backR, frontL, backL;

void motor_clockwise(motor target) {
  digitalWrite(target.pinA, HIGH);
  digitalWrite(target.pinB, LOW);
  analogWrite(target.pwmPin, 255);  // for now just full speed
}

void motor_cclockwise(motor target) {
  digitalWrite(target.pinA, LOW);
  digitalWrite(target.pinB, HIGH);
  analogWrite(target.pwmPin, 255);  // for now just full speed
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


// see diagram in "Mecanum Wheel Diagram" page in one note for wheel directions
void move_forward(int time) {
  motor_clockwise(frontR);
  motor_clockwise(backR);
  motor_cclockwise(frontL);
  motor_cclockwise(backL);

  wait_micros(time);
  
  allHalt();
}

void move_backward(int time) {
  motor_cclockwise(frontR);
  motor_cclockwise(backR);
  motor_clockwise(frontL);
  motor_clockwise(backL);

  wait_micros(time);

  allHalt();
}

void move_right(int time) {
  motor_clockwise(frontR);
  motor_cclockwise(backR);
  motor_cclockwise(frontL);
  motor_clockwise(backL);
  wait_micros(time);

  allHalt();
}

void move_left(int time) {
  motor_cclockwise(frontR);
  motor_clockwise(backR);
  motor_clockwise(frontL);
  motor_cclockwise(backL);
  wait_micros(time);

  allHalt();
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
  move_forward(5000);
  move_backward(5000);
  move_left(5000);
  move_right(5000);
}
