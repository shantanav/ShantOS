; Macro for interrupt handlers with no error code
%macro no_error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
    push    dword 0                     ; push 0 as error code
    push    dword %1                    ; push the interrupt number
    jmp     common_interrupt_handler    ; jump to the common handler
%endmacro

; Macro for interrupt handlers with error code
%macro error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
    push    dword %1                    ; push the interrupt number
    jmp     common_interrupt_handler    ; jump to the common handler
%endmacro

common_interrupt_handler:               ; the common parts of the generic interrupt handler
    ; save the registers
    push    eax
    push    ebx
    push    ecx
    push    edx
    push    ebp
    push    esi
    push    edi
    push    esp

    ; call the C function
    extern  interrupt_handler
    call    interrupt_handler

    ; restore the registers
    pop     eax
    pop     ebx
    pop     ecx
    pop     edx
    pop     ebp
    pop     esi
    pop     edi
    pop     esp

    ; restore the esp
    add     esp, 8

    ; return to the code that got interrupted
    iret

no_error_code_interrupt_handler 0       ; create handler for interrupt 0
no_error_code_interrupt_handler 1       ; create handler for interrupt 1

error_code_interrupt_handler    7       ; create handler for interrupt 7

