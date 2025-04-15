#pragma once

#include <inttypes.h>
#include <avr/io.h>

namespace mcp {

// Temp location
enum Error: uint8_t {
    kInvalidIndex = 1,
};

enum Pot: uint8_t {
    Zero = 0,
    One = 1,
};

class MCP42 {
    public:
        /**
         * @brief Initialize SPI for this module
         */
        void init() const;

        /**
         * @brief Sets the wiper of a specific pot to a specific value
         *
         * @param pot The potentiometer to set
         *
         * @param value The value to update the potentiometer with
         */
        void setWiper(Pot pot, uint8_t value) const;

        /**
         * @brief Set a potentiometer to low power mode
         */
        void setShutdown(Pot pot) const;

        /**
         * @brief Set both potentiometers to low power mode
         */
        void setShutdown() const;

        /**
        TODO update to handle daisy chaining
        std::Expected<Void, Error> setWiper(uint8_t index, Pot pot, uint8_t value) {
        void write()

        private:
        constexpr static uint8_t kPotsPerChip{2};
        constexpr uint8_t kChipCount{1};
        constexpr uint8_t kPotCount{kChipCount * 2};
        // chip0pot0, chip0pot1, chip1pot0, chip1pot1
        uint8_t data[kPotCount] {0};
         */
    private:
        void initSPI() const;
        void writeSPI(const uint8_t data) const;
        void chipSelectHigh() const;
        void chipSelectLow() const;

        constexpr static uint8_t kCSPin{PB3};
        constexpr static uint8_t kDOPin{PB1};
        constexpr static uint8_t kSCKPin{PB2};
        // constexpr static uintptr_t kPort{&PORTB};
};

} // mcp
