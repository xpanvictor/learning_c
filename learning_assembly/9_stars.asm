
section .text
	global _start

_start:
	mov edx, len		; the length of the message
	mov ecx, msg		; the message we want to move to count reg
	mov ebx, 1		; file descriptor, we want stdout
	mov eax, 4		; sys call number of sys_write
	int 0x80		; call kernel

	; we've displayed message, let's show the stars
	mov edx, 9		; len of stars is 9
	mov ecx, s2		; the stars message
	mov ebx, 1		; we want stdout - file descriptor
	mov eax, 4		; system call (sys_write)
	int 0x80		; call the kernel
	

	mov eax, 1		; system call (sys_exit)
	int 0x80		; call kernel




section .data
msg db 'Displaying 9 stars', 0xa ; the msg displayed
len equ $ - msg			; length of msg passed to len
s2 times 9 db '*'		; msg is 9 stars
