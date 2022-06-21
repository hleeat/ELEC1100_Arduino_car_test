/*
  ELEC1100 Your Lab#06 & Project Template

  To program the car tracking the white line on a dark mat

  Your Name: LEE Hyunji               
  Student ID: 20670332

*/

// assign meaningful names to those pins that will be used

#define pinLeftSensor A5      //pin A5
#define pinRightSensor A3     //pin A3
#define pinMiddleSensor A4    //pin A4

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

#define pinPWM_L 10            //pin D10
#define pinPWM_R 9            //pin D9

//define variables to be used in script
int leftSensor = 1;
int rightSensor = 1;
int middleSensor=1;//black
int count =0;
int start=0;
// the setup function runs once when you press reset or power the board
int gyosu= 0;
int amsal= 0;
int hago= 0;
int sipda= 0;

void setup ()
{
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  pinMode(pinMiddleSensor, INPUT);
  
  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);
  
  pinMode(pinPWM_L, OUTPUT);
  pinMode(pinPWM_R, OUTPUT);
  
  // initialize output pins.
  digitalWrite(pinLdir, HIGH);        
  digitalWrite(pinRdir, HIGH);   
  count =0;
  start=0;
}

// the loop function runs over and over again forever
void loop()
{
  //analogWrite(pinPWM_L, 255);
  //analogWrite(pinPWM_R, 255);

  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  middleSensor = digitalRead(pinMiddleSensor);
  
  if(count==0 ){
    if(start==0){
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,0);
      analogWrite(pinPWM_R,0);
      if(!leftSensor && !rightSensor && !middleSensor){
        start=1;//front white line white
      }
    }
    if(!leftSensor && !rightSensor && middleSensor && start>0){
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,170);
      analogWrite(pinPWM_R,170);
      delay(400);
      count=1;
      
    }
  }
  if(count==1){
    if(leftSensor && rightSensor){//forward
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,180);
      analogWrite(pinPWM_R,180);
      delay(20);
      gyosu=gyosu+1;
    }
    else if(!leftSensor && rightSensor ) {//turnleft
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,150);
      delay(20);
      gyosu=gyosu+1;
      
    }
    else if( leftSensor && !rightSensor ) {//turnright
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, LOW);
      analogWrite(pinPWM_L,150);
      analogWrite(pinPWM_R,100);
      delay(20);
      gyosu=gyosu+1;
    }
    else if ( !leftSensor && !rightSensor && middleSensor &&gyosu>0) {
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,100);
      delay(400);
      count=2;
    }   
  }
  if(count==2){
    if(leftSensor && rightSensor){//forward
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,180);
      analogWrite(pinPWM_R,180);
      delay(20);
      amsal=amsal+1;
    }
    else if(!leftSensor && rightSensor ) {//turnleft
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,150);
      delay(20);
      amsal=amsal+1;
      
    }
    else if( leftSensor && !rightSensor ) {//turnright
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, LOW);
      analogWrite(pinPWM_L,150);
      analogWrite(pinPWM_R,100);
      delay(20);
      amsal=amsal+1;
    }
    else if ( !leftSensor && !rightSensor && middleSensor &&amsal>0 ) {
      digitalWrite(pinLdir, LOW);//left
      digitalWrite(pinRdir, HIGH);
      
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,100);
      delay(400);
      count=3;
    }   
  }
   if(count==3){
    if(leftSensor && rightSensor){
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,180);
      analogWrite(pinPWM_R,180);
      delay(20);
      hago=hago+1;
    }
    else if(!leftSensor && rightSensor ) {//turnleft
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,150);
      delay(20);
      hago=hago+1;
      
    }
    else if( leftSensor && !rightSensor ) {//turnright
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, LOW);
      analogWrite(pinPWM_L,150);
      analogWrite(pinPWM_R,100);
      
      delay(20);
      hago=hago+1;
    }
    else if ( !leftSensor && !rightSensor && middleSensor &&hago>0) {
      digitalWrite(pinLdir, HIGH);//right
      digitalWrite(pinRdir, LOW);
      
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,100);
      delay(400);
      count=4;
    } 
  }
  if(count==4){
    if(leftSensor && rightSensor){
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,130);
      analogWrite(pinPWM_R,130);
      delay(20);
      sipda= sipda+1;
    }
    else if(!leftSensor && rightSensor ) {//turnleft
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,90);
      analogWrite(pinPWM_R,115);
      delay(20);
      sipda= sipda+1;
    }
    else if( leftSensor && !rightSensor ) {//turnright
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, LOW);
      analogWrite(pinPWM_L,1115);
      analogWrite(pinPWM_R,90);
      delay(20);
      sipda= sipda+1;
    }
    else if(!leftSensor && !rightSensor && !middleSensor && sipda> 0){
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, LOW);
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,100);
      delay(400);
      count=5;
    }
  }
  if(count==5){
    if(leftSensor && rightSensor){
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, LOW);
      analogWrite(pinPWM_L,100);
      analogWrite(pinPWM_R,100);
    }
    else if(!leftSensor && rightSensor){
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, LOW);
      analogWrite(pinPWM_L,0);
      analogWrite(pinPWM_R,0);
    }
    else if(leftSensor && !rightSensor){
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      analogWrite(pinPWM_L,0);
      analogWrite(pinPWM_R,0);
    }
  }
}