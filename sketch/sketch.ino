// Inclus la librairie pour interfacer avec le sensor
#include <zmpt101b.h>

// Initialise 
ZMPT101B voltageSensor(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {  
  auto V = voltageSensor.getMaxRMSVoltage();
  Serial.println(String(V));
  delay(100);

}



