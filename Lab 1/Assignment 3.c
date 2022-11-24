#include <inttypes.h>

#define LED_ADDRESS 0xFF200000
#define KEY_ADDRESS 0xFF200050
#define KEY_EC_ADDRESS 0xFF20005C

uint8_t poll_keys(void) {
    return 0b00001111 & *(uint8_t*) KEY_ADDRESS;
}

void write_leds(uint8_t leds) {
    *(uint8_t*) LED_ADDRESS = leds;
}

int32_t main(void) {
    uint8_t state = 0;
    while (1) {
        uint8_t new_state = state ^ poll_keys();
        if (new_state != state) {
            state = new_state;
            write_leds(state);
        }
    }
}