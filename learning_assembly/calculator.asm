
; ----------> constants definition
; --- Sys calls
SYS_EXIT equ 1
SYS_READ equ 3
SYS_WRITE equ 4
; --- Descriptors
STDIN equ 0
STDOUT equ 1


section .text
    global main

main:
    ; Start by requesting for operation
    mov eax, SYS_READ
    mov edx, len_welcome
    mov ecx, msg_welcome
    mov ebx, STDOUT
    int 0x80                ; interrupt

    ; retrieve the operand
    mov edx, 1
    mov ecx, operand
    mov ebx, STDIN,
    mov eax, SYS_WRITE
    int 0x80
    


exit:
    mov eax, SYS_EXIT
    int 0x80


section .data
    ; Some texts definition
    msg_welcome dw "Calculator mode selection. Enter 1,2,3 or 4 for +,-,*,/ respectively.", 0xA, 0xD
    len_welcome equ - msg_welcome
    



section .bss
    ; unintialized data
    operand resb 1          ; operand for calc mode
