#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd1(0x27, 16, 2);  // Set the LCD I2C address

void setup() {
Wire.begin();
 lcd1.begin();                                     //lcd1.print("1_pret");
 lcd1.clear();
lcd1.noBacklight();
lcd1.setCursor(0, 0);lcd1.print("---GROUPE 3---- "); //affichage sur le LCD dans l'habitacle 
}

void loop() {
lcd1.backlight();

lcd1.noBacklight();  // put your main code here, to run repeatedly:

}
