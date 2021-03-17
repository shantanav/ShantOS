#include "io.h"

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

#define CHAR_SCREEN_WIDTH       80
#define CHAR_SCREEN_HEIGHT      25
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

int write(unsigned int i, char *buf, unsigned int len) {
    unsigned int line_offset;
    unsigned int tab_offset;
    while (i < len && *buf) {
        if (*buf == '\n') { // Handle newline characters
            line_offset = CHAR_SCREEN_WIDTH - (i % CHAR_SCREEN_WIDTH) - 1;
            len += line_offset;
            i += line_offset;
        } else if (*buf == '\t') { // Handle tab characters
            tab_offset = TAB_WIDTH - ((i % CHAR_SCREEN_WIDTH) % TAB_WIDTH);
            i += tab_offset;
            len += tab_offset;
        } else {
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
    cursor_pos = write(cursor_pos, "I wrote a pretty convincing text driver for this!\nIt can:\n\t1.\t\tHandle variable tabbing\n\t2.\t\tDo newlines properly\n\t3..\tHandle variable tabbing properly\n", CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT);
    cursor_pos = write(cursor_pos, "It can even handle being given multiple write statements appropriately, and works akin to C's puts function.", CHAR_SCREEN_WIDTH * CHAR_SCREEN_HEIGHT);
}

