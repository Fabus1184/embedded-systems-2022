#include <stdio.h>

#include "DeviceDriverI2C.h"

#define ADC_ADDRESS 0x28

#define CHECK(x) if (x != 0) { \
	printf("%s\n", errors[-x]); \
	}

const char* errors = {
		 "successful operation",
		 "device not active",
		 "no ack after sending i2c_address",
		 "i2c_data is a null pointer"
};

int main(void) {
	CHECK(I2C_init());
	CHECK(I2C_open(I2CSPEED400));

	uint16_t data = 0;
	while (1) {
		uint16_t new_data;
		CHECK(I2C_write(ADC_ADDRESS, 0x80));
		CHECK(I2C_read(ADC_ADDRESS, &new_data));
		if (abs(data - new_data) > 2) {
			printf("%d\n", new_data);
			data = new_data;
		}
	}
}
