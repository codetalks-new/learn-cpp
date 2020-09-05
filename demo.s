
bin/demo:	file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
__text:
100000f60:	55 	pushq	%rbp
100000f61:	48 89 e5 	movq	%rsp, %rbp
100000f64:	8b 47 04 	movl	4(%rdi), %eax
100000f67:	03 07 	addl	(%rdi), %eax
100000f69:	5d 	popq	%rbp
100000f6a:	c3 	retq
100000f6b:	0f 1f 44 00 00 	nopl	(%rax,%rax)
100000f70:	55 	pushq	%rbp
100000f71:	48 89 e5 	movq	%rsp, %rbp
100000f74:	bf 08 00 00 00 	movl	$8, %edi
100000f79:	e8 16 00 00 00 	callq	22 <dyld_stub_binder+0x100000f94>
100000f7e:	48 b9 03 00 00 00 04 00 00 00 	movabsq	$17179869187, %rcx
100000f88:	48 89 08 	movq	%rcx, (%rax)
100000f8b:	48 89 c7 	movq	%rax, %rdi
100000f8e:	5d 	popq	%rbp
100000f8f:	e9 cc ff ff ff 	jmp	-52 <__Z6calcXYP5Point>

__Z6calcXYP5Point:
100000f60:	55 	pushq	%rbp
100000f61:	48 89 e5 	movq	%rsp, %rbp
100000f64:	8b 47 04 	movl	4(%rdi), %eax
100000f67:	03 07 	addl	(%rdi), %eax
100000f69:	5d 	popq	%rbp
100000f6a:	c3 	retq
100000f6b:	0f 1f 44 00 00 	nopl	(%rax,%rax)

_main:
100000f70:	55 	pushq	%rbp
100000f71:	48 89 e5 	movq	%rsp, %rbp
100000f74:	bf 08 00 00 00 	movl	$8, %edi
100000f79:	e8 16 00 00 00 	callq	22 <dyld_stub_binder+0x100000f94>
100000f7e:	48 b9 03 00 00 00 04 00 00 00 	movabsq	$17179869187, %rcx
100000f88:	48 89 08 	movq	%rcx, (%rax)
100000f8b:	48 89 c7 	movq	%rax, %rdi
100000f8e:	5d 	popq	%rbp
100000f8f:	e9 cc ff ff ff 	jmp	-52 <__Z6calcXYP5Point>
Disassembly of section __TEXT,__stubs:
__stubs:
100000f94:	ff 25 76 00 00 00 	jmpq	*118(%rip)
Disassembly of section __TEXT,__stub_helper:
__stub_helper:
100000f9c:	4c 8d 1d 65 00 00 00 	leaq	101(%rip), %r11
100000fa3:	41 53 	pushq	%r11
100000fa5:	ff 25 55 00 00 00 	jmpq	*85(%rip)
100000fab:	90 	nop
