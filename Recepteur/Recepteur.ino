#include <VirtualWire.h>
int receive_pin = 11 ; //initialisation du pin de l'emetteur
void setup(){
  Serial.begin(9600);
  vw_setup(2000);  //initialisation de la bibliothèque VirtualWire à 2000 bauds
  vw_set_rx_pin(receive_pin);  // intialisation du pin de la bibliotheque VirtualWire
  vw_rx_start();   // On peut maintenant recevoir des messages

  
  Serial.println("recepetion du message decrypte !");
 Serial.println("GO!");  // affichage du message 'Go' pour le debut de la transmission
 
}
void loop(){
  receiver();
}
void receiver(){
  byte message[VW_MAX_MESSAGE_LEN];
  byte taille_message = VW_MAX_MESSAGE_LEN;
  // N.B. La constante VW_MAX_MESSAGE_LEN est fournie par la lib VirtualWire

  /* 
   La variable "taille_message" doit impérativement être remise à 
   la taille du buffer avant de pouvoir recevoir un message. 
   Le plus simple est d'utiliser une variable locale pour ne pas
   avoir à réassigner la valeur à chaque début de loop().
   */
  // On attend de recevoir un message
  vw_wait_rx();

  if(vw_get_message(message,&taille_message)){
    // On copie le message, qu'il soit corrompu ou non
    int i;
        // Message avec contrôle reçu en lettre
        Serial.print("ACAR3: "); // Permet d'afficher "ACAR" devant le message reçu
        for(i = 0; i < message; ++i)
        {
          Serial.write(message[i]);// On reçois le message en lettre
          Serial.print(" ");
 
        }
        Serial.println("");
      }
}
