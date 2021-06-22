//Bibliotheque pour piloter les moteurs I2C
#include "Grove_I2C_Motor_Driver.h"
// adresse materiel par defaut de la commande
#define I2C_Adress 0x0f
/*-------définir les constantes------*/
int num;
/*-------définir les Entrees------*/
int R = 8;   // Right Sensor
int M = 7;  //Middle Sensor
int L = 3; //Left sensor
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

   if(MS == HIGH) //Si le capteur du centre détecte du noir
  {
    if (LS == HIGH && RS == LOW) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
    {
      Motor.speed(MOTOR1, -35);
      Motor.speed(MOTOR2,80);
    }
    else if (LS == LOW && MS == LOW && RS == HIGH) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
    {
        Motor.speed(MOTOR1,80);
      Motor.speed(MOTOR2,-35);
    }
    else //Si les conditions plus haut ne s'appliquent pas, continuer tout droit
    {
       Motor.speed(MOTOR1, 90);
      Motor.speed(MOTOR2,90);
    }
  }
  else //Si le capteur du centre détecte du blanc
  {
    if (LS == HIGH && MS == HIGH && RS == LOW) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
    {
       Motor.speed(MOTOR1, -35);
      Motor.speed(MOTOR2,80);
    }
    else if (LS == LOW && MS == LOW && RS == HIGH) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
    {
      Motor.speed(MOTOR1,80);
      Motor.speed(MOTOR2,-35);
    }
    else //Si les conditions plus hautdne s'appliquent pas, reculer
    {
      Motor.speed(MOTOR1, -90);
      Motor.speed(MOTOR2,-90);
    }
  }
}
 
