
void setupoto() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(oto, INPUT);
  Serial.begin(9600);
  setupmotor();
}
int s = 0;
int o = 0;

void loopoto() {
  
  buttonOto = digitalRead(oto);
  buttonState = digitalRead(buttonPin);
  if(buttonOto == LOW){
    o=1;
  }
  if(o==1){
  Serial.println("aaa");
    if (buttonState == HIGH) {
      s=1;
      
    }
      if(s==1){
        
        Serial.println("111");
        digitalWrite(ledPin, HIGH);
        digitalWrite(ledPin1, LOW);
        delay(1000);
        maju();
//        delay(10000);
//        mati();
      }
      else {
        digitalWrite(ledPin, LOW);
        digitalWrite(ledPin1, HIGH);
      }
      
  }
  
}
