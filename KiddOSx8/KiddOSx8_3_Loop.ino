/*°#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#° INIZIO SEZIONE LOOP °#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#°*/



/*°#°#°#°#°#°#° GENERALE °#°#°#°#°#°#°*/

void PgSelezione()                                                //Selezione della pagina.
{
 if((vPgS2-vPgS1)==1)                                               //Controllo di incremento della pagina, quando il relativo pulsante viene premuto la pagina aumenterà di uno.
 {
  Pg++;
 }
 
 if((vPgG2-vPgG1)==1)                                               //Controllo di decremento della pagina, quando il relativo pulsante viene premuto la pagina diminuirà di uno.
 {
  Pg--;
 }

 if(Pg!=-2)                                                         //Ciclo di impostazione della pagina; se si super l'ultima schermata si tornerà alla prima e viceversa.
 {
  if(Pg>=10)
  {
   Pg=0;
  }
  if(Pg<=-1)
  {
   Pg=9;
  }
 }
 
 vPgS2=vPgS1;                                                       //Assegnazione dei vecchi valori letti dai pulsanti alle rispettive variabili; serve per sapere se e quali pulsanti sono stati premuti.
 vPgG2=vPgG1;

 nr = random(1,6);                                                  //Questo comando non esiste. Shhh ;)
}


void FSelezione()                                                 //Selezione della funzione della pagina.
{
 if((vPgF2-vPgF1)==1)                                               //Se il pulsante della funzione viene premuto...
 {
  
  if(Pg==0)                                                             //...e si è sulla pagina iniziale si potrà cambiare da ora a data.
  {
   StPg0=1-StPg0;
  }
  
  else if(Pg==1)                                                        //...e si è sulla pagina del timer, si potrà cambiare tra 5 funzioni diverse in sequenza.
  {
   StPg1++;
   if(StPg1>4)
   {
    StPg1=0;
   }
  }
  
  else if(Pg==2)                                                        //...e si è sulla pagina della temperatura ambientale, si potrà scgliere se attivare o disattivare il controllo della temperatura.
  {
   StPg2=1-StPg2;
  }
  
  else if(Pg==3)                                                        //...e si è sulla pagina dell'umidità ambientale, si potrà scgliere se attivare o disattivare il controllo dell'umidità.
  {
   StPg3=1-StPg3;
  }
  
  else if(Pg==4)                                                        //...e si è sulla pagina del controllo dei filtri, si potrà scgliere se attivare o disattivare il controllo.
  {
   StPg4=1-StPg4;
  }
  
  else if(Pg==5)                                                        //...e si è sulla pagina del controllo del rumore, si potrà scgliere se attivare o disattivare il controllo.
  {
   StPg5=1-StPg5;
  }
  
  else if(Pg==6)                                                        //...e si è sulla pagina del controllo del battito del bambino, si potrà scgliere se attivare o disattivare il controllo.
  {
   StPg6=1-StPg6;
  }
  
  else if(Pg==7)                                                        //...e si è sulla pagina del controllo della temperatura del bambino, si potrà scgliere se attivare o disattivare il controllo.
  {
   StPg7=1-StPg7;
  }
  
  else if(Pg==8)                                                        //...e si è sulla pagina del controllo del livello del''acqua dell'umidificatore si potrà scgliere se attivare o disattivare il controllo.
  {
   StPg8=1-StPg8;
  }
 }
 
 if(Pg==9 && vPgF1==0)                                              //Mentre il pulsante della funzione è premuto e ci si trova sulla pagina del reset, la condizione di riavvio viene rispettata almeno a metà.                                      
 {
  StPg9=1;
 }
 else                                                               //Se no non viene registrato il comando e non si potrà effettuare il reset.
 {
  StPg9=0;
 }
 
 if(Pg!=0)                                                          //La schermata iniziale viene portata alla visualizzazione dell'ora ogni volta che si cambia pagina.
 {
  StPg0=0;
 }
 if(StPg0==0 && Pg==0)                                              //Finchè ci si trova sulla schermata iniziale e si visualizza l'ora la variabile "tRTC" viene aggiornata.
 {
  tRTC=millis();
 }
 if((millis()-tRTC)>=3000)                                          //Nel momento in cui si cambia schermata la schermata (passando su quella della data per esempio) la variabile non viene più aggiornata e dopo 3 secondi essa permette di tornare alla visualizzazione dell'ora.
 {
  StPg0=0;
 }

 if(Pg!=1)                                                          //La schermata del timer viene portata alla visualizzazione dello stato ogni volta che si cambia pagina.
 {
  StPg1=0;
 }
 
 vPgF2=vPgF1;                                                       //Assegnazione del veccho valore letto dal pulsante alla rispettiva variabila; serve per sapere se il pulsante è stato premuto.
}


