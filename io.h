#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/** outb:
*  Sends the given data to the given I/O port. Defined in io.s
*
*  @param port The I/O port to send the data to
*  @param data The data to send to the I/O port
*/
void outb(unsigned short port, unsigned char data);

/**write:
 * Writes a character to the framebuffer
 *
 * @param buf The pointer to the buffer
 * @param len The length of the string
 */
int write(char *buf, unsigned int len);

#endif /* INCLUDE_IO_H */
