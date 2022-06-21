/*
  Simple Test Code during project preparation

  The result is the same as Lab#06. This aims at distinguishing between
  connection problem or coding problem.

*/

// assign meaningful names to those pins that will be used
#define pinLeftSensor A5      //pin A5
#define pinRightSensor A2     //pin A3
#define pinMiddleSensor A4    //pin A4
#define pinUpperSensor A3     //pin A2

#define pinLQ3 3              //pin D3
#define pinLQ2 4              //pin D4
#define pinLQ1 5              //pin D5
#define pinLQ0 6              //pin D6

#define pinRQ3 7              //pin D7
#define pinRQ2 8              //pin D8
#define pinRQ1 9              //pin D9
#define pinRQ0 10             //pin D10

#define pinLdir 11            //pin D11
#define pinRdir 12            //pin D12

//define variables to be used in script
int leftSensor = 1;
int rightSensor = 1;
int middleSensor = 1;
int upperSensor = 1;
int count1 = 0;
boolean count3 = false;
boolean count2 = false;


// the setup function runs once when you press reset or power the board
void setup() {
  // define pins as input and output.
  pinMode(pinLeftSensor, INPUT);
  pinMode(pinRightSensor, INPUT);
  pinMode(pinMiddleSensor, INPUT);
  pinMode(pinUpperSensor, INPUT);

  pinMode(pinLQ3, OUTPUT);
  pinMode(pinLQ2, OUTPUT);
  pinMode(pinLQ1, OUTPUT);
  pinMode(pinLQ0, OUTPUT);

  pinMode(pinRQ3, OUTPUT);
  pinMode(pinRQ2, OUTPUT);
  pinMode(pinRQ1, OUTPUT);
  pinMode(pinRQ0, OUTPUT);

  pinMode(pinLdir, OUTPUT);
  pinMode(pinRdir, OUTPUT);

  // initialize output pins.
  digitalWrite(pinLQ3, 0);
  digitalWrite(pinLQ2, 0);
  digitalWrite(pinLQ1, 0);
  digitalWrite(pinLQ0, 0);
  digitalWrite(pinRQ3, 0);
  digitalWrite(pinRQ2, 0);
  digitalWrite(pinRQ1, 0);
  digitalWrite(pinRQ0, 0);
  digitalWrite(pinLdir, HIGH);        // HIGH: spin forward
  digitalWrite(pinRdir, HIGH); // LOW:  spin backward

  count1 = 0;
  count3 = false;
  count2 = false;

    
}

// the loop function runs over and over again forever
void loop() {

  leftSensor = digitalRead(pinLeftSensor);
  rightSensor = digitalRead(pinRightSensor);
  middleSensor = digitalRead(pinMiddleSensor);

  if (digitalRead(pinUpperSensor)==false && count2 == 0) {
    digitalWrite(pinLQ3, 1);
    digitalWrite(pinLQ2, 1);
    digitalWrite(pinLQ1, 1);
    digitalWrite(pinLQ0, 1);
    digitalWrite(pinRQ3, 1);
    digitalWrite(pinRQ2, 1);
    digitalWrite(pinRQ1, 1);
    digitalWrite(pinRQ0, 1);
    count2++;
    delay(300);
  }
  
  if (digitalRead(pinUpperSensor)==false && count2 >= 1) {
    digitalWrite(pinLdir, LOW);
    digitalWrite(pinRdir, HIGH);
    digitalWrite(pinLQ3, 1);
    digitalWrite(pinLQ2, 1);
    digitalWrite(pinLQ1, 1);
    digitalWrite(pinLQ0, 1);
    digitalWrite(pinRQ3, 1);
    digitalWrite(pinRQ2, 1);
    digitalWrite(pinRQ1, 1);
    digitalWrite(pinRQ0, 1);
    delay(900);
    digitalWrite(pinLdir, HIGH);
    digitalWrite(pinRdir, HIGH);
    delay(600);
    digitalWrite(pinLQ3, 0);
    digitalWrite(pinLQ2, 0);
    digitalWrite(pinLQ1, 0);
    digitalWrite(pinLQ0, 0);
    digitalWrite(pinRQ3, 0);
    digitalWrite(pinRQ2, 0);
    digitalWrite(pinRQ1, 0);
    digitalWrite(pinRQ0, 0);
  }

  if (leftSensor && rightSensor) {
    digitalWrite(pinLdir, HIGH);
    digitalWrite(pinRdir, HIGH);
    delay(15);
    
    
  }
  
  if (!leftSensor && rightSensor) {
    digitalWrite(pinLdir, LOW);
    digitalWrite(pinRdir, HIGH);
    delay(15);
    
  }
  
  if (leftSensor && !rightSensor) {
    digitalWrite(pinLdir, HIGH);
    digitalWrite(pinRdir, LOW);
    delay(15);
  }

  if (!leftSensor && !rightSensor && !middleSensor){
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      delay(15);
  }
 
  if ((count1 == 0) && (!leftSensor && !rightSensor && middleSensor)){
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      delay(150);
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      delay(200);
      leftSensor = digitalRead(pinLeftSensor);
      rightSensor = digitalRead(pinRightSensor);
      middleSensor = digitalRead(pinMiddleSensor);
      if ((!leftSensor && !rightSensor && middleSensor)==false) {
        count1++;
      }
  }

  if ((count1 == 1) && (!leftSensor && !rightSensor && middleSensor)){
      digitalWrite(pinLdir, LOW);
      digitalWrite(pinRdir, HIGH);
      delay(150);
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      delay(200);
      leftSensor = digitalRead(pinLeftSensor);
      rightSensor = digitalRead(pinRightSensor);
      middleSensor = digitalRead(pinMiddleSensor);
      if ((!leftSensor && !rightSensor && middleSensor)==false) {
        count1++;
      }    
  }
    
  if ((count1 == 2) && (!leftSensor && !rightSensor && middleSensor)){
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, LOW);
      delay(150);
      digitalWrite(pinLdir, HIGH);
      digitalWrite(pinRdir, HIGH);
      delay(200);    
  }
}
    



   

  
  
  
