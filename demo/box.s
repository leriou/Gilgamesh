	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_f                      ## -- Begin function f
	.p2align	4, 0x90
_f:                                     ## @f
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	%ecx, -24(%rbp)
	cmpl	$1, -24(%rbp)
	jne	LBB0_6
## BB#1:
	jmp	LBB0_2
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	movq	-8(%rbp), %rax
	cmpq	-16(%rbp), %rax
	je	LBB0_5
## BB#3:                                ##   in Loop: Header=BB0_2 Depth=1
	leaq	L_.str(%rip), %rdi
	movq	-8(%rbp), %rax
	movl	(%rax), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
## BB#4:                                ##   in Loop: Header=BB0_2 Depth=1
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movq	%rax, -8(%rbp)
	jmp	LBB0_2
LBB0_5:
	leaq	L_.str.1(%rip), %rdi
	movl	-20(%rbp), %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jmp	LBB0_11
LBB0_6:
	movq	-16(%rbp), %rax
	movl	$0, (%rax)
LBB0_7:                                 ## =>This Inner Loop Header: Depth=1
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	cmpl	-20(%rbp), %ecx
	jg	LBB0_10
## BB#8:                                ##   in Loop: Header=BB0_7 Depth=1
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rax
	addq	$4, %rax
	movl	-20(%rbp), %ecx
	movq	-16(%rbp), %rdx
	subl	(%rdx), %ecx
	movl	-24(%rbp), %esi
	subl	$1, %esi
	movl	%esi, -36(%rbp)         ## 4-byte Spill
	movq	%rax, %rsi
	movl	%ecx, %edx
	movl	-36(%rbp), %ecx         ## 4-byte Reload
	callq	_f
## BB#9:                                ##   in Loop: Header=BB0_7 Depth=1
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, (%rax)
	jmp	LBB0_7
LBB0_10:
	jmp	LBB0_11
LBB0_11:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_g                      ## -- Begin function g
	.p2align	4, 0x90
_g:                                     ## @g
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	%edi, -12(%rbp)
	movl	%esi, -16(%rbp)
	movl	-16(%rbp), %esi
	movl	%esi, %eax
	movq	%rsp, %rcx
	movq	%rcx, -24(%rbp)
	leaq	15(,%rax,4), %rax
	movabsq	$34359738352, %rcx      ## imm = 0x7FFFFFFF0
	andq	%rcx, %rax
	movq	%rsp, %rcx
	subq	%rax, %rcx
	movq	%rcx, %rsp
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %esi
	movq	%rcx, %rdi
	movl	%esi, -28(%rbp)         ## 4-byte Spill
	movq	%rcx, %rsi
	movl	-28(%rbp), %ecx         ## 4-byte Reload
	callq	_f
	movq	-24(%rbp), %rax
	movq	%rax, %rsp
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rsi
	cmpq	%rsi, %rax
	jne	LBB1_2
## BB#1:
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB1_2:
	callq	___stack_chk_fail
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	movl	$2, %edi
	movl	$3, %esi
	callq	_g
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d "

L_.str.1:                               ## @.str.1
	.asciz	"%d\n"


.subsections_via_symbols
