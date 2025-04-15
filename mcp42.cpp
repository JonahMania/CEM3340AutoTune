#include "mcp42.h"

namespace mcp {

void MCP42::init() const {
    initSPI();
}

void MCP42::setWiper(Pot pot, uint8_t value) const {
    chipSelectHigh();
    writeSPI(pot == Zero ? 0b00010001 : 0b00100010);
    writeSPI(value);
    chipSelectLow();
}

void MCP42::setShutdown(Pot pot) const {
    chipSelectHigh();
    writeSPI(pot == Zero ? 0b00100001 : 0b00100010);
    // Shutdown still requires the data bytes to be writtern but they have no effect
    writeSPI(0);
    chipSelectLow();
}

void MCP42::setShutdown() const {
    setShutdown(Zero);
    setShutdown(One);
}

/**
 * @brief Init SPI communication
 */
void MCP42::initSPI() const {
    DDRB |= _BV(kCSPin);
    DDRB |= _BV(kDOPin);
    DDRB |= _BV(kSCKPin);
    USICR = _BV(USIWM0);
}

/**
 * @brief Write one byte to SPI
 *
 * @param data A single byte to write to SPI
 */
void MCP42::writeSPI(const uint8_t data) const {
    USIDR = data;
    USISR = _BV(USIOIF);
    while ((USISR & _BV(USIOIF)) == 0) {
        USICR = _BV(USIWM0) | _BV(USICS1) | _BV(USICLK) | _BV(USITC);
    }
}

/**
 * @brief Set the chip select pin high
 */
void MCP42::chipSelectHigh() const {
    PORTB &= ~_BV(kCSPin);
}

/**
 * @brief Set the chip select pin low
 */
void MCP42::chipSelectLow() const {
    PORTB |= _BV(kCSPin);
}

} //mcp
