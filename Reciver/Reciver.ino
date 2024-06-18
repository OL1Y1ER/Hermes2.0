const int pin = 8;
const int frequency = 250;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  Sync();


}

void loop() {
  if(digitalRead(pin)){
  Output();
  }
}

void Sync(){
  digitalWrite(pin, HIGH);
  delay(frequency);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
}


//Format of Input?
String Output(){

  for(int i = 1; i <= 8 ; i++){
  delay(frequency);

  
  Serial.print(digitalRead(pin)); //For printing out
  //return Reformat(digitalRead(pin));
  }
  Serial.println();
}
String Reformat(String data){
  return data;
}
