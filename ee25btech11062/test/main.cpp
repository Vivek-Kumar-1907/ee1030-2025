#include <avr/io.h>
#include <util/delay.h>

// Define the CPU frequency for the delay function (16MHz for Uno)
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

int main(void) {
    // Set Pin 13 (Port B, Pin 5) as an OUTPUT
    // DDRB is the Data Direction Register for Port B
    DDRB |= (1 << DDB5);

    while (1) {
        // Set Pin 13 HIGH (PORTB5)
        PORTB |= (1 << PORTB5);
        _delay_ms(2000);

        // Set Pin 13 LOW
        PORTB &= ~(1 << PORTB5);
        _delay_ms(100);
    }

    return 0;
}
