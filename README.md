# CansatTraining2022

Name: Mahdi Hassen

///////////////////////////////////////////////////////////////////////////////////////////

The ino file includes servo.h for servo control and declares temp as a global float. It also sets up the servo with the name "servo", initializes the RGB values at 0 and assigns RGB pins as follows:

red -> pin 3
green -> pin 6
blue -> pin 5

The setup function attach's the servo to pin 9, and declares the RGB pins as outputs.


The loop function has 3 functions:

getTemp()
servoMatch()
ledSet()

below is an explination of each function

getTemp():

  The function reads the analog output of the TMP36 sensor as a value from 0-1023.
  This value is then turned into a voltage by dividing by 1023, then muktiplying by 5v (the input voltage) we can then multiply by 1000 to get the voltage in units of mV.
  Then we use the formula (Voltage-500)/10 to get a tempreture which we store in the "temp" var.
  
servoMatch():

  This funtion first normalizes the temp into a value of 0-1, this value is then multiplied by 180 to get an angle between 0-180 depending on the temp var.
we then feed this angle into the servo using the servo.write method.

ledSet():
  This funtion uses previously declared rVal, gVal and bVal values as RGB values for the LED (where 255 is max and 0 is min). Then there are if else statments which implement the following logic:
  
  Temperature Range 	Colour
  -40 <= Temp <= -10 	Blue
  -10 < Temp <= 20 	  Green
  20 < Temp <= 50 	  Yellow
  50 < Temp <= 80 	  Purple
  80 < Temp <= 110 	  Red
  110 < Temp <= 125 	White
  
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Note: Code is also well commented in INO file
