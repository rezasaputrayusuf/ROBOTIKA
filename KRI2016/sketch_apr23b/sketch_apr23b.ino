#include <Servo.h> 

Servo myservo;

void arm(){
  // arm the speed controller, modify as necessary for your ESC
  Serial.println("arming");
  setSpeed(30);
  delay(2000);
  setSpeed(50);
  delay(2000);
  Serial.println("armed");
  setSpeed(30);
  delay(2000);
}

void setSpeed(int speed){
  // speed is from 0 to 100 where 0 is off and 100 is maximum speed
  //the following maps speed values of 0-100 to angles from 0-180,
  int angle = map(speed, 0, 100, 0, 180);
  myservo.write(angle);  
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  myservo.attach(9);
  arm();
}

void loop() {
  setSpeed(0);
}
