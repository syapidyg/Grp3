




//Bibliotheque pour piloter les moteurs I2C
#include "Grove_I2C_Motor_Driver.h"
// adresse materiel par defaut de la commande
#define I2C_Adress 0x0f
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

///////////////////***** start of Sharp IR
#include <SharpIR.h>

#define IR A0 // define Sharp IR signal pin
#define model 430 // the model of the IR module
/*
 * GP2Y0A02YK0F --> "20150"
 GP2Y0A21YK --> "1080"
 GP2Y0A710K0F --> "100500"
  GP2YA41SK0F --> "430"
 */

SharpIR SharpIR(IR, model);
/////////////////////**** end of Sharp IR

/*-------définir les constantes------*/
   int RS;
   int LS;
   int cont=0;
   int temps;
   int temps_clone;
   int temps_final;
   int Distance;
   int vitesse;
   
void setup() {
        // put your setup code here, to run once:
        Motor.begin(I2C_Adress);
        pinMode(RS, INPUT);
        pinMode(LS, INPUT); 
        Serial.begin(9600);
    }

void loop() {
        // broche
        RS = digitalRead(7);
        LS = digitalRead(3);
        //nombre de tour 
        tour1(cont);tour2(cont);tour3(cont);tour4(cont);
   }

void tour1(int val){
        Motor.speed(MOTOR1,80 );
        Motor.speed(MOTOR2,80);
          //condition de depart 
          while(cont < 4){
            Motor.speed(MOTOR1,80 );
            Motor.speed(MOTOR2,80);
                //start of loop Robojax code for LCD with I2C
            lcd.clear();
            lcd.print("ACAR IR Test");
            lcd.setCursor (0,1); // go to start of 2nd line
            int dis=SharpIR.distance();// gets the distance in cm
            String distance = String(dis);
            distance ="Distance: "+distance+"cm";
            lcd.print(distance);
                //lcd.print(millis() / 1000);
                
            if(dis >= 5){
                Motor.speed(MOTOR1, 17);
                Motor.speed(MOTOR2,17);
                
                if(temps!=0 && temps_clone==0){
                    temps_final=temps;
                    Serial.print("Distance: ");
                    Distance = (temps_final*vitesse)/10;      // formule permettant d'obtenir la distance en cm
                    //Serial.print(temps_final);  
                    Serial.print(Distance);      // affichage de la distance
                    Serial.println(" cm");
                }
       
            }else{
               Motor.speed(MOTOR1, 80);
               Motor.speed(MOTOR2,80);
                  }
  delay(500);
        
          cont =cont +1;
        }
       if(cont==4){
           if(RS == LOW && LS == HIGH){
        Motor.speed(MOTOR1,-45 );
        Motor.speed(MOTOR2,80);
         delay(3000);
        Motor.speed(MOTOR1,80 );
        Motor.speed(MOTOR2,80);
           
          }
        }
        cont=0;
}

  void tour2(int val){
        Motor.speed(MOTOR1,80 );
        Motor.speed(MOTOR2,80);
         
         while(cont < 2){
            Motor.speed(MOTOR1,80 );
            Motor.speed(MOTOR2,80);
            //start of loop Robojax code for LCD with I2C
            lcd.clear();
            lcd.print("ACAR IR Test");
            lcd.setCursor (0,1); // go to start of 2nd line
            int dis=SharpIR.distance();// gets the distance in cm
            String distance = String(dis);
            distance ="Distance: "+distance+"cm";
            lcd.print(distance);
            //lcd.print(millis() / 1000);
            
            if(dis >= 5){
                Motor.speed(MOTOR1, 17);
                Motor.speed(MOTOR2,17);
                
                if(temps!=0 && temps_clone==0){
                    temps_final=temps;
                    Serial.print("Distance: ");
                    Distance = (temps_final*vitesse)/10;      // formule permettant d'obtenir la distance en cm
                    //Serial.print(temps_final);  
                    Serial.print(Distance);      // affichage de la distance
                    Serial.println(" cm");
                }
       
              }else{
                  Motor.speed(MOTOR1, 80);
                  Motor.speed(MOTOR2,80);
              }
              delay(500);
              cont =cont +1;
        }
    if(cont==2){
        if(RS == LOW && LS == HIGH){
            Motor.speed(MOTOR1,-45 );
            Motor.speed(MOTOR2,80);
            delay(3000);
            Motor.speed(MOTOR1,80 );
            Motor.speed(MOTOR2,80);
           
        }
             }
    cont=0;
}

  void tour3(int val){

      Motor.speed(MOTOR1,80 );
      Motor.speed(MOTOR2,80);  
         while(cont < 1){
            Motor.speed(MOTOR1,80 );
            Motor.speed(MOTOR2,80);
            //start of loop Robojax code for LCD with I2C
            lcd.clear();
            lcd.print("ACAR IR Test");
            lcd.setCursor (0,1); // go to start of 2nd line
            int dis=SharpIR.distance();// gets the distance in cm
            String distance = String(dis);
            distance ="Distance: "+distance+"cm";
            lcd.print(distance);
            //lcd.print(millis() / 1000);
            
            if(dis >= 5){
                Motor.speed(MOTOR1, 17);
                Motor.speed(MOTOR2,17);
                
                if(temps!=0 && temps_clone==0){
                    temps_final=temps;
                    Serial.print("Distance: ");
                    Distance = (temps_final*vitesse)/10;      // formule permettant d'obtenir la distance en cm
                    //Serial.print(temps_final);  
                    Serial.print(Distance);      // affichage de la distance
                    Serial.println(" cm");
                 }
       
            }else{
                Motor.speed(MOTOR1, 80);
                Motor.speed(MOTOR2,80);
                }
      delay(500);
      cont =cont +1;
        }
            if(cont==1){
              
                if(RS ==LOW && LS == HIGH){
                    Motor.speed(MOTOR1,-45 );
                    Motor.speed(MOTOR2,80);
                    delay(3000);
                    Motor.speed(MOTOR1,80 );
                    Motor.speed(MOTOR2,80);
           
                }
            }
          cont=0;
    
  }

  void tour4(int val){

      Motor.speed(MOTOR1,80 );
      Motor.speed(MOTOR2,80);  
          
          while(cont <=3){
              Motor.speed(MOTOR1,80 );
              Motor.speed(MOTOR2,80);
              //start of loop Robojax code for LCD with I2C
              lcd.clear();
              lcd.print("ACAR IR Test");
              lcd.setCursor (0,1); // go to start of 2nd line
              int dis=SharpIR.distance();// gets the distance in cm
              String distance = String(dis);
              distance ="Distance: "+distance+"cm";
              lcd.print(distance);
              //lcd.print(millis() / 1000);
              
              if(dis >= 5){
                  Motor.speed(MOTOR1, 17);
                  Motor.speed(MOTOR2,17);
                  
                  if(temps!=0 && temps_clone==0){
                      temps_final=temps;
                      Serial.print("Distance: ");
                      Distance = (temps_final*vitesse)/10;      // formule permettant d'obtenir la distance en cm
                      //Serial.print(temps_final);  
                      Serial.print(Distance);      // affichage de la distance
                      Serial.println(" cm");
                  }
       
              }else{
                  Motor.speed(MOTOR1, 80);
                  Motor.speed(MOTOR2,80);
              }
              delay(500);
              //end of loopcode Robojax code for LCD with I2C
              cont =cont +1;
         }
          
              if(cont==4){
                  if(RS == LOW && LS == HIGH){
                      Motor.speed(MOTOR1,-45 );
                      Motor.speed(MOTOR2,80);
                      delay(3000);
                      Motor.speed(MOTOR1,80 );
                      Motor.speed(MOTOR2,80);
                  }
              }
              cont=0;
}
