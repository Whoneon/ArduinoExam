/*
Uso questo codice per misurare la luce ambientale tramite una fotoresistenza. In realtà sarebbe più corretto dire che misuro la caduta di potenziale ai capi
della resistenza, ma esistendo una correlazione tra le due grandezze, basterebbe studiare il tipo di funzione che lega le due grandezze per poter passare
dall'una all'altra...
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
  pinMode(LED_BUILTIN, OUTPUT); //Parametro di controllo in preparazione
  Serial.print("Controllo la SD...");
  if (!SD.begin(4)) { //Per sicurezza, verifico che la scheda sia inserita e scrivibile
    Serial.println("errore!");
    while (1);
  }
  Serial.println("ci siamo!");  
  SD.remove("DATI_LUCE.TXT"); //Cancello il precedente file (se presente)
  delay(5000);
    Serial.print("Inizio a scrivere sul file di testo ...");
  dati = SD.open("DATI_LUCE.TXT", FILE_WRITE); //Apro il file, che verrà chiuso a fine misurazione. Faccio così per evitare di attendere che il singolo dato vada scritto sul file ad ogni iterazione, causando eccessivo stress sulla micro SD
  //se ho creato/trovato il file, scrivo un valore al secondo per 24h
  digitalWrite(LED_BUILTIN, HIGH); //Durante la misurazione, tengo acceso il led integrato sulla board
  if (dati) {
    for (int i = 0; i <=86400; i++) { //86400 + 1 valori, scarteremo il primo perchè "sporcato" dalle fluttuazioni di corrente all'interno della board all'accensione del pin 5V
       valore = analogRead(A0);
       dati.println(valore);
       delay(1000);
  }
    dati.close(); //Chiudo il file e lo salvo...
    digitalWrite(LED_BUILTIN, LOW); //...spengo il led...
    Serial.println("fine."); //...e fine!
  } 
  else {
    Serial.println("errore nell'aprire il file!");
  }
}

void loop() {
 //Tutto il programma va in setup in quanto va eseguito una sola volta e non voglio che si ripeta la misurazione al termine delle 24H
}
