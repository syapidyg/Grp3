 #include <VirtualWire.h>
 
    int RF_RX_PIN = 2; // Définition du pin
 
    void setup()
    {
      Serial.begin(9600);// Ouvre le port série, définit le débit de données à 9600 bps 
      Serial.println("setup"); // Permet de lire "setup", et permet de rentrer dans la boucle
      vw_set_rx_pin(RF_RX_PIN);  // Définir le pin
      vw_setup(2000); // Transmission en bit par seconde (bauds)
      vw_rx_start(); // Commencement du receveur
    }
 
    void loop()
    {
      uint8_t mess[VW_MAX_MESSAGE_LEN]; //Permet de mettre "mess" en nombre max d'octet
      uint8_t message = VW_MAX_MESSAGE_LEN;//Permet de mettre "message" en nombre max d'octet
      if(vw_get_message(mess, &message)) // on ne bloque ni les entrées ni les sorties
      {
        int i;
        // Message avec contrôle reçu en lettre
        Serial.print("ACAR: "); // Permet d'afficher "ACAR" devant le message reçu
        for(i = 0; i < message; ++i)
        {
          Serial.write(mess[i]);// On reçois le message en lettre
          Serial.print(" ");
 
        }
        Serial.println("");
      }
    }
