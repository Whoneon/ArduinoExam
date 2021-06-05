/*
Questo setup può essere utilizzato sia nella variante "headless", ovvero in grado di funzionare autonomamente senza passare da un PC, sia interfacciandosi ad un terminale fornendo in output lo stato attuale del led, che potrebbe aiutare a costruire un sistema di illuminazione controllabile via remoto (progetti di domotica o di IoT). Rimuovere la parte commentata nel ciclo if e nel void setup per avviare la comunicazione seriale
*/
#define pinLed 3 //Pin a cui è collegato il led o la lampada tramite relay
#define pinLux A0 //Pin a cui è collegata la fotoresistenza
int lux; //Il valore letto dalla resistenza tra 0 e 1023
const int soglia = 28; //Valore arbitrario corrispondente alla luce del tramonto misurato nella mia stanza
const int wait = 5; //Valore in secondi dell'attesa tra una misura e la successiva

void setup (){
	Serial.begin(9600);
	//pinMode(pinLed, OUTPUT);
}

void loop(){
	lux = analogRead(pinLux); //Leggo il valore della luce
	if (lux < soglia){
		digitalWrite(pinLed, HIGH);} //Accendo un led se la luce ambientale è sotto la soglia
		//Serial.println("Luce accesa con valore "); 
		//Serial.print(lux);
	else{
		digitalWrite(pinLed, LOW);
		//Serial.println("Luce spenta con valore ");
		//Serial.print(lux);
	}
	delay(wait*1000);
}
