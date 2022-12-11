float vin = 5;
float rref = 1000;
float res = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  float vout = (vin * sensorValue) / 1023;
  res = rref * (1/((vin/vout)-1));
  Serial.println(res);
  delay(3000);
}
