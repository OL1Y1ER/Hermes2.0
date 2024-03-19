const int pin = 8; 

//For SYNCING purposes
int startZeit =0;
int stopZeit =0;
int diffTime = 0;
bool stopp = false;

void setup() {
  pinMode(pin, INPUT);
  Serial.begin(2000000);
}

int testData[] = {2};
void loop() {
  if(diffTime == 0){
    Sync();
  }
  else{
    SendingMessages(testData);   
  }  
}



void SendingMessages(int text[]){
  /*
  delay(diffTime);
  digitalWrite(pin, HIGH);
  delay(diffTime);
  digitalWrite(pin, LOW);
  */
  //8bit Sending info
   //Teszing sending some info
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < testData[i]; j++){
      delay(diffTime);
      digitalWrite(pin, HIGH);
      
    }
    delay(diffTime);
    digitalWrite(pin, LOW);
    
  }
   
}


void Sync(){
  if(digitalRead(pin)&!stopp){
    startZeit = millis();
    stopp =true;
  }
  else if(stopp & !digitalRead(pin)){
    stopZeit = millis();
    diffTime = stopZeit-startZeit;
    pinMode(pin,OUTPUT);
    stopp = false;
  }
}
