#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "mcp42.h"

constexpr mcp::MCP42 mcp42{};

int main(void) {
    DDRB = 0;
    PORTB = 0;
    mcp42.init();
    uint8_t i = 10;

    while(true) {
        mcp42.setWiper(mcp::Pot::Zero, i);
        _delay_ms(20);
        i++;
        if(i > 20) {
            i = 0;
        }
    }
    return 0;
}
