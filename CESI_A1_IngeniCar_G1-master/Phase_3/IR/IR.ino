#define IR_PROXIMITY_SENSOR A1  //Pin du capteur IR
#define ADC_REF 5               //Détermine le voltage de référence comme étant 5 Volts
                                //Nous utilisons le shield Seeduino notre tension sera donc de 3,3 Volts
                 
float voltage;                  //Voltage du capteur, il permet de calculer une distance, un temps ou encore une vitesse

void setup()
{
    //Initialisation du capteur (délai de 9,6 secondes)
    Serial.begin(2000);
}

//-----------------------------------------------------------------------------

void loop()
{
  voltage = getVoltage();
  Serial.print("sensor voltage  = " );                       
  Serial.print(voltage);
  Serial.print("\n");
  //Délai de 0,5 secondes entre chaque test de réflection
  delay(200 );
}

/*Function: Obtenir un voltage d'un capteur via une pin analogique (A1)*/
/*Parameter: -void                                                     */
/*Return: -float, le voltage du pin analogique (A1)                    */

float getVoltage()              //Fonction permettant d'obtenir le voltage        
{
  int sensor_value;
  int sum;  
                                //Lis la valeur analogique
  for (int i = 0;i < 20;i ++)   //Test 20 fois
  {
    sensor_value = analogRead(IR_PROXIMITY_SENSOR);
    sum += sensor_value;
  }
  sensor_value = sum / 20;
  float voltage;
  voltage = (float)sensor_value*ADC_REF/1024;
  return voltage;
}
