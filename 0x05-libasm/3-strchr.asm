BITS 64

	global asm_strchr	; Export our 'asm_strchr' function

	section .text

	; char *asm_strchr(const char *s, int c);
	; Write a copycat of the function strchr

asm_strchr:

	push rbp		; setup
	mov rbp, rsp		; Those two lines are equivalent to 'enter'

	mov rax, 0h

while:
	mov al, BYTE [rdi]
	cmp BYTE [rdi], sil
	jz found
	cmp BYTE [rdi], 0h
	jz retur
	inc rdi
	jmp while

found:
	mov rax, rdi

retur:

	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'

	ret			; Return from procedure ('pop rip')
