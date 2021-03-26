BITS 64

	global asm_strcmp	; Export our 'asm_strcmp' function

	section .text

	; int asm_strcmp(const char *s1, const char *s2);
	; Write a copycat of the function strcmp

asm_strcmp:

	push rbp		; setup
	mov rbp, rsp		; Those two lines are equivalent to 'enter'

	push rdx

while:
	mov rax, rdi
	mov rdx, rsi
	movzx eax, BYTE [rax]
	movzx edx, BYTE [rdx]
	cmp al, 0h
	je after
	cmp al, dl
	jne after
	add rdi, 1h
	add rsi, 1h
	jmp while

after:
	cmp al, dl
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
	pop rdx

	mov rsp, rbp		; Restore previous stack frame
	pop rbp			; Those two lines are equivalent to 'leave'

	ret			; Return from procedure ('pop rip')
