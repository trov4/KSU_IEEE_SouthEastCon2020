

// pi10000.h: header file containing 100000 digits of Pi
// taken from official SouthEastCon2020 repo
#include "pi10000.h"

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  int maxIndex = 4;
  
  Serial.println("Print digits of Pi from index 0 to maxIndex-1:\n");
  for (int i = 0; i < maxIndex; i++)  {
    Serial.print(getPiDigit(i));
  }

  

}

void loop() {
  // put your main code here, to run repeatedly:

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
