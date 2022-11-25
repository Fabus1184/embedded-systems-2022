#include <stdio.h>
#include <stdint.h>
#include <sys/alt_irq.h>

#define KEY_IRQ 1
#define LED_ADDRESS 0xFF200000
#define KEY_ADDRESS 0xFF200050
#define KEY_INT_ADDRESS 0xFF200058
#define KEY_EC_ADDRESS 0xFF20005C

void isr_keys(void *context, uint32_t id) {
	*(uint32_t*) LED_ADDRESS = *(uint32_t*) KEY_EC_ADDRESS;
	*(uint32_t*) KEY_EC_ADDRESS = 0xF;
}

int main() {
	*(uint32_t*) KEY_INT_ADDRESS = 0b1111;
	alt_irq_register(KEY_IRQ, NULL, isr_keys);

	while (1) {
	}

	return 0;
}
