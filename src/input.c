#include "keyboard.h"
#include "drivers.h"

void interrupt_handler(cpu_state_t cpu, stack_state_t stack, unsigned int interrupt) {
    unsigned int a = cpu.esi;
    unsigned int b = stack.cs;
    char c = '0' + a + b - a - b + interrupt; // Intentionally useless line to allow to compile without warnings
    log(INFO, "Interrupt encountered");
    print(&c);
}

