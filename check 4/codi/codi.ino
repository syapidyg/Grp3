
#include "Grove_I2C_Motor_Driver.h" //Bibliotheque pour piloter les moteurs I2C
#include <FreqCounter.h>  //Inclure la librairie de fréquence
#include <VirtualWire.h>
#define I2C_Adress 0x0f // adresse materiel par defaut de la commande
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

///////////////////***** start of Sharp IR
#include <SharpIR.h>

#define IR A0 // define Sharp IR signal pin
#define model 430 // the model of the IR module
// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:
/*
 * GP2Y0A02YK0F --> "20150"
 GP2Y0A21YK --> "1080"
 GP2Y0A710K0F --> "100500"
  GP2YA41SK0F --> "430"
 */

SharpIR SharpIR(IR, model);
//end of Sharp IR




/*-------définir les constantes et variables------*/
int num;
int decallage;
char *p;
byte checksum;     // initialisation du checksum
int x;
int valeur_id;
unsigned long frq;    //fréquence mesurée
int cnt;              //nombre de mesures réalisées
float trmin;  //vitesse de rotation en tour/min
int distVC;
 float tempts;
 float vlineaire;

/*-------définir les Entrees------*/
int R = 8;   // Right Sensor
int M = 7;  //Middle Sensor
int L = 3; //Left sensor
int RS;
int MS;
int LS;
int pin=12; //Definition du pin
int encoches=2;  //16;       //nombre d encoches de la roue codeuse (1 ou plus)
char check[2];
char trame[20];
char message[20];
char dis[3];

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // initialisation du moniteur de serie a 9600 bauds
  vw_setup(2000);       //initialisation de la bibliothèque VirtualWire à 2000 bauds
   vw_set_tx_pin(pin);   // intialisation du pin de la bibliotheque VirtualWire
  Motor.begin(I2C_Adress);
  pinMode(RS, INPUT);
  pinMode(MS, INPUT);   //activation des ports
  pinMode(LS, INPUT);
  
  // Robojax code for LCD with I2C
  // initialize the LCD, 
  lcd.begin();
 
  // Turn on the blacklight and print a message.
  lcd.backlight();
  // Robojax code for LCD with I2C
  
  Serial.println("Go !");  // affichage du message 'Go' pour le debut de la transmission
  x= movement();

 sprintf(dis,"%d",x);      // sauvegarde et affichage de l'entier x qui represente la distance
 
}

void loop() {
  // put your main code here, to run repeatedly:
int distVC=SharpIR.distance();// gets the distance in cm
  vitesse() ;
transmitter();
movement(distVC ,vlineaire);
cesar_crypted(decallage, message);      // fonction de decallage


  }
  
void transmitter(){
    /* ------le Code d'envoie des informations a l'aide de la bibliotheque VirtualWire fait trois choses
*le code attend que l'utilisateur finisse de saisir une chaine de caractères dans le moniteur série.

N.B. La chaine de caractères est lue en mode octets, il est donc nécessaire de fermer cette chaine de caractère par un caractère vide '\0' en fin de chaine.

*le code envoie la chaine de caractères,

*Pour finir, le code attend que la transmission se termine. [/ul]-----*/

strcpy(message,"ACAR3:");    // affichage du message qui identifie notre groupe
//strcat(message,code);           //concatenation  du message et du code de la distance

cesar_crypted(decallage, message);      // fonction de decallage
constante_trame(message, trame);            //  sauvegarde et affichage des trames
checksum=calculofChecksum(trame);           // calcul du checksum
Serial.println((int) checksum);
strcat(trame, ",");         // separateur des trames
CheckSum(checksum);             // appelation du checksum

Serial.println("M");
Serial.println(trame); //on affiche la trame        // affichage des trames au moniteur de serie

vw_send(trame,75); // On envoie la trame
vw_wait_tx();
  }
  
  void vitesse() {
  // Attendre le signal
  //compensation (étalonnage)
  FreqCounter::f_comp=10;   // Cal Value / Calibrate with professional Freq Counter

  // 10, 100 ou 1000 ms pour une résolution de 100, 10 et 1 Hz 
  FreqCounter::start(100);  // 100 ms Gate Time

  // Attendre jusqu'à avoir un comptage terminé
  while (FreqCounter::f_ready == 0)
 
 // Afficher la mesure de fréquence (et de rotation)
  frq=FreqCounter::f_freq;
  trmin = frq/encoches*60;  //Vitesse de rotation en tour/min
  Serial.print(" vitesse lineaire: ");
  float trs = trmin/60;
  vlineaire = 2*3.14*0.04*trs;
  return vlineaire;
  delay(300);
} 
  void movement(int variable , float variable1){
    RS = digitalRead(R);
MS = digitalRead(M);
LS = digitalRead(L);
 //capture de la distance 


      //start of loop Robojax code for LCD with I2C
  lcd.clear();
  lcd.print("--GROUPE3--");
  lcd.setCursor (0,1); // go to start of 2nd line
  //lcd.print(millis() / 1000);

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
  while(temps_final == 0){
    if(variable >= 5){
    Motor.speed(MOTOR1, 17);
    Motor.speed(MOTOR2,17);
    unsigned long currentMillis = millis();
    tempts = currentMillis;
        float temptsR = tempts/1000;
    float interval = variable1*temptsR;
    //affichage lcd
   String intervale = String(interval);
    Serial.print("Distance:" +intervale+"cm");
  }
    String variable1e = String(variable1);
     lcd.print("vitesse" +variable1e+"cm/s");
  delay(300);
 //end of loopcode Robojax code for LCD with I2C
  }
 }
 void cesar_crypted (int decallage, char *message)//fonction de cryptage
{
   decallage = 3;
    int i;
    for(i=0 ; i<strlen(message) ; i++)
        if ('a' <= message[i] && message[i] <= 'z')
            message[i] = 'a' + ((message[i] - 'a') + decallage)%26;
        else
            if ('A' <= message[i] && message[i] <= 'Z')
                message[i] = 'A' + ((message[i] - 'A') + decallage)%26;
            else
               
                if ('0' <= message[i] && message[i] <= '9')
                    message[i] = '0' + ((message[i] - '0') + decallage)%10;
                else
                {
                   
                }
               
}
void constante_trame(char *message, char *trame){//caractère de début de trame

  strcpy(trame, "#");
  strcat(trame, message);
 
}

byte calculofChecksum (char *p){   // fonction calculant le checksum
    byte checksum = 0;
  // on commence a calculer après le '#' situé dans p[0]
  int i = 1;
  /* on boucle tant que l'on ne rencontre pas :
    $: séparateur du checksum (optionnel, peut ne pas être là)
  \r ou \n : marqueur de fin
   \0 : fin de chaine en C au cas où le marqueur de fin non présent*/
  while ( (p[i] != '$') && (p[i] != '\n') && (p[i] != '\r')
       && (p[i] != '\0') )
  {
    checksum = checksum ^ (byte)p[i];
    i++;
  }
  return checksum;
}

void CheckSum(byte checksums){
  int tab;
  tab = (int)checksums;
  char check[2];
  sprintf(check, "%d", tab);
  trame[8]= check[0];
  trame[9] = check[1];
}

void increment(int valeur_id){
  
  char check[2];
  sprintf(check, "%d", valeur_id);
  if(valeur_id>=10){
    trame[7]=check[0];
   
    trame[8]=check[1];
  }
  else {
    trame[8]= check[0];
  }
 
}
