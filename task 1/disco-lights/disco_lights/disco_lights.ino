// Khwanchanok Chaichanayothinwatchara 6280164

#define LEFT 0
#define RIGHT 1

int allPins[] = {2,3,4, 5, 6, 7};
int pinsNum = 6;
int side = LEFT;
int currentPinIndex = 0;
long interval;
unsigned long previousOffTime = 0;

void setup() {
  for (int i = 0; i < pinsNum; i++) {
     pinMode(allPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

int direction(int sensorValue) {
  if (sensorValue > 511) {
    return LEFT;
  } else {
    return RIGHT;
  }
}

int setInterval(int sensorValue) {
  if (sensorValue < 64 || sensorValue > 959) {
    interval = 50;
  } else if ((sensorValue >= 64 && sensorValue < 128) || (sensorValue > 895 && sensorValue <= 959)) {
    interval = 150;
  } else if ((sensorValue >= 128 && sensorValue < 192) || (sensorValue > 831 && sensorValue <= 895)) {
    interval = 250;
  } else if ((sensorValue >= 192 && sensorValue < 256) || (sensorValue > 767 && sensorValue <= 831)) {
    interval = 350;
  } else if ((sensorValue >= 256 && sensorValue < 320) || (sensorValue > 703 && sensorValue <= 767)) {
    interval = 350;
  } else if ((sensorValue >= 320 && sensorValue < 384) || (sensorValue > 639 && sensorValue <= 703)) {
    interval = 450;
  } else if ((sensorValue >= 384 && sensorValue < 448) || (sensorValue > 575 && sensorValue <= 639)) {
    interval = 550;
  } else {
    interval = 650;
  } 
  return interval;
}

void loop() {
  digitalWrite(allPins[currentPinIndex], HIGH);
  int sensorValue = analogRead(A0);
  interval = setInterval(sensorValue);
  side = direction(sensorValue);
  unsigned long currentMillis = millis();
  if(currentMillis - previousOffTime >= interval) {
    previousOffTime = currentMillis;   
    digitalWrite(allPins[currentPinIndex], LOW);
    if (side == RIGHT) {
      if (currentPinIndex == 5) {
        currentPinIndex = 0;
      } else {
        currentPinIndex++;
      }
    } else {
      if (currentPinIndex == 0) {
        currentPinIndex = 5;
      } else {
        currentPinIndex--;
      }
    }
  }
}
