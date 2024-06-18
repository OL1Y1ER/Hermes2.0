const int pin = 8;

//For SYNCING purposes
int startZeit = 0;
int stopZeit = 0;
int diffTime = 0;
bool stopp = false;



String test;
int MyArray[50];
int dieLaengeDerNachricht = 0;
int y;
int binArray[8];



void setup() {
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (diffTime == 0) {
    Sync();
  }
  else {
    //SendingMessages();
    SaveInArray();
    
    for (int i = 0; i <= dieLaengeDerNachricht ; i++) {
      DeztoBin(i);
    }
  }
}
/*
  void SendingMessages(){//int text[]){
  /*
  delay(diffTime);
  digitalWrite(pin, HIGH);
  delay(diffTime);
  digitalWrite(pin, LOW);
*/


//8bit Sending info




void Sync() {
  if (digitalRead(pin) & !stopp) {
    startZeit = millis();
    stopp = true;
    Serial.println("Synch1");
  }
  else if (stopp & !digitalRead(pin)) {
    stopZeit = millis();
    diffTime = stopZeit - startZeit;
    pinMode(pin, OUTPUT);
    stopp = false;
    Serial.println("Synch2");
  }
}

//other half





void SaveInArray() {
  Serial.println("SiA");

  long lastB;
  dieLaengeDerNachricht = 0;
  boolean ende = false;
  while (Serial.available() <= 0) {

  }
  while (ende == false) {
    if (Serial.available() > 0) {
      MyArray[dieLaengeDerNachricht] = Serial.read();
      Serial.println(MyArray[dieLaengeDerNachricht]);
      dieLaengeDerNachricht++;
      lastB = millis();
    } else {
      if (millis() - lastB >= 10000) {
        ende = true;
      }
    }

  }
  dieLaengeDerNachricht--;

}

void DeztoBin(int ArrayLocation) {
  int dez = MyArray[ArrayLocation];
  for (int i = 7 ; i >= 0; i--) {
    y = dez % 2;
    binArray[i] = y;
    dez = dez / 2;
  }
  /*prints bin
  Serial.println();
  for (int j = 0; j <= 7; j++) {
    Serial.print(binArray[j]);
  }
  */
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
  Serial.println();
  //ubertragung();
  for (int i = 1; i <= 8; i++) {
    delay(diffTime);
  
    digitalWrite(pin, binArray[i]);
  }
  
}
