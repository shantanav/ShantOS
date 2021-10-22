#ifndef INCLUDE_KEYBOARD_H
#define INCLUDE_KEYBOARD_H

#define PIC1_PORT_A 0x20
#define PIC2_PORT_A 0xA0

/* The PIC interrupts have been remapped */
#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT   PIC2_START_INTERRUPT + 7

#define PIC_ACK     0x20


/** cpu_state:
 *  Stores the state of the CPU. Registers are named accordingly.
 */ 
typedef struct {
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

typedef struct { unsigned int size;
    unsigned long offset; 
} __attribute__((packed)) idt_t;

typedef struct {
  unsigned int offset_0_15;
  unsigned int selector;
  unsigned char zero;
  unsigned char type_attr;
  unsigned int offset_16_31;
} __attribute__((packed)) interrupt_descriptor_t;

void interrupt_handler_0();
void interrupt_handler_1();
void interrupt_handler_2();
void interrupt_handler_3();
void interrupt_handler_4();
void interrupt_handler_5();
void interrupt_handler_6();
void interrupt_handler_7();
void interrupt_handler_8();
void interrupt_handler_9();
void interrupt_handler_10();
void interrupt_handler_11();
void interrupt_handler_12();
void interrupt_handler_13();
void interrupt_handler_14();
void interrupt_handler_15();
void interrupt_handler_16();
void interrupt_handler_17();
void interrupt_handler_18();
void interrupt_handler_19();
void interrupt_handler_20();
void interrupt_handler_21();
void interrupt_handler_22();
void interrupt_handler_23();
void interrupt_handler_24();
void interrupt_handler_25();
void interrupt_handler_26();
void interrupt_handler_27();
void interrupt_handler_28();
void interrupt_handler_29();
void interrupt_handler_30();
void interrupt_handler_31();
void interrupt_handler_32();
void interrupt_handler_33();
void interrupt_handler_34();
void interrupt_handler_35();
void interrupt_handler_36();
void interrupt_handler_37();
void interrupt_handler_38();
void interrupt_handler_39();
void interrupt_handler_40();
void interrupt_handler_41();
void interrupt_handler_42();
void interrupt_handler_43();
void interrupt_handler_44();
void interrupt_handler_45();
void interrupt_handler_46();
void interrupt_handler_47();
void interrupt_handler_48();
void interrupt_handler_49();
void interrupt_handler_50();
void interrupt_handler_51();
void interrupt_handler_52();
void interrupt_handler_53();
void interrupt_handler_54();
void interrupt_handler_55();
void interrupt_handler_56();
void interrupt_handler_57();
void interrupt_handler_58();
void interrupt_handler_59();
void interrupt_handler_60();
void interrupt_handler_61();
void interrupt_handler_62();
void interrupt_handler_63();
void interrupt_handler_64();
void interrupt_handler_65();
void interrupt_handler_66();
void interrupt_handler_67();
void interrupt_handler_68();
void interrupt_handler_69();
void interrupt_handler_70();
void interrupt_handler_71();
void interrupt_handler_72();
void interrupt_handler_73();
void interrupt_handler_74();
void interrupt_handler_75();
void interrupt_handler_76();
void interrupt_handler_77();
void interrupt_handler_78();
void interrupt_handler_79();
void interrupt_handler_80();
void interrupt_handler_81();
void interrupt_handler_82();
void interrupt_handler_83();
void interrupt_handler_84();
void interrupt_handler_85();
void interrupt_handler_86();
void interrupt_handler_87();
void interrupt_handler_88();
void interrupt_handler_89();
void interrupt_handler_90();
void interrupt_handler_91();
void interrupt_handler_92();
void interrupt_handler_93();
void interrupt_handler_94();
void interrupt_handler_95();
void interrupt_handler_96();
void interrupt_handler_97();
void interrupt_handler_98();
void interrupt_handler_99();
void interrupt_handler_100();
void interrupt_handler_101();
void interrupt_handler_102();
void interrupt_handler_103();
void interrupt_handler_104();
void interrupt_handler_105();
void interrupt_handler_106();
void interrupt_handler_107();
void interrupt_handler_108();
void interrupt_handler_109();
void interrupt_handler_110();
void interrupt_handler_111();
void interrupt_handler_112();
void interrupt_handler_113();
void interrupt_handler_114();
void interrupt_handler_115();
void interrupt_handler_116();
void interrupt_handler_117();
void interrupt_handler_118();
void interrupt_handler_119();
void interrupt_handler_120();
void interrupt_handler_121();
void interrupt_handler_122();
void interrupt_handler_123();
void interrupt_handler_124();
void interrupt_handler_125();
void interrupt_handler_126();
void interrupt_handler_127();
void interrupt_handler_128();
void interrupt_handler_129();
void interrupt_handler_130();
void interrupt_handler_131();
void interrupt_handler_132();
void interrupt_handler_133();
void interrupt_handler_134();
void interrupt_handler_135();
void interrupt_handler_136();
void interrupt_handler_137();
void interrupt_handler_138();
void interrupt_handler_139();
void interrupt_handler_140();
void interrupt_handler_141();
void interrupt_handler_142();
void interrupt_handler_143();
void interrupt_handler_144();
void interrupt_handler_145();
void interrupt_handler_146();
void interrupt_handler_147();
void interrupt_handler_148();
void interrupt_handler_149();
void interrupt_handler_150();
void interrupt_handler_151();
void interrupt_handler_152();
void interrupt_handler_153();
void interrupt_handler_154();
void interrupt_handler_155();
void interrupt_handler_156();
void interrupt_handler_157();
void interrupt_handler_158();
void interrupt_handler_159();
void interrupt_handler_160();
void interrupt_handler_161();
void interrupt_handler_162();
void interrupt_handler_163();
void interrupt_handler_164();
void interrupt_handler_165();
void interrupt_handler_166();
void interrupt_handler_167();
void interrupt_handler_168();
void interrupt_handler_169();
void interrupt_handler_170();
void interrupt_handler_171();
void interrupt_handler_172();
void interrupt_handler_173();
void interrupt_handler_174();
void interrupt_handler_175();
void interrupt_handler_176();
void interrupt_handler_177();
void interrupt_handler_178();
void interrupt_handler_179();
void interrupt_handler_180();
void interrupt_handler_181();
void interrupt_handler_182();
void interrupt_handler_183();
void interrupt_handler_184();
void interrupt_handler_185();
void interrupt_handler_186();
void interrupt_handler_187();
void interrupt_handler_188();
void interrupt_handler_189();
void interrupt_handler_190();
void interrupt_handler_191();
void interrupt_handler_192();
void interrupt_handler_193();
void interrupt_handler_194();
void interrupt_handler_195();
void interrupt_handler_196();
void interrupt_handler_197();
void interrupt_handler_198();
void interrupt_handler_199();
void interrupt_handler_200();
void interrupt_handler_201();
void interrupt_handler_202();
void interrupt_handler_203();
void interrupt_handler_204();
void interrupt_handler_205();
void interrupt_handler_206();
void interrupt_handler_207();
void interrupt_handler_208();
void interrupt_handler_209();
void interrupt_handler_210();
void interrupt_handler_211();
void interrupt_handler_212();
void interrupt_handler_213();
void interrupt_handler_214();
void interrupt_handler_215();
void interrupt_handler_216();
void interrupt_handler_217();
void interrupt_handler_218();
void interrupt_handler_219();
void interrupt_handler_220();
void interrupt_handler_221();
void interrupt_handler_222();
void interrupt_handler_223();
void interrupt_handler_224();
void interrupt_handler_225();
void interrupt_handler_226();
void interrupt_handler_227();
void interrupt_handler_228();
void interrupt_handler_229();
void interrupt_handler_230();
void interrupt_handler_231();
void interrupt_handler_232();
void interrupt_handler_233();
void interrupt_handler_234();
void interrupt_handler_235();
void interrupt_handler_236();
void interrupt_handler_237();
void interrupt_handler_238();
void interrupt_handler_239();
void interrupt_handler_240();
void interrupt_handler_241();
void interrupt_handler_242();
void interrupt_handler_243();
void interrupt_handler_244();
void interrupt_handler_245();
void interrupt_handler_246();
void interrupt_handler_247();
void interrupt_handler_248();
void interrupt_handler_249();
void interrupt_handler_250();
void interrupt_handler_251();
void interrupt_handler_252();
void interrupt_handler_253();
void interrupt_handler_254();
void interrupt_handler_255();

interrupt_descriptor_t idt[256];

unsigned long interrupt_handler_addresses[] = {
  (unsigned long) interrupt_handler_0,
  (unsigned long) interrupt_handler_1,
  (unsigned long) interrupt_handler_2,
  (unsigned long) interrupt_handler_3,
  (unsigned long) interrupt_handler_4,
  (unsigned long) interrupt_handler_5,
  (unsigned long) interrupt_handler_6,
  (unsigned long) interrupt_handler_7,
  (unsigned long) interrupt_handler_8,
  (unsigned long) interrupt_handler_9,
  (unsigned long) interrupt_handler_10,
  (unsigned long) interrupt_handler_11,
  (unsigned long) interrupt_handler_12,
  (unsigned long) interrupt_handler_13,
  (unsigned long) interrupt_handler_14,
  (unsigned long) interrupt_handler_15,
  (unsigned long) interrupt_handler_16,
  (unsigned long) interrupt_handler_17,
  (unsigned long) interrupt_handler_18,
  (unsigned long) interrupt_handler_19,
  (unsigned long) interrupt_handler_20,
  (unsigned long) interrupt_handler_21,
  (unsigned long) interrupt_handler_22,
  (unsigned long) interrupt_handler_23,
  (unsigned long) interrupt_handler_24,
  (unsigned long) interrupt_handler_25,
  (unsigned long) interrupt_handler_26,
  (unsigned long) interrupt_handler_27,
  (unsigned long) interrupt_handler_28,
  (unsigned long) interrupt_handler_29,
  (unsigned long) interrupt_handler_30,
  (unsigned long) interrupt_handler_31,
  (unsigned long) interrupt_handler_32,
  (unsigned long) interrupt_handler_33,
  (unsigned long) interrupt_handler_34,
  (unsigned long) interrupt_handler_35,
  (unsigned long) interrupt_handler_36,
  (unsigned long) interrupt_handler_37,
  (unsigned long) interrupt_handler_38,
  (unsigned long) interrupt_handler_39,
  (unsigned long) interrupt_handler_40,
  (unsigned long) interrupt_handler_41,
  (unsigned long) interrupt_handler_42,
  (unsigned long) interrupt_handler_43,
  (unsigned long) interrupt_handler_44,
  (unsigned long) interrupt_handler_45,
  (unsigned long) interrupt_handler_46,
  (unsigned long) interrupt_handler_47,
  (unsigned long) interrupt_handler_48,
  (unsigned long) interrupt_handler_49,
  (unsigned long) interrupt_handler_50,
  (unsigned long) interrupt_handler_51,
  (unsigned long) interrupt_handler_52,
  (unsigned long) interrupt_handler_53,
  (unsigned long) interrupt_handler_54,
  (unsigned long) interrupt_handler_55,
  (unsigned long) interrupt_handler_56,
  (unsigned long) interrupt_handler_57,
  (unsigned long) interrupt_handler_58,
  (unsigned long) interrupt_handler_59,
  (unsigned long) interrupt_handler_60,
  (unsigned long) interrupt_handler_61,
  (unsigned long) interrupt_handler_62,
  (unsigned long) interrupt_handler_63,
  (unsigned long) interrupt_handler_64,
  (unsigned long) interrupt_handler_65,
  (unsigned long) interrupt_handler_66,
  (unsigned long) interrupt_handler_67,
  (unsigned long) interrupt_handler_68,
  (unsigned long) interrupt_handler_69,
  (unsigned long) interrupt_handler_70,
  (unsigned long) interrupt_handler_71,
  (unsigned long) interrupt_handler_72,
  (unsigned long) interrupt_handler_73,
  (unsigned long) interrupt_handler_74,
  (unsigned long) interrupt_handler_75,
  (unsigned long) interrupt_handler_76,
  (unsigned long) interrupt_handler_77,
  (unsigned long) interrupt_handler_78,
  (unsigned long) interrupt_handler_79,
  (unsigned long) interrupt_handler_80,
  (unsigned long) interrupt_handler_81,
  (unsigned long) interrupt_handler_82,
  (unsigned long) interrupt_handler_83,
  (unsigned long) interrupt_handler_84,
  (unsigned long) interrupt_handler_85,
  (unsigned long) interrupt_handler_86,
  (unsigned long) interrupt_handler_87,
  (unsigned long) interrupt_handler_88,
  (unsigned long) interrupt_handler_89,
  (unsigned long) interrupt_handler_90,
  (unsigned long) interrupt_handler_91,
  (unsigned long) interrupt_handler_92,
  (unsigned long) interrupt_handler_93,
  (unsigned long) interrupt_handler_94,
  (unsigned long) interrupt_handler_95,
  (unsigned long) interrupt_handler_96,
  (unsigned long) interrupt_handler_97,
  (unsigned long) interrupt_handler_98,
  (unsigned long) interrupt_handler_99,
  (unsigned long) interrupt_handler_100,
  (unsigned long) interrupt_handler_101,
  (unsigned long) interrupt_handler_102,
  (unsigned long) interrupt_handler_103,
  (unsigned long) interrupt_handler_104,
  (unsigned long) interrupt_handler_105,
  (unsigned long) interrupt_handler_106,
  (unsigned long) interrupt_handler_107,
  (unsigned long) interrupt_handler_108,
  (unsigned long) interrupt_handler_109,
  (unsigned long) interrupt_handler_110,
  (unsigned long) interrupt_handler_111,
  (unsigned long) interrupt_handler_112,
  (unsigned long) interrupt_handler_113,
  (unsigned long) interrupt_handler_114,
  (unsigned long) interrupt_handler_115,
  (unsigned long) interrupt_handler_116,
  (unsigned long) interrupt_handler_117,
  (unsigned long) interrupt_handler_118,
  (unsigned long) interrupt_handler_119,
  (unsigned long) interrupt_handler_120,
  (unsigned long) interrupt_handler_121,
  (unsigned long) interrupt_handler_122,
  (unsigned long) interrupt_handler_123,
  (unsigned long) interrupt_handler_124,
  (unsigned long) interrupt_handler_125,
  (unsigned long) interrupt_handler_126,
  (unsigned long) interrupt_handler_127,
  (unsigned long) interrupt_handler_128,
  (unsigned long) interrupt_handler_129,
  (unsigned long) interrupt_handler_130,
  (unsigned long) interrupt_handler_131,
  (unsigned long) interrupt_handler_132,
  (unsigned long) interrupt_handler_133,
  (unsigned long) interrupt_handler_134,
  (unsigned long) interrupt_handler_135,
  (unsigned long) interrupt_handler_136,
  (unsigned long) interrupt_handler_137,
  (unsigned long) interrupt_handler_138,
  (unsigned long) interrupt_handler_139,
  (unsigned long) interrupt_handler_140,
  (unsigned long) interrupt_handler_141,
  (unsigned long) interrupt_handler_142,
  (unsigned long) interrupt_handler_143,
  (unsigned long) interrupt_handler_144,
  (unsigned long) interrupt_handler_145,
  (unsigned long) interrupt_handler_146,
  (unsigned long) interrupt_handler_147,
  (unsigned long) interrupt_handler_148,
  (unsigned long) interrupt_handler_149,
  (unsigned long) interrupt_handler_150,
  (unsigned long) interrupt_handler_151,
  (unsigned long) interrupt_handler_152,
  (unsigned long) interrupt_handler_153,
  (unsigned long) interrupt_handler_154,
  (unsigned long) interrupt_handler_155,
  (unsigned long) interrupt_handler_156,
  (unsigned long) interrupt_handler_157,
  (unsigned long) interrupt_handler_158,
  (unsigned long) interrupt_handler_159,
  (unsigned long) interrupt_handler_160,
  (unsigned long) interrupt_handler_161,
  (unsigned long) interrupt_handler_162,
  (unsigned long) interrupt_handler_163,
  (unsigned long) interrupt_handler_164,
  (unsigned long) interrupt_handler_165,
  (unsigned long) interrupt_handler_166,
  (unsigned long) interrupt_handler_167,
  (unsigned long) interrupt_handler_168,
  (unsigned long) interrupt_handler_169,
  (unsigned long) interrupt_handler_170,
  (unsigned long) interrupt_handler_171,
  (unsigned long) interrupt_handler_172,
  (unsigned long) interrupt_handler_173,
  (unsigned long) interrupt_handler_174,
  (unsigned long) interrupt_handler_175,
  (unsigned long) interrupt_handler_176,
  (unsigned long) interrupt_handler_177,
  (unsigned long) interrupt_handler_178,
  (unsigned long) interrupt_handler_179,
  (unsigned long) interrupt_handler_180,
  (unsigned long) interrupt_handler_181,
  (unsigned long) interrupt_handler_182,
  (unsigned long) interrupt_handler_183,
  (unsigned long) interrupt_handler_184,
  (unsigned long) interrupt_handler_185,
  (unsigned long) interrupt_handler_186,
  (unsigned long) interrupt_handler_187,
  (unsigned long) interrupt_handler_188,
  (unsigned long) interrupt_handler_189,
  (unsigned long) interrupt_handler_190,
  (unsigned long) interrupt_handler_191,
  (unsigned long) interrupt_handler_192,
  (unsigned long) interrupt_handler_193,
  (unsigned long) interrupt_handler_194,
  (unsigned long) interrupt_handler_195,
  (unsigned long) interrupt_handler_196,
  (unsigned long) interrupt_handler_197,
  (unsigned long) interrupt_handler_198,
  (unsigned long) interrupt_handler_199,
  (unsigned long) interrupt_handler_200,
  (unsigned long) interrupt_handler_201,
  (unsigned long) interrupt_handler_202,
  (unsigned long) interrupt_handler_203,
  (unsigned long) interrupt_handler_204,
  (unsigned long) interrupt_handler_205,
  (unsigned long) interrupt_handler_206,
  (unsigned long) interrupt_handler_207,
  (unsigned long) interrupt_handler_208,
  (unsigned long) interrupt_handler_209,
  (unsigned long) interrupt_handler_210,
  (unsigned long) interrupt_handler_211,
  (unsigned long) interrupt_handler_212,
  (unsigned long) interrupt_handler_213,
  (unsigned long) interrupt_handler_214,
  (unsigned long) interrupt_handler_215,
  (unsigned long) interrupt_handler_216,
  (unsigned long) interrupt_handler_217,
  (unsigned long) interrupt_handler_218,
  (unsigned long) interrupt_handler_219,
  (unsigned long) interrupt_handler_220,
  (unsigned long) interrupt_handler_221,
  (unsigned long) interrupt_handler_222,
  (unsigned long) interrupt_handler_223,
  (unsigned long) interrupt_handler_224,
  (unsigned long) interrupt_handler_225,
  (unsigned long) interrupt_handler_226,
  (unsigned long) interrupt_handler_227,
  (unsigned long) interrupt_handler_228,
  (unsigned long) interrupt_handler_229,
  (unsigned long) interrupt_handler_230,
  (unsigned long) interrupt_handler_231,
  (unsigned long) interrupt_handler_232,
  (unsigned long) interrupt_handler_233,
  (unsigned long) interrupt_handler_234,
  (unsigned long) interrupt_handler_235,
  (unsigned long) interrupt_handler_236,
  (unsigned long) interrupt_handler_237,
  (unsigned long) interrupt_handler_238,
  (unsigned long) interrupt_handler_239,
  (unsigned long) interrupt_handler_240,
  (unsigned long) interrupt_handler_241,
  (unsigned long) interrupt_handler_242,
  (unsigned long) interrupt_handler_243,
  (unsigned long) interrupt_handler_244,
  (unsigned long) interrupt_handler_245,
  (unsigned long) interrupt_handler_246,
  (unsigned long) interrupt_handler_247,
  (unsigned long) interrupt_handler_248,
  (unsigned long) interrupt_handler_249,
  (unsigned long) interrupt_handler_250,
  (unsigned long) interrupt_handler_251,
  (unsigned long) interrupt_handler_252,
  (unsigned long) interrupt_handler_253,
  (unsigned long) interrupt_handler_254,
  (unsigned long) interrupt_handler_255,
};

/** interrupt_handler: 
 *  Handle interrupts (but you knew that)
 *
 *  @param   cpu_state   The state of the CPu
 *  @param   stack_state The state of the stack
 *  @param   interrupt   The interrupt being handled
 */
void interrupt_handler(cpu_state_t cpu, stack_state_t stack, unsigned int interrupt);

/** load_idt:
 *  Takes the address to a idt_t struct and loads it as the interrupt
 *  descriptor table
 *
 *  @param idt: Pointer to a IDT struct
 */
extern void load_idt(idt_t* idt);

#endif

