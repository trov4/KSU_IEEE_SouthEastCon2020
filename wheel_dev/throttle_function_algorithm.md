======================================================
==============Throttle Function Algorithm=============
======================================================


##### NEED 4 PINS DECLARED IN SETUP LOOP FOR MOTORS IF USING ANALOG WRITE ####


******declarations and pre-logic arithmatic*********   
0.0  	int presentLocation and int Desired location are taken in                               //assumed as arrays for x,y coordinate
  0.1	Declare int array diffLocation for distance between two location
  0.2	Declare float array diffLocationPercent for percentage distance calculations
  0.3	Declare int array scaledPWM for percentage scaled PWN for motors
1.0	diffLocation equal to DesiredLocation - presentLocation                                //direction taken care of by pos or negative in this var
  1.1 	diffLocationPercent equal to diffLocation divide desiredLocation + present location    //transfer diffLocation to percentage difference
  1.2	scaledPWM equal to abs(diffLocationPercent multiply 255)                               //0-255 is the PWM strength, so we scale it based on distnace from target

=======Logic Flow=========
2.0.0	loop through arrays to look for  if-else conditions
2.1.0	if scaledPWM less than 25 && greater than -25              //minimum speed, so it doesn't go too slow when it closes distance
  2.1.0.1	   scaledPWM equal 25	  			   //10% duty cycle
  2.1.0.2	   analogWrite(PWM MOTOR PIN HERE, scaledPWM) x4   //write the pwm signal to each motor pin     ***MIGHT CHANGE TO DESIRED MOTOR OUTPUT ARRAY***
  2.1.0.3    return
2.1.1	else if desiredLocation == presentLocation                 //set PWM to 0% duty cycle to cut power to motor
  2.1.1.1    scaledPWM equal 0                                     //0% == off	
  2.1.1.2    analogWrite(PWM MOTOR PIN HERE, scaledPWM) x4         //PWM signal off for each motor 		***MIGHT CHANGE TO DESIRED MOTOR OUTPUT ARRAY***
  2.1.1.3    return
2.1.2	else if scaled PWM > 255 || PWM < -255			   //PWM is greater than 100% duty cycle
  2.1.2.1    scaledPWM equal to 255
  2.1.2.2    analogWrite(PWM MOTOR PIN HERE, scaledPWM) x4							***MIGHT CHANGE TO DESIRED MOTOR OUTPUT ARRAY***
2.1.3	else
  2.1.3.1    analogWrite(PWM MOTOR PIN HERE, scaledPWM) x4							***MIGHT CHANGE TO DESIRED MOTOR OUTPUT ARRAY*** 