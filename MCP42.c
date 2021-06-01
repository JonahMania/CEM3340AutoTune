#include "MCP42.h"

#define CS_PIN 3
#define DO_PIN 5
#define DI_PIN 6
#define SCK_PIN 4

void initSPI() {
    DDRA |= (1 << CS_PIN);
    DDRA |= (1 << DO_PIN);
    DDRA |= (1 << SCK_PIN);
    DDRA &= ~(1 << DI_PIN);
    PORTA |= (1 << DI_PIN);
}


uint8_t writeSPI(uint8_t data) {
    USIDR = data;
    USISR = (1 << USIOIF);

    while ((USISR & (1 << USIOIF)) == 0) {
        USICR = (1<<USIWM0)|(1<<USICS1)|(1<<USICLK)|(1<<USITC);
    }

    return USIDR;
}


void setWiper(uint8_t value, Pot pot) {
    // SET CS LOW
    PORTA &= ~(1 << CS_PIN);

    //if(pot == Zero) {
        writeSPI(0b00010001);
    //}
    //if(pot == One) {
    //    writeSPI(0b00010010);
    //}

    writeSPI(value);

    // SET CS HIGH
    PORTA |= (1 << CS_PIN);
}

void setShutdown() {

}
