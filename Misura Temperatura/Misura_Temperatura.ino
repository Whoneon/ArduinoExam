/*
Stavolta mi sono imposto di trovare la relazione matematica tra la resistenza e la temperatura, quindi il programma fa tutto da solo!
*/
#include <SPI.h>
#include <SD.h>

File dati;
int valore;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.print("Controllo la SD...");
  if (!SD.begin(4)) {
    Serial.println("errore!");
    while (1);
  }
  Serial.println("ci siamo!");  
  SD.remove("DATI_TEMPERATURA.TXT");
  delay(5000);
    Serial.print("Inizio a scrivere sul file di testo ...");
  dati = SD.open("DATI_TEMPERATURA.TXT", FILE_WRITE);
  //se ho creato/trovato il file, scrivo un valore al secondo per 24h
  digitalWrite(LED_BUILTIN, HIGH);
  if (dati) {
    for (int i = 0; i <=86400; i++) { //Anche qui scarteremo il primo valore perchè influenzato dalle fluttuazioni elettriche nel pin 5V
       valore = analogRead(A0);
double temperatura = log(10000.0 * ((1024.0 / valore - 1))); //Calcolo il valore della resistenza equivalente del circuito
temperatura = ( 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temperatura * temperatura )) * temperatura ) - 273.15) / 2; //Applico i parametri di Steinhart-Hart ricavati in precedenza
       dati.println(temperatura);
       delay(1000);
  }
    dati.close();
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("fine.");
  } 
  else {
    Serial.println("errore nell'aprire il file!");
  }
}

void loop() {
 //Anche qui, il codice deve girare una sola volta, dunque lo scrivo nel void setup
}
