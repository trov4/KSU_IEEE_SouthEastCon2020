void throttle(int presentLocation[], int DesiredLocation[])
{

//2 arrays for location difference and the scaled PWM signal for sending out
int diffLocation[2];
int scaledPWM[2];

//float array in order to multiply by 255 to get a section of max PWM duty cycle
float diffLocationPercent[2];

//OPERATIONS//

//get the difference in location for the x and the y
for(int i = 0; i < 2; i++){
  diffLocation[i] = DesiredLocation[i] - presentLocation[i];
}

//convert location differnece to decimal percent difference for use in arithamtic
for(int i = 0; i < 2; i++){
  diffLocationPercent[i] = diffLocation[i]/(DesiredLocation[i]+presentLocation[i]);
}

//get the percentage of max PWM duty cycle
for(int i = 0; i < 2; i++){
  scaledPWM[i] = diffLocationPercent[i] * 255;
}


//FLOW//

//cycle through array
for(int i = 0; i < 2; i++){

//start of error check

  if(scaledPWM[i] < 25){	//Check to set no less than 10% duty cycle, to not have robot slow when it gets 				//close
    scaledPWM[i] = 25;		//25 ~= 10% duty cycle

    //write PWM duty cycle to each pin, STILL NEED PIN #
    for(int p = 0; p < 3; p++){
      analogWrite(PIN MOTOR, scaledPWM[i]);
    };

    return;

  }else if( DesiredLocation[i] == presentLocation[i]){		//check for if robot is at desired location

    scaledPWM[i] = 0;						//stop, 0% duty cycle

    //write PWM duty cycle to each pin, STILL NEED PIN #
    for(int p = 0; p < 3; p++){
      analogWrite(PIN MOTOR, scaledPWM[i]);
    };
    
    return;

  }else if (scaledPWM[i] > 255){				//correct for greater than 100% duty cycle
    
    scaledPWM[i] = 255;						//scaled PWM set to 100% duty cycle

    //write PWM duty cycle to each pin, STILL NEED PIN #
    for(int p = 0; p < 3; p++){
      analogWrite(PIN MOTOR, scaledPWM[i]);
    };
    return;

  }else{	// all other conditions, with exception of error causing ones

    //write PWM duty cycle to each pin, STILL NEED PIN #
    for(int p = 0; p < 3; p++){
      analogWrite(PIN MOTOR, scaledPWM[i]);
    };
    return;
} 
}
