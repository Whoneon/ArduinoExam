#include <Arduino.h> //Miglioro la comprensione di formule matematiche e di operatori logici
#include <Wire.h> //Potenzio la comunicazione seriale. Potrei anche accoppiare due Arduino per farli funzionare da trasmittente e ricettore

char* lettere[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
}; //Un array di valori corrispondenti alle lettere scritte in Morse

char* numeri[] = {
  "-----", ".----", "..---", "...--", "....-", ".....", // 0-5
"-....", "--...", "---..", "----." // 6-9
}; //Un array di valori corrispondenti ai numeri scritti in Morse
const int durata_punto = 200; //La durata del - viene calcolata in base a quella di .

void setup() {
	Serial.begin(9600); //Avvio la comunicazione seriale per leggere l'input della tastiera
}

void loop() {
	char carattere;
	if (Serial.available())
	{
		carattere = Serial.read(); // Leggo la stringa immessa dall'utente
		if (carattere >= 'a' && carattere <= 'z')
		{
			flashSequenza(lettere[carattere - 'a']); //Identifico l'indice dell'array come differenza tra caratteri
		}
		else if (carattere >= 'A' && carattere <= 'Z') //Stessa cosa, ma per le lettere maiuscole
		{
			flashSequenza(lettere[carattere - 'A']);
		}
		else if (carattere >= '0' && carattere <= '9') //E per i numeri
		{
			flashSequenza(numeri[carattere - '0']);
		}
		else if (carattere == ' ') //Allo spazio tra due parole faccio corrispondere un'attesa di 4 volte un punto
		{
			delay(durata_punto * 4);
		}
	}
}

void flashSequenza(char* sequenza) {
	int i = 0;
	while (sequenza[i] != NULL) {
        		flashPuntoTratto(sequenza[i]);
		i++; 
	}
	delay(durata_punto * 2);
}


void flashPuntoTratto(char PoT) { //Identifico ciò che devo rappresentare
	digitalWrite(LED_BUILTIN, HIGH);
	if (PoT == '.') //se quello che devo rappresentare è un punto .
	{
    		delay(durata_punto); //tengo acceso il led per la durata del punto
  	}
	else // se quello che devo rappresentare è un trattino -
	{
		delay(durata_punto * 3); //tengo  acceso il led per la durata del trattino
	}
	digitalWrite(LED_BUILTIN, LOW);
	delay(durata_punto); //Attesa tra un segnale luminoso e il successivo
}
