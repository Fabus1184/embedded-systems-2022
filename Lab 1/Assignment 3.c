#include <inttypes.h>
#include <stdio.h>

#define LED_ADDRESS 0xFF200000
#define KEY_ADDRESS 0xFF200050
#define KEY_EC_ADDRESS 0xFF20005C

uint32_t poll_keys(void) {
    return 0b1111 & *(uint32_t*) KEY_ADDRESS;
}

void write_leds(uint32_t leds) {
    *(uint32_t*) LED_ADDRESS = leds;
}

int main(void) {
    uint32_t last_keys = 0;

    while (1) {
    	uint32_t new_keys = poll_keys();

    	if ((last_keys & 0b1) == 0 && (new_keys & 0b1) == 1) {
    		write_leds(0b1);
    	} else if(((last_keys >> 1) & 0b1) == 0 && ((new_keys >> 1) & 0b1) == 1) {
    		write_leds(0b10);
    	} else if(((last_keys >> 2) & 0b1) == 0 && ((new_keys >> 2) & 0b1) == 1) {
    		write_leds(0b100);
    	} else if(((last_keys >> 3) & 0b1) == 0 && ((new_keys >> 3) & 0b1) == 1) {
    		write_leds(0b1000);
    	}

    	last_keys = new_keys;
    }
}
