#include "pi10000.h"
#include <Servo.h>

int index = 0;
bool onSwitch;

Servo myServo;

void initPins() {
  // iterate through 0 to 10
  for (int i = 0; i <= 12; i++)
  {
    pinMode(i, OUTPUT);
  }
}

int getPiDigit(int index) {
  /* read byte at the address of pi + index
    (address of pi means starting address of pi char array)
    the "- '0' " part casts this to an integer
    taken from SouthEastCon implementation
  */
  return pgm_read_byte_near(pi + index) - '0';
}

void PowerGOGO() {
  digitalWrite(getPiDigit(index)+2, HIGH);
  delay(30);
  digitalWrite(getPiDigit(index)+2, LOW);
  delay(30);

  index++;

 /* for(int i =2; i<12; i++){
    digitalWrite(i, HIGH);
    delay(3000);
    digitalWrite(i, LOW);
    delay(3000);
  }*/

}

void ZaWarudo() {
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  //digitalWrite(12, LOW);

}

void setup() {
  // put your setup code here, to run once:
  initPins(); // initialize pins 1 through 10
  //myServo.attach(12);

  // initialize pin 11 as input for master switch
  //pinMode(13, INPUT);
  //startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(12) == HIGH) {
    onSwitch = true;
    //ZaWarudo();
  }
  else {
    //PowerGOGO();
    Serial.println("This line is low");
    onSwitch =false;
    ZaWarudo();
  }

  while(onSwitch){
    PowerGOGO();
  }
}
