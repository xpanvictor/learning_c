section .text
	global _start		; tells linker starting point of instructions


_start:				; linker's entry point
	mov edx, len		; message length
	mov ecx, msg		; message to write
	mov ebx, 1		; file descriptor (stdout in langs)
	mov eax, 4		; sys call (sys_write)
	int 0x80		; call kernel



section .data
msg db 'Hello, world!', 0xa	; string to be printed
len equ $ - msg			; length of the string msg
