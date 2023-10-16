const int numPins = 3; // Anzahl der verfügbaren Pins (0 bis 5)
int fadePins[numPins] = {0, 1, 4}; // Array mit den Pin-Nummern
const int Pin1 = 0; // Anzahl der verfügbaren Pins (0 bis 5)
const int Pin2 = 1; // Anzahl der verfügbaren Pins (0 bis 5)
const int Pin3 = 4; // Anzahl der verfügbaren Pins (0 bis 5)

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(fadePins[i], OUTPUT);
  }
  randomSeed(analogRead(0)); // Zufallsgenerator initialisieren
  }

  int fadeAmount1 = 6 ; // Schrittgröße für das Ein- und Ausfaden
  int fadeAmount2 = 8 ; // Schrittgröße für das Ein- und Ausfaden
  int fadeAmount3 = 10 ; // Schrittgröße für das Ein- und Ausfaden

  int fadeValue1 = 3;
  int fadeValue2 = 31;
  int fadeValue3 = 63;

void loop() {
  int zufallsZahl = random(3);

  int newAmount;
  if (zufallsZahl == 0) {
    newAmount = 4;
  } else if (zufallsZahl == 1) {
    newAmount = 8;
  } else {
    newAmount = 16;
  }

  
  if (fadeValue1 >= 240) {
    fadeAmount1 = -newAmount;
  } else if (fadeValue1 <= 15) {
    fadeAmount1 = newAmount;
  }
  
  if (fadeValue2 >= 240) {
    fadeAmount2 = -newAmount;
  } else if (fadeValue2 <= 15) {
    fadeAmount2 = newAmount;
  }
  
  if (fadeValue3 >= 240) {
    fadeAmount3 = -newAmount;
  } else if (fadeValue3 <= 15) {
    fadeAmount3 = newAmount;
  }
  
  fadeValue1 = fadeValue1 + fadeAmount1;
  fadeValue2 = fadeValue2 + fadeAmount2;
  fadeValue3 = fadeValue3 + fadeAmount3;

  analogWrite(Pin1, fadeValue1); // Helligkeit Pin 1 ändern
  analogWrite(Pin2, fadeValue2); // Helligkeit Pin 2 ändern
  analogWrite(Pin3, fadeValue3); // Helligkeit Pin 3 ändern

  delay(30); // Warte kurz zwischen den Schritten, um das Einblenden sichtbar zu machen
}
