global load_gdt
; load_gdt - Loads the global descriptor table and local descriptor tables
; stack:    [esp + 4] Address to a GDT structure
;           [esp    ] return address
load_gdt:
    mov eax, [esp + 4]  ; Get the pointer to the GDT, passed as a parameter.
    lgdt [eax]        ; Load the new GDT pointer

    mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
    ret

global load_idt
; load_idt - Loads the interrupt descriptor table and local descriptor tables
; stack:    [esp + 4] Address to an IDT structure
;           [esp    ] return address
load_idt:
    lidt [esp + 4]              ; Load IDT table from ESP register
    ret

