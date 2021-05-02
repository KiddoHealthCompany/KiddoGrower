/*°#°#°#°#°#°#° LIBREIRE E VARIABILI GENERALI °#°#°#°#°#°#°*/
#include <Wire.h>         //Inclusione libreria per I2C.
const int pinPgS = 4;     //Pin pulsante verde, di aumento pagina.
const int pinPgG = 5;     //Pin pulsante rosso, di diminuzione pagina.
const int pinPgF = 3;     //Pin pulsante giallo, di cambio menu o funzione.
const int pinPgFSt = 2;   //Pin pulsante blu, di interazione o stato di funzione.
int vPgS1;                //Valori di selezione pulsante verde.
int vPgS2;
int vPgG1;                //Valori di selezione pulsante rosso.
int vPgG2;
int vPgF1;                //Valori di selezione pulsante giallo.
int vPgF2;
int vPgFSt1;              //Valori di selezione pulsante blu.
int vPgFSt2;

int Pg = 0;               //Valore della pagina.
int StPg0 = 0;            //Variabili di stato delle pagine.
int StPg1 = 0;
int StPg2 = 0;
int StPg3 = 0;
int StPg4 = 0;
int StPg5 = 0;
int StPg6 = 0;
int StPg7 = 0;
int StPg8 = 0;
int StPg9 = 0;
float VPot = 0;           //Valore del potenziometro.

