int prevVal = 0;
int count = -1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0); 
  if (sensorValue - prevVal >= 45) {
    count++;
    Serial.println(count);
  }
  prevVal = sensorValue;
  delay(1000);
}
