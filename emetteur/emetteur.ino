#include <VirtualWire.h>


void setup(){
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_tx_pin(12);
  pinMode(7,INPUT_PULLUP);
  Serial.println("Go !"); 
}
void loop(){
  byte message[27];
  byte taille_message=27;

 
  int len = Serial.readBytesUntil('\n', (char*) message, taille_message - 1); 
  if(!len){
    return;
  }
  message[len]='\0';
  strcpy(paquet, "Hello World!");
    vw_send(message,len+1);
    vw_wait_tx();
}
