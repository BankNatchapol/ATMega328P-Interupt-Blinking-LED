#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
volatile int pressed = 0;

ISR(INT0_vect) {
    
    _delay_ms(30);
    
    if (pressed) {
        pressed = 0;
    } else {
        pressed = 1;
    }
      
}

void init_int0() {
    EICRA |= (1 << ISC01);
    EIMSK |= (1 << INT0);
    
}

int main(void) {

    
    DDRB |= (1 << DDB1);
    PORTB &= ~(1 << PORTB1);
    
    init_int0();
    sei();

    while (1) {
        
        if((PIND & (1 << PIND2)) == 0) {
            if(pressed)
                pressed = 0;
            else
                pressed = 1;
            
            _delay_ms(10);
            
            while((PIND & (1 << PIND2)) == 0);
            _delay_ms(10);
        }
        
        if(pressed)
            PORTB ^= (1 << PORTB1);
        
        else
            PORTB &= ~(1 << PORTB1);  
        _delay_ms(100);
    }
}
