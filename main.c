#include "MCP42.h"

int main() {
    initSPI();
    setWiper(128, Zero);
    return 0;
}
