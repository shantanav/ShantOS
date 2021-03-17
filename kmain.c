#include "io.h"

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

#define CHAR_SCREEN_WIDTH       80
#define CHAR_SCREEN_HEIGHT      25
#define FB_LENGTH               CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT
#define TAB_WIDTH               4   // Don't start a war, kids

char *fb = (char *) 0x000B8000;

/** serial_configure_baud_rate:
 *  Sets the speed of the data being sent. The default speed of a serial
 *  port is 115200 bits/s. The argument is a divisor of that number, hence
 *  the resulting speed becomes (115200 / divisor) bits/s.
 *
 *  @param com      The COM port to configure
 *  @param divisor  The divisor
 */
void serial_configure_bitrate(unsigned short com, unsigned short divisor) {
    outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

 /** serial_configure_line:
 *  Configures the line of the given serial port. The port is set to have a
 *  data length of 8 bits, no parity bits, one stop bit and break control
 *  disabled.
 *
 *  @param com  The serial port to configure
 */
void serial_configure_line(unsigned short com) {
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

/** serial_is_transmit_fifo_empty:
 *  Checks whether the transmit FIFO queue is empty or not for the given COM
 *  port.
 *
 *  @param  com The COM port
 *  @return 0 if the transmit FIFO queue is not empty
 *          1 if the transmit FIFO queue is empty
 */
int serial_is_transmit_fifo_empty(unsigned int com) {
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

/** fb_move_cursor:
*  Moves the cursor of the framebuffer to the given position
*
*  @param pos The new position of the cursor
*/
void fb_move_cursor(unsigned short pos) {
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}

/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the framebuffer.
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg) {
	fb[i * 2] = c;
    fb[(i * 2) + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/**
 * fb_clear:
 * Clears the screen. Replaces the entire framebuffer with NUL-chars.
 */
void fb_clear() {
    unsigned int i = 0;
    while (i < CHAR_SCREEN_HEIGHT * CHAR_SCREEN_WIDTH) {
        fb_write_cell(i, '\0', 0, 15);
        i++;
    }
    fb_move_cursor(0);
}

/**
 * write:
 * Driver to write to framebuffer. Outputs to the screen.
 *
 * @param i     Location in the framebuffer
 * @param buf   The buffer to be printed to the screen
 * @return int  Cursor position after text is printed to the screen
 */
int fb_write(unsigned int i, char *buf) {
    unsigned int line_offset;
    unsigned int tab_offset;
    while (*buf) {
        // Handle scrolling when trying to print beyond framebuffer.
        if (i > CHAR_SCREEN_HEIGHT * CHAR_SCREEN_WIDTH) { 
            unsigned int j = 0;
            while (j <= CHAR_SCREEN_HEIGHT * CHAR_SCREEN_WIDTH) {
                fb_write_cell(j, fb[(j + CHAR_SCREEN_WIDTH) * 2], 0, 15);
                j++;
            }
            i -= CHAR_SCREEN_WIDTH * 1;
            fb_move_cursor(i);
        }
        // Handle newline characters
        if (*buf == '\n') { 
            line_offset = CHAR_SCREEN_WIDTH - (i % CHAR_SCREEN_WIDTH) - 1;
            i += line_offset;
        } 
        // Handle tab characters
        else if (*buf == '\t') { 
            tab_offset = TAB_WIDTH - ((i % CHAR_SCREEN_WIDTH) % TAB_WIDTH);
            i += tab_offset;
        } 
        // Not a special character? Put it in the framebuffer normally.
        else { 
            fb_write_cell(i, *buf, 0, 15);
            fb_move_cursor(i + 1);
        }
        buf++;
        i++;
    }
    return i;
}

/** TODO: Stub for now. Write this function.
 * serial_write:
 * Driver to write to the serial port. Outputs logs to `com1.out`
 *
 * @param buf   The buffer to write to the port
 */
void serial_write(char *buf) {
    // Dummy operation to avoid warning.
    char a = *buf;
    a++;
}

/** TODO: Stub for now. Write this function.
 * print:
 * Akin to printf. Write either to framebuffer or serial port
 * 
 * @param buf   The buffer to write
 * @param dest  Where to write it to
 *                  MUST BE EITHER 0 or 1
 *                  - 0: SERIAL PORT
 *                  - 1: FRAME BUFFER
 */
void print(char *buf, unsigned short dest) {
    // Dummy operation to avoid warning;
    char a = *buf;
    unsigned short b = dest;
    a += b;
} 

int main(void) {
    unsigned int cursor_pos = 0;
    cursor_pos = fb_write(cursor_pos, "Welcome to ShantOS!\n");
}

