
main:	file format Mach-O 64-bit x86-64

Disassembly of section __TEXT,__text:
__text:
1000014f0:	pushq	%rbp
1000014f1:	movq	%rsp, %rbp
1000014f4:	subq	$16, %rsp
1000014f8:	leaq	-16(%rbp), %rdi
1000014fc:	callq	31 <__ZN7Student8sayHelloEv>
100001501:	leaq	-8(%rbp), %rdi
100001505:	callq	70 <__ZN5Hello8sayHelloEv>
10000150a:	xorl	%eax, %eax
10000150c:	addq	$16, %rsp
100001510:	popq	%rbp
100001511:	retq
100001512:	nopw	%cs:(%rax,%rax)
10000151c:	nopl	(%rax)
100001520:	pushq	%rbp
100001521:	movq	%rsp, %rbp
100001524:	subq	$16, %rsp
100001528:	movq	2785(%rip), %rdi
10000152f:	leaq	2502(%rip), %rsi
100001536:	callq	53 <__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc>
10000153b:	leaq	-8(%rbp), %rdi
10000153f:	callq	12 <__ZN5Hello8sayHelloEv>
100001544:	addq	$16, %rsp
100001548:	popq	%rbp
100001549:	retq
10000154a:	nopw	(%rax,%rax)
100001550:	pushq	%rbp
100001551:	movq	%rsp, %rbp
100001554:	movq	2741(%rip), %rdi
10000155b:	leaq	2472(%rip), %rsi
100001562:	popq	%rbp
100001563:	jmp	8 <__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc>
100001568:	nopl	(%rax,%rax)
100001570:	pushq	%rbp
100001571:	movq	%rsp, %rbp
100001574:	pushq	%r14
100001576:	pushq	%rbx
100001577:	movq	%rsi, %rbx
10000157a:	movq	%rdi, %r14
10000157d:	movq	%rsi, %rdi
100001580:	callq	299 <__ZNSt3__111char_traitsIcE6lengthEPKc>
100001585:	movq	%r14, %rdi
100001588:	movq	%rbx, %rsi
10000158b:	movq	%rax, %rdx
10000158e:	popq	%rbx
10000158f:	popq	%r14
100001591:	popq	%rbp
100001592:	jmp	9 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>
100001597:	nopw	(%rax,%rax)
1000015a0:	pushq	%rbp
1000015a1:	movq	%rsp, %rbp
1000015a4:	pushq	%r15
1000015a6:	pushq	%r14
1000015a8:	pushq	%r13
1000015aa:	pushq	%r12
1000015ac:	pushq	%rbx
1000015ad:	subq	$40, %rsp
1000015b1:	movq	%rdx, %r12
1000015b4:	movq	%rsi, %r15
1000015b7:	movq	%rdi, %r14
1000015ba:	leaq	-72(%rbp), %rdi
1000015be:	movq	%r14, %rsi
1000015c1:	callq	1976 <dyld_stub_binder+0x100001d7e>
1000015c6:	leaq	-72(%rbp), %rdi
1000015ca:	callq	241 <__ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbEv>
1000015cf:	testb	%al, %al
1000015d1:	je	116 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xa7>
1000015d3:	leaq	-48(%rbp), %rdi
1000015d7:	movq	%r14, %rsi
1000015da:	callq	529 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1ERNS_13basic_ostreamIcS2_EE>
1000015df:	movq	(%r14), %rax
1000015e2:	movq	-24(%rax), %rbx
1000015e6:	addq	%r14, %rbx
1000015e9:	movq	%rbx, %rdi
1000015ec:	callq	527 <__ZNKSt3__18ios_base5flagsEv>
1000015f1:	movl	%eax, %r13d
1000015f4:	movq	%rbx, %rdi
1000015f7:	callq	532 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv>
1000015fc:	addq	%r15, %r12
1000015ff:	andl	$176, %r13d
100001606:	cmpl	$32, %r13d
10000160a:	movq	%r15, %rdx
10000160d:	cmoveq	%r12, %rdx
100001611:	movq	-48(%rbp), %rdi
100001615:	movsbl	%al, %r9d
100001619:	movq	%r15, %rsi
10000161c:	movq	%r12, %rcx
10000161f:	movq	%rbx, %r8
100001622:	callq	169 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_>
100001627:	movq	%rax, -56(%rbp)
10000162b:	leaq	-56(%rbp), %rdi
10000162f:	callq	540 <__ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedEv>
100001634:	testb	%al, %al
100001636:	je	15 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xa7>
100001638:	movq	(%r14), %rax
10000163b:	movq	-24(%rax), %rdi
10000163f:	addq	%r14, %rdi
100001642:	callq	537 <__ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj>
100001647:	leaq	-72(%rbp), %rdi
10000164b:	callq	1844 <dyld_stub_binder+0x100001d84>
100001650:	movq	%r14, %rax
100001653:	addq	$40, %rsp
100001657:	popq	%rbx
100001658:	popq	%r12
10000165a:	popq	%r13
10000165c:	popq	%r14
10000165e:	popq	%r15
100001660:	popq	%rbp
100001661:	retq
100001662:	jmp	0 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xc4>
100001664:	movq	%rax, %rbx
100001667:	leaq	-72(%rbp), %rdi
10000166b:	callq	1812 <dyld_stub_binder+0x100001d84>
100001670:	jmp	3 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xd5>
100001672:	movq	%rax, %rbx
100001675:	movq	%rbx, %rdi
100001678:	callq	1841 <dyld_stub_binder+0x100001dae>
10000167d:	movq	(%r14), %rax
100001680:	movq	-24(%rax), %rdi
100001684:	addq	%r14, %rdi
100001687:	callq	1796 <dyld_stub_binder+0x100001d90>
10000168c:	callq	1827 <dyld_stub_binder+0x100001db4>
100001691:	jmp	-67 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xb0>
100001693:	movq	%rax, %rbx
100001696:	callq	1817 <dyld_stub_binder+0x100001db4>
10000169b:	movq	%rbx, %rdi
10000169e:	callq	1725 <dyld_stub_binder+0x100001d60>
1000016a3:	ud2
1000016a5:	movq	%rax, %rdi
1000016a8:	callq	451 <___clang_call_terminate>
1000016ad:	nopl	(%rax)
1000016b0:	pushq	%rbp
1000016b1:	movq	%rsp, %rbp
1000016b4:	popq	%rbp
1000016b5:	jmp	1798 <dyld_stub_binder+0x100001dc0>
1000016ba:	nopw	(%rax,%rax)
1000016c0:	pushq	%rbp
1000016c1:	movq	%rsp, %rbp
1000016c4:	movb	(%rdi), %al
1000016c6:	popq	%rbp
1000016c7:	retq
1000016c8:	nopl	(%rax,%rax)
1000016d0:	pushq	%rbp
1000016d1:	movq	%rsp, %rbp
1000016d4:	pushq	%r15
1000016d6:	pushq	%r14
1000016d8:	pushq	%r13
1000016da:	pushq	%r12
1000016dc:	pushq	%rbx
1000016dd:	subq	$56, %rsp
1000016e1:	movl	%r9d, -44(%rbp)
1000016e5:	movq	%r8, %r15
1000016e8:	movq	%rcx, %rbx
1000016eb:	movq	%rdx, %r12
1000016ee:	movq	%rsi, %r14
1000016f1:	movq	%rdi, %r13
1000016f4:	callq	391 <__ZNSt3__1L15__get_nullptr_tEv>
1000016f9:	testq	%r13, %r13
1000016fc:	je	185 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xeb>
100001702:	movq	%rbx, -64(%rbp)
100001706:	subq	%r14, %rbx
100001709:	movq	%r15, -56(%rbp)
10000170d:	movq	%r15, %rdi
100001710:	callq	395 <__ZNKSt3__18ios_base5widthEv>
100001715:	xorl	%r15d, %r15d
100001718:	subq	%rbx, %rax
10000171b:	cmovgq	%rax, %r15
10000171f:	movq	%r12, %rbx
100001722:	subq	%r14, %r12
100001725:	testq	%r12, %r12
100001728:	jle	19 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x6d>
10000172a:	movq	%r13, %rdi
10000172d:	movq	%r14, %rsi
100001730:	movq	%r12, %rdx
100001733:	callq	376 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl>
100001738:	cmpq	%r12, %rax
10000173b:	jne	105 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xd6>
10000173d:	testq	%r15, %r15
100001740:	movq	-64(%rbp), %r14
100001744:	movq	%rbx, %r12
100001747:	jle	55 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xb0>
100001749:	movsbl	-44(%rbp), %edx
10000174d:	leaq	-88(%rbp), %rbx
100001751:	movq	%rbx, %rdi
100001754:	movq	%r15, %rsi
100001757:	callq	356 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Emc>
10000175c:	movq	%rbx, %rdi
10000175f:	callq	364 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv>
100001764:	movq	%r13, %rdi
100001767:	movq	%rax, %rsi
10000176a:	movq	%r15, %rdx
10000176d:	callq	318 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl>
100001772:	cmpq	%r15, %rax
100001775:	jne	54 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xdd>
100001777:	leaq	-88(%rbp), %rdi
10000177b:	callq	1528 <dyld_stub_binder+0x100001d78>
100001780:	subq	%r12, %r14
100001783:	testq	%r14, %r14
100001786:	jle	19 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xcb>
100001788:	movq	%r13, %rdi
10000178b:	movq	%r12, %rsi
10000178e:	movq	%r14, %rdx
100001791:	callq	282 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl>
100001796:	cmpq	%r14, %rax
100001799:	jne	11 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xd6>
10000179b:	movq	-56(%rbp), %rdi
10000179f:	callq	332 <__ZNSt3__18ios_base5widthEl>
1000017a4:	jmp	24 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xee>
1000017a6:	callq	213 <__ZNSt3__1L15__get_nullptr_tEv>
1000017ab:	jmp	14 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xeb>
1000017ad:	callq	206 <__ZNSt3__1L15__get_nullptr_tEv>
1000017b2:	leaq	-88(%rbp), %rdi
1000017b6:	callq	1469 <dyld_stub_binder+0x100001d78>
1000017bb:	xorl	%r13d, %r13d
1000017be:	movq	%r13, %rax
1000017c1:	addq	$56, %rsp
1000017c5:	popq	%rbx
1000017c6:	popq	%r12
1000017c8:	popq	%r13
1000017ca:	popq	%r14
1000017cc:	popq	%r15
1000017ce:	popq	%rbp
1000017cf:	retq
1000017d0:	movq	%rax, %rbx
1000017d3:	leaq	-88(%rbp), %rdi
1000017d7:	callq	1436 <dyld_stub_binder+0x100001d78>
1000017dc:	movq	%rbx, %rdi
1000017df:	callq	1404 <dyld_stub_binder+0x100001d60>
1000017e4:	ud2
1000017e6:	movq	%rax, %rdi
1000017e9:	callq	130 <___clang_call_terminate>
1000017ee:	nop
1000017f0:	pushq	%rbp
1000017f1:	movq	%rsp, %rbp
1000017f4:	popq	%rbp
1000017f5:	jmp	1094 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2ERNS_13basic_ostreamIcS2_EE>
1000017fa:	nopw	(%rax,%rax)
100001800:	pushq	%rbp
100001801:	movq	%rsp, %rbp
100001804:	movl	8(%rdi), %eax
100001807:	popq	%rbp
100001808:	retq
100001809:	nopl	(%rax)
100001810:	pushq	%rbp
100001811:	movq	%rsp, %rbp
100001814:	pushq	%rbx
100001815:	pushq	%rax
100001816:	movq	%rdi, %rbx
100001819:	callq	1154 <__ZNSt3__111char_traitsIcE3eofEv>
10000181e:	movl	144(%rbx), %esi
100001824:	movl	%eax, %edi
100001826:	callq	1125 <__ZNSt3__111char_traitsIcE11eq_int_typeEii>
10000182b:	testb	%al, %al
10000182d:	je	17 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv+0x30>
10000182f:	movq	%rbx, %rdi
100001832:	callq	1145 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc>
100001837:	movsbl	%al, %eax
10000183a:	movl	%eax, 144(%rbx)
100001840:	movsbl	144(%rbx), %eax
100001847:	addq	$8, %rsp
10000184b:	popq	%rbx
10000184c:	popq	%rbp
10000184d:	retq
10000184e:	nop
100001850:	pushq	%rbp
100001851:	movq	%rsp, %rbp
100001854:	cmpq	$0, (%rdi)
100001858:	sete	%al
10000185b:	popq	%rbp
10000185c:	retq
10000185d:	nopl	(%rax)
100001860:	pushq	%rbp
100001861:	movq	%rsp, %rbp
100001864:	popq	%rbp
100001865:	jmp	1254 <__ZNSt3__18ios_base8setstateEj>
10000186a:	nopw	(%rax,%rax)
100001870:	pushq	%rax
100001871:	callq	1336 <dyld_stub_binder+0x100001dae>
100001876:	callq	1313 <dyld_stub_binder+0x100001d9c>
10000187b:	nopl	(%rax,%rax)
100001880:	pushq	%rbp
100001881:	movq	%rsp, %rbp
100001884:	subq	$16, %rsp
100001888:	leaq	-8(%rbp), %rdi
10000188c:	callq	111 <__ZNSt3__19nullptr_tC1EMNS0_5__natEi>
100001891:	movq	-8(%rbp), %rax
100001895:	addq	$16, %rsp
100001899:	popq	%rbp
10000189a:	retq
10000189b:	nopl	(%rax,%rax)
1000018a0:	pushq	%rbp
1000018a1:	movq	%rsp, %rbp
1000018a4:	movq	24(%rdi), %rax
1000018a8:	popq	%rbp
1000018a9:	retq
1000018aa:	nopw	(%rax,%rax)
1000018b0:	pushq	%rbp
1000018b1:	movq	%rsp, %rbp
1000018b4:	movq	(%rdi), %rax
1000018b7:	movq	96(%rax), %rax
1000018bb:	popq	%rbp
1000018bc:	jmpq	*%rax
1000018be:	nop
1000018c0:	pushq	%rbp
1000018c1:	movq	%rsp, %rbp
1000018c4:	popq	%rbp
1000018c5:	jmp	86 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2Emc>
1000018ca:	nopw	(%rax,%rax)
1000018d0:	pushq	%rbp
1000018d1:	movq	%rsp, %rbp
1000018d4:	callq	631 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv>
1000018d9:	movq	%rax, %rdi
1000018dc:	popq	%rbp
1000018dd:	jmp	606 <__ZNSt3__1L16__to_raw_pointerIKcEEPT_S3_>
1000018e2:	nopw	%cs:(%rax,%rax)
1000018ec:	nopl	(%rax)
1000018f0:	pushq	%rbp
1000018f1:	movq	%rsp, %rbp
1000018f4:	movq	$0, 24(%rdi)
1000018fc:	popq	%rbp
1000018fd:	retq
1000018fe:	nop
100001900:	pushq	%rbp
100001901:	movq	%rsp, %rbp
100001904:	popq	%rbp
100001905:	jmp	6 <__ZNSt3__19nullptr_tC2EMNS0_5__natEi>
10000190a:	nopw	(%rax,%rax)
100001910:	pushq	%rbp
100001911:	movq	%rsp, %rbp
100001914:	movq	$0, (%rdi)
10000191b:	popq	%rbp
10000191c:	retq
10000191d:	nopl	(%rax)
100001920:	pushq	%rbp
100001921:	movq	%rsp, %rbp
100001924:	pushq	%r15
100001926:	pushq	%r14
100001928:	pushq	%rbx
100001929:	pushq	%rax
10000192a:	movl	%edx, %r14d
10000192d:	movq	%rsi, %r15
100001930:	movq	%rdi, %rbx
100001933:	callq	24 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1Ev>
100001938:	movq	%rbx, %rdi
10000193b:	movq	%r15, %rsi
10000193e:	movl	%r14d, %edx
100001941:	addq	$8, %rsp
100001945:	popq	%rbx
100001946:	popq	%r14
100001948:	popq	%r15
10000194a:	popq	%rbp
10000194b:	jmp	1058 <dyld_stub_binder+0x100001d72>
100001950:	pushq	%rbp
100001951:	movq	%rsp, %rbp
100001954:	popq	%rbp
100001955:	jmp	6 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2Ev>
10000195a:	nopw	(%rax,%rax)
100001960:	pushq	%rbp
100001961:	movq	%rsp, %rbp
100001964:	popq	%rbp
100001965:	jmp	6 <__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2Ev>
10000196a:	nopw	(%rax,%rax)
100001970:	pushq	%rbp
100001971:	movq	%rsp, %rbp
100001974:	movq	$0, 16(%rdi)
10000197c:	movq	$0, 8(%rdi)
100001984:	movq	$0, (%rdi)
10000198b:	popq	%rbp
10000198c:	retq
10000198d:	nopl	(%rax)
100001990:	pushq	%rbp
100001991:	movq	%rsp, %rbp
100001994:	pushq	%rbx
100001995:	pushq	%rax
100001996:	movq	%rsi, %rbx
100001999:	addb	%bl, %bl
10000199b:	callq	288 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
1000019a0:	movb	%bl, (%rax)
1000019a2:	addq	$8, %rsp
1000019a6:	popq	%rbx
1000019a7:	popq	%rbp
1000019a8:	retq
1000019a9:	nopl	(%rax)
1000019b0:	pushq	%rbp
1000019b1:	movq	%rsp, %rbp
1000019b4:	callq	263 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
1000019b9:	leaq	1(%rax), %rdi
1000019bd:	callq	286 <__ZNSt3__114pointer_traitsIPcE10pointer_toERc>
1000019c2:	popq	%rbp
1000019c3:	retq
1000019c4:	nopw	%cs:(%rax,%rax)
1000019ce:	nop
1000019d0:	cmpq	$23, %rdi
1000019d4:	jae	6 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE11__recommendEm+0xc>
1000019d6:	movl	$22, %eax
1000019db:	retq
1000019dc:	pushq	%rbp
1000019dd:	movq	%rsp, %rbp
1000019e0:	incq	%rdi
1000019e3:	callq	280 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE10__align_itILm16EEEmm>
1000019e8:	movq	%rax, %rcx
1000019eb:	decq	%rax
1000019ee:	cmpq	$23, %rax
1000019f2:	cmoveq	%rcx, %rax
1000019f6:	popq	%rbp
1000019f7:	retq
1000019f8:	nopl	(%rax,%rax)
100001a00:	pushq	%rbp
100001a01:	movq	%rsp, %rbp
100001a04:	callq	263 <__ZNSt3__19allocatorIcE8allocateEmPKv>
100001a09:	popq	%rbp
100001a0a:	retq
100001a0b:	nopl	(%rax,%rax)
100001a10:	pushq	%rbp
100001a11:	movq	%rsp, %rbp
100001a14:	pushq	%rbx
100001a15:	pushq	%rax
100001a16:	movq	%rsi, %rbx
100001a19:	callq	162 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001a1e:	movq	%rbx, 16(%rax)
100001a22:	addq	$8, %rsp
100001a26:	popq	%rbx
100001a27:	popq	%rbp
100001a28:	retq
100001a29:	nopl	(%rax)
100001a30:	pushq	%rbp
100001a31:	movq	%rsp, %rbp
100001a34:	pushq	%rbx
100001a35:	pushq	%rax
100001a36:	movq	%rsi, %rbx
100001a39:	orq	$1, %rbx
100001a3d:	callq	126 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001a42:	movq	%rbx, (%rax)
100001a45:	addq	$8, %rsp
100001a49:	popq	%rbx
100001a4a:	popq	%rbp
100001a4b:	retq
100001a4c:	nopl	(%rax)
100001a50:	pushq	%rbp
100001a51:	movq	%rsp, %rbp
100001a54:	pushq	%rbx
100001a55:	pushq	%rax
100001a56:	movq	%rsi, %rbx
100001a59:	callq	98 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001a5e:	movq	%rbx, 8(%rax)
100001a62:	addq	$8, %rsp
100001a66:	popq	%rbx
100001a67:	popq	%rbp
100001a68:	retq
100001a69:	nopl	(%rax)
100001a70:	pushq	%rbp
100001a71:	movq	%rsp, %rbp
100001a74:	pushq	%r14
100001a76:	pushq	%rbx
100001a77:	movq	%rdi, %r14
100001a7a:	testq	%rsi, %rsi
100001a7d:	je	24 <__ZNSt3__111char_traitsIcE6assignEPcmc+0x27>
100001a7f:	movq	%rsi, %rbx
100001a82:	movsbl	%dl, %edi
100001a85:	callq	166 <__ZNSt3__111char_traitsIcE11to_int_typeEc>
100001a8a:	movq	%r14, %rdi
100001a8d:	movl	%eax, %esi
100001a8f:	movq	%rbx, %rdx
100001a92:	callq	803 <dyld_stub_binder+0x100001dba>
100001a97:	movq	%r14, %rax
100001a9a:	popq	%rbx
100001a9b:	popq	%r14
100001a9d:	popq	%rbp
100001a9e:	retq
100001a9f:	nop
100001aa0:	pushq	%rbp
100001aa1:	movq	%rsp, %rbp
100001aa4:	movq	%rdi, %rax
100001aa7:	popq	%rbp
100001aa8:	retq
100001aa9:	nopl	(%rax)
100001ab0:	pushq	%rbp
100001ab1:	movq	%rsp, %rbp
100001ab4:	movb	(%rsi), %al
100001ab6:	movb	%al, (%rdi)
100001ab8:	popq	%rbp
100001ab9:	retq
100001aba:	nopw	(%rax,%rax)
100001ac0:	pushq	%rbp
100001ac1:	movq	%rsp, %rbp
100001ac4:	callq	7 <__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv>
100001ac9:	popq	%rbp
100001aca:	retq
100001acb:	nopl	(%rax,%rax)
100001ad0:	pushq	%rbp
100001ad1:	movq	%rsp, %rbp
100001ad4:	movq	%rdi, %rax
100001ad7:	popq	%rbp
100001ad8:	retq
100001ad9:	nopl	(%rax)
100001ae0:	pushq	%rbp
100001ae1:	movq	%rsp, %rbp
100001ae4:	callq	7 <__ZNSt3__1L9addressofIcEEPT_RS1_>
100001ae9:	popq	%rbp
100001aea:	retq
100001aeb:	nopl	(%rax,%rax)
100001af0:	pushq	%rbp
100001af1:	movq	%rsp, %rbp
100001af4:	movq	%rdi, %rax
100001af7:	popq	%rbp
100001af8:	retq
100001af9:	nopl	(%rax)
100001b00:	pushq	%rbp
100001b01:	movq	%rsp, %rbp
100001b04:	leaq	15(%rdi), %rax
100001b08:	andq	$-16, %rax
100001b0c:	popq	%rbp
100001b0d:	retq
100001b0e:	nop
100001b10:	pushq	%rbp
100001b11:	movq	%rsp, %rbp
100001b14:	callq	7 <__ZNSt3__1L17__libcpp_allocateEmm>
100001b19:	popq	%rbp
100001b1a:	retq
100001b1b:	nopl	(%rax,%rax)
100001b20:	pushq	%rbp
100001b21:	movq	%rsp, %rbp
100001b24:	callq	639 <dyld_stub_binder+0x100001da8>
100001b29:	popq	%rbp
100001b2a:	retq
100001b2b:	nopl	(%rax,%rax)
100001b30:	pushq	%rbp
100001b31:	movq	%rsp, %rbp
100001b34:	movzbl	%dil, %eax
100001b38:	popq	%rbp
100001b39:	retq
100001b3a:	nopw	(%rax,%rax)
100001b40:	pushq	%rbp
100001b41:	movq	%rsp, %rbp
100001b44:	movq	%rdi, %rax
100001b47:	popq	%rbp
100001b48:	retq
100001b49:	nopl	(%rax)
100001b50:	pushq	%rbp
100001b51:	movq	%rsp, %rbp
100001b54:	pushq	%rbx
100001b55:	pushq	%rax
100001b56:	movq	%rdi, %rbx
100001b59:	callq	34 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longEv>
100001b5e:	movq	%rbx, %rdi
100001b61:	addq	$8, %rsp
100001b65:	testb	%al, %al
100001b67:	je	7 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv+0x20>
100001b69:	popq	%rbx
100001b6a:	popq	%rbp
100001b6b:	jmp	32 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv>
100001b70:	popq	%rbx
100001b71:	popq	%rbp
100001b72:	jmp	41 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv>
100001b77:	nopw	(%rax,%rax)
100001b80:	pushq	%rbp
100001b81:	movq	%rsp, %rbp
100001b84:	callq	55 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001b89:	movb	(%rax), %al
100001b8b:	andb	$1, %al
100001b8d:	popq	%rbp
100001b8e:	retq
100001b8f:	nop
100001b90:	pushq	%rbp
100001b91:	movq	%rsp, %rbp
100001b94:	callq	39 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001b99:	movq	16(%rax), %rax
100001b9d:	popq	%rbp
100001b9e:	retq
100001b9f:	nop
100001ba0:	pushq	%rbp
100001ba1:	movq	%rsp, %rbp
100001ba4:	callq	23 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001ba9:	leaq	1(%rax), %rdi
100001bad:	callq	46 <__ZNSt3__114pointer_traitsIPKcE10pointer_toERS1_>
100001bb2:	popq	%rbp
100001bb3:	retq
100001bb4:	nopw	%cs:(%rax,%rax)
100001bbe:	nop
100001bc0:	pushq	%rbp
100001bc1:	movq	%rsp, %rbp
100001bc4:	callq	7 <__ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv>
100001bc9:	popq	%rbp
100001bca:	retq
100001bcb:	nopl	(%rax,%rax)
100001bd0:	pushq	%rbp
100001bd1:	movq	%rsp, %rbp
100001bd4:	movq	%rdi, %rax
100001bd7:	popq	%rbp
100001bd8:	retq
100001bd9:	nopl	(%rax)
100001be0:	pushq	%rbp
100001be1:	movq	%rsp, %rbp
100001be4:	callq	7 <__ZNSt3__1L9addressofIKcEEPT_RS2_>
100001be9:	popq	%rbp
100001bea:	retq
100001beb:	nopl	(%rax,%rax)
100001bf0:	pushq	%rbp
100001bf1:	movq	%rsp, %rbp
100001bf4:	movq	%rdi, %rax
100001bf7:	popq	%rbp
100001bf8:	retq
100001bf9:	nopl	(%rax)
100001c00:	pushq	%rbp
100001c01:	movq	%rsp, %rbp
100001c04:	popq	%rbp
100001c05:	jmp	22 <__ZNSt3__19allocatorIcE10deallocateEPcm>
100001c0a:	nopw	(%rax,%rax)
100001c10:	pushq	%rbp
100001c11:	movq	%rsp, %rbp
100001c14:	callq	-345 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001c19:	movq	16(%rax), %rax
100001c1d:	popq	%rbp
100001c1e:	retq
100001c1f:	nop
100001c20:	pushq	%rbp
100001c21:	movq	%rsp, %rbp
100001c24:	popq	%rbp
100001c25:	jmp	6 <__ZNSt3__1L19__libcpp_deallocateEPvm>
100001c2a:	nopw	(%rax,%rax)
100001c30:	pushq	%rbp
100001c31:	movq	%rsp, %rbp
100001c34:	popq	%rbp
100001c35:	jmp	360 <dyld_stub_binder+0x100001da2>
100001c3a:	nopw	(%rax,%rax)
100001c40:	pushq	%rbp
100001c41:	movq	%rsp, %rbp
100001c44:	pushq	%rbx
100001c45:	pushq	%rax
100001c46:	movq	%rdi, %rbx
100001c49:	movq	(%rsi), %rax
100001c4c:	addq	-24(%rax), %rsi
100001c50:	movq	%rsi, %rdi
100001c53:	callq	24 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufEv>
100001c58:	movq	%rax, (%rbx)
100001c5b:	addq	$8, %rsp
100001c5f:	popq	%rbx
100001c60:	popq	%rbp
100001c61:	retq
100001c62:	nopw	%cs:(%rax,%rax)
100001c6c:	nopl	(%rax)
100001c70:	pushq	%rbp
100001c71:	movq	%rsp, %rbp
100001c74:	popq	%rbp
100001c75:	jmp	6 <__ZNKSt3__18ios_base5rdbufEv>
100001c7a:	nopw	(%rax,%rax)
100001c80:	pushq	%rbp
100001c81:	movq	%rsp, %rbp
100001c84:	movq	40(%rdi), %rax
100001c88:	popq	%rbp
100001c89:	retq
100001c8a:	nopw	(%rax,%rax)
100001c90:	pushq	%rbp
100001c91:	movq	%rsp, %rbp
100001c94:	cmpl	%esi, %edi
100001c96:	sete	%al
100001c99:	popq	%rbp
100001c9a:	retq
100001c9b:	nopl	(%rax,%rax)
100001ca0:	pushq	%rbp
100001ca1:	movq	%rsp, %rbp
100001ca4:	movl	$4294967295, %eax
100001ca9:	popq	%rbp
100001caa:	retq
100001cab:	nopl	(%rax,%rax)
100001cb0:	pushq	%rbp
100001cb1:	movq	%rsp, %rbp
100001cb4:	pushq	%rbx
100001cb5:	pushq	%rax
100001cb6:	movq	%rdi, %rax
100001cb9:	leaq	-16(%rbp), %rbx
100001cbd:	movq	%rbx, %rdi
100001cc0:	movq	%rax, %rsi
100001cc3:	callq	164 <dyld_stub_binder+0x100001d6c>
100001cc8:	movq	%rbx, %rdi
100001ccb:	callq	64 <__ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE>
100001cd0:	movq	%rax, %rdi
100001cd3:	callq	88 <__ZNKSt3__15ctypeIcE5widenEc>
100001cd8:	movl	%eax, %ebx
100001cda:	leaq	-16(%rbp), %rdi
100001cde:	callq	167 <dyld_stub_binder+0x100001d8a>
100001ce3:	movsbl	%bl, %eax
100001ce6:	addq	$8, %rsp
100001cea:	popq	%rbx
100001ceb:	popq	%rbp
100001cec:	retq
100001ced:	movq	%rax, %rbx
100001cf0:	leaq	-16(%rbp), %rdi
100001cf4:	callq	145 <dyld_stub_binder+0x100001d8a>
100001cf9:	movq	%rbx, %rdi
100001cfc:	callq	95 <dyld_stub_binder+0x100001d60>
100001d01:	ud2
100001d03:	movq	%rax, %rdi
100001d06:	callq	-1179 <___clang_call_terminate>
100001d0b:	nopl	(%rax,%rax)
100001d10:	pushq	%rbp
100001d11:	movq	%rsp, %rbp
100001d14:	movq	765(%rip), %rsi
100001d1b:	callq	70 <dyld_stub_binder+0x100001d66>
100001d20:	popq	%rbp
100001d21:	retq
100001d22:	nopw	%cs:(%rax,%rax)
100001d2c:	nopl	(%rax)
100001d30:	pushq	%rbp
100001d31:	movq	%rsp, %rbp
100001d34:	movq	(%rdi), %rax
100001d37:	movq	56(%rax), %rax
100001d3b:	movl	$32, %esi
100001d40:	popq	%rbp
100001d41:	jmpq	*%rax
100001d43:	nopw	%cs:(%rax,%rax)
100001d4d:	nopl	(%rax)
100001d50:	pushq	%rbp
100001d51:	movq	%rsp, %rbp
100001d54:	movl	32(%rdi), %esi
100001d57:	orl	$5, %esi
100001d5a:	popq	%rbp
100001d5b:	jmp	54 <dyld_stub_binder+0x100001d96>

