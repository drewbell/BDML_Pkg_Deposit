#include <Servo.h>
#include <stdio.h>
#include <ctype.h>

#define servoPin 3
#define CAPTURE_MODE 180
#define RELEASE_MODE 0

Servo servo;

char serialMessage;

void setup() {
  Serial.begin(57600);    //begin serial 
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.write("Welcome to BDML Package Deposit.");
  Serial.println("");
  Serial.write("Please command (C)apture or (R)elease.");
  Serial.println("");
}

void loop()
{
  if (Serial.available())
  {    
      serialMessage = tolower(Serial.read());  
      if(serialMessage == 'c' ){
        servo.write(CAPTURE_MODE);
        Serial.write(serialMessage);
        Serial.write(" | Entering Capture Mode.");
        Serial.println("");
     }
     else if(serialMessage == 'r'){
        servo.write(RELEASE_MODE);
        Serial.write(serialMessage);
        Serial.write(" | Entering Release Mode.");
        Serial.println("");
     }
     else{
      Serial.write("Please command (C)apture or (R)elease.");
      Serial.println("");
     }
  }
}


