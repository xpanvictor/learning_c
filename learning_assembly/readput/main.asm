section .data
	msg db 'Please enter a number: '	; Ask the user to enter a number
	lenMsg equ $ nnnn - msg;			; Length of the message
	dispMsg db 'You have entered: '		; Preparing to show user msg
	lenDispMsg equ $- dispMsg		; the length of display msg




section .bss					; unintialized data
	num resb 5



section .text					; code starting point for linker
	global _start

_start:
	; Ask user for number
	mov edx, lenMsg				; length of msg as arg
	mov ecx, msg				; move msg itself as arg
	mov ebx, 1				; file descriptor std_out
	mov eax, 4				; sys_write system call
	int 80h					; call kernel

	
	; Read and store user input
	mov edx, 5				; 5 bytes for the number, 1 byte for sign
	mov ecx, num				; move allocated space to ecx, as arg for sys_read
	mov ebx, 1
	mov eax, 3				; sys_read sys call
	int 80h					; execute | kernel call

	
	; Output beginning of response
	mov edx, lenDispMsg			; length of disp msg
	mov ecx, dispMsg			; disp msg itself
	mov ebx, 1				; std out
	mov eax, 4				; sys_write
	int 80h					; interrupt, call kernel

	; Output the number entered
	mov edx, 5				; num of byte of output
	mov ecx, num				; the entered num to ecx
	mov ebx, 1				; std_out
	mov eax, 4				; sys_write
	int 80h					; kernel call

	; Exit code
	mov ebx, 0
	mov eax, 1				; sys_exit
	int 80h					; kernel call