int EeggG = 0;            //Hehe, segreto
int EeggB = 0;
int nr;
int nEegg;
double tEegg = 0;
const unsigned char EeggPerboni [] PROGMEM =
{
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xf0, 0x07, 0xe0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x01, 0xf0, 0x07, 0xc0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0xf8, 0x0f, 0x80, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0xf8, 0x0f, 0x80, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x01, 0xf0, 0x07, 0xc0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x07, 0xf0, 0x07, 0xf0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00
};
const unsigned char EeggBulaiUp [] PROGMEM =
{
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x43, 0x30, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x03, 0x84, 0x0c, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x07, 0x85, 0x83, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x18, 0x63, 0x06, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x78, 0x18, 0x0a, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x86, 0x06, 0x12, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x29, 0x81, 0xe3, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x28, 0x61, 0xbc, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x30, 0x1e, 0xc0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x28, 0x1b, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x80, 0xe4, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x67, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x18, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x18, 0x07, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x18, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x99, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
  
const unsigned char EeggBulaiDown [] PROGMEM =
{
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x85, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x63, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x18, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x86, 0x06, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x29, 0x81, 0xe2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x28, 0x61, 0x83, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x30, 0x1e, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x26, 0x28, 0x18, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x80, 0xe0, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x67, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x18, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x60, 0x18, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x38, 0x18, 0x1a, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x46, 0x18, 0x62, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0x99, 0x82, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x7e, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


/*°#°#°#°#° LIBREIRE E VARIABILI RTC E TIMER °#°#°#°#°#°#°*/
#include "RTClib.h"       //Inclusione libreria RTC e assegnamento.
RTC_DS1307 RTC;
double tRTC = 0;          //Variabile di aggiornamento RTC.
int Anno;                 //Variabili RTC.
int Mese;
int Giorno;
int Ora;
int Minuti;
int Secondi;
int Leg = 0;              //Variabile per l'ora legale.

int secTimer = 0;         //Variabili timer.
int minTimer = 0;
int oreTimer = 0;
double tTimer;            //Variabile di aggiornamento timer.
double totTimer = 0;      //Variabile di tempo assegnato al timer.
float tRest;              //Variabile di tempo rimanente.
int timerSt = 0;          //Variabile di stato del timer.

/*°#°#°#°#°#°#° LIBREIRE E VARIABILI DEBUG °#°#°#°#°#°#°#°*/
double tDebug = 0;        //Variabile di tempo per l'aggiornamento del debug.
const int dtDebug = 1000; //Variabile di intervallo di aggiornamento del debug.

/*°#°#°#°#°#°#° LIBREIRE E VARIABILI OLED °##°°#°#°#°#°#°#°*/
#include <Adafruit_GFX.h> //Dichiarzione librerire del display Oled 32*128 px.
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128  //Larghezza del display in pixel
#define SCREEN_HEIGHT 32  //Altezza del display in pixel
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C//Indirizzo I2C del display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   32  //Dimensioni del logo all'avvio
#define LOGO_WIDTH    128

const unsigned char Kiddo_grower_logo [] PROGMEM =  //Logo d'avvio
{
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x68, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x98, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0c, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x04, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x07, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x30, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x0c, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x06, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x62, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0a, 0x82, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0a, 0x82, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0c, 0xb2, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1a, 0x92, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x2a, 0x64, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x21, 0x84, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x98, 0x18, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x15, 0xdc, 0xe3, 0x03, 0x9c, 0xe4, 0x97, 0xb8, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x14, 0x92, 0x94, 0x84, 0x15, 0x14, 0x94, 0x28, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x14, 0x92, 0x94, 0x84, 0x15, 0x14, 0x94, 0x28, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x18, 0x92, 0x94, 0x84, 0xd9, 0x14, 0x97, 0x30, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x14, 0x92, 0x94, 0x84, 0x55, 0x14, 0x94, 0x28, 0x00, 0x00, 0x00, 0x00, 
 0x00, 0x00, 0x00, 0x00, 0x15, 0xdc, 0xe3, 0x03, 0x94, 0xe3, 0x67, 0xa8, 0x00, 0x00, 0x00, 0x00
};

double tOLED = 0;         //Variabile di aggiornamento OLED.


/*°#°#°#°#°#°#° LIBREIRE E VARIABILI BME280 °#°#°#°#°#°#°#°*/
#include "Seeed_BME280.h" //Dichiarzione librerire BME280, sensore di temperatura.
BME280 bme280;
float VTemp = 22;         //Variabili di temperatura, letta e selezionata.
float TempAmb = 0;
int VUm = 60;             //Variabili di umidità, letta e selezionata.
int UmAmb = 0;
double tBME;              //Variabile di aggiornamento BME280.

/*°#°#°#°#°#°#° LIBREIRE E VARIABILI DM501 °##°°#°#°#°#°#°*/
#include<string.h>        //Dichiarzione librerire DM501, sensore per il particolato.
int pinDM501 = 12;        //Pin di lettura del DM501.
int interr = 0;           //Tempo delle interruzioni.
int interrTot = 0;
int part = 0;             //Tempo totale delle interruzioni delle particelle.
double tDM501;            //Variabile di aggiornamento DM501.

/*°#°#°#°#°#°#° LIBREIRE E VARIABILI MICROFONO °#°#°#°#°#°*/
const int pinMic = 6;     //Pin di lettura del microfono.
float sMic = 175;         //Variabile di somma di rumori.
float vMic = 0;           //Variabile del valore misurato dal microfono.
double tMic = 0;          //Variabile di aggiornamento microfono.

/*°#°#°#°#°#°#° LIBREIRE E VARIABILI MAX30102 °#°#°#°#°#°#°*/
#include "MAX30105.h"     //Libreria del sensore di battito MAX30102.
#include "heartRate.h"    //Libreria di calcolo del battito cardiaco.
MAX30105 particleSensor;  //Dichiarazione del sensore.
long irValue;             //Variabile del valore letto dal sensore di infrarossi riflessi.
long delta;               //Variabile di intervallo di tempo tra battiti
double lastBeat = 0;      //Variabile di tempo dell'ultimo battito.
float beatsPerMinute;     //variabile dei battiti al minuto.

/*°#°#°#°#°#°#° LIBREIRE E VARIABILI MLX90614 °#°#°#°#°#°*/
#include <Adafruit_MLX90614.h> //Libreria del sensore di temperatura a infrarossi MLX90614.
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
float TempBambino;        //Variabile di aggiornamento del sensore.

/*°#°#°#°#° LIBREIRE E VARIABILI UMIDIFICATORE °#°#°#°#°#°*/
int vEl;                  //Variabile del valore letto dalla sonda dell'umidificatore.
const int pinEl = A1;     //Pin di lettura della sonda.

/*°#°#°#°#°#°#° LIBREIRE E VARIABILI OUTPUT °#°#°#°#°#°#°*/
const int pinReset = 8;   //Pin del sistema di reset.
const int pinBuzzer = 7;  //Pin di uscita del buzzer.
const int pinVent = 9;    //Pin di regolazione della ventola.
const int pinResist = 10; //Pin di regolazione della resistenza di riscaldamento dell'aria.
const int pinUmidif = 11; //Pin di regolazione della resistenza dell'umidificatore.
int ventRicTemp = 0;      //Variabile di richiesta della ventilazione in funzione della temperatura.
int ventRicUm = 0;        //Variabile di richiesta della ventilazione in funzione dell'umidità.
int ventRic = 0;          //Variabile di richiestat totale della ventilazione.
int AllSt = 0;            //Variabile dello stato dell'allarme.
double tAll = 0;          //Variabile di tempo dell'allarme.



void setup() 
{
 inputStart();            //Inizializzazione dei pin di input.
 
 debugVisualStart();      //Inizializzazione del monitor seriale per il debug.

 I2CStart();              //Inizializzazione del canale di comunicazione con i sensori I2C.

 debugRTCStart();         //Debug di avvio del modulo RTC.
 RTCStart();              //Inizializzazione del modulo RTC.

 debugOLEDStart();        //Debug di avvio del display OLED.
 OLEDStart();             //Inizializzazione del display OLED con visualizzazione del logo.
 
 outputStart();           //Inizializzazione dei pin di output.

 MLX90614Start();         //Inizializzazione del sensore MLX90614.

 debugBME280Start();      //Debug di avvio del sensore BME280.
 BME280Start();           //Inizializzazione del sensore BME280.

 MicStart();              //Inizializzazione del microfono.

 DM501Start();            //Inizializzazione del sensore DM501

 debugMAX30102Start();    //Debug di avvio del sensore MAX30102.
 MAX30102Start();         //Inizializzazione del sensore MAX30102.

 debugStop();             //Separazione dei paragrafi di debug.

 OLEDStartFinish();       //Fine dell'avvio del sistema su OLED.
}



void loop() 
{
 PgSelezione();           //Selezione del comando in entrata per le pagine (pulsanti rosso e verde).
 FSelezione();            //Selezione della funzione della pagina (pulsante giallo).
 FStSelezione();          //Selezione dello stato della funzione o interazione (pulsante blu).

 BttLett();               //Lettura del valore dei pulsanti.
 PotLett();               //Lettura del valore del poteziometro.

 RTCLett();               //Lettura dei dati dal modulo RTC.
 BME280Lett();            //Lettura dei valori ambientali dal sensore BME280.
 MicLett();               //Lettura e calcolo dei dati del microfono.
 DM501Lett();             //Lettura e calcolo dei dati del sensore DM501.
 MAX30102Lett();          //Lettura e calcolo dei dati del sensore MAX30102.
 MLX90614Lett();          //Lettura dei dati del sensore MLX90614.
 elettrodiLett();         //Lettura del valore dalla sonda dell'umidificatore.

 OLEDPgStmp();            //Visualizzazione della pagina su display.

 if((millis()-tDebug)>=dtDebug)//ciclo "if" di stampa su monito seriale per debug; viene effettuato ogni secondo.
 {
  debugInput();           //Debug degli input (pulsanti+potenziometro).
  debugPg();              //Debug del numero della pagina.
  debugStop();            //Separazione dei paragrafi di debug.
  tDebug=millis();        //Azzeramento dell'intervallo di aggiornamento del debug.
 }

 outputAmb();             //Assegnazione dei parametri per l'output a livello ambientale (ventilazione, riscaldamento e umidificatore).
 outputAll();             //Assegnazione dei parametri d'allarme.
}