_main:
1000014f0:	pushq	%rbp
1000014f1:	movq	%rsp, %rbp
1000014f4:	subq	$16, %rsp
1000014f8:	leaq	-16(%rbp), %rdi
1000014fc:	callq	31 <__ZN7Student8sayHelloEv>
100001501:	leaq	-8(%rbp), %rdi
100001505:	callq	70 <__ZN5Hello8sayHelloEv>
10000150a:	xorl	%eax, %eax
10000150c:	addq	$16, %rsp
100001510:	popq	%rbp
100001511:	retq
100001512:	nopw	%cs:(%rax,%rax)
10000151c:	nopl	(%rax)

__ZN7Student8sayHelloEv:
100001520:	pushq	%rbp
100001521:	movq	%rsp, %rbp
100001524:	subq	$16, %rsp
100001528:	movq	2785(%rip), %rdi
10000152f:	leaq	2502(%rip), %rsi
100001536:	callq	53 <__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc>
10000153b:	leaq	-8(%rbp), %rdi
10000153f:	callq	12 <__ZN5Hello8sayHelloEv>
100001544:	addq	$16, %rsp
100001548:	popq	%rbp
100001549:	retq
10000154a:	nopw	(%rax,%rax)

__ZN5Hello8sayHelloEv:
100001550:	pushq	%rbp
100001551:	movq	%rsp, %rbp
100001554:	movq	2741(%rip), %rdi
10000155b:	leaq	2472(%rip), %rsi
100001562:	popq	%rbp
100001563:	jmp	8 <__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc>
100001568:	nopl	(%rax,%rax)

