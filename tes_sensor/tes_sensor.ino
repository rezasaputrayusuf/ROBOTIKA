int sen1 = A0;
int sen2 = A1;
int sen3 = A2;
int sen4 = A3;

int sens1 = 0;
int sens2 = 0; 
int sens3 = 0;
int sens4 = 0;

int sV1 = 0;
int sV2 = 0;
int sV3 = 0;
int sV4 = 0;

int oV1 = 0;
int oV2 = 0;
int oV3 = 0;
int oV4 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(3,HIGH);
    bacasensor();
  if(sens1==1 && sens2==1 && sens3==1 && sens4==1) {
    Serial.println("lurus");
  } else if(sens1==1 && sens2==1 && sens3==0 && sens4==0) {
    Serial.println("belok kanan");
  }  else if(sens1==0 && sens2==0 && sens3==1 && sens4==1) {
    Serial.println("belok kiri");
  } else {
    Serial.println("diam");
  }
  Serial.print(sV1);
  Serial.print(" ");
  Serial.print(sV2);
  Serial.print(" ");
  Serial.print(sV3);
  Serial.print(" ");
  Serial.println(sV4);
}

void bacasensor() {
  sV1 = analogRead(sen1);
  sV2 = analogRead(sen2);
  sV3 = analogRead(sen3);
  sV4 = analogRead(sen4);
  
  oV1 = map(sV1, 0, 1023, 0, 255);
  oV2 = map(sV2, 0, 1023, 0, 255);
  oV3 = map(sV3, 0, 1023, 0, 255);
  oV4 = map(sV4, 0, 1023, 0, 255);  

  if(oV1<50) {
    sens1 = 1;
  } else {
    sens1 = 0;
  }

  if(oV2<50) {
    sens2 = 1;
  } else {
    sens2 = 0;
  }

  if(oV3<60) {
    sens3 = 1;
  } else {
    sens3 = 0;
  }

  if(oV4<60) {
    sens4 = 1;
  } else {
    sens4 = 0;
  }
}
