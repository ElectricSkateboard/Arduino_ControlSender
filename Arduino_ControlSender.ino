#include <SoftwareSerial.h>

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

SoftwareSerial Bluetooth(8, 9);

void setup() {
  // initialize serial communications at 9600 bps:
  Bluetooth.begin(115200);
  //Serial.begin(115200);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  Bluetooth.write(outputValue);
  //Serial.println(outputValue);

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(5);
}