__ZNSt3__1lsINS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc:
100001570:	pushq	%rbp
100001571:	movq	%rsp, %rbp
100001574:	pushq	%r14
100001576:	pushq	%rbx
100001577:	movq	%rsi, %rbx
10000157a:	movq	%rdi, %r14
10000157d:	movq	%rsi, %rdi
100001580:	callq	299 <__ZNSt3__111char_traitsIcE6lengthEPKc>
100001585:	movq	%r14, %rdi
100001588:	movq	%rbx, %rsi
10000158b:	movq	%rax, %rdx
10000158e:	popq	%rbx
10000158f:	popq	%r14
100001591:	popq	%rbp
100001592:	jmp	9 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>
100001597:	nopw	(%rax,%rax)

__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m:
1000015a0:	pushq	%rbp
1000015a1:	movq	%rsp, %rbp
1000015a4:	pushq	%r15
1000015a6:	pushq	%r14
1000015a8:	pushq	%r13
1000015aa:	pushq	%r12
1000015ac:	pushq	%rbx
1000015ad:	subq	$40, %rsp
1000015b1:	movq	%rdx, %r12
1000015b4:	movq	%rsi, %r15
1000015b7:	movq	%rdi, %r14
1000015ba:	leaq	-72(%rbp), %rdi
1000015be:	movq	%r14, %rsi
1000015c1:	callq	1976 <dyld_stub_binder+0x100001d7e>
1000015c6:	leaq	-72(%rbp), %rdi
1000015ca:	callq	241 <__ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbEv>
1000015cf:	testb	%al, %al
1000015d1:	je	116 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xa7>
1000015d3:	leaq	-48(%rbp), %rdi
1000015d7:	movq	%r14, %rsi
1000015da:	callq	529 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1ERNS_13basic_ostreamIcS2_EE>
1000015df:	movq	(%r14), %rax
1000015e2:	movq	-24(%rax), %rbx
1000015e6:	addq	%r14, %rbx
1000015e9:	movq	%rbx, %rdi
1000015ec:	callq	527 <__ZNKSt3__18ios_base5flagsEv>
1000015f1:	movl	%eax, %r13d
1000015f4:	movq	%rbx, %rdi
1000015f7:	callq	532 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv>
1000015fc:	addq	%r15, %r12
1000015ff:	andl	$176, %r13d
100001606:	cmpl	$32, %r13d
10000160a:	movq	%r15, %rdx
10000160d:	cmoveq	%r12, %rdx
100001611:	movq	-48(%rbp), %rdi
100001615:	movsbl	%al, %r9d
100001619:	movq	%r15, %rsi
10000161c:	movq	%r12, %rcx
10000161f:	movq	%rbx, %r8
100001622:	callq	169 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_>
100001627:	movq	%rax, -56(%rbp)
10000162b:	leaq	-56(%rbp), %rdi
10000162f:	callq	540 <__ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedEv>
100001634:	testb	%al, %al
100001636:	je	15 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xa7>
100001638:	movq	(%r14), %rax
10000163b:	movq	-24(%rax), %rdi
10000163f:	addq	%r14, %rdi
100001642:	callq	537 <__ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj>
100001647:	leaq	-72(%rbp), %rdi
10000164b:	callq	1844 <dyld_stub_binder+0x100001d84>
100001650:	movq	%r14, %rax
100001653:	addq	$40, %rsp
100001657:	popq	%rbx
100001658:	popq	%r12
10000165a:	popq	%r13
10000165c:	popq	%r14
10000165e:	popq	%r15
100001660:	popq	%rbp
100001661:	retq
100001662:	jmp	0 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xc4>
100001664:	movq	%rax, %rbx
100001667:	leaq	-72(%rbp), %rdi
10000166b:	callq	1812 <dyld_stub_binder+0x100001d84>
100001670:	jmp	3 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xd5>
100001672:	movq	%rax, %rbx
100001675:	movq	%rbx, %rdi
100001678:	callq	1841 <dyld_stub_binder+0x100001dae>
10000167d:	movq	(%r14), %rax
100001680:	movq	-24(%rax), %rdi
100001684:	addq	%r14, %rdi
100001687:	callq	1796 <dyld_stub_binder+0x100001d90>
10000168c:	callq	1827 <dyld_stub_binder+0x100001db4>
100001691:	jmp	-67 <__ZNSt3__124__put_character_sequenceIcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xb0>
100001693:	movq	%rax, %rbx
100001696:	callq	1817 <dyld_stub_binder+0x100001db4>
10000169b:	movq	%rbx, %rdi
10000169e:	callq	1725 <dyld_stub_binder+0x100001d60>
1000016a3:	ud2
1000016a5:	movq	%rax, %rdi
1000016a8:	callq	451 <___clang_call_terminate>
1000016ad:	nopl	(%rax)

