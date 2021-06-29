
 #include <VirtualWire.h>
 

int pin = 12 ; // Définition du pin
int  decallage;
byte message[VW_MAX_MESSAGE_LEN];

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(pin); // initialisation de la bibliotheque 
  vw_setup(2000);
  vw_rx_start();  // on peut deja recevoir les messages

  Serial.println("recepetion du message decripte !");
 Serial.println("ACAR7");
 
}

void loop() {
 
  byte taille_message = VW_MAX_MESSAGE_LEN;
 
  // On attend de recevoir un message
 // vw_wait_rx_max(3000);

  if (vw_get_message(message, &taille_message)) {
    // On copie le message, qu'il soit corrompu ou non
         cesar_decrypt (decallage, message);
         Serial.println((char*) message); // Affiche le message
         
     
     }
     //Serial.println("#gpe7_10 cm");  
  }



void cesar_decrypt (int decallage, char *message)
{
   decallage = 3;
    int i;
    for(i=0 ; i<strlen(message) ; i++)
        if ('a' <= message[i] && message[i] <= 'z')
            message[i] = 'a' + ((message[i] - 'a') - decallage)%26;
        else
            if ('A' <= message[i] && message[i] <= 'Z')
                message[i] = 'A' + ((message[i] - 'A') - decallage)%26;
            else
               
                if ('0' <= message[i] && message[i] <= '9')
                    message[i] = '0' + ((message[i] - '0') - decallage)%10;
                else
                {
                   
                }
                  
      
    }
