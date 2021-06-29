#include <VirtualWire.h>
//#include <VirtualWire_Config.h>
#include <SharpIR.h>
#include <Grove_I2C_Motor_Driver.h>
#define I2C_ADDRESS 0x0f

#define IR A0 // define signal pin
#define model 1080 // used 1080 because model GP2Y0A21YK0F is used

// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            430 for GP2Y0A41SK  
/*
2 to 15 cm GP2Y0A51SK0F  use 1080
4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
10 to 80 cm GP2Y0A21YK0F  use 1080
10 to 150 cm GP2Y0A60SZLF use 10150
20 to 150 cm GP2Y0A02YK0F use 20150
100 to 550 cm GP2Y0A710K0F  use 10055
 */
 
int capteurgauche = 5;
int capteurmil = 7;
int capteurdroit = 8;
int ed;
int mi;
int eg;
int Distance=0;
double vitesse=0.3;
int compteur=0;
int a=0;
int b=0;
int temps=0;
int temps_final=0;
boolean isVide=false;
int x;
char y;
int pin =11;      // initialisation du pin de l'emetteur
char code[3];
int decallage;
char message[20];
char trame[20];
int c = 0;
char *p;
byte checksum;     // initialisation du checksum
char check[2];
int valeur_id;

SharpIR SharpIR(IR, model);     // initialisation du pin du capteur de distance sur la broche A0 et du modele du capteur

void setup() {

 Serial.begin(9600);    // initialisation du moniteur de serie a 9600 bauds
Motor.begin(I2C_ADDRESS);
pinMode(5,INPUT);
pinMode(7,INPUT);     //activage des ports
pinMode(8,INPUT);


 vw_set_tx_pin(pin);    // intialisation du pin de la bibliotheque VirtualWire
 vw_setup(2000);

 Serial.println("Go !");       // affichage du message 'Go' pour le debut e la transmission
 x= distance();

 sprintf(code,"%d",x);      // sauvegarde et affichage de l'entier x qui represente la distance
 
 
/* Serial.begin(I2C_ADDRESS);
 Motor.speed(MOTOR1, 50);
 Motor.speed(MOTOR2, 50);*/
 
}

void loop() {
   
ed = digitalRead(capteurdroit);
mi = digitalRead(capteurmil);
eg = digitalRead(capteurgauche);

strcpy(message,"ACAR7");    // affichage du message qui identifie notre groupe
strcat(message,code);           //concatenation  du message et du code de la distance

cesar_crypt(decallage, message);      // fonction de decallage
const_trame(message, trame);            //  sauvegarde et affichage des trames
checksum=calculChecksum(trame);           // calcul du checksum
Serial.println((int) checksum);
strcat(trame, ",");         // separateur des trames
CheckSum(checksum);             // appelation du checksum

Serial.println("a");
Serial.println(trame); //on affiche la trame        // affichage des trames au moniteur de serie

vw_send(trame,75); // On envoie la trame
vw_wait_tx();
       
}


