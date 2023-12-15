section .text
    global main


main:
    mov ecx, 10
    mov eax, '1'
l1:
    ; move value of accumulator to num
    mov [num], eax
    ; print value of eax
    mov eax, 4
    mov ebx, 1
    push ecx        ; copies value of ecx to stack
    mov ecx, num
    mov edx, 1
    int 0x80        ; interrupt
    mov eax, [num]  ; copies num back to eax
    sub eax, '0'
    inc eax
    add eax, '0'
    pop ecx
    loop l1         ; repeats by dec ecx till 0
    ; exit point
exit:
    mov eax, 1
    int 0x80

section .bss
num resb 1