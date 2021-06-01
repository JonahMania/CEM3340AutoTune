#include <avr/io.h>
#include <inttypes.h>

typedef enum {Zero, One} Pot;

void initSPI();
void setWiper(uint8_t value, Pot pot);
void setShutdown();
