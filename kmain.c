#include "io.h"

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

#define CHAR_SCREEN_WIDTH       80
#define CHAR_SCREEN_HEIGHT      25
#define FB_LENGTH               CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT
#define TAB_WIDTH               4   // Don't start a war, kids

char *fb = (char *) 0x000B8000;

int sum_of_three(int arg1, int arg2, int arg3) {
	return arg1 + arg2 + arg3;
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

void fb_clear() {
    unsigned int i = 0;
    while (i < CHAR_SCREEN_HEIGHT * CHAR_SCREEN_WIDTH) {
        fb_write_cell(i, '\0', 0, 15);
        i++;
    }
    fb_move_cursor(0);
}

int write(unsigned int i, char *buf, unsigned int len) {
    unsigned int line_offset;
    unsigned int tab_offset;
    while (*buf) {
        if (i > CHAR_SCREEN_HEIGHT * CHAR_SCREEN_WIDTH) { // Handle scrolling when trying to print beyond framebuffer.
            unsigned int j = 0;
            while (j <= CHAR_SCREEN_HEIGHT * CHAR_SCREEN_WIDTH) {
                fb_write_cell(j, fb[(j + CHAR_SCREEN_WIDTH) * 2], 0, 15);
                j++;
            }
            i -= CHAR_SCREEN_WIDTH * 1;
            fb_move_cursor(i);
        }
        if (*buf == '\n') { // Handle newline characters
            line_offset = CHAR_SCREEN_WIDTH - (i % CHAR_SCREEN_WIDTH) - 1;
            len += line_offset;
            i += line_offset;
        } else if (*buf == '\t') { // Handle tab characters
            tab_offset = TAB_WIDTH - ((i % CHAR_SCREEN_WIDTH) % TAB_WIDTH);
            i += tab_offset;
            len += tab_offset;
        } else { // Not a special character? Print normally.
            fb_write_cell(i, *buf, 0, 15);
            fb_move_cursor(i + 1);
        }
        buf++;
        i++;
    }
    return i;
}

int main(void) {
    unsigned int cursor_pos = 0;
    cursor_pos = write(cursor_pos, "Welcome to ShantOS!\n", CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT);
    cursor_pos = write(cursor_pos, "I can't do much yet, but I exist!\n", CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT);
    cursor_pos = write(cursor_pos, "I can output text!\n", CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT);
}

