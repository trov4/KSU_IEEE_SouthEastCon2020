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

void motor_clockwise(motor target, uint8_t pwm) {
  digitalWrite(target.pinA, HIGH);
  digitalWrite(target.pinB, LOW);
  analogWrite(target.pwmPin, pwm);  // for now just full speed
}

void motor_cclockwise(motor target, uint8_t pwm) {
  digitalWrite(target.pinA, LOW);
  digitalWrite(target.pinB, HIGH);
  analogWrite(target.pwmPin, pwm);  // for now just full speed
}

void halt(motor target) {
  digitalWrite(target.pinA, LOW);
  digitalWrite(target.pinB, HIGH);
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


// see diagram in "Mecanum Wheel Diagram" page in one note for wheel directions
void move_right(uint8_t pwm) {
  motor_clockwise(frontR, pwm);
  motor_clockwise(backR, pwm);
  motor_cclockwise(frontL, pwm);
  motor_cclockwise(backL, pwm);
}

void move_left(uint8_t pwm) {
  motor_cclockwise(frontR, pwm);
  motor_cclockwise(backR, pwm);
  motor_clockwise(frontL, pwm);
  motor_clockwise(backL, pwm);
}

void move_up(uint8_t pwm) {
  motor_clockwise(frontR, pwm);
  motor_cclockwise(backR, pwm);
  motor_cclockwise(frontL, pwm);
  motor_clockwise(backL, pwm);
}

void move_down(uint8_t pwm) {
  motor_cclockwise(frontR, pwm);
  motor_clockwise(backR, pwm);
  motor_clockwise(frontL, pwm);
  motor_cclockwise(backL, pwm);
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
