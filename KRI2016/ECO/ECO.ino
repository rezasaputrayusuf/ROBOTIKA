#include <Servo.h> 
 
Servo myservo;
int pos = 0;

int sen1 = A0;
int sen2 = A1;
int sen3 = A2;
int sen4 = A3;
int sen5 = A4;
int sen6 = A5;

int sens1 = 0;
int sens2 = 0; 
int sens3 = 0;
int sens4 = 0;
int sens5 = 0;
int sens6 = 0; 


int sV1 = 0;
int sV2 = 0;
int sV3 = 0;
int sV4 = 0;
int sV5 = 0;
int sV6 = 0;

int oV1 = 0;
int oV2 = 0;
int oV3 = 0;
int oV4 = 0;
int oV5 = 0;
int oV6 = 0;

String senssss;
String segaris;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(90);
}


unsigned char c;

void loop() {
  
  bacasensor();
//  Serial.print(sV1);
//  Serial.print("  ");
//  Serial.print(sV2);
//  Serial.print("  ");
//    Serial.print(sV3);
//  Serial.print("  ");
//    Serial.print(sV4);
//  Serial.print("  ");
//    Serial.print(sV5);
//  Serial.print("  ");
//    Serial.print(sV6);
//  Serial.print("  ");
//    Serial.print(sV7);
//  Serial.print("  ");
//    Serial.println(sV8);

    
//  Serial.print(sens1);
//  Serial.print("  ");
//  Serial.print(sens2);
//  Serial.print("  ");
//    Serial.print(sens3);
//  Serial.print("  ");
//    Serial.print(sens4);
//  Serial.print("  ");
//    Serial.print(sens5);
//  Serial.print("  ");
//    Serial.print(sens6);
//  Serial.print("  ");
//    Serial.print(sens7);
//  Serial.print("  ");
//    Serial.println(sens8);


//  if(sens2==0 && sens3==0 && sens4==1 || sens4 ==0 && sens5==1 && sens6==1 || sens6==0 && sens7==0 && sens8==0) {
//      Serial.println("lurus");                             // in steps of 1 degree 
//      myservo.write(20);              // tell servo to go to position in variable 'pos' 
//      delay(1);
//  }
//  if(sens2==1) {
//      Serial.println("kanan");                             // in steps of 1 degree 
//      myservo.write(25);              // tell servo to go to position in variable 'pos' 
////      delay(1);
//  }else if(sens8==1) {
//      Serial.println("kiri");                             // in steps of 1 degree 
//      myservo.write(75);              // tell servo to go to position in variable 'pos' 
////      delay(1);
//  }else if(sens3==1 || sens4==1 || sens5==1 || sens6==1 || sens7==1){
//      myservo.write(50);
//      Serial.println("depan");
//    }
//  if(sens1==1 && sens2==1 && sens3==1 && sens4==1) {               
//      myservo.write(20);              // tell servo to go to position in variable 'pos' 
//      Serial.println("depan");
//  }

  if(segaris=="11100000" || segaris=="11000000" || segaris=="11100000" || segaris=="10000000"){
      Serial.println("kanan");                     
      myservo.write(25);
  }else if(segaris=="01100000" || segaris=="01110000" || segaris=="00110000"){
      Serial.println("kanan");                     
      myservo.write(50);
  }else if(segaris=="00111000" || segaris=="00011100" || segaris=="00011000"){
      Serial.println("lurus");                     
      myservo.write(70);
  }else if(segaris=="00000110" || segaris=="00001110" || segaris=="00001100"){
      Serial.println("kiri");                     
      myservo.write(90);
  }else if(segaris=="00000011" || segaris=="00000111" || segaris=="00000001" || segaris=="00001111"){
      Serial.println("kiri");                     
      myservo.write(115);
  }
}

void bacasensor() {
  sV1 = analogRead(sen1);
  sV2 = analogRead(sen2);
  sV3 = analogRead(sen3);
  sV4 = analogRead(sen4);
  sV5 = analogRead(sen5);
  sV6 = analogRead(sen6);
  sV7 = analogRead(sen7);
  sV8 = analogRead(sen8);
  
  oV1 = map(sV1, 0, 1023, 0, 255);
  oV2 = map(sV2, 0, 1023, 0, 255);
  oV3 = map(sV3, 0, 1023, 0, 255); 
  oV4 = map(sV4, 0, 1023, 0, 255);  
  oV5 = map(sV5, 0, 1023, 0, 255);
  oV6 = map(sV6, 0, 1023, 0, 255);
  oV7 = map(sV7, 0, 1023, 0, 255);
  oV8 = map(sV8, 0, 1023, 0, 255);  

  if(sV1<150) {
    sens1 = 1;
  } else {
    sens1 = 0;
  }

  if(sV2<150) {
    sens2 = 1;
  } else {
    sens2 = 0;
  }

  if(sV3<150) {
    sens3 = 1;
  } else {
    sens3 = 0;
  }

  if(sV4<150) {
    sens4 = 1;
  } else {
    sens4 = 0;
  }

  if(sV5<150) {
    sens5 = 1;
  } else {
    sens5 = 0;
  }

  if(sV6<150) {
    sens6 = 1;
  } else {
    sens6 = 0;
  }

  if(sV7<150) {
    sens7 = 1;
  } else {
    sens7 = 0;
  }

  if(sV8<200) {
    sens8 = 1;
  } else {
    sens8 = 0;
  }

  senssss = String(sens1);
  senssss += String(sens2);
  senssss += String(sens3);
  senssss += String(sens4);
  senssss += String(sens5);
  senssss += String(sens6);
  senssss += String(sens7);
  senssss += String(sens8);
  
  segaris = senssss;

  Serial.println(segaris);
}