int distance()      // methode de la distance
{
    // si uniquement le capteur du milieu est actif alors la voiture continue tout droit
if(ed == LOW && mi == HIGH && eg == LOW){

  Serial.println(ed);
  Motor.speed(MOTOR1, 70);
  Motor.speed(MOTOR2, 70);
}

  // si uniquement le capteur de gauche est actif alors la voiture tourne à gauche
else if(ed == LOW && mi == LOW && eg == HIGH){

  Serial.println(eg);
  Motor.speed(MOTOR1, -60);
  Motor.speed(MOTOR2, 70);
}

  // si uniquement le capteur de droite est actif alors la voiture tourne à droite
else if(ed == HIGH && mi == LOW && eg == LOW){

  Serial.println(ed);
  Motor.speed(MOTOR1, 70);
  Motor.speed(MOTOR2, -60);
}

 
 // si le capteur de milieu ou celui de gauche on part à gauche
else if(ed == LOW && mi == HIGH && eg == HIGH){

  Serial.println(mi);
  Serial.println(eg);
  Motor.speed(MOTOR1, -60);
  Motor.speed(MOTOR2, 70);
}
// si le capteur de milieu ou celui de droit on part à droite
else if(ed == HIGH && mi == HIGH && eg == LOW){

  Serial.println(mi);
  Serial.println(ed);
  Motor.speed(MOTOR1, 70);
  Motor.speed(MOTOR2, -60);
}

// si le capteur de gauche ou celui de droit on part à gauche
/*else if(ed == LOW && mi == HIGH && eg == LOW){

  Serial.println(digitalRead(capteurmil));
  Serial.println(digitalRead(capteurdroit));
  Motor.speed(MOTOR1, -60);
  Motor.speed(MOTOR2, 70);
}
// si tous les capteurs sont actifs on va tout droit
else if(HIGH == digitalRead(capteurmil) && HIGH == digitalRead(capteurgauche) && HIGH == digitalRead(capteurdroit)){

  Serial.println(digitalRead(capteurgauche));
  Serial.println(digitalRead(capteurdroit));
   Serial.println(digitalRead(capteurmil));
  Motor.speed(MOTOR1, 500);
  Motor.speed(MOTOR2, 500);
}*/
// si le capteur de gauche et de droite est actif alors on part à gauche

else if(ed == HIGH && mi == LOW && eg == HIGH){

  Serial.println(eg);
  Serial.println(ed);
 //  Serial.println(digitalRead(capteurmil));
  Motor.speed(MOTOR1, -60);
  Motor.speed(MOTOR2, 70);
}

// si le capteur de gauche et de droite est actif alors on part à gauche

else if(ed == HIGH && mi == HIGH && eg == HIGH){

  Motor.stop(MOTOR1);
  Motor.stop(MOTOR2);
}

/*
  Motor.begin(I2C_ADDRESS);  // initialisation de la bibliotheque Grove_Motor
 Motor.speed(MOTOR1,-65);      
 Motor.speed(MOTOR2,65);
  */
 
  while(temps_final == 0){
  unsigned long startTime=millis();  // takes the time before the loop on the library begins
  int time_T= millis();
  int dis=SharpIR.distance();  // this returns the distance to the object you're measuring
     
        if(dis > 9){         // condition de la didstance du capteur à l'objet
         Serial.println("vide");     // tant que l'objet est distant de plus de 9cm alors afficher le vide
         Serial.print("  ");
         a++;
         isVide=true;
        }
        else{
         Serial.println("objet");   // sinon afficher qu'il a detecté un objet
         Serial.print("  ");
         compteur=time_T;
         isVide=false;
        }
       
        int temps_clone;   // intervalle de temps separant 2 objets et permettant de trouver la distance
       
         if(isVide){
          temps_clone=millis()-compteur;
          temps=temps_clone;
         } else{
          temps_clone=0;
         }

         if(temps!=0 && temps_clone==0){
           temps_final=temps;
     
          Serial.print("Distance: ");
          Distance = (temps_final*vitesse)/10;      // formule permettant d'obtenir la distance en cm
          //Serial.print(temps_final);  
         Serial.print(Distance);      // affichage de la distance
         Serial.println(" cm");
         }
       
}

         return Distance;  
}        
void cesar_crypt (int decallage, char *message)//fonction de cryptage
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

void const_trame(char *message, char *trame){//caractère de début de trame

  strcpy(trame, "$");
  strcat(trame, message);
 
}

byte calculChecksum (char *p){   // fonction calculant le checksum
    byte checksum = 0;
  // on commence a calculer après le '$' situé dans p[0]
  int i = 1;
  // on boucle tant que l'on ne rencontre pas :
  // * : séparateur du checksum (optionnel, peut ne pas être là)
  // \r ou \n : marqueur de fin
  // \0 : fin de chaine en C au cas où le marqueur de fin non présent
  while ( (p[i] != '*') && (p[i] != '\n') && (p[i] != '\r')
       && (p[i] != '\0') )
  {
    checksum = checksum ^ (byte)p[i];
    i++;
  }
  return checksum;
}

void CheckSum(byte SommeDecontrole){
  int tab;
  tab = (int)SommeDecontrole;
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
