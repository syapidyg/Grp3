//Bibliotheque pour piloter les moteurs I2C
#include "Grove_I2C_Motor_Driver.h"
// adresse materiel par defaut de la commande
#define I2C_Adress 0x0f
/*-------définir les constantes------*/
int num;
/*-------définir les Entrees------*/
int R = 8;   // Right Sensor
int M = 7;  //Middle Sensor
int L = 2; //Left sensor
int RS;
int MS;
int LS;

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
RS = digitalRead(R);
MS = digitalRead(M);
LS = digitalRead(L);                                                                                                                                                                                                                            

 /*if(edg == 0 && edm == 0 && ed == 0) {
  Motor.speed(MOTOR1, -50);
      Motor.speed(MOTOR2, -50);
      */
//} else 
  // if(LS == LOW && MS == HIGH && RS == LOW) {
    // Move Foward
      Motor.speed(MOTOR1, 80);
      Motor.speed(MOTOR2,80);
     
//   }  else              
   if(LS == HIGH && MS == HIGH && RS == HIGH) {
      
      Motor.stop(MOTOR1);
      Motor.stop(MOTOR2);
//   }  else 
   if(LS == LOW && MS == HIGH && RS == HIGH) {
    //Rotation a droite
      Motor.speed(MOTOR1, 75);
      Motor.speed(MOTOR2,-35);
//   }  else 
   if(LS == LOW && MS == LOW && RS == HIGH) {
    // Rotation a GAUCHE
      Motor.speed(MOTOR1, 75);
      Motor.speed(MOTOR2,-45);
//   }  else 
   if(LS == HIGH && MS == LOW && RS == LOW) {
    // Rotation a GAUCHE
      Motor.speed(MOTOR1,-35);
      Motor.stop(MOTOR2,75);
//   }else 
   if(LS == LOW && MS == HIGH && RS == HIGH) {
    // Rotation a droite
      Motor.speed(MOTOR1,75);
      Motor.stop(MOTOR2,-35);
//   }else
 if (LS == HIGH && RS == LOW  && MS == HIGH)   
  {
      /*-----Random movement:Intersection-----*/        
     // Serial.println("Intersection:Random movement");

      
  num=random(3);

  if (num == 1){
      Serial.println("Turn Left");
      Motor.speed(MOTOR1, -35);
      Motor.speed(MOTOR2,75);
  }
  if (num == 2)
  {
      Serial.println("Turn Right");
      Motor.speed(MOTOR1, 75);
      Motor.speed(MOTOR2,-35);
    }
  }
}
 
