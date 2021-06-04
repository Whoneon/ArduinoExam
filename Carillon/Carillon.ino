/*
 * Mozart "Eine kleine Nachtmusik" I. Allegro per Arduino - Antonio Guastella, M05000889
 * Si ringrazia il sito internet https://sparks.gogo.co.nz/ per avermi fornito uno strumento in grado di estrarre gli array contenenti  le note e le rispettive durate dal file midi fornitogli in input
 */
 //Dichiaro il pin a cui collegherò il buzzer
static const uint8_t tonePin = 4;

void setup() 
{
//Niente da dichiarare qui
}

void loop() 
{
//Cambiando il valore di tempoToPlay si modifica la velocità con cui la melodia viene riprodotta, dove 1 indica la velocità massima e 255 quella più lenta
//Il valore di melodyToPlay invece indica la traccia da ripodurre. Nel nostro caso la melodia 0 sarebbe la mano "destra" del pianista, mentre la 1 la mano "sinistra"
//Avendo a disposizione due buzzer sarebbe possibile riprodurre entrambe le tracce in simultanea...
  
  uint8_t melodyToPlay = 0;
  uint8_t tempoToPlay  = 1;
  
  playMelody(melodyToPlay, tempoToPlay);   
}
//Un po di valori: tonalità e durata di ogni nota
#include <avr/pgmspace.h>
#define NUMBER_OF_MELODIES 2
static const uint16_t Melody0[] PROGMEM = { 
        0b1111111101100111, 0b1111111101100111, 0b1111111101100111, 0b1111111101100111, 
        0b0000010001100111, 0b1111111111111111, 0b1111111111111111, 0b0000001011111111, 
        0b1111111101100010, 0b1111111101100010, 0b0000001001100010, 0b1111111101100111, 
        0b1111111101100111, 0b1111111101100111, 0b1111111101100111, 0b0000010001100111, 
        0b1111111111111111, 0b1111111111111111, 0b0000001011111111, 0b1111111101100010, 
        0b1111111101100010, 0b0000001001100010, 0b1111111101100111, 0b1111111101100111, 
        0b0000001001100111, 0b1111111101100010, 0b1111111101100010, 0b0000001001100010, 
        0b1111111101100111, 0b1111111101100111, 0b0000001001100111, 0b1111111101101011, 
        0b1111111101101011, 0b0000001001101011, 0b1111111101110010, 0b1111111101110010, 
        0b1111111101110010, 0b1111111101110010, 0b0000010001110010, 0b1111111111111111, 
        0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111101110000, 
        0b1111111101110000, 0b1111111101110000, 0b1111111101110000, 0b0000010001110000, 
        0b1111111111111111, 0b1111111111111111, 0b0000001011111111, 0b1111111101101001, 
        0b1111111101101001, 0b0000001001101001, 0b1111111101110000, 0b1111111101110000, 
        0b1111111101110000, 0b1111111101110000, 0b0000010001110000, 0b1111111111111111, 
        0b1111111111111111, 0b0000001011111111, 0b1111111101101001, 0b1111111101101001, 
        0b0000001001101001, 0b1111111101110000, 0b1111111101110000, 0b0000001001110000, 
        0b1111111101101001, 0b1111111101101001, 0b0000001001101001, 0b1111111101100110, 
        0b1111111101100110, 0b0000001001100110, 0b1111111101101001, 0b1111111101101001, 
        0b0000001001101001, 0b1111111101100010, 0b1111111101100010, 0b1111111101100010, 
        0b1111111101100010, 0b0000010001100010, 0b1111111111111111, 0b1111111111111111, 
        0b1111111111111111, 0b1111111111111111, 0b1111111101100111, 0b1111111101100111, 
        0b0000001001100111, 0b1111111111111111, 0b1111111111111111, 0b0000001011111111, 
        0b1111111101100111, 0b1111111101100111, 0b1111111101100111, 0b1111111101100111, 
        0b1111111101100111, 0b1111111101100111, 0b0000011001100111, 0b1111111101101011, 
  };
static const uint16_t Melody0_Length    = sizeof( Melody0 ) / sizeof(uint16_t);

