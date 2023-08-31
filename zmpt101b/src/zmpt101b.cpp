#include "ZMPT101B.h"

ZMPT101B::ZMPT101B(uint8_t _pin) {
	pin = _pin;
}

void ZMPT101B::setZeroPoint(uint16_t _zero) {
	zero = _zero;
}

void ZMPT101B::setFrequency(uint16_t _frequency_hz) {
	frequency_hz = _frequency_hz;
}

float ZMPT101B::getInstantRMSVoltage() {
  int v_data = analogRead(pin) - zero;
  float v_current = v_data / sqrt(2) * ADC_SCALE / ZMPT101B_VOLTAGE_RANGE;
  return v_current;
}

float ZMPT101B::getMaxRMSVoltage() {
  auto v_max = 0.0;
  auto period = 1000000 / frequency_hz;
  auto t_start = micros();
  while (micros() - t_start < period) {
    auto v_current = abs(getInstantRMSVoltage());
    if (v_current > v_max) {
      v_max = v_current;
    }
  }
  return v_max;
}