void FStSelezione()                                               //Selezione dello stato delle funzioni, l'azionwe delle varianti avviene direttamente nel ciclo di visualizzazione su schermo.
{
 vPgFSt2=vPgFSt1;                                                   //Assegnazione del veccho valore letto dal pulsante alla rispettiva variabila; serve per sapere se il pulsante è stato premuto.
}


void BttLett()                                                    //Lettura dei valori dei pulsanti.
{
 vPgS1=digitalRead(pinPgS);                                         //Lettura del pulsante di incremento.
 vPgG1=digitalRead(pinPgG);                                         //Lettura del pulsante di decremento.
 vPgF1=digitalRead(pinPgF);                                         //Lettura del pulsante di funzione.
 vPgFSt1=digitalRead(pinPgFSt);                                     //Lettura del pulsante dello stato della funzione.
}


void PotLett()                                                    //Lettura del valore del potenziometro.
{
 VPot=analogRead(A0);
}



/*°#°#°#°#°#° RTC E TIMER °#°#°#°#°*/

void RTCLett()                                                    //Acquisizione dei dati dal modulo RTC.
{
 DateTime now = RTC.now();                                          //Aggiornamento dei dati.
 Giorno=now.day();                                                  //Assegnazione dei valori alle rispettive variabili.
 Mese=now.month();
 Anno=now.year();
 Ora=now.hour();
 Minuti=now.minute();
 Secondi=now.second();
}



/*°#°#°#°#°#°#° DEBUG °#°#°#°#°#°#°*/

void debugInput()                                                 //Debug degli input generici: pulsanti e potenziometro.
{
 Serial.print("PgS btt: "); Serial.println(digitalRead(pinPgS));    //Debug del pulsante di incremento.
 Serial.print("PgG btt: "); Serial.println(digitalRead(pinPgG));    //Debug del pulsante di decremento.
 Serial.print("PgF btt: "); Serial.println(digitalRead(pinPgF));    //Debug del pulsante di funzione
 Serial.print("PgFSt btt: "); Serial.println(digitalRead(pinPgFSt));//Debug del pulsante di stato funzione.
 Serial.print("Selez pot: "); Serial.println(analogRead(A0));       //Debug del potenziometro.
 Serial.println(' ');
}

void debugPg()                                                    //Debug della pagina visualizzata.
{
 Serial.print("Pg: "); Serial.println(Pg);                          //Viene stampata la pagina attuale.
 Serial.println(' ');
}



/*°#°#°#°#°#°#° OLED °#°#°#°#°#°#°*/

