//Bibliotheque pour piloter les moteurs I2C
#include "Grove_I2C_Motor_Driver.h"
// adresse materiel par defaut de la commande
#define I2C_Adress 0x0f

/*-------définir les Entrees------*/
int RS ;  // Right Sensor
int MS ;  //Middle Sensor
int LS ;  //Left sensor

void setup() {
  // put your setup code here, to run once:
Motor.begin(I2C_Adress);
  pinMode(RS, INPUT);
  pinMode(MS, INPUT); 
  pinMode(LS, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
RS = digitalRead(8);
MS = digitalRead(4);
LS = digitalRead(2);

if(RS ==0 && MS ==1 && LS == 0){
 Motor.speed(MOTOR1,80 );
 Motor.speed(MOTOR2,80);
}
//m2=rs m1 = ls
if(RS ==0 && MS ==1 && LS ==1){
 Motor.speed(MOTOR1, -45);
 Motor.speed(MOTOR2,80);
}

if(RS ==1 && MS ==1 && LS ==0){
 Motor.speed(MOTOR1,80);
 Motor.speed(MOTOR2,-35);
  }

  if(RS ==0 && MS ==0 && LS ==1){
 Motor.speed(MOTOR1, -35);
 Motor.speed(MOTOR2,80);
}

if(RS ==1 && MS ==0 && LS ==0){
 Motor.speed(MOTOR1,80);
 Motor.speed(MOTOR2,-35);
  }
 }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
