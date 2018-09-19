; loader.asm
; by Renat Mansurov
; v0.1

bits 32			            ;nasm directive - 32 bit CPU
section .text           ;start of section with code

      ;multiboot specification
      align 4
      dd 0x1BADB002     ;magic
      dd 0x00           ;flags
      dd - (0x1BADB002 + 0x00) ;should be zero

global start            ;nasm directive - global symbols
extern kmain	          ;kmain is defined in the c file

start:
  cli 			            ;block interrupts
  mov esp, stack_space	;set stack pointer
  call kernelmain
  hlt		 	              ;halt the CPU

section .bss            ;allocating memory
resb 8192	            	;8KB for stack
stack_space:
