#ifndef INCLUDE_DRIVER_H
#define INCLUDE_DRIVER_H

/**
 * gdt:
 * Structure to represent a global descriptor tableo
 *
 *      address:    Address of the GDT structure
 *      size:       Size of the GDT
 */
typedef struct gdt {
    unsigned int address;
    unsigned short size;
}__attribute__((packed)) gdt_t;

/**
 * log:
 * Driver to write to the serial port. Outputs logs to `com1.out`
 *
 * @param dlvl  Debug level
 * @param buf   The string to log
 */
extern void log(unsigned int dlvl, char *buf);

/**
 * print:
 * Driver to write to framebuffer. Outputs to the screen.
 *
 * @param buf   The buffer to be printed to the screen
 */
extern void print(char *buf);

/**
 * load_gdt:
 * Takes the address to a gdt_t struct and loads it as the global
 * descriptor table
 *
 * @param gdt: Pointer to a GDT struct
 */
extern void load_gdt(gdt_t *gdt);

/**
 * create_tables:
 * Wrapper function for the lgdt instruction
 */
extern void create_tables();

#endif
