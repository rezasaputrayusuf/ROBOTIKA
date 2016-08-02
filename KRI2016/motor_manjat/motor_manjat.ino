int STBY1 = 16; //standby
int STBY2 = 17; //standby
int STBY3 = 18; //standby
int STBY4 = 19; //standby
int STBY5 = 21; //standby

int PWMA = 4; //Speed control 
int AIN1 = 26; //Direction
int AIN2 = 27; //Direction

int PWMB = 5; //Speed control
int BIN1 = 28; //Direction
int BIN2 = 29; //Direction

int PWMC = 6; //Speed control
int CIN1 = 30; //Direction
int CIN2 = 31; //Direction

int PWMD = 7; //Speed control
int DIN1 = 32; //Direction
int DIN2 = 33; //Direction



void setup() {
  // put your setup code here, to run once:
  pinMode(STBY1, OUTPUT);
  pinMode(STBY2, OUTPUT);
  pinMode(STBY3, OUTPUT);
  pinMode(STBY4, OUTPUT);
//  pinMode(STBY5, OUTPUT);
//  
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  pinMode(PWMC, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);

  pinMode(PWMD, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);
//
//  pinMode(PWME, OUTPUT);
//  pinMode(EIN1, OUTPUT);
//  pinMode(EIN2, OUTPUT);
Serial.begin(9600);
}


unsigned char c;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0 ){
      c = Serial.read();
    }
  if(c=='a'){
      maju();
    }

  if(c=='s'){
      mati();
    }
}

void move(int motor, int speed, int direction){

  digitalWrite(STBY1, HIGH); //disable standby
  digitalWrite(STBY2, HIGH); //disable standby
  digitalWrite(STBY3, HIGH); //disable standby
  digitalWrite(STBY4, HIGH); //disable standby
//  digitalWrite(STBY4, HIGH); //disable standby
  
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
  }else if(motor == 2){
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }else if(motor == 3){
    digitalWrite(CIN1, inPin1);
    digitalWrite(CIN2, inPin2);
    analogWrite(PWMC, speed);
  }else {
    digitalWrite(DIN1, inPin1);
    digitalWrite(DIN2, inPin2);
    analogWrite(PWMD, speed);
//  }else{
//    digitalWrite(EIN1, inPin1);
//    digitalWrite(EIN2, inPin2);
//    analogWrite(PWME, speed);
//  }
}
}

void maju(){
  move(1, 100, 0); //motor 1, full speed, left
  move(2, 100, 0); //motor 2, full speed, left
  move(3, 100, 0); //motor 1, full speed, left
  move(4, 100, 0); //motor 2, full speed, left
  move(5, 100, 0); //motor 2, full speed, left
}

void mati(){
     digitalWrite(STBY1, LOW); //disable standby
  digitalWrite(STBY2, LOW); //disable standby
  digitalWrite(STBY3, LOW); //disable standby
  digitalWrite(STBY4, LOW); //disable standby
  }

