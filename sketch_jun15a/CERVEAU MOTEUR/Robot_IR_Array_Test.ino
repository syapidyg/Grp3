#include <Servo.h>

Servo monServo;  // on crée l'objet monServo

void setup()
{
    monServo.attach(3); // on définit le Pin utilisé par le servomoteur
    monServo.write(1);
}

void loop()
{
  monServo.write(1); 
  delay(50);
  monServo.write(50); 
  delay(50);
  monServo.write(90); 
  delay(50);
  monServo.write(120); 
  delay(50);
   monServo.write(150); 
  delay(50);
    monServo.write(170); 
  delay(50);
   monServo.write(175); 
  delay(50);
}
 