//Stessa cosa ma riferita alla seconda traccia
static const uint16_t Melody1[] PROGMEM = { 
        0b0011101101000111, 0b0011101101000010, 0b1111111100110111, 0b1111111100110111, 
        0b1111111100110111, 0b1011111100110111, 0b1111111111111111, 0b1111111111111111, 
        0b0000001011111111, 0b1111111101000010, 0b1111111101000010, 0b0000001001000010, 
        0b1111111101000111, 0b1111111101000111, 0b1111111101000111, 0b1111111101000111, 
        0b0000010001000111, 0b1111111111111111, 0b1111111111111111, 0b0000001011111111, 
        0b1111111101000010, 0b1111111101000010, 0b0000001001000010, 0b1111111101000111, 
        0b1111111101000111, 0b0000001001000111, 0b1111111101000010, 0b1111111101000010, 
        0b0000001001000010, 0b1111111101000111, 0b1111111101000111, 0b0000001001000111, 
        0b1111111101001011, 0b1111111101001011, 0b0000001001001011, 0b1111111101010010, 
        0b1111111101010010, 0b1111111101010010, 0b1111111101010010, 0b0000010001010010, 
        0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 
        0b1111111101010000, 0b1111111101010000, 0b1111111101010000, 0b1111111101010000, 
        0b0000010001010000, 0b1111111111111111, 0b1111111111111111, 0b0000001011111111, 
        0b1111111101001001, 0b1111111101001001, 0b0000001001001001, 0b1111111101010000, 
        0b1111111101010000, 0b1111111101010000, 0b1111111101010000, 0b0000010001010000, 
        0b1111111111111111, 0b1111111111111111, 0b0000001011111111, 0b1111111101001001, 
        0b1111111101001001, 0b0000001001001001, 0b1111111101010000, 0b1111111101010000, 
        0b0000001001010000, 0b1111111101001001, 0b1111111101001001, 0b0000001001001001, 
        0b1111111101000110, 0b1111111101000110, 0b0000001001000110, 0b1111111101001001, 
        0b1111111101001001, 0b0000001001001001, 0b1111111101010010, 0b1111111101010010, 
        0b1111111101010010, 0b1111111101010010, 0b0000010001010010, 0b1111111111111111, 
        0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111101001011, 
        0b0000000101001011, 0b1111111101010010, 0b0000000101010010, 0b1111111101001011, 
        0b0000000101001011, 0b1111111101010010, 0b0000000101010010, 0b1111111101001011, 
        0b0000000101001011, 0b1111111101010010, 0b0000000101010010, 0b1111111101001011, 
  };
static const uint16_t Melody1_Length    = sizeof( Melody1 ) / sizeof(uint16_t);
void playMelody_Data(const uint16_t MelodyData[], const uint16_t MelodyLength, const uint8_t tempo)
{
  // Frequenze dell'ottava C8 a B8, da cui calcolo le ottave più basse (temperamento equabile, ogni nota è proporzionale all'altra mediante un fattore radice dodicesima di due)
  static const uint16_t Freq8[] PROGMEM = { 4186 , 4435 , 4699  , 4978 , 5274 , 5588 , 5920 , 6272 , 6645 , 7040 , 7459 , 7902 };

  for(uint16_t  x = 0; x < MelodyLength; x++)
  {
    uint16_t data = pgm_read_word((uint16_t *)&MelodyData[x]);
    if((data & 0xF) == 0xF) 
    {
      noTone(tonePin);
    }
    else
    {
      uint16_t Freq = pgm_read_word(&Freq8[data&0xF]) / ( 1 << (8-(data>>4 & 0xF)) );
      tone(tonePin, Freq);    
    }    
    int16_t Duration = data>>8;
    while(Duration--) delay(tempo);
  }
}

inline static void playMelody(uint8_t melodyNumber, uint8_t tempo)
{
  switch(melodyNumber)
  {
  #if NUMBER_OF_MELODIES > 0
    case 0: { playMelody_Data(Melody0, Melody0_Length, tempo); return; }
  #endif
  #if NUMBER_OF_MELODIES > 1
    case 1: { playMelody_Data(Melody1, Melody1_Length, tempo); return; }
  #endif
  }
}

