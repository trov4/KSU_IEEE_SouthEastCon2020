/*
    File: GrabAndGo.ino
    Noah Trinite
    Description: Takes that heckin block and stacks that shit (but right now just grabs and releases)
*/

//If casing is a bother then I can just replace it.

struct motor {
  int pinA;
  int pinB;
  int pwmPin;
} ;

//motors in charge of lifting the block
motor left, right;

/*stolen from mover.ino because it's just motors
  but can still change it if need be
  just might as well use it if it works */
//Moves motor clockwise
void MotorCW(motor target) {
  digitalWrite(target.pinA, HIGH); //input 1 high
  digitalWrite(target.pinB, LOW);  //input 2 low
  analogWrite(target.pwmPin, 255);  // ZOOOOOM
}

/*stolen from mover.ino because it's just motors
  but can still change it if need be
  just might as well use it if it works */
//moves motor counter clockwise
void MotorCCW(motor target) {
  digitalWrite(target.pinA, LOW); //input 1 low
  digitalWrite(target.pinB, HIGH); //input 2 high
  analogWrite(target.pwmPin, 255);  // ZOOOOOM
}

void PleaseStop(motor target) {
  analogWrite(target.pwmPin, 0); //should stop
}

//is that a JoJo's reference? (stops all motors)
void ZaWarudo() {
  PleaseStop(left);
  PleaseStop(right);
}

//Goes up, For now it's time based
void GoingUp(int wait) {
  MotorCCW(left);
  MotorCW(right);

  delay(wait); //waits (in milliseconds)
  ZaWarudo();

}

//Goes down, for now it's time based
void DownSheGoes(int wait) {
  MotorCCW(right);
  MotorCW(left);

  delay(wait); //waits (in n/1000 seconds)
  ZaWarudo();
}

//unsure how many pins the solenoid requires/how they actually work so
void Grab(int pin) {
  digitalWrite(pin, LOW);
}

void Release(int pin) {
  digitalWrite(pin, HIGH);
}

void YEET() {
  Grab(26);
  MotorCCW(left);
  MotorCW(right);
  delay(300);
  Release(26);
}

//Also stolen from mover.ino because it should work
void PinInit(motor target) {
  pinMode(target.pinA, OUTPUT);
  pinMode(target.pinB, OUTPUT);
  pinMode(target.pwmPin, OUTPUT);
}


//stealing pins: Analog 6, 7 Digital: 22, 23, 24, 25, 26

//global variables
 int solenoid = 26;

void setup() {
  // put your setup code here, to run once:
  left.pwmPin = 6;
  right.pwmPin = 7;

  left.pinA = 22;
  left.pinB = 23;

  right.pinA = 24;
  right.pinB = 25;

  PinInit(left);
  PinInit(right);

  pinMode(solenoid, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Grab(solenoid);
  GoingUp(2000);
  DownSheGoes(2000);
  Release(solenoid);
  delay(5000); //waits 5 seconds
  YEET(); //Hopefully yeets the block but I can't test it now

}
