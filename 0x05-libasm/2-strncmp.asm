BITS 64

	global asm_strncmp	; Export our 'strncmp' function

	section .text

	; int asm_strncmp(const char *s1, const char *s2, size_t n);
	; Write a copycat of the function strncmp

asm_strncmp:

	push rbp		; setup
	mov rbp, rsp		; Those two lines are equivalent to 'enter'

	push rcx

while:
	mov rax, rdi
	mov rcx, rsi
	movzx eax, BYTE [rax]
	movzx ecx, BYTE [rcx]
	cmp al, 0h
	je after
	cmp al, cl
	jne after
	add rdi, 1h
	add rsi, 1h
	dec edx
	jz equal
	jmp while

after:
	cmp al, cl
	je equal
	jl less
	mov RAX, 0x1
	jmp retur
equal:
	mov RAX, 0x0
	jmp retur
less:
	mov RAX, -0x1
	jmp retur

retur:
	pop rcx


	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'

	ret			; Return from procedure ('pop rip')
