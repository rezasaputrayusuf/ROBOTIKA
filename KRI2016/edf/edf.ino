#include <Servo.h>

Servo myservo;

int switchPin = 8;


void setSpeed(int speed){
// speed is from 0 to 100 where 0 is off and 100 is maximum speed
//the following maps speed values of 0-100 to angles from 0-180,
int angle = map(speed, 0, 100, 0, 180);
myservo.write(angle);  
}

void setup()
{
Serial.begin(9600);
myservo.attach(9);
}

void loop()
{
int speed;

Serial.println("GO");
if (digitalRead(switchPin) == HIGH); 
{
  setSpeed(60);
  Serial.println(speed);
  delay(4000);
}

Serial.println("STOP");
if (digitalRead(switchPin) == LOW);
{
    setSpeed(0);
  Serial.println(speed);
  delay(100);
}
Serial.println("30 halting...");
setSpeed(30);
delay(5000);
}
