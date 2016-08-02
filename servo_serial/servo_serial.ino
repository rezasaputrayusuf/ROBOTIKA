#include <Servo.h>

Servo langServo;
int val;
String langString = "";

void setup()
{
  Serial.begin(9600);
  langServo.attach(9);
}

void loop()
{
  int degree;
  Serial.print("Masukkan sudut motor servo ");
  if(Serial.available() > 0){
  int langChar = Serial.read();
  if(isDigit(langChar))
  {
    langString += (char)langChar;    
  }
  if(langChar == '\n')
  {
    val = langString.toInt();
    Serial.println(val);
    langString = "";
    if(val > 179)
    {
      val = 179;
    }
    for(degree = 0; degree = val; degree++)
    {
      langServo.write(degree);
      delay(15);
    }
    for(degree = val; degree = 0; degree--)
    {
      langServo.write(degree);
      delay(15);
    }
  }
  }
}


