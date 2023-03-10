	.file	"1.c"
	.text
	.section	.rodata
.LC0:
	.string	"Entering main"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	$40, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	addq	$20, %rax
	addl	$10, %edx
	movl	%edx, (%rax)
	movl	$30, -12(%rbp)
	movl	-12(%rbp), %eax
	addl	$40, %eax
	movl	%eax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
