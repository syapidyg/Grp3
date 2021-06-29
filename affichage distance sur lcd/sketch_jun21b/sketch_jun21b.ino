
 /*
 * Sharp IR (infrared) distance measurement module with LCD1602 and I2C for Arduino
 * Measures the distance in cm.

 * Watch the video https://youtu.be/RHgMwtKLEnE

 *  * 

Original library: https://github.com/guillaume-rico/SharpIR


// Written and updated by Ahmad Shamshiri for Robojax.com
// on Jan 03, 2018 at 20:01 in Ajax, Ontario, Canada
Nejrabi
* Get this code and other Arduino codes from Robojax.com
Learn Arduino step by step in structured course with all material, wiring diagram and library
all in once place. Purchase My course on Udemy.com http://robojax.com/L/?id=62

If you found this tutorial helpful, please support me so I can continue creating 
content like this. You can support me on Patreon http://robojax.com/L/?id=63

or make donation using PayPal http://robojax.com/L/?id=64

 *  * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/


#include "Grove_I2C_Motor_Driver.h"
// adresse materiel par defaut de la commande
#define I2C_Adress 0x0f

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

///////////////////***** start of Sharp IR
#include <SharpIR.h>

#define IR A0 // define Sharp IR signal pin
#define model 430 // the model of the IR module
// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:
/*
 * GP2Y0A02YK0F --> "20150"
 GP2Y0A21YK --> "1080"
 GP2Y0A710K0F --> "100500"
  GP2YA41SK0F --> "430"
 */

SharpIR SharpIR(IR, model);
/////////////////////**** end of Sharp IR
 int dist;
 float t;
 float dr;
void setup()
{
  // Robojax code for LCD with I2C
  // initialize the LCD, 
  lcd.begin();
 
  // Turn on the blacklight and print a message.
  lcd.backlight();
  // Robojax code for LCD with I2C
}

void loop()
{
  
  int dist=SharpIR.distance();// gets the distance in cm
   distance(dist);
}

void distance(int dis){
  //capture de la distance 


      //start of loop Robojax code for LCD with I2C
  lcd.clear();
  lcd.print("ACAR IR Test");
  lcd.setCursor (0,1); // go to start of 2nd line
  //lcd.print(millis() / 1000);
  if(dis >= 5){
    Motor.speed(MOTOR1, 17);
    Motor.speed(MOTOR2,17);
    unsigned long currentMillis = millis();
    t = currentMillis;
  }else{
    Motor.speed(MOTOR1, 70);
    Motor.speed(MOTOR2,70);
    }
    float t1=t*1000;
    //int distancer = v*t;
    //affichage lcd
    float dr = t1*1;
    String distance = String(dis);
    distance ="Distance: "+distance+"cm"+dr+"s";
    lcd.print(distance);
  delay(500);
 //end of loopcode Robojax code for LCD with I2C
}

 
