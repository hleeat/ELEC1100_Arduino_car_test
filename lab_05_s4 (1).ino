/*
  ELEC1100 Lab#05
  
  Use sensors to control motor rotation 

*/

// assign meaningful names to those pins that will be used

#define pinLeftSensor A5      //pin A5
#define pinRightSensor A3     //pin A3

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

#define pinPWM_L 10            //pin D10
#define pinPWM_R 9            //pin D9

//define variables to be used in script
int leftSensor = 1;
int rightSensor = 1;

// the setup function runs once when you press reset or power the board

void setup ()
{
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  
  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);
  
  pinMode(pinPWM_L, OUTPUT);
  pinMode(pinPWM_R, OUTPUT);
  
  // initialize output pins.
  digitalWrite(pinLdir, HIGH);        
  digitalWrite(pinRdir, HIGH);   
}

// the loop function runs over and over again forever
void loop()
{
  analogWrite(pinPWM_L, 200);
  analogWrite(pinPWM_R, 200);

  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);

  if ( leftSensor ) {
    digitalWrite(pinLdir, HIGH);
  }

  if ( !leftSensor ) {
    digitalWrite(pinLdir, LOW);
  }

  if ( rightSensor ) {
    digitalWrite(pinRdir, HIGH);
  }

  if ( !rightSensor ) {
    digitalWrite(pinRdir, LOW);
  }  
}