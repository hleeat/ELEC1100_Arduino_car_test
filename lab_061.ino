/*
  ELEC1100 Your Lab#06 & Project Template

  To program the car tracking the white line on a dark mat

  Your Name:Hoonjoo Ra     
  Student ID:20668793

*/

// assign meaningful names to those pins that will be used

#define pinLeftSensor A5      //pin A5
#define pinBumpSensor A4      //pin A5
#define pinRightSensor A3     //pin A3

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

#define pinPWM_L 10            //pin D10
#define pinPWM_R 9            //pin D9

//define variables to be used in script
int leftSensor = 1;
int rightSensor = 1;
int bumpSensor = 1;
int turn = 0;

// the setup function runs once when you press reset or power the board

void forward(){
  analogWrite(pinPWM_L, 100);
  analogWrite(pinPWM_R, 100);
  digitalWrite(pinLdir, 1);
  digitalWrite(pinRdir, 1);
}

void turnright(){
  analogWrite(pinPWM_L, 70);
  analogWrite(pinPWM_R, 30);
  digitalWrite(pinLdir, 1);
  digitalWrite(pinRdir, 0);
}

void turnleft(){
  analogWrite(pinPWM_L, 30);
  analogWrite(pinPWM_R, 70);
  digitalWrite(pinLdir, 0);
  digitalWrite(pinRdir, 1);
}

void Forward(){
  analogWrite(pinPWM_L, 70);
  analogWrite(pinPWM_R, 70);
  digitalWrite(pinLdir, 1);
  digitalWrite(pinRdir, 1);
}

void Turnright(){
  analogWrite(pinPWM_L, 50);
  analogWrite(pinPWM_R, 20);
  digitalWrite(pinLdir, 1);
  digitalWrite(pinRdir, 0);
}

void Turnleft(){
  analogWrite(pinPWM_L, 50);
  analogWrite(pinPWM_R, 20);
  digitalWrite(pinLdir, 0);
  digitalWrite(pinRdir, 1);
}

void setup ()
{
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinBumpSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  
  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);
  
  pinMode(pinPWM_L, OUTPUT);
  pinMode(pinPWM_R, OUTPUT);
  
  // initialize output pins.
  digitalWrite(pinLdir, HIGH);        
  digitalWrite(pinRdir, HIGH);   
}

int bump = 0;

// the loop function runs over and over again forever
void loop()
{
  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  bumpSensor = digitalRead(pinBumpSensor);
  
  if (turn == 0){
  	if (bumpSensor && bump==0) {
    	analogWrite(pinPWM_L, 0);
  		analogWrite(pinPWM_R, 0);
    	digitalWrite(pinLdir, 0);
    	digitalWrite(pinRdir, 0);
  	}
  
  	if (!bumpSensor && bump==0) {
    	analogWrite(pinPWM_L, 100);
  		analogWrite(pinPWM_R, 100);
    	digitalWrite(pinLdir, 1);
    	digitalWrite(pinRdir, 1);
    	delay(500);
      	bump=1;
  	}
    if ( leftSensor && rightSensor && bumpSensor && bump==1) {
    	forward();
  	}

  	if ( !leftSensor && rightSensor ) {
		turnleft();
  	}

  	if ( leftSensor && !rightSensor ) {
      	turnright();
  	}
    
  	if ( !leftSensor && !rightSensor && bumpSensor) {
    	digitalWrite(pinLdir, 0);
    	digitalWrite(pinRdir, 1);
      	analogWrite(pinPWM_L, 100);
  		analogWrite(pinPWM_R, 100);
      	delay(200);
      	turn=1;
	}
  }
  if (turn==1){
    if ( leftSensor && rightSensor) {
    	forward();
  	}

  	if ( !leftSensor && rightSensor ) {
		turnleft();
  	}

  	if ( leftSensor && !rightSensor ) {
      	turnright();
  	}
    if ( !leftSensor && !rightSensor && bumpSensor) {
    	digitalWrite(pinLdir, 0);
    	digitalWrite(pinRdir, 1);
      	analogWrite(pinPWM_L, 100);
  		analogWrite(pinPWM_R, 100);
      	delay(200);
      	turn=2;
	}
  }
  if (turn==2){
    if ( leftSensor && rightSensor) {
    	forward();
  	}

  	if ( !leftSensor && rightSensor ) {
		turnleft();
  	}

  	if ( leftSensor && !rightSensor ) {
      	turnright();
  	}
    if ( !leftSensor && !rightSensor && bumpSensor) {
    	digitalWrite(pinLdir, 1);
    	digitalWrite(pinRdir, 0);
      	analogWrite(pinPWM_L, 100);
  		analogWrite(pinPWM_R, 100);
      	delay(200);
      	turn=3;
	}
  }
  if (turn==3){
    if ( leftSensor && rightSensor) {
    	Forward();
  	}

  	if ( !leftSensor && rightSensor ) {
		Turnleft();
  	}

  	if ( leftSensor && !rightSensor ) {
      	Turnright();
  	}
    if ( !leftSensor && !rightSensor && !bumpSensor) {
      	digitalWrite(pinLdir, 0);
    	digitalWrite(pinRdir, 0);
      	analogWrite(pinPWM_L, 100);
  		analogWrite(pinPWM_R, 100);
      	delay(400);
      	turn=4;
	}
  }
  if (turn==4){
    if ( leftSensor && rightSensor) {
    	analogWrite(pinPWM_L, 100);
 		analogWrite(pinPWM_R, 100);
  		digitalWrite(pinLdir, 0);
  		digitalWrite(pinRdir, 0);
  	}
    if ( !leftSensor && rightSensor) {
    	analogWrite(pinPWM_L, 0);
 		analogWrite(pinPWM_R, 0);
  		digitalWrite(pinLdir, 1);
  		digitalWrite(pinRdir, 0);
  	}
    if ( leftSensor && !rightSensor) {
    	analogWrite(pinPWM_L, 0);
 		analogWrite(pinPWM_R, 0);
  		digitalWrite(pinLdir, 0);
  		digitalWrite(pinRdir, 1);
  	}
  }
}