__ZNSt3__111char_traitsIcE6lengthEPKc:
1000016b0:	pushq	%rbp
1000016b1:	movq	%rsp, %rbp
1000016b4:	popq	%rbp
1000016b5:	jmp	1798 <dyld_stub_binder+0x100001dc0>
1000016ba:	nopw	(%rax,%rax)

__ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbEv:
1000016c0:	pushq	%rbp
1000016c1:	movq	%rsp, %rbp
1000016c4:	movb	(%rdi), %al
1000016c6:	popq	%rbp
1000016c7:	retq
1000016c8:	nopl	(%rax,%rax)

__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_:
1000016d0:	pushq	%rbp
1000016d1:	movq	%rsp, %rbp
1000016d4:	pushq	%r15
1000016d6:	pushq	%r14
1000016d8:	pushq	%r13
1000016da:	pushq	%r12
1000016dc:	pushq	%rbx
1000016dd:	subq	$56, %rsp
1000016e1:	movl	%r9d, -44(%rbp)
1000016e5:	movq	%r8, %r15
1000016e8:	movq	%rcx, %rbx
1000016eb:	movq	%rdx, %r12
1000016ee:	movq	%rsi, %r14
1000016f1:	movq	%rdi, %r13
1000016f4:	callq	391 <__ZNSt3__1L15__get_nullptr_tEv>
1000016f9:	testq	%r13, %r13
1000016fc:	je	185 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xeb>
100001702:	movq	%rbx, -64(%rbp)
100001706:	subq	%r14, %rbx
100001709:	movq	%r15, -56(%rbp)
10000170d:	movq	%r15, %rdi
100001710:	callq	395 <__ZNKSt3__18ios_base5widthEv>
100001715:	xorl	%r15d, %r15d
100001718:	subq	%rbx, %rax
10000171b:	cmovgq	%rax, %r15
10000171f:	movq	%r12, %rbx
100001722:	subq	%r14, %r12
100001725:	testq	%r12, %r12
100001728:	jle	19 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x6d>
10000172a:	movq	%r13, %rdi
10000172d:	movq	%r14, %rsi
100001730:	movq	%r12, %rdx
100001733:	callq	376 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl>
100001738:	cmpq	%r12, %rax
10000173b:	jne	105 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xd6>
10000173d:	testq	%r15, %r15
100001740:	movq	-64(%rbp), %r14
100001744:	movq	%rbx, %r12
100001747:	jle	55 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xb0>
100001749:	movsbl	-44(%rbp), %edx
10000174d:	leaq	-88(%rbp), %rbx
100001751:	movq	%rbx, %rdi
100001754:	movq	%r15, %rsi
100001757:	callq	356 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Emc>
10000175c:	movq	%rbx, %rdi
10000175f:	callq	364 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv>
100001764:	movq	%r13, %rdi
100001767:	movq	%rax, %rsi
10000176a:	movq	%r15, %rdx
10000176d:	callq	318 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl>
100001772:	cmpq	%r15, %rax
100001775:	jne	54 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xdd>
100001777:	leaq	-88(%rbp), %rdi
10000177b:	callq	1528 <dyld_stub_binder+0x100001d78>
100001780:	subq	%r12, %r14
100001783:	testq	%r14, %r14
100001786:	jle	19 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xcb>
100001788:	movq	%r13, %rdi
10000178b:	movq	%r12, %rsi
10000178e:	movq	%r14, %rdx
100001791:	callq	282 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl>
100001796:	cmpq	%r14, %rax
100001799:	jne	11 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xd6>
10000179b:	movq	-56(%rbp), %rdi
10000179f:	callq	332 <__ZNSt3__18ios_base5widthEl>
1000017a4:	jmp	24 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xee>
1000017a6:	callq	213 <__ZNSt3__1L15__get_nullptr_tEv>
1000017ab:	jmp	14 <__ZNSt3__116__pad_and_outputIcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xeb>
1000017ad:	callq	206 <__ZNSt3__1L15__get_nullptr_tEv>
1000017b2:	leaq	-88(%rbp), %rdi
1000017b6:	callq	1469 <dyld_stub_binder+0x100001d78>
1000017bb:	xorl	%r13d, %r13d
1000017be:	movq	%r13, %rax
1000017c1:	addq	$56, %rsp
1000017c5:	popq	%rbx
1000017c6:	popq	%r12
1000017c8:	popq	%r13
1000017ca:	popq	%r14
1000017cc:	popq	%r15
1000017ce:	popq	%rbp
1000017cf:	retq
1000017d0:	movq	%rax, %rbx
1000017d3:	leaq	-88(%rbp), %rdi
1000017d7:	callq	1436 <dyld_stub_binder+0x100001d78>
1000017dc:	movq	%rbx, %rdi
1000017df:	callq	1404 <dyld_stub_binder+0x100001d60>
1000017e4:	ud2
1000017e6:	movq	%rax, %rdi
1000017e9:	callq	130 <___clang_call_terminate>
1000017ee:	nop

