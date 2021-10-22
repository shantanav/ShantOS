#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

typedef struct {
    unsigned short  limit_low;
    unsigned short  base_low;
    unsigned char   base_middle;
    unsigned char   access_byte;
    unsigned char   granularity;
    unsigned char   base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct {
    unsigned int address;
    unsigned short  size;
} __attribute__((packed)) gdt_t;

// ALL OF THESE FUNCTIONS ARE DEFINED IN THE ASSEMBLY (loader.s/tables.s)
// The intent of this header file is to make the Assembly functions
// conveniently accessible from C.

/** outb:
 *  Sends the given data to the given I/O port. Defined in io.s
 *
 *  @param port The I/O port to send the data to
 *  @param data The data to send to the I/O port
 */
extern void outb(unsigned short port, unsigned char data);

/** inb:
 *  Read a byte from an I/O port.
 *
 *  @param  port The address of the I/O port
 *  @return      The read byte
 */
extern unsigned char inb(unsigned short port);

/** load_gdt:
 *  Takes the address to a gdt_t struct and loads it as the global
 *  descriptor table
 *
 *  @param gdt: Pointer to a GDT struct
 */
extern void load_gdt(gdt_t* gdt);

#endif

