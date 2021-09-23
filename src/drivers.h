#ifndef INCLUDE_DRIVER_H
#define INCLUDE_DRIVER_H

/**
 * log:
 * Driver to write to the serial port. Outputs logs to `exec/com1.out`
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
