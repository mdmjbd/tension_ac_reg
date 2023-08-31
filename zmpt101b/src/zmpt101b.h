#ifndef ZMPT101B_h
#define ZMPT101B_h

#include <Arduino.h>

#define ADC_SCALE 1023.0
#define ZEROPOINT 512
#define FREQUENCY_HZ 60
#define ZMPT101B_VOLTAGE_RANGE 500.0
// #define PATATE 1.4467404743076762

class ZMPT101B {
public:
	ZMPT101B(uint8_t _pin);
	void setZeroPoint(uint16_t _zero);
    void setFrequency(uint16_t _frequency_hz);
	float getInstantRMSVoltage();
    float getMaxRMSVoltage();

private:
	uint16_t zero = ZEROPOINT;
    uint16_t frequency_hz = FREQUENCY_HZ;
	uint8_t pin;
};

#endif