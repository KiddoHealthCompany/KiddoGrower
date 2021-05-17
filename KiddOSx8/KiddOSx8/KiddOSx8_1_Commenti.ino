/*°#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#° INIZIO SEZIONE COMMENTI °#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#°*/



/*°#°#°#°#°#°#° PRESENTAZIONE °#°#°#°#°#°#°*/
/* KiddOSx8 Ver.: 1.0
 *
 * Sviluppato per il progetto di P.C.T.O. della 3^A eln dell' I.T.I.S. G.B. Pininfarina (Moncalieri, Italia).
 * Tutti i crediti al link di GitHub sotto.
 *
 * Questo progetto ha lo scopo di creare un sistema di gestione per qualsiasi incubatrice neonatale; sistema che fornisca molte funzionalità in un'unica soluzione.
*/


/*°#°#°#°#°#°#°#° PREMESSA °#°#°#°#°#°#°#°*/
/* E' consigliabile consultare il manuale d'sitruzioni prima di mettere mano sul programma.
 * Leggendo e comprendendo il manuale è possibile capire al meglio il funzionamento e le dinamiche di ogni componente.
 * Puoi trovare il manuale di istruzioni e di costruzione con tutti i componenti e gli schemi elettrici al seguente link:
 * https://github.com/KiddoHealthCompany/KiddoGrower
*/

/*°#°#°#°#° LETTURA DEL PROGRAMMA °#°#°#°#°*/
/* Questo codice è stato scritto per la piattaforma Arduino, per la precisione per il Mega 2560 Rev3
 * Il sistema comprende 7 moduli esterni tra cui sensori, un RTC e un display Oled più tutti i componenti "classici" come pulsanti, un buzzer, un potenziometro ed innumerevoli jumper
 * In questo caso il codice è stato diviso in 4 parti: Sezione iniziale, con tutti i comandi generici, sezione di commento (questa), contenente una descrizione del programma, la sezione 
 * setup che gestice tutte le funzioni di setup e la sezione loop, che racchiude in sè le operazioni specifiche eseguite dall'algoritmo di Arduino.
 * 
 * L'ordine delle parti non è mai casuale; generalmente segue queseta sequenza: generale, RTC e timer, debug, oled, parte ambientale (BME280, DM510 e microfono), parte personale (MAX30102 e 
 * MLX90614) e parte di output (controllo umidificatore e output).
 * Ovviamente l'ordine dei cicli viene cambiato in funzione delle esigenze, ma si tende a seguire questa sequenza per un maggior ordine e per facilitare la ricerca di eventuali errori
*/

/*°#°#°#°#°#°#°#° LE PARTI °#°#°#°#°#°#°#°*/
/* Le parti sopra elencate racchiudono al loro interno una serie di comandi e calcoli; vediamone la suddivisione:
 * _GENERALE: sono presenti tutte le variabili ed i calcoli che accomunano tutti i cicli o quasi o che per lo meno non siano specifici di un solo settore. In questa parte si trova gran
 *  parte della selezione delle pagine e delle funzioni; in sostanza dell'interazione utente-macchina.
 * _RTC E TIMER: qui si trova la gestione delle variabili e dei calcoli di tempo per la visualizzazione di data e ora o dell'uso di un timer generico.
 * _DEBUG: si tratta della sezione che si occupa di fornire tutti i dati a tecnici o manutentori in caso di malfunzionamenti o errori anomali; serve a segnalare il corretto 
 *  (o non) funzionamento di ogni singola parte della macchina rtamite minitor seriale.
 * _OLED: sezione che si occupa della visualizzazione delle interfacce sul display; permette la comunicazione di tutti i dati utili all'utente. Qui è possibile trovare la restante parte delle
 *  interazioni dell'utente verso la macchina via input classici.
 * _BME280: parte che si occupa della misurazione dei parametri di temperatura e umidità, all'interno dell'incubatricetramite, tramite il sensore omonimo.
 * _DM510: parte che si occupa della misurazione della qualità dell'aria, all'interno dell'incubatricetramite, tramite il sensore omonimo.
 * _MICROFONO: sezione che si occupa di effettuare le misurazioni per definire se il rumore ambientale è troppo forte.
 * _MAX30102: parte che si occupa della misurazione delbattito del bambino tramite il sensore omonimo.
 * _MLX90614: parte che si occupa della misurazione della temperatura del bambino tramite il sensore omonimo.
 * _CONTROLLO UMIDIFICATORE: Questa sezione è tra le più semplici: gestisce il controllo della presenza dell'acqua nel serbatoio dell'umidificatore; si tratta di una semplice protezione.
 * _OUTPUT: Questa è l'ultima delle sezioni. Si occupa di gestire gli output ambientali come il riscaldamento, l'umidificazione, la ventilazione, ma soprattutto l'attivazione di un'allarme in caso 
 *  di necessità, che varia dallo scadere del tempo di un normalissimo timer preimpostato, fino all'avvertimento del caso in cui il battito del babino fosse troppo basso. Da parametri solamente di 
 *  comfort fino a quelli vitali.
*/

/*°#°#°#°#°#°#°#° CONCLUSIONI °#°#°#°#°#°#°#°*/
/* Ci auguriamo che il progetto sia gradito da tutti e che possa essere d'aiuto.
 * Se avete bisogno di contattarci scrivete alla seguente mail:
 * KiddoHealthCompany@gmail.com
 * 
 * E' importantissimo scaricare le seguenti librerie:
 * libreria per comunicazione I2C - Wire.h
 * libreria Adafruit per RTC - RTClib.h
 * libreria Adafruit per Oled - Adafruit_SSD1306.h (accettando di installare anche quelle ausiliarie)
 * libreria Groove per BME 280 - Seeed_BME280.h
 * libreria SparkFun per MAX30102 - MAX30105.h
 * libreria Adafruit per MLX90614 - Adafruit_MLX90614.h
*/
 
/*°#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#° FINE SEZIONE COMMENTI °#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#°*/