__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1ERNS_13basic_ostreamIcS2_EE:
1000017f0:	pushq	%rbp
1000017f1:	movq	%rsp, %rbp
1000017f4:	popq	%rbp
1000017f5:	jmp	1094 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2ERNS_13basic_ostreamIcS2_EE>
1000017fa:	nopw	(%rax,%rax)

__ZNKSt3__18ios_base5flagsEv:
100001800:	pushq	%rbp
100001801:	movq	%rsp, %rbp
100001804:	movl	8(%rdi), %eax
100001807:	popq	%rbp
100001808:	retq
100001809:	nopl	(%rax)

__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv:
100001810:	pushq	%rbp
100001811:	movq	%rsp, %rbp
100001814:	pushq	%rbx
100001815:	pushq	%rax
100001816:	movq	%rdi, %rbx
100001819:	callq	1154 <__ZNSt3__111char_traitsIcE3eofEv>
10000181e:	movl	144(%rbx), %esi
100001824:	movl	%eax, %edi
100001826:	callq	1125 <__ZNSt3__111char_traitsIcE11eq_int_typeEii>
10000182b:	testb	%al, %al
10000182d:	je	17 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillEv+0x30>
10000182f:	movq	%rbx, %rdi
100001832:	callq	1145 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc>
100001837:	movsbl	%al, %eax
10000183a:	movl	%eax, 144(%rbx)
100001840:	movsbl	144(%rbx), %eax
100001847:	addq	$8, %rsp
10000184b:	popq	%rbx
10000184c:	popq	%rbp
10000184d:	retq
10000184e:	nop

__ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedEv:
100001850:	pushq	%rbp
100001851:	movq	%rsp, %rbp
100001854:	cmpq	$0, (%rdi)
100001858:	sete	%al
10000185b:	popq	%rbp
10000185c:	retq
10000185d:	nopl	(%rax)

__ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateEj:
100001860:	pushq	%rbp
100001861:	movq	%rsp, %rbp
100001864:	popq	%rbp
100001865:	jmp	1254 <__ZNSt3__18ios_base8setstateEj>
10000186a:	nopw	(%rax,%rax)

___clang_call_terminate:
100001870:	pushq	%rax
100001871:	callq	1336 <dyld_stub_binder+0x100001dae>
100001876:	callq	1313 <dyld_stub_binder+0x100001d9c>
10000187b:	nopl	(%rax,%rax)

__ZNSt3__1L15__get_nullptr_tEv:
100001880:	pushq	%rbp
100001881:	movq	%rsp, %rbp
100001884:	subq	$16, %rsp
100001888:	leaq	-8(%rbp), %rdi
10000188c:	callq	111 <__ZNSt3__19nullptr_tC1EMNS0_5__natEi>
100001891:	movq	-8(%rbp), %rax
100001895:	addq	$16, %rsp
100001899:	popq	%rbp
10000189a:	retq
10000189b:	nopl	(%rax,%rax)

__ZNKSt3__18ios_base5widthEv:
1000018a0:	pushq	%rbp
1000018a1:	movq	%rsp, %rbp
1000018a4:	movq	24(%rdi), %rax
1000018a8:	popq	%rbp
1000018a9:	retq
1000018aa:	nopw	(%rax,%rax)

__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnEPKcl:
1000018b0:	pushq	%rbp
1000018b1:	movq	%rsp, %rbp
1000018b4:	movq	(%rdi), %rax
1000018b7:	movq	96(%rax), %rax
1000018bb:	popq	%rbp
1000018bc:	jmpq	*%rax
1000018be:	nop

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1Emc:
1000018c0:	pushq	%rbp
1000018c1:	movq	%rsp, %rbp
1000018c4:	popq	%rbp
1000018c5:	jmp	86 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2Emc>
1000018ca:	nopw	(%rax,%rax)

__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataEv:
1000018d0:	pushq	%rbp
1000018d1:	movq	%rsp, %rbp
1000018d4:	callq	631 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv>
1000018d9:	movq	%rax, %rdi
1000018dc:	popq	%rbp
1000018dd:	jmp	606 <__ZNSt3__1L16__to_raw_pointerIKcEEPT_S3_>
1000018e2:	nopw	%cs:(%rax,%rax)
1000018ec:	nopl	(%rax)

__ZNSt3__18ios_base5widthEl:
1000018f0:	pushq	%rbp
1000018f1:	movq	%rsp, %rbp
1000018f4:	movq	$0, 24(%rdi)
1000018fc:	popq	%rbp
1000018fd:	retq
1000018fe:	nop

__ZNSt3__19nullptr_tC1EMNS0_5__natEi:
100001900:	pushq	%rbp
100001901:	movq	%rsp, %rbp
100001904:	popq	%rbp
100001905:	jmp	6 <__ZNSt3__19nullptr_tC2EMNS0_5__natEi>
10000190a:	nopw	(%rax,%rax)

