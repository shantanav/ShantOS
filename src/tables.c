#include "drivers.h"

void create_tables() {
    gdt_t gdt;
    gdt.address = 0x800;
    gdt.size = 65535;

    load_gdt(&gdt);
}
