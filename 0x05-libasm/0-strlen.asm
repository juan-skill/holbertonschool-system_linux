BITS 64

	global asm_strlen	; Export our 'asm_strlen' function

	section .text

	; size_t asm_strlen(const char *str);
	; write a copycat of the function strlen

asm_strlen:

	push rbp		; setup
	mov rbp, rsp		; Those two lines are equivalent to 'enter'

	mov rax, 10h

	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'

	ret			; Return from procedure ('pop rip')
