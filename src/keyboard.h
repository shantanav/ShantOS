/** cpu_state:
 *  Stores the state of the CPU. Registers are named accordingly.
 */ typedef struct {
    unsigned int eax;
    unsigned int ebx;
    unsigned int ecx;
    unsigned int edx;
    unsigned int ebp;
    unsigned int esi;
    unsigned int edi;
    unsigned int esp;
}__attribute__((packed)) cpu_state_t;

/** stack_state:
 *  State of the stack to handle the interrupt.
 */
typedef struct {
    unsigned int error_code;
    unsigned int eip;
    unsigned int cs;
    unsigned int eflags;
}__attribute__((packed)) stack_state_t;


/** interrupt_handler: 
 *  Handle interrupts (but you knew that)
 *
 *  @param   cpu_state   The state of the CPu
 *  @param   stack_state The state of the stack
 *  @param   interrupt   The interrupt being handled
 */
void interrupt_handler(cpu_state_t cpu, stack_state_t stack, unsigned int interrupt);

