#include <stdio.h>

#include "DeviceDriverI2C.h"

#include "main.h"

int main(void) {
	CHECK(I2C_init(), INIT_ERRORS);
	CHECK(I2C_open(I2CSPEED400), OPEN_ERRORS);

	int16_t prev = 0;
	while (1) {
		int16_t value;
		ADC_read(0, &value);
		if (abs(value - prev) > 0) {
			prev = value;
			printf("%d\n", prev);
		}
	}

}

