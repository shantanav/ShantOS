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

#endif
