//Bibliotheque pour piloter les moteurs I2C
#include "Grove_I2C_Motor_Driver.h"
// adresse materiel par defaut de la commande
#define I2C_Adress 0x0f

int d = 8;
int d1= 7;
int d2 = 3;
int ed;
int edm;
int edg;

void setup() {
  // put your setup code here, to run once:
Motor.begin(I2C_Adress);
  pinMode(ed, INPUT);
  pinMode(edm, INPUT);
  pinMode(edg, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
ed = digitalRead(d); 
edm = digitalRead(d1);
edg = digitalRead(d2);
/*if(edg == 0 && edm == 0 && ed == 0) {
  Motor.speed(MOTOR1, -50);
      Motor.speed(MOTOR2, -50);
} else */

if( edg == 0 && edm == 1 && ed == 0){
     Motor.speed(MOTOR2, 75);
      Motor.speed(MOTOR1,75);
  }
if(ed == 1 && edm == 1 && edg == 1){
           Motor.speed(MOTOR2,80);
      Motor.speed(MOTOR1,-35);
  }
 if(edg == 0 && edm == 1 && ed == 1) {
   Motor.speed(MOTOR1,80);
      Motor.speed(MOTOR2,-35);
   }
     if(edg == 1 && edm == 1 && ed == 0) {
   Motor.speed(MOTOR2, 80);
      Motor.speed(MOTOR1,-35);
   } 
if(ed == 1 && edm == 0 && edg == 1){
           Motor.speed(MOTOR2,80);
      Motor.speed(MOTOR1,-35);
  }
 if(edg == 0 && edm == 0 && ed == 1) {
   Motor.speed(MOTOR1,80);
      Motor.speed(MOTOR2,-35);
   }
     if(edg == 1 && edm == 0 && ed == 0) {
   Motor.speed(MOTOR2, 80);
      Motor.speed(MOTOR1,-35);
   } 
}
