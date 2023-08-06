#include <ZMPT101B.h>

#define VOLTAGE_SENSOR_PIN A0

ZMPT101B voltageSensor(VOLTAGE_SENSOR_PIN);
// PATATE douce

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // Set zero point while sensor is live
  voltageSensor.calibrateLive();

  // To measure the voltage we need to know the frequency
  // By default 50Hz is used, but you can specify the desired frequency
  // as the first argument for "getVoltageAC()"
  float V = voltageSensor.getVoltageAC();

  Serial.println(String(V) + " V");

  delay(1000);

}



