#include <zmpt101b.h>

ZMPT101B voltageSensor(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {  
  // To measure the voltage we need to know the frequency
  // By default 50Hz is used, but you can specify the desired frequency
  // as the first argument for "getVoltageAC()"
  auto V = voltageSensor.getMaxRMSVoltage();
  // auto V = getInstantVoltage(A0);
  // float V = voltageSensor.getVoltageAC(60);

  Serial.println(String(V));

  delay(100);

}



