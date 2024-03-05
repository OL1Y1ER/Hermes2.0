const int pin = 8;
bool mG = false;
int altI;

void setup() {
  // put your setup code here, to run once:
pinMode(pin, OUTPUT);
Serial.begin(9600);
Sync();


}

void loop() {

  pinMode(pin, INPUT);
delay(500);
Serial.print(digitalRead(pin));
  // put your main code here, to run repeatedly:
  /*
  for(int i =0; i<= 100; i++){
    if(!mG){
      digitalWrite(13, HIGH);
      mG = true;
      altI = i;
    }
    else if(mG && altI != i){
      mG = false;
    }
    
  
  
  }
  */
}

void Sync(){
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
 }
