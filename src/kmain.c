#include "drivers.h"

/**
 * main:
 * Main function. Program entrypoint.
 */
int main(void) {
    create_tables();
    print("Welcome to ShantOS!\n");
    log(INFO, "Printed welcome message");
}

