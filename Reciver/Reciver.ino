const int pin = 8;
const int frequency = 23;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(2000000);
  Sync();


}

void loop() {
  
  Output();
 
}

void Sync(){
  digitalWrite(pin, HIGH);
  delay(frequency);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
}

int counting =0;
//Format of Input?
String Output(){
  delay(frequency);
 
  Serial.print(digitalRead(pin)); //For printing out
  //return Reformat(digitalRead(pin));

}
/*
String Reformat(String data){
  return data;
}
*/
