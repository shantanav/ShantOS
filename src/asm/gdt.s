global load_gdt
; load_gdt - Loads the global descriptor table and local descriptor tables
; stack:    [esp + 4] Address to a GDT structure
;           [esp    ] return address
load_gdt:
    lgdt [esp + 4]              ; Load GDT table from ESP register
    ret

