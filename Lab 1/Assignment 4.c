#include <stdio.h>
#include <stdint.h>
#include <sys/alt_irq.h>

#define KEY_IRQ 1
#define LED_ADDRESS *(volatile uint32_t*) 0xFF200000
#define KEY_ADDRESS *(volatile uint32_t*) 0xFF200050
#define KEY_INT_ADDRESS *(volatile uint32_t*) 0xFF200058
#define KEY_EC_ADDRESS *(volatile uint32_t*) 0xFF20005C
#define PIO_ADDRESS *(volatile uint32_t*) 0xff204060
#define PIO_DIR_ADDRESS *(volatile uint32_t*) 0xff204064

void isr_keys(void *context, uint32_t id) {
	PIO_ADDRESS |= 0b1;

	LED_ADDRESS = KEY_EC_ADDRESS;
	KEY_EC_ADDRESS = 0xF;

	PIO_ADDRESS &= 0b0;
}

int main() {
	KEY_INT_ADDRESS = 0b1111;
	alt_irq_register(KEY_IRQ, NULL, isr_keys);

	PIO_DIR_ADDRESS |= 0b1;

	while (1) {
	}

	return 0;
}
