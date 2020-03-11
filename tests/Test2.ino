#include "pi10000.h"
#include <Servo.h>

int index = 0;
int masterSwitch;

Servo myServo;

void initPins() {
  // iterate through 0 to 10
  for (int i = 1; i <= 10; i++)
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
  digitalWrite(getPiDigit(index), HIGH);
  delay(30);
  digitalWrite(getPiDigit(index), LOW);
  delay(30);
  index++;

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

}

void setup() {
  // put your setup code here, to run once:
  initPins(); // initialize pins 1 through 10
  myServo.attach(12);

  // initialize pin 11 as input for master switch
  pinMode(11, INPUT);
  startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(11) == LOW) {
     PowerGOGO();
     Serial.println("This line is high");
    //ZaWarudo();
   

  }
  else {
    //PowerGOGO();
    Serial.println("This line is low");
    ZaWarudo();
  }
}
