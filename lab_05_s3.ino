#define pinPWM_L 10            //pin D10
#define pinPWM_R 9            //pin D9

void setup()
{
  pinMode(pinPWM_L, OUTPUT);
  pinMode(pinPWM_R, OUTPUT);
} 

void loop()
{
  
  analogWrite(pinPWM_L, 200);
  analogWrite(pinPWM_R, 100);
}