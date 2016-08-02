#include <PS2X_lib.h>  //for v1.6
#include <Servo.h> 
/******************************************************************
 * set pins connected to PS2 controller:
 *   - 1e column: original 
 *   - 2e colmun: Stef?
 * replace pin numbers by the ones you use
 ******************************************************************/
#define PS2_DAT        47  //14    
#define PS2_CMD        48  //15
#define PS2_SEL        46  //16
#define PS2_CLK        49  //17

//#define PS2_DAT        12  //14    
//#define PS2_CMD        11  //15
//#define PS2_SEL        10  //16
//#define PS2_CLK        13  //17
const int oto = 52;     // the number of the pushbutton pin
const int buttonPin = 53;     // the number of the pushbutton pin
const int ledPin =  50;
const int ledPin1 =  51;// the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
int buttonOto = 0;

Servo gripper;
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
int STBY1 = 14; //standby
int STBY2 = 15; //standby
int STBY3 = 20; //standby

//Motor kiri
int PWMA = 2; //Speed control 
int AIN1 = 22; //Direction
int AIN2 = 23; //Direction

//Motor kanan
int PWMB = 3; //Speed control
int BIN1 = 24; //Direction
int BIN2 = 25; //Direction

//forklif
int PWMC = 10; //Speed control
int CIN1 = 34; //Direction
int CIN2 = 35; //Direction

//gerbang atas
int PWME = 8; //Speed control
int EIN1 = 36; //Direction
int EIN2 = 37; //Direction
/******************************************************************
 * select modes of PS2 controller:
 *   - pressures = analog reading of push-butttons 
 *   - rumble    = motor rumbling
 * uncomment 1 of the lines for each mode selection
 ******************************************************************/
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you connect the controller, 
//or call config_gamepad(pins) again after connecting the controller.

int error = 0;
byte type = 0;
byte vibrate = 0;

void setup(){
  myservo.attach(9);
  gripper.attach(45);
  
  myservo.write(10); 
  gripper.write(90);

  
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
  
  delay(300);  //added delay to give wireless ps2 module some time to startup, before configuring it
   
  //CHANGES for v1.6 HERE!!! **************PAY ATTENTION*************
  
  //setup pins and settings: GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  
  if(error == 0){
    Serial.print("Found Controller, configured successful ");
    Serial.print("pressures = ");
  if (pressures)
    Serial.println("true ");
  else
    Serial.println("false");
  Serial.print("rumble = ");
  if (rumble)
    Serial.println("true)");
  else
    Serial.println("false");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Note: Go to www.billporter.info for updates and to report bugs.");
  }  
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  
//  Serial.print(ps2x.Analog(1), HEX);
  
  type = ps2x.readType(); 
  switch(type) {
    case 0:
      Serial.print("Unknown Controller type found ");
      break;
    case 1:
      Serial.print("DualShock Controller found ");
      break;
    case 2:
      Serial.print("GuitarHero Controller found ");
      break;
  case 3:
      Serial.print("Wireless Sony DualShock Controller found ");
      break;
   }
}

