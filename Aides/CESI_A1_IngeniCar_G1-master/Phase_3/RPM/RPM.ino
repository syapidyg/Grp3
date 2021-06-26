#include <FreqCounter.h>  //Inclure la librairie de fréquence

// Variables utilisées
unsigned long frq;    //fréquence mesurée
int cnt;              //nombre de mesures réalisées
int encoches=2;  //16;       //nombre d encoches de la roue codeuse (1 ou plus)
float trmin;  //vitesse de rotation en tour/min

// Initialisation
void setup() {
  Serial.begin(9600);   //connection au port série
  Serial.println("Frequencemetre");
}

// === Boucle de mesures
void loop() {
  // Attendre le signal
  //compensation (étalonnage)
  FreqCounter::f_comp=10;   // Cal Value / Calibrate with professional Freq Counter

  // 10, 100 ou 1000 ms pour une résolution de 100, 10 et 1 Hz 
  FreqCounter::start(100);  // 100 ms Gate Time

  // Attendre jusqu'à avoir un comptage terminé
  while (FreqCounter::f_ready == 0)
 
 // Afficher la mesure de fréquence (et de rotation)
  frq=FreqCounter::f_freq;
  Serial.print(cnt++);
  Serial.print("  Freq (Hz): ");
  Serial.print(frq);
 
  trmin = frq/encoches*60;  //Vitesse de rotation en tour/min
  Serial.print("  tour/min: ");
  Serial.println(trmin);
  delay(600);
} 
