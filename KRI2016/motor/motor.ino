 
int STBY1 = 2; //standby
int STBY2 = 4; //standby

//Motor A
int PWMA = 3; //Speed control 
int AIN1 = 22; //Direction
int AIN2 = 23; //Direction

//Motor B
int PWMB = 5; //Speed control
int BIN1 = 24; //Direction
int BIN2 = 25; //Direction

void setup(){
//  myservo.attach(9);
//  myservo.write(0); 
//  delay(1000);

  pinMode(STBY1, OUTPUT);
  pinMode(STBY2, OUTPUT);
  
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  Serial.begin(9600);
}

unsigned char c;

void loop(){
    if(Serial.available() > 0){
      c = Serial.read();
      }

      if(c=='a'){
          maju();
          Serial.println("maju");
        }else if(c=='s'){
          stopMOTOR();
          }else if(c=='d'){
          mundur();
          }
  }
void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY1, HIGH); //disable standby
  digitalWrite(STBY2, HIGH); //disable standby
  
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void maju(){
  move(1, 128, 1); //motor 1, full speed, left
  move(2, 128, 1); //motor 2, full speed, left
}

void serongKanan(){
  move(1, 200, 1); //motor 1, full speed, left
  move(2, 200, 1); //motor 2, full speed, left
}

void serongKiri(){
  move(1, 200, 1); //motor 1, full speed, left
  move(2, 200, 1); //motor 2, full speed, left
}

void kiri(){
  move(1, 200, 1); //motor 1, half speed, right
  move(2, 200, 1); //motor 2, half speed, right

}

void kanan(){
  move(1, 200, 1); //motor 1, half speed, right
  move(2, 200, 1); //motor 2, half speed, right

}

void mundur(){
  move(1, 200, 0); //motor 1, half speed, right
  move(2, 200, 0); //motor 2, half speed, right

}

void stopMOTOR(){
//enable standby  
  digitalWrite(STBY1, LOW); 
  digitalWrite(STBY2, LOW); 
}