__ZNSt3__19nullptr_tC2EMNS0_5__natEi:
100001910:	pushq	%rbp
100001911:	movq	%rsp, %rbp
100001914:	movq	$0, (%rdi)
10000191b:	popq	%rbp
10000191c:	retq
10000191d:	nopl	(%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2Emc:
100001920:	pushq	%rbp
100001921:	movq	%rsp, %rbp
100001924:	pushq	%r15
100001926:	pushq	%r14
100001928:	pushq	%rbx
100001929:	pushq	%rax
10000192a:	movl	%edx, %r14d
10000192d:	movq	%rsi, %r15
100001930:	movq	%rdi, %rbx
100001933:	callq	24 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1Ev>
100001938:	movq	%rbx, %rdi
10000193b:	movq	%r15, %rsi
10000193e:	movl	%r14d, %edx
100001941:	addq	$8, %rsp
100001945:	popq	%rbx
100001946:	popq	%r14
100001948:	popq	%r15
10000194a:	popq	%rbp
10000194b:	jmp	1058 <dyld_stub_binder+0x100001d72>

__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1Ev:
100001950:	pushq	%rbp
100001951:	movq	%rsp, %rbp
100001954:	popq	%rbp
100001955:	jmp	6 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2Ev>
10000195a:	nopw	(%rax,%rax)

__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2Ev:
100001960:	pushq	%rbp
100001961:	movq	%rsp, %rbp
100001964:	popq	%rbp
100001965:	jmp	6 <__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2Ev>
10000196a:	nopw	(%rax,%rax)

__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2Ev:
100001970:	pushq	%rbp
100001971:	movq	%rsp, %rbp
100001974:	movq	$0, 16(%rdi)
10000197c:	movq	$0, 8(%rdi)
100001984:	movq	$0, (%rdi)
10000198b:	popq	%rbp
10000198c:	retq
10000198d:	nopl	(%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE16__set_short_sizeEm:
100001990:	pushq	%rbp
100001991:	movq	%rsp, %rbp
100001994:	pushq	%rbx
100001995:	pushq	%rax
100001996:	movq	%rsi, %rbx
100001999:	addb	%bl, %bl
10000199b:	callq	288 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
1000019a0:	movb	%bl, (%rax)
1000019a2:	addq	$8, %rsp
1000019a6:	popq	%rbx
1000019a7:	popq	%rbp
1000019a8:	retq
1000019a9:	nopl	(%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv:
1000019b0:	pushq	%rbp
1000019b1:	movq	%rsp, %rbp
1000019b4:	callq	263 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
1000019b9:	leaq	1(%rax), %rdi
1000019bd:	callq	286 <__ZNSt3__114pointer_traitsIPcE10pointer_toERc>
1000019c2:	popq	%rbp
1000019c3:	retq
1000019c4:	nopw	%cs:(%rax,%rax)
1000019ce:	nop

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE11__recommendEm:
1000019d0:	cmpq	$23, %rdi
1000019d4:	jae	6 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE11__recommendEm+0xc>
1000019d6:	movl	$22, %eax
1000019db:	retq
1000019dc:	pushq	%rbp
1000019dd:	movq	%rsp, %rbp
1000019e0:	incq	%rdi
1000019e3:	callq	280 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE10__align_itILm16EEEmm>
1000019e8:	movq	%rax, %rcx
1000019eb:	decq	%rax
1000019ee:	cmpq	$23, %rax
1000019f2:	cmoveq	%rcx, %rax
1000019f6:	popq	%rbp
1000019f7:	retq
1000019f8:	nopl	(%rax,%rax)

__ZNSt3__116allocator_traitsINS_9allocatorIcEEE8allocateERS2_m:
100001a00:	pushq	%rbp
100001a01:	movq	%rsp, %rbp
100001a04:	callq	263 <__ZNSt3__19allocatorIcE8allocateEmPKv>
100001a09:	popq	%rbp
100001a0a:	retq
100001a0b:	nopl	(%rax,%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__set_long_pointerEPc:
100001a10:	pushq	%rbp
100001a11:	movq	%rsp, %rbp
100001a14:	pushq	%rbx
100001a15:	pushq	%rax
100001a16:	movq	%rsi, %rbx
100001a19:	callq	162 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001a1e:	movq	%rbx, 16(%rax)
100001a22:	addq	$8, %rsp
100001a26:	popq	%rbx
100001a27:	popq	%rbp
100001a28:	retq
100001a29:	nopl	(%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE14__set_long_capEm:
100001a30:	pushq	%rbp
100001a31:	movq	%rsp, %rbp
100001a34:	pushq	%rbx
100001a35:	pushq	%rax
100001a36:	movq	%rsi, %rbx
100001a39:	orq	$1, %rbx
100001a3d:	callq	126 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001a42:	movq	%rbx, (%rax)
100001a45:	addq	$8, %rsp
100001a49:	popq	%rbx
100001a4a:	popq	%rbp
100001a4b:	retq
100001a4c:	nopl	(%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE15__set_long_sizeEm:
100001a50:	pushq	%rbp
100001a51:	movq	%rsp, %rbp
100001a54:	pushq	%rbx
100001a55:	pushq	%rax
100001a56:	movq	%rsi, %rbx
100001a59:	callq	98 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001a5e:	movq	%rbx, 8(%rax)
100001a62:	addq	$8, %rsp
100001a66:	popq	%rbx
100001a67:	popq	%rbp
100001a68:	retq
100001a69:	nopl	(%rax)

__ZNSt3__111char_traitsIcE6assignEPcmc:
100001a70:	pushq	%rbp
100001a71:	movq	%rsp, %rbp
100001a74:	pushq	%r14
100001a76:	pushq	%rbx
100001a77:	movq	%rdi, %r14
100001a7a:	testq	%rsi, %rsi
100001a7d:	je	24 <__ZNSt3__111char_traitsIcE6assignEPcmc+0x27>
100001a7f:	movq	%rsi, %rbx
100001a82:	movsbl	%dl, %edi
100001a85:	callq	166 <__ZNSt3__111char_traitsIcE11to_int_typeEc>
100001a8a:	movq	%r14, %rdi
100001a8d:	movl	%eax, %esi
100001a8f:	movq	%rbx, %rdx
100001a92:	callq	803 <dyld_stub_binder+0x100001dba>
100001a97:	movq	%r14, %rax
100001a9a:	popq	%rbx
100001a9b:	popq	%r14
100001a9d:	popq	%rbp
100001a9e:	retq
100001a9f:	nop

__ZNSt3__1L16__to_raw_pointerIcEEPT_S2_:
100001aa0:	pushq	%rbp
100001aa1:	movq	%rsp, %rbp
100001aa4:	movq	%rdi, %rax
100001aa7:	popq	%rbp
100001aa8:	retq
100001aa9:	nopl	(%rax)

__ZNSt3__111char_traitsIcE6assignERcRKc:
100001ab0:	pushq	%rbp
100001ab1:	movq	%rsp, %rbp
100001ab4:	movb	(%rsi), %al
100001ab6:	movb	%al, (%rdi)
100001ab8:	popq	%rbp
100001ab9:	retq
100001aba:	nopw	(%rax,%rax)

__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv:
100001ac0:	pushq	%rbp
100001ac1:	movq	%rsp, %rbp
100001ac4:	callq	7 <__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv>
100001ac9:	popq	%rbp
100001aca:	retq
100001acb:	nopl	(%rax,%rax)

__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv:
100001ad0:	pushq	%rbp
100001ad1:	movq	%rsp, %rbp
100001ad4:	movq	%rdi, %rax
100001ad7:	popq	%rbp
100001ad8:	retq
100001ad9:	nopl	(%rax)

__ZNSt3__114pointer_traitsIPcE10pointer_toERc:
100001ae0:	pushq	%rbp
100001ae1:	movq	%rsp, %rbp
100001ae4:	callq	7 <__ZNSt3__1L9addressofIcEEPT_RS1_>
100001ae9:	popq	%rbp
100001aea:	retq
100001aeb:	nopl	(%rax,%rax)

__ZNSt3__1L9addressofIcEEPT_RS1_:
100001af0:	pushq	%rbp
100001af1:	movq	%rsp, %rbp
100001af4:	movq	%rdi, %rax
100001af7:	popq	%rbp
100001af8:	retq
100001af9:	nopl	(%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE10__align_itILm16EEEmm:
100001b00:	pushq	%rbp
100001b01:	movq	%rsp, %rbp
100001b04:	leaq	15(%rdi), %rax
100001b08:	andq	$-16, %rax
100001b0c:	popq	%rbp
100001b0d:	retq
100001b0e:	nop

__ZNSt3__19allocatorIcE8allocateEmPKv:
100001b10:	pushq	%rbp
100001b11:	movq	%rsp, %rbp
100001b14:	callq	7 <__ZNSt3__1L17__libcpp_allocateEmm>
100001b19:	popq	%rbp
100001b1a:	retq
100001b1b:	nopl	(%rax,%rax)

__ZNSt3__1L17__libcpp_allocateEmm:
100001b20:	pushq	%rbp
100001b21:	movq	%rsp, %rbp
100001b24:	callq	639 <dyld_stub_binder+0x100001da8>
100001b29:	popq	%rbp
100001b2a:	retq
100001b2b:	nopl	(%rax,%rax)

__ZNSt3__111char_traitsIcE11to_int_typeEc:
100001b30:	pushq	%rbp
100001b31:	movq	%rsp, %rbp
100001b34:	movzbl	%dil, %eax
100001b38:	popq	%rbp
100001b39:	retq
100001b3a:	nopw	(%rax,%rax)

__ZNSt3__1L16__to_raw_pointerIKcEEPT_S3_:
100001b40:	pushq	%rbp
100001b41:	movq	%rsp, %rbp
100001b44:	movq	%rdi, %rax
100001b47:	popq	%rbp
100001b48:	retq
100001b49:	nopl	(%rax)

__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv:
100001b50:	pushq	%rbp
100001b51:	movq	%rsp, %rbp
100001b54:	pushq	%rbx
100001b55:	pushq	%rax
100001b56:	movq	%rdi, %rbx
100001b59:	callq	34 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longEv>
100001b5e:	movq	%rbx, %rdi
100001b61:	addq	$8, %rsp
100001b65:	testb	%al, %al
100001b67:	je	7 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerEv+0x20>
100001b69:	popq	%rbx
100001b6a:	popq	%rbp
100001b6b:	jmp	32 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv>
100001b70:	popq	%rbx
100001b71:	popq	%rbp
100001b72:	jmp	41 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv>
100001b77:	nopw	(%rax,%rax)

__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longEv:
100001b80:	pushq	%rbp
100001b81:	movq	%rsp, %rbp
100001b84:	callq	55 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001b89:	movb	(%rax), %al
100001b8b:	andb	$1, %al
100001b8d:	popq	%rbp
100001b8e:	retq
100001b8f:	nop

__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv:
100001b90:	pushq	%rbp
100001b91:	movq	%rsp, %rbp
100001b94:	callq	39 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001b99:	movq	16(%rax), %rax
100001b9d:	popq	%rbp
100001b9e:	retq
100001b9f:	nop

__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerEv:
100001ba0:	pushq	%rbp
100001ba1:	movq	%rsp, %rbp
100001ba4:	callq	23 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001ba9:	leaq	1(%rax), %rdi
100001bad:	callq	46 <__ZNSt3__114pointer_traitsIPKcE10pointer_toERS1_>
100001bb2:	popq	%rbp
100001bb3:	retq
100001bb4:	nopw	%cs:(%rax,%rax)
100001bbe:	nop

__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv:
100001bc0:	pushq	%rbp
100001bc1:	movq	%rsp, %rbp
100001bc4:	callq	7 <__ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv>
100001bc9:	popq	%rbp
100001bca:	retq
100001bcb:	nopl	(%rax,%rax)

__ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getEv:
100001bd0:	pushq	%rbp
100001bd1:	movq	%rsp, %rbp
100001bd4:	movq	%rdi, %rax
100001bd7:	popq	%rbp
100001bd8:	retq
100001bd9:	nopl	(%rax)

__ZNSt3__114pointer_traitsIPKcE10pointer_toERS1_:
100001be0:	pushq	%rbp
100001be1:	movq	%rsp, %rbp
100001be4:	callq	7 <__ZNSt3__1L9addressofIKcEEPT_RS2_>
100001be9:	popq	%rbp
100001bea:	retq
100001beb:	nopl	(%rax,%rax)

__ZNSt3__1L9addressofIKcEEPT_RS2_:
100001bf0:	pushq	%rbp
100001bf1:	movq	%rsp, %rbp
100001bf4:	movq	%rdi, %rax
100001bf7:	popq	%rbp
100001bf8:	retq
100001bf9:	nopl	(%rax)

__ZNSt3__116allocator_traitsINS_9allocatorIcEEE10deallocateERS2_Pcm:
100001c00:	pushq	%rbp
100001c01:	movq	%rsp, %rbp
100001c04:	popq	%rbp
100001c05:	jmp	22 <__ZNSt3__19allocatorIcE10deallocateEPcm>
100001c0a:	nopw	(%rax,%rax)

__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerEv:
100001c10:	pushq	%rbp
100001c11:	movq	%rsp, %rbp
100001c14:	callq	-345 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstEv>
100001c19:	movq	16(%rax), %rax
100001c1d:	popq	%rbp
100001c1e:	retq
100001c1f:	nop

__ZNSt3__19allocatorIcE10deallocateEPcm:
100001c20:	pushq	%rbp
100001c21:	movq	%rsp, %rbp
100001c24:	popq	%rbp
100001c25:	jmp	6 <__ZNSt3__1L19__libcpp_deallocateEPvm>
100001c2a:	nopw	(%rax,%rax)

__ZNSt3__1L19__libcpp_deallocateEPvm:
100001c30:	pushq	%rbp
100001c31:	movq	%rsp, %rbp
100001c34:	popq	%rbp
100001c35:	jmp	360 <dyld_stub_binder+0x100001da2>
100001c3a:	nopw	(%rax,%rax)

__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2ERNS_13basic_ostreamIcS2_EE:
100001c40:	pushq	%rbp
100001c41:	movq	%rsp, %rbp
100001c44:	pushq	%rbx
100001c45:	pushq	%rax
100001c46:	movq	%rdi, %rbx
100001c49:	movq	(%rsi), %rax
100001c4c:	addq	-24(%rax), %rsi
100001c50:	movq	%rsi, %rdi
100001c53:	callq	24 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufEv>
100001c58:	movq	%rax, (%rbx)
100001c5b:	addq	$8, %rsp
100001c5f:	popq	%rbx
100001c60:	popq	%rbp
100001c61:	retq
100001c62:	nopw	%cs:(%rax,%rax)
100001c6c:	nopl	(%rax)

__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufEv:
100001c70:	pushq	%rbp
100001c71:	movq	%rsp, %rbp
100001c74:	popq	%rbp
100001c75:	jmp	6 <__ZNKSt3__18ios_base5rdbufEv>
100001c7a:	nopw	(%rax,%rax)

__ZNKSt3__18ios_base5rdbufEv:
100001c80:	pushq	%rbp
100001c81:	movq	%rsp, %rbp
100001c84:	movq	40(%rdi), %rax
100001c88:	popq	%rbp
100001c89:	retq
100001c8a:	nopw	(%rax,%rax)

__ZNSt3__111char_traitsIcE11eq_int_typeEii:
100001c90:	pushq	%rbp
100001c91:	movq	%rsp, %rbp
100001c94:	cmpl	%esi, %edi
100001c96:	sete	%al
100001c99:	popq	%rbp
100001c9a:	retq
100001c9b:	nopl	(%rax,%rax)

__ZNSt3__111char_traitsIcE3eofEv:
100001ca0:	pushq	%rbp
100001ca1:	movq	%rsp, %rbp
100001ca4:	movl	$4294967295, %eax
100001ca9:	popq	%rbp
100001caa:	retq
100001cab:	nopl	(%rax,%rax)

__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenEc:
100001cb0:	pushq	%rbp
100001cb1:	movq	%rsp, %rbp
100001cb4:	pushq	%rbx
100001cb5:	pushq	%rax
100001cb6:	movq	%rdi, %rax
100001cb9:	leaq	-16(%rbp), %rbx
100001cbd:	movq	%rbx, %rdi
100001cc0:	movq	%rax, %rsi
100001cc3:	callq	164 <dyld_stub_binder+0x100001d6c>
100001cc8:	movq	%rbx, %rdi
100001ccb:	callq	64 <__ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE>
100001cd0:	movq	%rax, %rdi
100001cd3:	callq	88 <__ZNKSt3__15ctypeIcE5widenEc>
100001cd8:	movl	%eax, %ebx
100001cda:	leaq	-16(%rbp), %rdi
100001cde:	callq	167 <dyld_stub_binder+0x100001d8a>
100001ce3:	movsbl	%bl, %eax
100001ce6:	addq	$8, %rsp
100001cea:	popq	%rbx
100001ceb:	popq	%rbp
100001cec:	retq
100001ced:	movq	%rax, %rbx
100001cf0:	leaq	-16(%rbp), %rdi
100001cf4:	callq	145 <dyld_stub_binder+0x100001d8a>
100001cf9:	movq	%rbx, %rdi
100001cfc:	callq	95 <dyld_stub_binder+0x100001d60>
100001d01:	ud2
100001d03:	movq	%rax, %rdi
100001d06:	callq	-1179 <___clang_call_terminate>
100001d0b:	nopl	(%rax,%rax)

__ZNSt3__1L9use_facetINS_5ctypeIcEEEERKT_RKNS_6localeE:
100001d10:	pushq	%rbp
100001d11:	movq	%rsp, %rbp
100001d14:	movq	765(%rip), %rsi
100001d1b:	callq	70 <dyld_stub_binder+0x100001d66>
100001d20:	popq	%rbp
100001d21:	retq
100001d22:	nopw	%cs:(%rax,%rax)
100001d2c:	nopl	(%rax)

__ZNKSt3__15ctypeIcE5widenEc:
100001d30:	pushq	%rbp
100001d31:	movq	%rsp, %rbp
100001d34:	movq	(%rdi), %rax
100001d37:	movq	56(%rax), %rax
100001d3b:	movl	$32, %esi
100001d40:	popq	%rbp
100001d41:	jmpq	*%rax
100001d43:	nopw	%cs:(%rax,%rax)
100001d4d:	nopl	(%rax)

__ZNSt3__18ios_base8setstateEj:
100001d50:	pushq	%rbp
100001d51:	movq	%rsp, %rbp
100001d54:	movl	32(%rdi), %esi
100001d57:	orl	$5, %esi
100001d5a:	popq	%rbp
100001d5b:	jmp	54 <dyld_stub_binder+0x100001d96>
Disassembly of section __TEXT,__stubs:
__stubs:
100001d60:	jmpq	*706(%rip)
100001d66:	jmpq	*708(%rip)
100001d6c:	jmpq	*710(%rip)
100001d72:	jmpq	*712(%rip)
100001d78:	jmpq	*714(%rip)
100001d7e:	jmpq	*716(%rip)
100001d84:	jmpq	*718(%rip)
100001d8a:	jmpq	*720(%rip)
100001d90:	jmpq	*722(%rip)
100001d96:	jmpq	*724(%rip)
100001d9c:	jmpq	*726(%rip)
100001da2:	jmpq	*728(%rip)
100001da8:	jmpq	*730(%rip)
100001dae:	jmpq	*732(%rip)
100001db4:	jmpq	*734(%rip)
100001dba:	jmpq	*736(%rip)
100001dc0:	jmpq	*738(%rip)
Disassembly of section __TEXT,__stub_helper:
__stub_helper:
100001dc8:	leaq	569(%rip), %r11
100001dcf:	pushq	%r11
100001dd1:	jmpq	*553(%rip)
100001dd7:	nop
100001dd8:	pushq	$22
100001ddd:	jmp	-26 <__stub_helper>
100001de2:	pushq	$67
100001de7:	jmp	-36 <__stub_helper>
100001dec:	pushq	$103
100001df1:	jmp	-46 <__stub_helper>
100001df6:	pushq	$184
100001dfb:	jmp	-56 <__stub_helper>
100001e00:	pushq	$259
100001e05:	jmp	-66 <__stub_helper>
100001e0a:	pushq	$328
100001e0f:	jmp	-76 <__stub_helper>
100001e14:	pushq	$394
100001e19:	jmp	-86 <__stub_helper>
100001e1e:	pushq	$422
100001e23:	jmp	-96 <__stub_helper>
100001e28:	pushq	$485
100001e2d:	jmp	-106 <__stub_helper>
100001e32:	pushq	$519
100001e37:	jmp	-116 <__stub_helper>
100001e3c:	pushq	$542
100001e41:	jmp	-126 <__stub_helper>
100001e46:	pushq	$568
100001e4b:	jmp	-136 <__stub_helper>
100001e50:	pushq	$0
100001e55:	jmp	-146 <__stub_helper>
100001e5a:	pushq	$592
100001e5f:	jmp	-156 <__stub_helper>
100001e64:	pushq	$607
100001e69:	jmp	-166 <__stub_helper>
