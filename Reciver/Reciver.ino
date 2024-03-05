const int pin = 8;

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
 
}

void Sync(){
  digitalWrite(pin, HIGH);
  delay(500);
  digitalWrite(pin, LOW);
}
