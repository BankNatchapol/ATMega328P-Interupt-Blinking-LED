#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT0_vect) {
    
    _delay_ms(30);
    TCCR1B ^= (1 << CS12);
    
}

void init_int0() {
    EICRA |= (1 << ISC01);
    EIMSK |= (1 << INT0);
    
}

void init_timer1(uint16_t count) {
    TCCR1A |= (1 << COM1A0);
    TCCR1B |= (1 << WGM12);
    OCR1A = count;
}


int main(void) {
    DDRB |= (1 << DDB1);
    PORTB &= ~(1 << PORTB1);
    
    init_int0();
    sei();
    
    init_timer1(3125);

    while (1) {

    }
}
