/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  myservo.write(10);
} 

unsigned char c;

void loop() 
{ 
  
  if(Serial.available() > 0){
    c = Serial.read();
    }

  if(c == 'a'){
      Serial.println("kanan");                             // in steps of 1 degree 
      myservo.write(30);              // tell servo to go to position in variable 'pos' 
//      delay(1);
//      c = 's';
  }
  if(c == 's'){
      Serial.println("kiri");                             // in steps of 1 degree 
      myservo.write(50);   
  }
  if(c == 'd'){                 
      myservo.write(70);              // tell servo to go to position in variable 'pos' 
      Serial.println("depan");
  }
  if(c == 'x'){                 
      myservo.write(60);              // tell servo to go to position in variable 'pos' 
      Serial.println("stop");
  }
} 