void OLEDPgStmp()                                                 //Visualizzazione della pagina.
{
 display.clearDisplay();
 display.setCursor(0,0);
 
 if(Pg==0)                                                          //Schermata iniziale; nome: "Ora".
 {
  display.print("Ora:");
  display.setCursor(0,17);
  if(StPg0==0)                                                            //Se viene visualizzata la sezione dell'ora (StPg0==0)...
  {
   if(Leg==1)                                                               //Se la funzione dell'ora legale è attivata viene sommata un'ora. 
   {
    Ora=Ora+1;
   }
   display.print(Ora);                                                      //... verranno visualizzati rispettivamente ora, minuti e secondi separati da ":".
   display.setCursor(22,17);
   display.print(':');
   display.setCursor(32,17);
   display.print(Minuti);
   display.setCursor(54,17);
   display.print(':');
   display.setCursor(64,17);
   display.print(Secondi);
   if((vPgFSt2-vPgFSt1)==1)                                                 //Ciclo di attivazione della funzione dell'ora legale.
   {
    Leg=1-Leg;
    display.setCursor(80,0);
    display.print("*");
   }
  }
  else if(StPg0==1)                                                       //Se viene visualizzata la sezione della data verranno visualizzati rispettivamente il giorno, il mese e l'anno in corso.
  {
   display.print(Giorno);
   display.setCursor(26,17);
   display.print('/');
   display.setCursor(38,17);
   display.print(Mese);
   display.setCursor(64,17);
   display.print('/');
   display.setCursor(76,17);
   display.print(Anno);
   if((vPgFSt2-vPgFSt1)==1)                                               //Se ci si trova sulla schermata della data e si preme il pulsante di interazione, si reimposterà la data a quandoè stato caricato l'ultimo sketch.
   {
    RTC.adjust(DateTime(__DATE__, __TIME__));
   }
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 }

 else if(Pg==1)                                                     //Schermata del timer; nome: "Timer".
 {
  display.print("Timer:");
  display.setCursor(0,17);
  if(StPg1==0)
  {
   if(timerSt==0)                                                       //Di default viene visualizzato lo stato del timer; se non è attivato verrà visualizzato il messaggio "off".
   {
    display.print("Stato");
    display.setCursor(64,17);
    display.print("Off");
   }
   if(timerSt==1)                                                       //Se è stato attivato...
   {
    if(vPgFSt1==1)                                                        //...quando il pulsante d'interazione non è premuto si visualizza il messaggio "On".
    {
     display.print("Stato");
     display.setCursor(64,17);
     display.print("On");
    }
    if(vPgFSt1==0)                                                        //...quando il pulsante d'interazione è premuto si visualizzerà il tempo rimanenete, a seconda delle necessità,...
    {
     tRest=(totTimer-(millis()-tTimer))/1000;
     if(tRest>3600)
     {
      display.print((tRest/3600),1);                                        //...espresso in ore.
      display.setCursor(52,17);
      display.print("Ore");
     }
     else if(tRest>60)
     {
      display.print((tRest/60),1);                                          //...espresso in minuti.
      display.setCursor(52,17);
      display.print("Min");
     }
     else if(tRest<=60)
     {
      display.print(tRest,1);                                               //...espresso in secondi.
      display.setCursor(52,17);
      display.print("Sec");
     }
    }
   }
   if(timerSt==2)                                                       //Se il timer è giunto a termine verrà visualizzato il messaggio d'allarme "All."
   {
    display.print("Stato");
    display.setCursor(64,17);
    display.print("All.");
    if(vPgFSt1==0)                                                        //Quando si visualizza il messaggio d'allarme, se si preme il pulsante d'interazione, l'allarme verrà disattivato.
    {
     timerSt=0;
    }
   }
  }
  else if(StPg1==1)                                                     //Accedendo alla schermata di selezione dei secondi sarà possibile impartire una durata tra 1 e 60 secndi.
  {
   display.print("Secondi");
   display.setCursor(85,17);
   secTimer=map(VPot,0,1024,1,61);                                        //Viene visualizzata la quantità di tempo selezionabile.
   display.print(secTimer);
   if((vPgFSt2-vPgFSt1)==1)                                               //Se si preme il pulsante interazione...
   {
    totTimer=totTimer+(secTimer*1000);                                      //...vengono sommati al conteggio i secondi selezionati e...
    display.setCursor(85,0);
    display.print("*");                                                     //...viene visualizzato un asterisco che avverte dell'avenuta selezione.
    tTimer=millis();
    timerSt=1;                                                              //lo stato del timer viene portato ad "attivato".
   }
  }
  else if(StPg1==2)                                                     //Accedendo alla schermata di selezione dei minuti sarà possibile impartire una durata tra 1 e 60 minuti.
  {
   display.print("Minuti");
   display.setCursor(72,17);
   minTimer=map(VPot,0,1024,1,61);                                        //Viene visualizzata la quantità di tempo selezionabile.
   display.print(minTimer);
   if((vPgFSt2-vPgFSt1)==1)                                               //Se si preme il pulsante interazione...
   {
    totTimer=totTimer+(minTimer*60000);                                     //...vengono sommati al conteggio i minuti selezionati e...
    display.setCursor(85,0);
    display.print("*");                                                     //...viene visualizzato un asterisco che avverte dell'avenuta selezione.
    tTimer=millis();
    timerSt=1;;                                                             //lo stato del timer viene portato ad "attivato".
   }
  }
  else if(StPg1==3)                                                     //Accedendo alla schermata di selezione delle ore sarà possibile impartire una durata tra 1 e 24 ore.
  {
   display.print("Ore");
   display.setCursor(40,17);
   oreTimer=map(VPot,0,1024,1,25);                                        //Viene visualizzata la quantità di tempo selezionabile.
   display.print(oreTimer);
   if((vPgFSt2-vPgFSt1)==1)                                               //Se si preme il pulsante interazione...
   {
    totTimer=totTimer+(oreTimer*3600000);                                   //...vengono sommate al conteggio le ore selezionate e...
    display.setCursor(85,0);
    display.print("*");                                                     //...viene visualizzato un asterisco che avverte dell'avenuta selezione.
    tTimer=millis();
    timerSt=1;;                                                             //lo stato del timer viene portato ad "attivato".
   }
  }
  else if(StPg1==4)                                                     //Accedendo alla schermata di reset del timer è possibile disattivare l'allarme o azzerare il conteggio.
  {
   display.print("Reset");
   display.setCursor(70,17);
   
   if(timerSt==0)                                                         //Se il timer è spento verrà visualizzato un messaggio che dirà che il reset è già stato effettuato: "Ok": 
   {
    display.print("Ok");
   }
   else if((millis()-tTimer)<totTimer || timerSt==2)                      //Se è presente un conteggio in atto o il contatore è in allarme, verrà visualizzato un messaggio che definisce la disponibilità del reset: "nn".
   {
    display.print("nn");
   }

   if(vPgFSt2-vPgFSt1)                                                    //quando si è nella pagina di reset del timer, se si preme il pulsante di interazione, il conteggio verrà portato a zero e il timer sarà spento.
   {
    totTimer=0;                                                             //Azzeramento.
    timerSt=0;                                                              //Stato del timer portato su spento.
   }
  }
  display.display();                                                      //Vengono visualizzati i dati sullo schermo. 

  if(totTimer>172800000)                                                  //viene limitato il timer ad un massimo di 48 ore.
  {
   totTimer=172800000;
  }
 }
 
 else if(Pg==2)                                                     //Schermata di controllo della temperatura ambientale; nome: "Temp.amb.".
 {
  display.print("Tmp.amb.:");
  display.setCursor(0,17);
  if(StPg2==0)                                                          //Se il controllo è disattivato viene visualizzata solo la temperatura letta dal sensore.
  {
   display.print(TempAmb,1);
   display.setCursor(48,17);
   display.print("C-off");
  }
  else if(StPg2==1)                                                     //Se il controllo è attivato viene visualizzata la temperatura letta dal sensore insieme a quella che si vuole raggiungere.
  {
   display.print(TempAmb,1);
   display.setCursor(48,17);
   display.print("-");
   display.setCursor(60,17);
   if(vPgFSt1==0)                                                       //Premendo il pulsante di interazione verrà aggiornato il valore di temperatura desiderato, letto dal potenziometro.
   {
    VTemp=(VPot/64)+22;                                                   //Valore compreso tra i 22°C ed i 38°C
   }
   display.print(VTemp,1);
   display.setCursor(110,17);
   display.print("C");
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 }

 else if(Pg==3)                                                     //Schermata di controllo dell'umidità ambientale; nome: "Um.amb.".
 {
  display.print("Um.amb.:");
  display.setCursor(0,17);

  if(vEl<400 || StPg8==0)                                               //Se il controllo del livello dell'acqua dell'umidificatore è disattivato o il livello è troppo basso, non saarà possibile attvare il controllo dell'umidità.
  {
   StPg3=0;
  }
  
  if(StPg3==0)                                                          //Se il controllo è dissattivato verrà visualizzata solo l'umidità letta dal sensore...
  {
   display.print(UmAmb,1);
   display.setCursor(25,17);
   if(vEl>=400)
   {
    display.print("%-off");                                               //...accompaganta dal messaggio "Off" se il controllo è disattivato
   }
   if(vEl<400 || StPg8==0)
   {
    display.print("%-Err");                                               //...accompaganta dal messaggio "Err" se il controllo del livello dell'acqua è disattivato
   }
  }
  else if(StPg3==1)                                                     //Se il controllo è attivato verrà visualizzata l'umidità letta dal sensore insieme a quella che si vuole raggiungere.
  {
   display.print(UmAmb);
   display.setCursor(25,17);
   display.print("-");
   display.setCursor(40,17);
   if(vPgFSt1==0)                                                       //Premendo il pulsante di interazione verrà aggiornato il valore di umidità desiderato, letto dal potenziometro.
   {
    VUm=map(VPot,0,1023,50,71);                                           //Valore compreso tra 50% e 70%.
   }
   display.print(VUm);
   display.setCursor(65,17);
   display.print("%");
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 }

 else if(Pg==4)                                                     //Schermata di controllo dello stato dei filtri; nome: "Filtri".
 {
  display.print("Filtri:");
  display.setCursor(0,17);
  if(StPg4==0)                                                          //Se il controllo è disattivato viene visualizzato il messaggio "Off".
  {
   display.print("Off");
  }
  
  if(StPg4==1)                                                          //Se il controllo è attivato...
  {
   if(part<=1000)                                                         //...e il sensore rileva poche particelle, viene visualizzato il messaggio "Ok".
   {
    display.print("Ok");
   }
   else if(part>1000)                                                     //...e il sensore rileva tante particelle, viene visualizzato il messaggio "Otturati".
   {
    display.print("Otturati");
   }

   if((millis()-tDM501) >= 9800)                                          //Viene visualizzato un segnale di aggiornamento 200ms prima dell'aggiornamento del dato
   {
    display.setCursor(90,0);
    display.print("*");
   }
  }
    
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 }

 else if(Pg==5)                                                     //Schermata di controllo del rumore; nome: "Rumore".
 {
  display.print("Rumore:");
  display.setCursor(0,17);
  if(StPg5==0)                                                          //Se il controllo è disattivato viene visualizzato il messaggio "Off".
  {
   display.print("Off");
  }
  if(StPg5==1)                                                          //Se il controllo è attivato...
  {
   if(vMic>0.85)                                                          //...e la media del sensore è sopra allo 0.85, quindi il rumore non è esageratamente alto, verrà visualizzato il messaggio "Silenzio".
   {
    display.println("Silenzio");
   }
   if(vMic<=0.85)                                                         //...e la media del sensore è sotto allo 0.85, quindi il rumore è troppo alto, verrà visualizzato il messaggio "Rumore".
   {
    display.println("Rumore");
   }

   if((millis()-tMic)>=4800)                                              //Viene visualizzato un segnale di aggiornamento 200ms prima dell'aggiornamento del dato.
   {
    display.setCursor(90,0);
    display.println("*");
   }
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 } 
 
 else if(Pg==6)                                                     //Schermata di controllo del battito del bambino; nome: "Battito".
 {
  display.print("Battito:");
  display.setCursor(0,17);
  if(StPg6==0)                                                          //Se il controllo è disattivato viene visualizzato il messaggio "Off".
  {
   display.print("Off");
  }
  if(StPg6==1)                                                          //Se il controllo è attivato...
  {
   if(irValue>=100000)                                                    //...e se il valore Ir riflesso è abbastanza alto da essere ottenibile da un dito umano, verranno visualizzati i battiti per minuto.
   {
    display.print(beatsPerMinute,1);
    display.setCursor(70,17);
    display.print("BPM");
   }
   else if(irValue<100000)                                                //...e se il valore Ir riflesso è troppo basso, quindi il dito non è appoggiato, verrà visualizzato il messaggio "nn".
   {
    display.print("nn");
   }
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 }

 else if(Pg==7)                                                     //Schermata di controllo della temperatura del bambimno; nome: "Tmp.bamb.".
 {
  display.print("Tmp.bamb.:");
  display.setCursor(0,17);
  
  if(StPg7==1 || vPgFSt1==0)                                            //Se il sistema di controllo è attivato di fisso da funzione o se tenuto attivo momentaneamente tenendo premuto il pulsante d'interazione, si visualizzerà la temperatura del bambiino.
  {
   display.print(TempBambino);
   display.setCursor(60,17);
   display.print('C');
  }
  else if(StPg7==0)                                                     //Se il controllo è disattivato viene visualizzato il messaggio "Off".
  {
   display.print("Off");
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 }

 else if(Pg==8)                                                     //Schermata di controllo del livello dell'acqua dell'umidificatore; nome: "Cont.um.".
 {
  display.print("Cont.um.:");
  display.setCursor(0,17);
  if(StPg8==0)                                                          //Se il controllo è disattivato viene visualizzato il messaggio "Off".
  {
   display.print("Off");
  }
  else if(StPg8==1)                                                     //Se il controllo è attivato...
  {
   if(vEl>=400)                                                           //...e il valore letto dalls sonda è maggiore di 400, verrà visulaizzato il messaggio "Ok".
   {
    display.print("Ok");
   }

   else if(vEl<400)                                                       //...e il valore letto dalls sonda è minore di 400, verrà visulaizzato il messaggio "Rifornire".
   {
    display.print("Rifornire");
   }
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.
 }
 
 else if(Pg==9)                                                     //Schermata del reset; nome: "Reset".
 {
  display.print("Reset:");
  display.setCursor(0,17);
  if(vPgF1==0||vPgFSt1==0)                                              //Se viene premuto uno soslo dei due pulsanti necessari al riavvio, viene visualizzatoi l messaggio di coferma: "Sicuro?.
  {
   display.print("Sicuro?");
  }
  else                                                                  //Se nessun pulsante è premuto viene visualizzato il messaggio "Puls.G+B", che ricorda come effettuare il riavvio.
  {
   display.print("Puls.G+B");
  }

  if(vPgF1==0&&vPgFSt1==0)                                              //Se vengono premuti entrambi i pulsanti avviene il riavvio.
  {
   digitalWrite(pinReset,HIGH);                                           //viene portato a livello logico alto il pin collegato al transistor che permette il riavvio hardware.
  }
  display.display();                                                    //Vengono visualizzati i dati sullo schermo.

  if((vPgF2-vPgF1)==1)                                                  //Questa parte non dovrebbe interessare a nessuno.
  {
   EeggG++;
  }
  if((vPgFSt2-vPgFSt1)==1)
  {
   EeggB++;
  }
  if((millis()-tEegg)>=3000)
  {
   tEegg=millis();
   EeggG=0;
   EeggB=0;
  }
  if(EeggG==5&&EeggB==5&&VUm==51)
  {
   Pg=-2;
   EeggG=0;
   EeggB=0;
   nEegg=nr;
   tEegg=millis();
  }
 }

 else if(Pg==-2)                                                    //Mi raccomando, questo ciclo non esiste e nessuno lo può leggere, nemmeno tu eh.
 {
  if(nEegg==1)
  {
   display.setTextSize(1);
   display.print("Chi pianta tamarindi non raccoglie");
   display.setCursor(0,16);
   display.print("tamarindi dice");
   display.setCursor(0,24);
   display.print("il saggio.");
  }
  
  else if(nEegg==2)
  {
   display.drawBitmap(0,0 ,EeggPerboni, LOGO_WIDTH, LOGO_HEIGHT, 2);
  }
  
  else if(nEegg==3)
  {
   display.setTextSize(1);
   display.print("Tu mi piaci, ti sei");
   display.setCursor(0,9);
   display.print("meritato un'ampolla!");
  }
  
  else if(nEegg==4)
  {
   display.setTextSize(1);
   display.print("Controlla il bambino invece di toccarmi;");
   display.setCursor(0,16);
   display.print("idiota!");
  }
  
  else if(nEegg==5)
  {
   display.clearDisplay();
   display.display();
   delay(1000);
   
   display.setTextSize(1);
   for(int i = 0; i < 4; i++)
   {
    display.setCursor(25,16);
    display.print("SYSTEM HACKED");
    display.display();
    delay(500);
    display.clearDisplay();
    display.display();
    delay(500);
   }
   delay(2000);
   digitalWrite(pinReset,HIGH);
  }
  
  else if(nEegg==6)
  {
   for(int i = 0; i < 8; i++)
   {
    display.clearDisplay();
    display.drawBitmap(0,0 ,EeggBulaiUp, LOGO_WIDTH, LOGO_HEIGHT, 2);
    display.display();
    delay(300);
    display.clearDisplay();
    display.drawBitmap(0,0 ,EeggBulaiDown, LOGO_WIDTH, LOGO_HEIGHT, 2);
    display.display();
    delay(300);
   }
   display.clearDisplay();
   display.display();
   digitalWrite(pinReset,HIGH);
  }
  
  display.display();
  
  if((millis()-tEegg)>=3000)
  {
   delay(2000);
   digitalWrite(pinReset,HIGH);
  }
 }
}



/*°#°#°#°#°#°#° BME280 °#°#°#°#°#°#°*/

void BME280Lett()                                                 //Lettura dati del sensore BME280.
{
 if(Pg==2||Pg==3||StPg2==1||StPg3==1)                               //Se ci si trova in una pagina o se è presente un controllo attivo relativo a temperatura o umidità ambientale...
 {
  if((millis()-tBME)>500)                                               //...e se è già passato il tempo di aggiornamento...
  {
   if(Pg==2||StPg2==1)                                                    //...Se il controllo o la pagina riguardano la temperatura sarà effettuata la misura della stessa.
   {
   TempAmb=bme280.getTemperature();
   }
   if(Pg==3||StPg3==1)                                                    //...Se il controllo o la pagina riguardano l'umidità sarà effettuata la misura della stessa.                                                 //
   {
   UmAmb=bme280.getHumidity();
   }
   tBME=millis();                                                       //Viene azzerato il tempo di aggiornamento.
  }
 }
}



/*°#°#°#°#°#°#° DM501 °#°#°#°#°#°#°*/

void DM501Lett()                                                  //Lettura dati del sensore DM501.
{
 if(Pg==4 && StPg4==1)                                              //Se ci si trova sulla pagina del controllo dei filtri e il controllo è attivo...
 {
  interr = pulseIn(pinDM501, LOW);                                      //...viene contato il tempo di ogni interruzione...
  interrTot += interr;                                                  //...si fa la somma del tempo delle interruzioni...
  if ((millis()-tDM501) > 10000)                                        //...quando il tempo di aggiornamento è passato si assegna l'intervallo di interruzioni alla variabile "part", usata nella visualizzazione del dato.
  {
   interrTot=abs(interrTot);
   part=interrTot;
   interrTot = 0;
   tDM501 = millis();                                                     //Viene azzerato il tempo di aggiornamento.
  }
 }
}



/*°#°#°#°#°#°#° MICROFONO °#°#°#°#°#°#°*/

void MicLett()                                                    //Lettura dati del microfono.
{
 if(StPg5==1)                                                       //Se il controllo del ruomore è attivato...
 {
  sMic=sMic+digitalRead(pinMic);                                        //...viene campionato se c'è rumore...
 
  if((millis()-tMic)>=5000)                                             //...e ogni volta che si raggiumge l'intervallo di aggiornamento viene calcolato il rapporto di rumorosità "vMic".
  {
   vMic=sMic/145;
   tMic=millis();                                                         //Viene azzerato il tempo di aggiornamento.
   sMic=0;
  }
 }
}



/*°#°#°#°#°#°#° MAX30102 °#°#°#°#°#°#°*/

void MAX30102Lett()                                               //Lettura dati del sensore MAX30102.
{
 if(StPg6==1)                                                       //Se la lettura è attivata...
 {
  irValue = particleSensor.getIR();                                     //...viene misuratoil riflesso di Ir...
  delta=millis()-lastBeat;                                              //...e l'intervallo tra due battiti.  
  
  if (checkForBeat(irValue) == true)                                    //Se il sensore rileva un battito...
  {
   lastBeat=millis();                                                     //...si azzera l'intervallo...
   beatsPerMinute = 60 / (delta / 1000.0);                                //...e si calcolano i battiti al minuto in base all'intervallo di tempo.
  } 
  if(delta>=4000)                                                       //Se non viene registrato un battito per 4 secondi si considera assente.
  {
   beatsPerMinute=0.00;
  }   
 }
}



/*°#°#°#°#°#°#° MLX90614 °#°#°#°#°#°#°*/

void MLX90614Lett()                                               //Lettura dati del sensore MLX90614.
{
 if(StPg7==1 || (Pg==7&&vPgFSt1==0))                                //Se il controllo della temperatura è attivo o se si premem il pulsante d'interazione mentre ci si trova sulla pagina della temperatura del bambino...
 {
  TempBambino=mlx.readObjectTempC();                                    //...verrà misurata la temperatura.
 }
}



/*°#°#°#° CONTROLLO UMIDIFICATORE °#°#°*/

void elettrodiLett()                                              //Lettura dati degli elettrodi dell'umidificatore.
{
 if(StPg8==1)                                                       //Se il controllo della sonda è attivo verrà misurato il valore letto dalla stessa. generalmente viene superato il valore 400 quando è completamente immersa.
 {
  vEl=analogRead(pinEl);
 }
}



/*°#°#°#°#°#°#° OUTPUT °#°#°#°#°#°#°*/

void outputAmb()                                                  //Gestione degli output ambientali
{
 if(StPg2==0)                                                       //Se non è attivo il controllo di temperatura...
 {
  analogWrite(pinResist,0);                                             //...la resistenza di riscaldamento e la richiesta di ventilazione per il riscaldamento è zero.
  ventRicTemp=0;
 }
 if(StPg2==1)                                                       //Se il controllo di temperatura è attivo...
 {
  if((VTemp-TempAmb)<=-2)                                               //...e si superano i due gradi di differenza (positiva) dalla temperatura desiderata...
  {
   analogWrite(pinResist,0);                                              //...la resistenza di riscaldamento è portata a zero e...
   ventRicTemp=2;                                                         //...la richiesta di ventilazione per il riscaldamento è 2.
  }
  else if((VTemp-TempAmb)>=-2 && (VTemp-TempAmb)<=-0.5)                 //...e si è tra i due e il mezzzo grado di differenza (positiva) dalla temperatura desiderata...
  {
   analogWrite(pinResist,0);                                              //...la resistenza di riscaldamento è portata a zero e...
   ventRicTemp=1;                                                         //...la richiesta di ventilazione per il riscaldamento è 1.
  }
  else if((VTemp-TempAmb)>=-0.5 && (VTemp-TempAmb)<=0.5)                //...e si ha +- mezzo grado di differenza dalla temperatura desiderata...
  {
   analogWrite(pinResist,0);                                              //...la resistenza di riscaldamento è portata a zero e...
   ventRicTemp=0;                                                         //...la richiesta di ventilazione per il riscaldamento è zero.
  }
  else if((VTemp-TempAmb)>=0.5 && (VTemp-TempAmb)<=2)                   //...e si è tra i due e il mezzzo grado di differenza (negativa) dalla temperatura desiderata...
  {
   analogWrite(pinResist,75);                                             //...la resistenza di riscaldamento è portata ad un'accensione lieve e...
   ventRicTemp=1;                                                         //...la richiesta di ventilazione per il riscaldamento è 1.
  }
  else if((VTemp-TempAmb)>2)                                            //...e si superano i due gradi di differenza (negativa) dalla temperatura desiderata...
  {
   analogWrite(pinResist,150);                                            //...la resistenza di riscaldamento è portata ad un'accensione media e...
   ventRicTemp=2;                                                         //...la richiesta di ventilazione per il riscaldamento è 2.
  }
 }
 
 if(StPg3==0)                                                       //Se non è attivo il controllo di umidità...
 {
  analogWrite(pinUmidif,0);                                             //...la resistenza dell'umidificatore e la richiesta di ventilazione per l'umidificazione è zero.
  ventRicUm=0;
 }
 if(StPg3==1)                                                       //Se il controllo dell'umidità è attivo...
 {
  if((VUm-UmAmb)>=-5)                                                   //...e si supera il 5% di differenza (positiva) dall'umidità desiderata...
  {
   analogWrite(pinUmidif,0);                                              //...la resistenza dell'umidificatore è portata a zero e...
   ventRicUm=2;                                                           //...la richiesta di ventilazione per l'umidificazione è 2.
  }
  else if((VUm-UmAmb)>=-5 && (VUm-UmAmb)<=-2)                           //...e si è tra il 5% e il 2%  di differenza (positiva) dall'umidità desiderata...
  {
   analogWrite(pinUmidif,0);                                              //...la resistenza dell'umidificatore è portata a zero e...
   ventRicUm=1;                                                           //...la richiesta di ventilazione per l'umidificazione è 1.
  }
  else if((VUm-UmAmb)>=-2 && (VUm-UmAmb)<=2)                            //...e si ha +- 2% di differenza dall'umidità desiderata...
  {
   analogWrite(pinUmidif,0);                                              //...la resistenza dell'umidificatore è portata a zero e...
   ventRicUm=0;                                                           //...la richiesta di ventilazione per l'umidificazione è zero.
  }
  else if((VUm-UmAmb)>=2 && (VUm-UmAmb)<=5)                             //...e si è tra il 5% e il 2%  di differenza (negativa) dall'umidità desiderata...
  {
   analogWrite(pinUmidif,75);                                             //...la resistenza dell'umidificatore è portata ad un'accensione lieve e...
   ventRicUm=1;                                                           //...la richiesta di ventilazione per l'umidificazione è 1.
  }
  else if((VUm-UmAmb)>5)                                                //...e si supera il 5% di differenza (negativa) dall'umidità desiderata...
  {
   analogWrite(pinUmidif,150);                                            //...la resistenza dell'umidificatore è portata ad un'accensione media e...
   ventRicUm=2;                                                           //...la richiesta di ventilazione per l'umidificazione è 2.
  }
 }

 ventRic=ventRicTemp+ventRicUm;                                     //Si calcola la richiesta totale di ventilazione sommando quelle di riscaldamento ed umidificazione.
 
 if(ventRic==4)                                                         //Se la richiesta totale è 4...
 {
  analogWrite(pinVent,150);                                               //...la ventilazione viene accesa con un valore medio-alto.
 }
 else if(ventRic>=2)                                                    //Se la richiesta totale è 2 o 3...
 {
  analogWrite(pinVent,100);                                               //...la ventilazione viene accesa con un valore medio.
 }
 else if(ventRic==1)                                                    //Se la richiesta totale è 1...
 {
  analogWrite(pinVent,50);                                                //...la ventilazione viene accesa con un valore basso.
 }
 else if(ventRic==0)                                                    //Se la richiesta totale è zero...
 {
  analogWrite(pinVent,0);                                                 //...la ventilazione viene spenta.
 }
}

void outputAll()                                                  //Gestione degli allarmi
{
 if((millis()-tTimer)>totTimer && timerSt==1)                       //Se il timer stava conteggiando e esaurisce il tempo il suo stato va in allarme
 {
  timerSt=2;
 }
 
 if(( timerSt==2 || (vMic<0.85 && StPg5==1) || (beatsPerMinute<30 && StPg6==1 && irValue>=100000) || (TempBambino>38.5 && (StPg7==1 || (Pg==7&&vPgFSt1==0))) || (vEl<400 && StPg8==1))&&Pg!=-2)  //Quando una pagina allarmata esce dai parametri standard...
 {
  if((millis()-tAll)>=500)                                          //...si attiva l'allarme con alternanaza di 500ms.
  {
   tAll=millis();
   AllSt=1-AllSt;                                                     //viene alternzato il valore dell'allarme.
  }
 }
 else                                                             //Se i parametri sono nella norma...
 {
  AllSt=0;                                                            //...l'allarme resta spento...
  tAll=millis();                                                      //... el'aggiornamento dell'allarme si ferma.
 }

 if(AllSt==0)                                                     //Se l'allarme è spento...
 {
  display.invertDisplay(false);                                       //...il colore del display è quello classico...
  digitalWrite(pinBuzzer,LOW);                                        //...e il buzzer resta spento.
 }
 else if(AllSt==1)                                                //Se l'allarme è acceso...
 {
  display.invertDisplay(true);                                        //...il colore del display è invertito...
  digitalWrite(pinBuzzer,HIGH);                                       //...e il buzzer viene acceso.
 }
}



/*°#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#° FINE SEZIONE LOOP °#°#°#°#°#°#°°#°#°#°#°#°#°°#°#°#°#°#°#°*/
