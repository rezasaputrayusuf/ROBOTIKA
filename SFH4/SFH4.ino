int sen1 = A0;
int sen2 = A1;
int sen3 = A2;
int sen4 = A3;
int sen5 = A4;
int sen6 = A5;
int sen7 = A6;
int sen8 = A7;

int sV1 = 0;
int sV2 = 0;
int sV3 = 0;
int sV4 = 0;
int sV5 = 0;
int sV6 = 0;
int sV7 = 0;
int sV8 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(3,HIGH);
 bacaSensor();
 
}

void bacaSensor(){
  sV1 = analogRead(sen1);
  sV2 = analogRead(sen2);
  sV3 = analogRead(sen3);
  sV4 = analogRead(sen4);
  sV5 = analogRead(sen5);
  sV6 = analogRead(sen6);
  sV7 = analogRead(sen7);
  sV8 = analogRead(sen8);

  Serial.print(sV1);
  Serial.print("  ");
  Serial.print(sV2);
  Serial.print("  ");
  Serial.print(sV3);
  Serial.print("  ");
  Serial.print(sV4);
  Serial.print("  ");
  Serial.print(sV5);
  Serial.print("  ");
  Serial.print(sV6);
  Serial.print("  ");
  Serial.print(sV7);
  Serial.print("  ");
  Serial.println(sV8);
 
  }
