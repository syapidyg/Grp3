#include "Grove_I2C_Motor_Driver.h"

/*-------définir les entrées------*/
#define  LS 2    //Left sensor
#define  MS 7   //Middle Sensor
#define  RS 4  // Right Sensor

/*-------définir les sorties------*/
#define LM1 11     // moteur gauche
#define LM2 10     // moteur gauche
#define RM1 9     // moteur droit
#define RM2 6      // moteur droit

/*-------définir les constantes------*/
const int u=2;
const int l=1;
#define I2C_ADRESSE 0x0f

#define DESTINATION 8

void setup() {
  Serial.begin(9600);
  pinMode ( LS ,  INPUT );
  pinMode ( RS ,  INPUT );
  pinMode ( MS ,  INPUT );
  pinMode ( LM1 ,  OUTPUT );
  pinMode ( LM2 ,  OUTPUT );
  pinMode ( RM1 ,  OUTPUT );
  pinMode ( RM2 ,  OUTPUT );
  //Motor.begin(I2C_ADRESSE);
  
  

}

void loop() {
 if (( digitalRead ( LS ) == LOW )  &&  ( digitalRead ( RS ) == LOW )&& (digitalRead (MS)== HIGH))     // Condition_1 FORWARD
{   
    Serial.println("Move Forward"); 
    MoveFoward ();
  }
  
  if (( digitalRead ( LS ) == LOW )  &&  ( digitalRead ( RS ) == LOW ) && (digitalRead(MS)==LOW))   //CONDITION-2 STOP
  {
       Serial.println("Back Off");
      Back Off();
    }
  if (( digitalRead ( LS ) == LOW )  &&  ( digitalRead ( RS ) == HIGH )/*&& (digitalRead (MS)== LOW)*/)   // RIGHT
  {
     Serial.println("Turn Right");
    Turn Right ();
  }
  if (( digitalRead ( LS ) == HIGH )  &&  ( digitalRead ( RS ) == LOW ))  //LEFT
{
    Serial.println("Turn Left");
    Turn Left ();
  }
  /*-----Random movement:Intersection-----*/
 if (( digitalRead ( LS ) == HIGH )  &&  ( digitalRead ( RS ) == HIGH ) && (digitalRead(MS)==LOW))   //CONDITION-2 STOP
  {
      Serial.println("Intersection:Random movement");
      delay(1000);
      RandomMovement();
    }
    delay(1000);
  
}
    void MoveFoward()
    {
     digitalWrite( LM1 ,  HIGH );
     digitalWrite( LM2 ,  LOW);
     digitalWrite( RM1 ,  HIGH );
     digitalWrite( RM2 ,  LOW);
     delay ( 20 );
}

void Turn Left ()
{
     digitalWrite( LM1 ,  LOW );
     digitalWrite( LM2 ,  LOW);
     digitalWrite( RM1 ,  HIGH );
     digitalWrite( RM2 ,  LOW);
    delay ( 30 ); 
}

void  Turn Right ()
{
     digitalWrite( LM1 ,  HIGH );
     digitalWrite( LM2 ,  LOW);
     digitalWrite( RM1 ,  LOW);
     digitalWrite( RM2 ,  LOW);
    delay ( 30 );
}

void Stop()
{
     digitalWrite( LM1 ,  LOW );
     digitalWrite( LM2 ,  LOW);
     digitalWrite( RM1 ,  LOW );
     digitalWrite( RM2 ,  LOW);
    delay ( 20 );
} 
void RandomMovement()
{
  srand(time(0));
  num=(rand()%(u-l+1)+1);

  if (num == 1){
    Serial.println("Turn Left");
    Turn Left();
  }
  if (num == 2)
  {
    Serial.println("Turn Right");
    Turn Right();
  }
  void Back Off()
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    }
}
    
  
  
