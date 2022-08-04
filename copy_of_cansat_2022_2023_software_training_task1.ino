#include <Servo.h>

int tmp36 = A0; //define pin A0 as the TMP36
float temp; //define temp variable 
Servo servo; //set up servo with name servo

int red = 3;   //define pin's with coorisponding RGB colours
int green = 6;
int blue = 5;

  int rVal = 0, gVal = 0, bVal= 0; //define RGB values initialized at 0

void setup()
{
servo.attach(9); //attach servo as pin 9
  
   pinMode(red, OUTPUT); //define rgb pinmodes as outputs
   pinMode(green, OUTPUT);
   pinMode(blue, OUTPUT);

}

void loop()
{
  
getTemp(); //run functions in order
servoMatch();
ledSet();
  
  
 
  
}

void getTemp(){
  
  float rawTemp = analogRead(tmp36); //read raw temp data with value 0-1023 based on Vin
  float voltage = (rawTemp/1023.0)*5.0 *1000  ;//divide by anaolg factor (1023) and multiply by Vin (5v) to get voltage output of sensor,then x1000 to get mV
  temp = (voltage - 500)/10; // formula to calculate temp from voltage in mV
  
}

void servoMatch(){
  //servo range is 0-180
  
  float normalizedTemp = (temp +40)/(125 + 45); //normalixe temp data in value between 0-1
  float angle = normalizedTemp * 180; //multiply by 180 to get coorespoinding angle
  servo.write(angle); //write angle to servo 
  
}

void ledSet(){
  
//if else statments that depend on tempreture to give RGB value
  
  if (-40 <= temp && temp <= -10){
 	bVal = 255; rVal = 0; gVal = 0; //blue
  
  }
  
  else if (-10 < temp && temp <= 20){
    gVal = 255; rVal = 0; bVal = 0;//green
  }
  
  else if (20 < temp && temp <= 50){
    gVal = 255; rVal = 255; bVal = 0;//yellow
  }
  
  else if (50 < temp && temp <= 80){
    gVal = 0; rVal = 255; bVal = 255;//purple
  }
  
  else if (80 < temp && temp <= 110){
    gVal = 0; rVal = 255; bVal = 0;//red
  }
  
  else if (110 < temp && temp <= 125){
    gVal = 255; rVal = 255; bVal = 255;//white
  }
  
  analogWrite(red, rVal); //give red RGB value to red PWM input
  analogWrite(green, gVal); // give green RBG value to green PWM input
  analogWrite(blue, bVal); //give blue RGB value to blue PWM input
  
  
}