#include <VirtualWire.h>

    int RF_TX_PIN = 2; //Définition pin

    void setup()

    {
      vw_set_tx_pin(RF_TX_PIN); // Definir le pin de transmission
      vw_setup(2000); // Transmission en bit par seconde (bauds)
    }
    
    void loop()

    {
      const char *msg = "test"; // Envoie du message 
      vw_send((uint8_t *)msg, strlen(msg));  // Envoie message en 2000ms
      delay(2000);

     }
