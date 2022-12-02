#pragma once

#include <inttypes.h>
#include <stdio.h>
#include "DeviceDriverI2C.h"

#define ADC_ADDRESS 0x28
#define V_REF 5.D

enum ADC_CHANNEL {
	CH0, CH1, CH2, CH3, CH4, CH5, CH6, CH7
};

#define CHECK(x, errors) \
	if (x != 0) { \
		printf("%s\n", errors[-x]);  \
		return x; \
	}

const char* WRITE_ERRORS[] = { "successful operation", "device not active",
		"no ack after sending i2c_address", "no ack after sending i2c_data" };

const char* READ_ERRORS[] = { "successful operation", "device not active",
		"no ack after sending i2c_address", "i2c_data is a null pointer" };

const char* INIT_ERRORS[] = { "successful operation", "wrong initial state" };

const char* OPEN_ERRORS[] = { "successful operation", "device not initialized",
		"illegal I2C clock rate" };

int ADC_read(enum ADC_CHANNEL ch, int16_t *val) {
	CHECK(I2C_write(ADC_ADDRESS, 0x80 + ch), WRITE_ERRORS);
	uint16_t data;
	CHECK(I2C_read(ADC_ADDRESS, &data), READ_ERRORS);
	*val = round(1000 * V_REF * (double) data / (pow(2, 12) - 1));
	return 0;
}
