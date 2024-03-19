String test;
int MyArray[50];
int n = 0;
long lastB;


void setup() {
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
    MyArray[n] = Serial.read();
    Serial.println(MyArray[n]);
    Serial.println(n);
    n = n + 1;
    lastB = millis;
  } else {
    if(millis - lastB > 10000){
      n = 0;
    }
  }
  delay(1);
}
