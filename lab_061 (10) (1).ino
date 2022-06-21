/*
  ELEC1100 Your Lab#06 & Project Template

  To program the car tracking the white line on a dark mat

  Your Name:Hyunji Lee  
  Student ID:20670332

*/

// assign meaningful names to those pins that will be used

#define pinLeftSensor A5      //pin A5
#define pinMiddleSensor A4      //pin A4
#define pinRightSensor A3     //pin A3

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

#define pinPWM_L 10            //pin D10
#define pinPWM_R 9            //pin D9

//define variables to be used in script
int leftSensor = 1;
int rightSensor = 1;
int middleSensor = 1;
int count = 0;

// the setup function runs once when you press reset or power the board

void setup ()
{
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinMiddleSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  
  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);
  
  pinMode(pinPWM_L, OUTPUT);
  pinMode(pinPWM_R, OUTPUT);
  
  // initialize output pins.
  digitalWrite(pinLdir, HIGH);        
  digitalWrite(pinRdir, HIGH);   
}

int start = 0;
int gyosu= 0;
int amsal= 0;
int hago= 0;
int sipda= 0;

// the loop function runs over and over again forever
void loop()
{
  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  middleSensor = digitalRead(pinMiddleSensor);
  
  if (count == 0){
    if (start==0){
      analogWrite(pinPWM_L, 0);
      analogWrite(pinPWM_R, 0);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 0);
      if( !leftSensor && !rightSensor && !middleSensor) {
        start+=1;
      }
    }
  
    if ( !leftSensor && !rightSensor && middleSensor && start>0) {
      analogWrite(pinPWM_L, 180);
      analogWrite(pinPWM_R, 180);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 1);
      delay(500);
      count=1;
    }
  }
  if (count == 1){
    if ( leftSensor && rightSensor && middleSensor) {//forward
      analogWrite(pinPWM_L, 180);
      analogWrite(pinPWM_R, 180);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 1);
      gyosu+=1;
    }

    else if ( !leftSensor && rightSensor ) {//trunleft
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 150);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 1);
      gyosu+=1;
    }

    else if ( leftSensor && !rightSensor ) {//turnright
      analogWrite(pinPWM_L, 150);
      analogWrite(pinPWM_R, 100);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 0);
      gyosu+=1;
    }
    
    else if ( !leftSensor && !rightSensor && middleSensor && gyosu>0) {
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 100); 
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 1);
      delay(500);
      count=2;
    }
  }
  if (count==2){
    if ( leftSensor && rightSensor) {//forward
      analogWrite(pinPWM_L, 180);
      analogWrite(pinPWM_R, 180);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 1);
      amsal+=1;
    }

    else if ( !leftSensor && rightSensor ) {//turnleft
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 150);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 1);
      amsal+=1;
    }

    else if ( leftSensor && !rightSensor ) {//turnright
      analogWrite(pinPWM_L, 150);
      analogWrite(pinPWM_R, 100);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 0);
      amsal+=1;
    }
    else if ( !leftSensor && !rightSensor && middleSensor && amsal>0) {
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 100);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 1);
      delay(500);
      count=3;
    }
  }
  if (count==3){
    if ( leftSensor && rightSensor) {
      analogWrite(pinPWM_L, 180);
      analogWrite(pinPWM_R, 180);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 1);
      hago+=1;
    }

    else if ( !leftSensor && rightSensor ) {//turnleft
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 150);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 1);
      hago+=1;
    }

    else if ( leftSensor && !rightSensor ) {//turnright
      analogWrite(pinPWM_L, 150);
      analogWrite(pinPWM_R, 100);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 0);
      hago+=1;
    }
    else if ( !leftSensor && !rightSensor && middleSensor && hago>0) {
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 100);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 0);
      delay(500);
      count=4;
    }
  }
  if (count==4){
    if ( leftSensor && rightSensor) {//Forw
      analogWrite(pinPWM_L, 130);
      analogWrite(pinPWM_R, 130);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 1);
      sipda+=1;
    }

    else if ( !leftSensor && rightSensor ) {//Turnle
      analogWrite(pinPWM_L, 95);
      analogWrite(pinPWM_R, 115);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 1);
      sipda+=1;
    }

    else if ( leftSensor && !rightSensor ) {//Turnrig
      analogWrite(pinPWM_L, 115);
      analogWrite(pinPWM_R, 95);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 0);
      sipda+=1;
    }
    else if ( !leftSensor && !rightSensor && middleSensor) {
      analogWrite(pinPWM_L, 95);
      analogWrite(pinPWM_R, 115);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 0);
    }
    else if ( !leftSensor && !rightSensor && !middleSensor && sipda>0) {
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 100);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 0);
      delay(500);
      count=5;
    }
  }
  if (count==5){
    if ( leftSensor && rightSensor) {
      analogWrite(pinPWM_L, 100);
      analogWrite(pinPWM_R, 100);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 0);
    }
    else if ( !leftSensor && rightSensor) {
      analogWrite(pinPWM_L, 0);
      analogWrite(pinPWM_R, 0);
      digitalWrite(pinLdir, 1);
      digitalWrite(pinRdir, 0);
    }
    else if ( leftSensor && !rightSensor) {
      analogWrite(pinPWM_L, 0);
      analogWrite(pinPWM_R, 0);
      digitalWrite(pinLdir, 0);
      digitalWrite(pinRdir, 1);
    }
  }
}
