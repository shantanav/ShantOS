extern  interrupt_handler

; Macro for interrupt handlers with no error code
%macro interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
    push    dword 0                     ; push 0 as error code 
    push    dword %1                    ; push the interrupt number 
    jmp     common_interrupt_handler    ; jump to the common handler
%endmacro ; Macro for interrupt handlers with error code

interrupt_handler 0
interrupt_handler 1
interrupt_handler 2
interrupt_handler 3
interrupt_handler 4
interrupt_handler 5
interrupt_handler 6
interrupt_handler 7
interrupt_handler 8
interrupt_handler 9
interrupt_handler 10
interrupt_handler 11
interrupt_handler 12
interrupt_handler 13
interrupt_handler 14
interrupt_handler 15
interrupt_handler 16
interrupt_handler 17
interrupt_handler 18
interrupt_handler 19
interrupt_handler 20
interrupt_handler 21
interrupt_handler 22
interrupt_handler 23
interrupt_handler 24
interrupt_handler 25
interrupt_handler 26
interrupt_handler 27
interrupt_handler 28
interrupt_handler 29
interrupt_handler 30
interrupt_handler 31
interrupt_handler 32
interrupt_handler 33
interrupt_handler 34
interrupt_handler 35
interrupt_handler 36
interrupt_handler 37
interrupt_handler 38
interrupt_handler 39
interrupt_handler 40
interrupt_handler 41
interrupt_handler 42
interrupt_handler 43
interrupt_handler 44
interrupt_handler 45
interrupt_handler 46
interrupt_handler 47
interrupt_handler 48
interrupt_handler 49
interrupt_handler 50
interrupt_handler 51
interrupt_handler 52
interrupt_handler 53
interrupt_handler 54
interrupt_handler 55
interrupt_handler 56
interrupt_handler 57
interrupt_handler 58
interrupt_handler 59
interrupt_handler 60
interrupt_handler 61
interrupt_handler 62
interrupt_handler 63
interrupt_handler 64
interrupt_handler 65
interrupt_handler 66
interrupt_handler 67
interrupt_handler 68
interrupt_handler 69
interrupt_handler 70
interrupt_handler 71
interrupt_handler 72
interrupt_handler 73
interrupt_handler 74
interrupt_handler 75
interrupt_handler 76
interrupt_handler 77
interrupt_handler 78
interrupt_handler 79
interrupt_handler 80
interrupt_handler 81
interrupt_handler 82
interrupt_handler 83
interrupt_handler 84
interrupt_handler 85
interrupt_handler 86
interrupt_handler 87
interrupt_handler 88
interrupt_handler 89
interrupt_handler 90
interrupt_handler 91
interrupt_handler 92
interrupt_handler 93
interrupt_handler 94
interrupt_handler 95
interrupt_handler 96
interrupt_handler 97
interrupt_handler 98
interrupt_handler 99
interrupt_handler 100
interrupt_handler 101
interrupt_handler 102
interrupt_handler 103
interrupt_handler 104
interrupt_handler 105
interrupt_handler 106
interrupt_handler 107
interrupt_handler 108
interrupt_handler 109
interrupt_handler 110
interrupt_handler 111
interrupt_handler 112
interrupt_handler 113
interrupt_handler 114
interrupt_handler 115
interrupt_handler 116
interrupt_handler 117
interrupt_handler 118
interrupt_handler 119
interrupt_handler 120
interrupt_handler 121
interrupt_handler 122
interrupt_handler 123
interrupt_handler 124
interrupt_handler 125
interrupt_handler 126
interrupt_handler 127
interrupt_handler 128
interrupt_handler 129
interrupt_handler 130
interrupt_handler 131
interrupt_handler 132
interrupt_handler 133
interrupt_handler 134
interrupt_handler 135
interrupt_handler 136
interrupt_handler 137
interrupt_handler 138
interrupt_handler 139
interrupt_handler 140
interrupt_handler 141
interrupt_handler 142
interrupt_handler 143
interrupt_handler 144
interrupt_handler 145
interrupt_handler 146
interrupt_handler 147
interrupt_handler 148
interrupt_handler 149
interrupt_handler 150
interrupt_handler 151
interrupt_handler 152
interrupt_handler 153
interrupt_handler 154
interrupt_handler 155
interrupt_handler 156
interrupt_handler 157
interrupt_handler 158
interrupt_handler 159
interrupt_handler 160
interrupt_handler 161
interrupt_handler 162
interrupt_handler 163
interrupt_handler 164
interrupt_handler 165
interrupt_handler 166
interrupt_handler 167
interrupt_handler 168
interrupt_handler 169
interrupt_handler 170
interrupt_handler 171
interrupt_handler 172
interrupt_handler 173
interrupt_handler 174
interrupt_handler 175
interrupt_handler 176
interrupt_handler 177
interrupt_handler 178
interrupt_handler 179
interrupt_handler 180
interrupt_handler 181
interrupt_handler 182
interrupt_handler 183
interrupt_handler 184
interrupt_handler 185
interrupt_handler 186
interrupt_handler 187
interrupt_handler 188
interrupt_handler 189
interrupt_handler 190
interrupt_handler 191
interrupt_handler 192
interrupt_handler 193
interrupt_handler 194
interrupt_handler 195
interrupt_handler 196
interrupt_handler 197
interrupt_handler 198
interrupt_handler 199
interrupt_handler 200
interrupt_handler 201
interrupt_handler 202
interrupt_handler 203
interrupt_handler 204
interrupt_handler 205
interrupt_handler 206
interrupt_handler 207
interrupt_handler 208
interrupt_handler 209
interrupt_handler 210
interrupt_handler 211
interrupt_handler 212
interrupt_handler 213
interrupt_handler 214
interrupt_handler 215
interrupt_handler 216
interrupt_handler 217
interrupt_handler 218
interrupt_handler 219
interrupt_handler 220
interrupt_handler 221
interrupt_handler 222
interrupt_handler 223
interrupt_handler 224
interrupt_handler 225
interrupt_handler 226
interrupt_handler 227
interrupt_handler 228
interrupt_handler 229
interrupt_handler 230
interrupt_handler 231
interrupt_handler 232
interrupt_handler 233
interrupt_handler 234
interrupt_handler 235
interrupt_handler 236
interrupt_handler 237
interrupt_handler 238
interrupt_handler 239

common_interrupt_handler:               ; Common parts of interrupt handler
    ; save the registers
    push    eax
    push    ebx
    push    ecx
    push    edx
    push    esi
    push    edi
    push    ebp
    mov eax, cr2
    push eax
    ; call the C function
    call    common_interrupt_handler
    ; restore the registers
    add     esp, 4  ; cr2
    pop     ebp
    pop     edi
    pop     esi
    pop     edx
    pop     ecx
    pop     ebx
    pop     eax
    add     esp, 8  ; restore the esp
    iret            ; return to the code that got interrupted

interrupt_with_return:               ; Common parts of interrupt handler
    ; save the registers
    push    eax
    push    ebx
    push    ecx
    push    edx
    push    esi
    push    edi
    push    ebp
    mov eax, cr2
    push eax
    ; call the C function
    call    common_interrupt_handler
    ; restore the registers
    add     esp, 4  ; cr2
    pop     ebp
    pop     edi
    pop     esi
    pop     edx
    pop     ecx
    pop     ebx
    ; Literally the only difference - don't pop eax
    add     esp, 8  ; restore the esp
    iret            ; return to the code that got interrupted
