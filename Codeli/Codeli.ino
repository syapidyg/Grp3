//Bibliotheque pour piloter les moteurs I2C
#include "Grove_I2C_Motor_Driver.h"
#include <VirtualWire.h>
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
int pin=12; //Definition du pin

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // initialisation du moniteur de serie a 9600 bauds
  vw_setup(2000);       //initialisation de la bibliothèque VirtualWire à 2000 bauds
   vw_set_tx_pin(pin);   // intialisation du pin de la bibliotheque VirtualWire
  Motor.begin(I2C_Adress);
  pinMode(RS, INPUT);
  pinMode(MS, INPUT);   //activation des ports
  pinMode(LS, INPUT);
  vw_set_tx_pin(pin);   // intialisation du pin de la bibliotheque VirtualWire
  
  Serial.println("Go !");  // affichage du message 'Go' pour le debut de la transmission
}

void loop() {
  // put your main code here, to run repeatedly:

transmitter();
movement();


  }
  
void transmitter(){
    /* ------le Code d'envoie des informations a l'aide de la bibliotheque VirtualWire fait trois choses
*le code attend que l'utilisateur finisse de saisir une chaine de caractères dans le moniteur série.

N.B. La chaine de caractères est lue en mode octets, il est donc nécessaire de fermer cette chaine de caractère par un caractère vide '\0' en fin de chaine.

*le code envoie la chaine de caractères,

*Pour finir, le code attend que la transmission se termine. [/ul]-----*/

//const char *message="Maiva est gentille";
byte message[27];
  byte taille_message = 27;
  // N.B. La constante VW_MAX_MESSAGE_LEN est fournie par la lib VirtualWire
  
 // Lit un message de maximum 76 caractères depuis le port série
  int len = Serial.readBytesUntil('\n', (char*) message, taille_message - 1); 
  if(!len){
    return;// Pas de message
  }
  message[len]='\0';  // Ferme la chaine de caractères
  strcpy(message,"ACAR3:");    // affichage du message qui identifie notre groupe
    vw_send(message,len+1);   // On envoie le message 
    vw_wait_tx();         // On attend la fin de l'envoi
 
  }
  void movement(){
    RS = digitalRead(R);
MS = digitalRead(M);
LS = digitalRead(L);

   if(LS == LOW && MS == HIGH && RS == LOW) {
    // Move Foward
      Motor.speed(MOTOR1, 100);
      Motor.speed(MOTOR2,100);
     
   }  else              
   if(LS == HIGH && MS == HIGH && RS == HIGH) {
      //Stop the car
      Motor.stop(MOTOR1);
      Motor.stop(MOTOR2);
   } 
 else 
   if(LS == LOW && MS == HIGH && RS == HIGH) {
    //Rotation a Droite
      Motor.speed(MOTOR1, 80);
      Motor.speed(MOTOR2,-35);
   }  else 
   if(LS == HIGH && MS == HIGH && RS == LOW) {
    // Rotation a Gauche
      Motor.speed(MOTOR1, -35);
      Motor.speed(MOTOR2,80);
   }  else 
   if(LS == LOW && MS == LOW && RS == HIGH) {
    // Decaler a Droite
      Motor.speed(MOTOR1,80);
      Motor.speed(MOTOR2,-35);
   }else 
   if(LS == HIGH && MS == LOW && RS == LOW) {
    // Decaler a Gauche
      Motor.speed(MOTOR1,-35);
      Motor.speed(MOTOR2,90);
   }else
   if(LS == LOW && MS == LOW && RS == LOW) {
  Motor.speed(MOTOR1, -50);
      Motor.speed(MOTOR2, -50);
} else
 if (LS == HIGH && RS == LOW  && MS == HIGH)   
  {
      /*-----Random movement:Intersection-----*/        
     // Serial.println("Intersection:Random movement");

      
  num=random(3);

  if (num == 0){
      Serial.println("Turn Left");
      Motor.speed(MOTOR1, -35);
      Motor.speed(MOTOR2,90);
  }
  else
  {
      Serial.println("Turn Right");
      Motor.speed(MOTOR1, 90);
      Motor.speed(MOTOR2,-35);
    }
  }
 }
