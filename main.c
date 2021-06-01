#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "MCP42.h"


void ramp(){
    uint8_t firstValue = 2;
    uint8_t lastValue = 16;
    uint8_t step = 1;
    int delay = 20;
    uint8_t currentValue = firstValue;

    while(currentValue < lastValue) {
        setWiper(currentValue, Zero);
        currentValue += step;
        _delay_ms(delay);
    }
    while(currentValue > firstValue) {
        setWiper(currentValue, Zero);
        currentValue -= step;
        _delay_ms(delay);
    }
}


int main(void)
{
    initSPI();
    while(1) {
        ramp();
    }
    //setWiper(0, Zero);
    //setShutdown();
}
