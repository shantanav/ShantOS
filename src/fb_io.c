#include "gdt.h"
#include "drivers.h"

// The I/O ports
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

// The I/O port commands
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

// Constants for screen size - height and width...
#define CHAR_SCREEN_WIDTH       80
#define CHAR_SCREEN_HEIGHT      25
//...and the length of the visible framebuffer
#define FB_LENGTH               CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT

#define TAB_WIDTH               4   // Don't start a war, kids

// Memory address for frame buffer to print to the screen
// Is globally available and hardcoded. This is intentional.
// Can this become a local variable? As far as I understand it,
// No.
char *fb = (char *) 0x000B8000;

// Global mention of cursor position for all functions that need it.
// This is not a local variable to prevent it from being cleared when
// fb_write is done running. This could probably be local to main, but
// that's a change I've yet to test or make.
unsigned int CURSOR_POS = 0;

/** 
 * fb_move_cursor:
 * Moves the cursor of the framebuffer to the given position
 *
 * @param pos The new position of the cursor
 */
void fb_move_cursor(unsigned short pos) {
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
    CURSOR_POS = pos;
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
    while (i < FB_LENGTH) {
        fb_write_cell(i, '\0', 0, 15);
        i++;
    }
    fb_move_cursor(0);
}

/**
 * print:
 * Driver to write to framebuffer. Outputs to the screen.
 *
 * @param buf   The buffer to be printed to the screen
 */
void print(char *buf) {
    unsigned int i = CURSOR_POS;
    while (*buf) { 
        // Handle scrolling when trying to print beyond framebuffer.
        if (i > FB_LENGTH) { 
            unsigned int j = 0;
            while (j <= FB_LENGTH) {
                fb_write_cell(j, fb[(j + CHAR_SCREEN_WIDTH) * 2], 0, 15);
                j++;
            }
            i -= CHAR_SCREEN_WIDTH;
            fb_move_cursor(i);
        }
        // Handle newline characters
        if (*buf == '\n') { 
            i += CHAR_SCREEN_WIDTH - (i % CHAR_SCREEN_WIDTH) - 1;
        } 
        // Handle tab characters
        else if (*buf == '\t') { 
            i += TAB_WIDTH - ((i % CHAR_SCREEN_WIDTH) % TAB_WIDTH);
        } 
        // Not a special character? Put it in the framebuffer normally.
        else { 
            fb_write_cell(i, *buf, 0, 15);
            fb_move_cursor(i + 1);
        }
        buf++;
        i++;
    }
    CURSOR_POS = i;
}

