/*°#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#° INIZIO SEZIONE SETUP °#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#°*/



/*°#°#°#°#°#°#° GENERALE °#°#°#°#°#°#°*/

void I2CStart()
{
 Wire.begin();                                             //Avvio del bus di comunicazione I2C.
}

void inputStart()
{
 pinMode(pinPgS,INPUT);                                    //Dichiarazione del pin del pulsante verde, pagina su.
 pinMode(pinPgG,INPUT);                                    //Dichiarazione del pin del pulsante rosso, pagina giù.
 pinMode(pinPgF,INPUT);                                    //Dichiarazione del pin del pulsante giallo, cambio funzione.
 pinMode(pinPgFSt,INPUT);                                  //Dichiarazione del pin del pulsante blu, interazione.
 digitalWrite(pinPgS,HIGH);                                //Attivazione delle resistenze di pull-up integrate sulla scheda per i pulsanti.
 digitalWrite(pinPgG,HIGH);
 digitalWrite(pinPgF,HIGH);
 digitalWrite(pinPgFSt,HIGH);
}

void outputStart()
{
 pinMode(pinReset,OUTPUT);                                 //Dichiarazione del pin del sistema di reset.
 pinMode(pinBuzzer,OUTPUT);                                //Dichiarazione del pin di controllo del buzzer.
 pinMode(pinVent,OUTPUT);                                  //Dichiarazione del pin di controllo della ventilazione.
 pinMode(pinUmidif,OUTPUT);                                //Dichiarazione del pin di controllo dell'umidificatore.
 pinMode(pinResist,OUTPUT);                                //Dichiarazione del pin di controllo del riscaldamento.

 digitalWrite(pinBuzzer,HIGH);                             //Test di funzionamento delle periferiche
 delay(50);
 digitalWrite(pinBuzzer,LOW);
 digitalWrite(pinVent,HIGH);
 delay(1000);
 digitalWrite(pinVent,LOW);
 digitalWrite(pinResist,HIGH);
 delay(1000);
 digitalWrite(pinResist,LOW);
 digitalWrite(pinUmidif,HIGH);
 delay(1000);
 digitalWrite(pinUmidif,LOW);
}



/*°#°#°#°#°#° RTC E TIMER °#°#°#°#°*/

void RTCStart()
{
 RTC.begin();                                              //Inizializzazione del modulo RTC.
 tTimer = millis();                                        //Azzeramento della variabile di aggiornamento del modulo RTC.
}



/*°#°#°#°#°#°#° DEBUG °#°#°#°#°#°#°*/

void debugVisualStart()                                    //Inizializzazione del monitor seriale per il debug.
{
 Serial.begin(115200);                                     //Impostazione del baudrate.
 Serial.println("Serial monitor opened");                  //Messaggio di conferma avvio.
 Serial.println(' ');                                      //Spazio di separazione.
}

void debugRTCStart()                                       //Debug di avvio del modulo RTC.
{
 if (!RTC.isrunning())                                     //Messaggio di avvertenza e correzione del modulo in caso di anomalie.
 {
  Serial.println("RTC is not running!");
  RTC.adjust(DateTime(__DATE__, __TIME__));
 }
 else                                                      //Messaggio di configuarazione avvenuta correttamente.
 {
  Serial.println("RTC is running correctly!");
 }
 Serial.println(' ');                                      //Spazio di separazione.
}

void debugBME280Start()                                    //Debug di avvio del sensore BME280.
{
 if(!bme280.init())                                        //Messaggio di avvertenza in caso di anomalie.
 {
  Serial.println("BME280 error!");
 }
 else                                                      //Messaggio di configuarazione avvenuta correttamente.
 {
  Serial.println("BME280 check OK!");
 }
 Serial.println(' ');                                      //Spazio di separazione.
}

void debugOLEDStart()                                      //Debug di avvio del display.
{
 if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))  //Messaggio di avvertenza in caso di anomalie.
 {
  Serial.println("Display allocation failed");
 }
 else                                                      //Messaggio di configuarazione avvenuta correttamente.
 {
  Serial.println("Display allocation completed");
 }
 Serial.println(' ');                                      //Spazio di separazione.
}

void debugStop()
{
 Serial.println("#°#°#°#°#°#°#°#°#°#°#°#°#°#°#°#°#°#°#°#");//Separazione grafica tra paragrafi.
 Serial.println(' ');                                      //Spazio di separazione.
}



/*°#°#°#°#°#°#° OLED °#°#°#°#°#°#°*/

void OLEDStart()                                           //Avviamento del display con visualizzazione del logo di avvio.
{
 display.clearDisplay(); 
 display.drawBitmap(0,0 ,Kiddo_grower_logo, LOGO_WIDTH, LOGO_HEIGHT, 1);
 display.display();
}

void OLEDStartFinish()                                     //Pulizia dello schermo dopo l'avvio del sistema e impostazioni di default per il funzionamento.
{
 delay(2000);                              
 display.clearDisplay();                                   //Pulizia del display.
 display.setTextColor(SSD1306_WHITE);                      //Impostazione del colore del testo su diplay (non vale con tutti i modelli).
 display.setTextSize(2);                                   //Impostazione della dimensione del testo a 2, scala  di media grandezza, per i prossimi testi da scrivere.
 display.display();
}



/*°#°#°#°#°#°#° BME280 °#°#°#°#°#°#°#°*/

void BME280Start()                                         //Avvio del modulo BME280.
{
 tBME=millis();                                            //Azzeramento della variabile di aggiornamento del sensore BME280.
}



/*°#°#°#°#°#°#° MICROFONO °#°#°#°#°#°#°*/

void MicStart()                                            //Avvio del microfono.
{
 pinMode(pinMic,INPUT);                                    //Dichiarazione del pin di lettura del microfno.
 tMic = millis();                                          //Azzeramento della variabile di aggiornamento del microfono.
}



/*°#°#°#°#°#°#° DMM501 *#°#°#°#°#°#°#°*/

void DM501Start()                                          //Avvio del sensore DM501.
{
 pinMode(pinDM501,INPUT);                                  //Dichiarazione del pin di lettura del sensore DM501.
 tDM501 = millis();                                        //Azzeramento della variabile di aggiornamento del sensore DM501.
}



/*°#°#°#°#°#°#° MAX30102 °#°#°#°#°#°#°*/

void debugMAX30102Start()                                  //Debug di avvio del sensore MAX30102.
{
 Serial.println("Initializing MAX30102...");               //Messaggio d'inizio configurazione swl sensore.
 
 if (!particleSensor.begin(Wire, I2C_SPEED_FAST))          //Messaggio di avvertenza in caso di anomalie.
 {
  Serial.println("MAX30102 was not found. Please check wiring/power. ");
  while (1);
 }
 else                                                      //Messaggio di configuarazione avvenuta correttamente.
 {
  Serial.println("MAX30102 initialization OK");
 }
 Serial.println(' ');                                      //Spazio di separazione.
}

void MAX30102Start()                                       //Avvio del sensore MAX30102.
{
 particleSensor.setup();                                   //Inizializzazione del sensore.
 particleSensor.setPulseAmplitudeRed(0x0A);                //Impostazione della luminosità del led rosso integrato nel sensore.
 particleSensor.setPulseAmplitudeGreen(0);                 //Impostazione della luminosità del led varde integrato nel sensore.
}



/*°#°#°#°#°#°#° MLX90614 °#°#°#°#°#°#°*/

void MLX90614Start()                                       //Avvio del sensore MLX90614.
{
 mlx.begin();                                              //Inizializzazione del sensore.
}



/*°#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#° FINE SEZIONE SETUP °#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#°*/
