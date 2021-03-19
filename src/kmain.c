#include "drivers.h"

// Used by the logger function for output
#define INFO                    1
#define DEBUG                   2
#define ERROR                   3

/**
 * main:
 * Main function. Program entrypoint.
 */
int main(void) {
    print("Welcome to ShantOS!\n");
    log(INFO, "Printed welcome message");
}