void loop() {

//    myservo.write(50);      
        //delay(1000);
  /* You must Read Gamepad to get new values and set vibration values
     ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
     if you don't enable the rumble, use ps2x.read_gamepad(); with no values
     You should call this at least once a second
   */  
  if(error == 1) //skip loop if no controller found
    return; 
  
  if(type == 2){ //Guitar Hero Controller
    ps2x.read_gamepad();          //read controller 
   
    if(ps2x.ButtonPressed(GREEN_FRET))
      Serial.println("Green Fret Pressed");
    if(ps2x.ButtonPressed(RED_FRET))
      Serial.println("Red Fret Pressed");
    if(ps2x.ButtonPressed(YELLOW_FRET))
      Serial.println("Yellow Fret Pressed");
    if(ps2x.ButtonPressed(BLUE_FRET))
      Serial.println("Blue Fret Pressed");
    if(ps2x.ButtonPressed(ORANGE_FRET))
      Serial.println("Orange Fret Pressed"); 

    if((ps2x.Analog(PSS_LY), DEC) == 255) {
         Serial.print("Analog works");
      }
    if(ps2x.ButtonPressed(STAR_POWER))
      Serial.println("Star Power Command");
    
    if(ps2x.Button(UP_STRUM))          //will be TRUE as long as button is pressed
      Serial.println("Up Strum");
    if(ps2x.Button(DOWN_STRUM))
      Serial.println("DOWN Strum");
 
    if(ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
//      gripper.write(0);
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");
//      gripper.write(180);
    
    if(ps2x.Button(ORANGE_FRET)) {     // print stick value IF TRUE
      Serial.print("Wammy Bar Position:");
      Serial.println(ps2x.Analog(WHAMMY_BAR), DEC); 
    } 
  }
  else { //DualShock Controller
    stopMOTOR();
    ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed
    
    if(ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
//      gripper.write(0);
//    if(ps2x.Button(PSB_SELECT))
//      Serial.println("Select is being held");      

    if(ps2x.Button(PSB_PAD_UP)) {      //will be TRUE as long as button is pressed
      Serial.print("Up held this hard: ");
      maju();
      Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC);
    }
    if(ps2x.Button(PSB_PAD_RIGHT)){
      Serial.print("Right held this hard: ");
      kanan();
      Serial.println(ps2x.Analog(PSAB_PAD_RIGHT), DEC);
    }
    if(ps2x.Button(PSB_PAD_LEFT)){
      Serial.print("LEFT held this hard: ");
      kiri();
      Serial.println(ps2x.Analog(PSAB_PAD_LEFT), DEC);
    }
    if(ps2x.Button(PSB_PAD_DOWN)){
      Serial.print("DOWN held this hard: ");
      mundur();
//      gripper.write(0);
      Serial.println(ps2x.Analog(PSAB_PAD_DOWN), DEC);
    }   

    vibrate = ps2x.Analog(PSAB_CROSS);  //this will set the large motor vibrate speed based on how hard you press the blue (X) button
    if (ps2x.NewButtonState()) {        //will be TRUE if any button changes state (on to off, or off to on)
      if(ps2x.Button(PSB_L3))
      g ripper.write(180);
        Serial.println("L3 pressed");
        
      if(ps2x.Button(PSB_R3))
        myservo.write(100);
        Serial.println("R3 pressed");
      if(ps2x.Button(PSB_L2)){
        Serial.println("L2 pressed");
        forklifUP();
        
      }
      if(ps2x.Button(PSB_R2)){
        Serial.println("R2 pressed");
        forklifDOWN();
      }
      if(ps2x.Button(PSB_TRIANGLE)) {
        Serial.println("Triangle pressed");  
//        setSpeed(60);
//        delay(1000);
        myservo.write(60);      
//        gripper.write(180);
//        delay(1000);
//        myservo.write(0); 
      }
    }

    if(ps2x.ButtonPressed(PSB_CIRCLE)){               //will be TRUE if button was JUST pressed
      Serial.println("Circle just pressed");
      myservo.write(10);
      gripper.write(0);
    }
    if(ps2x.NewButtonState(PSB_CROSS)){               //will be TRUE if button was JUST pressed OR released
      Serial.println("X just changed");
//      int g = 0;
//      if (g==0){
              
//      }
      myservo.write(80);
//      delay(1000);
//      gripper.write(90);
      }
    if(ps2x.ButtonReleased(PSB_SQUARE)){              //will be TRUE if button was JUST released
      Serial.println("Square just released");
      myservo.write(70);  
      
  }     

    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { //print stick values if either is TRUE
      Serial.print("Stick Values:");
      Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_LX), DEC); 
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_RY), DEC); 
      Serial.print(",");
      Serial.println(ps2x.Analog(PSS_RX), DEC); 
    }     
  }
  delay(50);  

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
  move(1, 200, 0); //motor 1, full speed, left
  move(2, 200, 0); //motor 2, full speed, left
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
  move(1, 128, 2); //motor 1, half speed, right
  move(2, 128, 1); //motor 2, half speed, right

}

void kanan(){
  move(1, 128, 1); //motor 1, half speed, right
  move(2, 128, 2); //motor 2, half speed, right

}

void mundur(){
  move(1, 200, 1); //motor 1, half speed, right
  move(2, 200, 1); //motor 2, half speed, right

}

void stopMOTOR(){
//enable standby  
  digitalWrite(STBY1, LOW); 
  digitalWrite(STBY2, LOW); 
}

void forklifUP(){
    digitalWrite(STBY3, HIGH); 
    digitalWrite(CIN1, LOW);
    digitalWrite(CIN2, HIGH);
    analogWrite(PWMC, 200);
    delay(1000);
    analogWrite(PWMC, 0);
}

void GERBANG(){
    digitalWrite(EIN1, HIGH);
    digitalWrite(EIN2, LOW);
    analogWrite(PWME, 200);
    delay(500);
    analogWrite(PWME, 0);
}

void forklifDOWN(){
    digitalWrite(STBY3, HIGH); 
    digitalWrite(CIN1, HIGH);
    digitalWrite(CIN2, LOW);
    analogWrite(PWMC, 200);
    delay(1000);
    analogWrite(PWMC, 0);
}

void setSpeed(int speed){
int angle = map(speed, 0, 100, 0, 180);
myservo.write(angle);  
}

