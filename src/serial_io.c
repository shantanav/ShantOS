#include "io.h"
#include "drivers.h"

// The I/O ports
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

// The I/O port commands
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

// All the I/O ports are calculated relative to the data port. This is because
// all serial ports (COM1, COM2, COM3, COM4) have their ports in the same
// order, but they start at different values.
#define SERIAL_COM1_BASE        0x3F8      /* COM1 base port */

// Today I Learnt: You can have basic functions in #define statements
#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

// The I/O port commands

// SERIAL_LINE_ENABLE_DLAB:
// Tells the serial port to expect first the highest 8 bits on the data port,
// then the lowest 8 bits will follow
#define SERIAL_LINE_ENABLE_DLAB 0x80

// Used by the logger function for output
#define INFO                    1
#define DEBUG                   2
#define ERROR                   3

/** 
 * serial_configure_bitrate:
 * Sets the speed of the data being sent. The default speed of a serial
 * port is 115200 bits/s. The argument is a divisor of that number, hence
 * the resulting speed becomes (115200 / divisor) bits/s.
 *
 * @param com      The COM port to configure
 * @param divisor  The divisor
 */
void serial_configure_bitrate(unsigned short com, unsigned short divisor) {
    outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

/** 
 * serial_configure_line:
 * Configures the line of the given serial port. The port is set to have a
 * data length of 8 bits, no parity bits, one stop bit and break control
 * disabled.
 *
 * @param com  The serial port to configure
 */
void serial_configure_line(unsigned short com) {
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

void serial_configure_modem(unsigned short com) {
    outb(SERIAL_MODEM_COMMAND_PORT(com), 0x03);
}

/** 
 * serial_is_transmit_fifo_empty:
 * Checks whether the transmit FIFO queue is empty or not for the given COM
 * port.
 *
 * @param  com The COM port
 * @return 0 if the transmit FIFO queue is not empty
 *         1 if the transmit FIFO queue is empty
 */
int serial_is_transmit_fifo_empty(unsigned int com) {
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

/**
 * init:
 * Initialize port information
 */
void init() {
    serial_configure_bitrate(SERIAL_COM1_BASE, 2);
    serial_configure_line(SERIAL_COM1_BASE);
    serial_configure_modem(SERIAL_COM1_BASE);
}

/**
 * serial_write:
 * Write to serial port
 *
 * @param buf   The buffer to write to the serial port
 */
void serial_write(char *buf) {
    while (*buf) {
        // Wait until transfer queue is empty
        while (!serial_is_transmit_fifo_empty(SERIAL_COM1_BASE));
        // Write out to port
        outb(SERIAL_COM1_BASE, *buf);
        buf++;
    }
}

/**
 * log:
 * Driver to write to the serial port. Outputs logs to `com1.out`
 *
 * @param dlvl  Debug level
 * @param buf   The string to log
 */
void log(unsigned int dlvl, char *buf) {
    init();
    switch (dlvl) {
        case DEBUG:
            serial_write("[DEBUG] ");
            break;
        case INFO:
            serial_write("[INFO] ");
            break;
        case ERROR:
            serial_write("[ERROR] ");
            break;
    }
    serial_write(buf);
    serial_write("\n");
}

