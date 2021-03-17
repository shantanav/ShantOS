#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

// ALL OF THESE FUNCTIONS ARE DEFINED IN THE ASSEMBLY (loader.s)
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

#endif
