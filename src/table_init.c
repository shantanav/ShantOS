#include "gdt.h"

#define SEGMENT_DESCRIPTOR_COUNT 3

#define SEGMENT_BASE 0
#define SEGMENT_LIMIT 0xFFFFF

#define SEGMENT_CODE_TYPE 0x9A
#define SEGMENT_DATA_TYPE 0x92

#define SEGMENT_GRANULARITY 0xCF

static gdt_entry_t gdt_entries[SEGMENT_DESCRIPTOR_COUNT];

void gdt_set_gate(int index, unsigned int base_address, unsigned int limit, unsigned char access_byte, unsigned char gran) {
	gdt_entries[index].base_low = base_address & 0xFFFF;
	gdt_entries[index].base_middle = (base_address >> 16) & 0xFF;
	gdt_entries[index].base_high = (base_address >> 24) & 0xFF;
    gdt_entries[index].access_byte = access_byte;
	gdt_entries[index].limit_low = limit & 0xFFFF;
  	gdt_entries[index].granularity = gran;
}

void create_tables() {
	gdt_t gdt;
	gdt.size = (sizeof(gdt_entry_t) * SEGMENT_DESCRIPTOR_COUNT) - 1;
	gdt.address = (unsigned int)&gdt_entries;

  	gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
  	
  	gdt_set_gate(1, SEGMENT_BASE, SEGMENT_LIMIT, SEGMENT_CODE_TYPE, SEGMENT_GRANULARITY); // Kernel Code segment
  	gdt_set_gate(2, SEGMENT_BASE, SEGMENT_LIMIT, SEGMENT_DATA_TYPE, SEGMENT_GRANULARITY); // Kernel Data segment

  	load_gdt(&gdt);
}

