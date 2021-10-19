#ifndef INCLUDE_DRIVER_H
#define INCLUDE_DRIVER_H

// Used by the logger function for output
#define INFO                    1
#define DEBUG                   2
#define ERROR                   3

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

/**
 * create_tables:
 * Wrapper function for the lgdt instruction
 */
extern void create_tables();


#endif

