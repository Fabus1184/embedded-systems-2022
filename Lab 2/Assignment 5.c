#include "../Lab2A4/main.h"
#include "DeviceDriverI2C.h"

#include <stdio.h>
#include <math.h>

int main(void) {
	CHECK(I2C_init(), INIT_ERRORS);
	CHECK(I2C_open(I2CSPEED400), OPEN_ERRORS);

	while (1) {
		int16_t values[1000];
		for (int i = 0; i < 1000; ++i) {
			int c = ADC_read(0, values + i);

			if (c != 0) {
				printf("Error reading ADC!\n");
				return 1;
			}
		}

		int16_t max = 0, min = 0x7FFF;
		double mean = 0;

		for (int i = 0; i < 1000; ++i) {
			if (values[i] > max) {
				max = values[i];
			}

			if (values[i] < min) {
				min = values[i];
			}

			mean += values[i];
		}

		mean /= 1000;

		double variance = 0;

		for (int i = 0; i < 1000; ++i) {
			variance += pow(values[i] - mean, 2);
		}

		variance /= 1000;

		double stddev = sqrt(variance);

		printf("max:\t%d\tmV\n", max);
		printf("min:\t%d\tmV\n", min);
		printf("mean:\t%.1f\tmV\n", mean);
		printf("variance:\t%.3f\tµV²\n", variance);
		printf("stddev:\t%.1f\tmV\n", stddev);

		printf("Press any key to repeat...\n");
		getchar();
	}
}

