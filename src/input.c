// #include "idt.h"
// #include "drivers.h"
// #include "gdt.h"
// 
// void interrupt_handler(cpu_state_t cpu, stack_state_t stack, unsigned int interrupt) {
    // unsigned int a = cpu.esi;
    // unsigned int b = stack.cs;
    // char c = '0' + a + b - a - b + interrupt; // Intentionally useless line to allow to compile without warnings
    // log(INFO, "Interrupt encountered");
    // print(&c);
// }
// 
// /** pic_acknowledge:
 // *  Acknowledges an interrupt from either PIC 1 or PIC 2.
 // *
 // *  @param interrupt The number of the interrupt
 // */
// void pic_acknowledge(unsigned int interrupt) {
    // if (interrupt < PIC1_START_INTERRUPT || interrupt > PIC2_END_INTERRUPT) return;
// 
    // if (interrupt < PIC2_START_INTERRUPT) {
      // outb(PIC1_PORT_A, PIC_ACK);
    // } else {
      // outb(PIC2_PORT_A, PIC_ACK);
    // }
// }
// 
