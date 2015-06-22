.PRINTF_U:
	.string "%u"
.PRINTF_U_N:
	.string "%u\n"
.PRINTF_F:
	.string "%f"
.PRINTF_F_N:
	.string "%f\n"
.text
gcd: 
subl $4, %esp
movl $8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $0, %eax	# calculate int ExpConst 
pushl %eax
popl %ebx
popl %eax
cmpl %ebx, %eax
movl $0, %eax
seteb %al
cmpl $1, %eax
je __CG__label0 
jmp __CG__label1
__CG__label0:
movl $4, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
jmp __CG__label2
__CG__label1: 
pushl %eax
movl $4, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
popl %ebx
popl %eax
xorl %edx, %edx
idivl %ebx
movl %edx, %eax
pushl %eax
movl $8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
pushl %ecx
movl %esp, %ecx
call gcd
popl %ecx
popl %eax
popl %eax
popl %eax
pushl %eax
movl $12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
__CG__label2: 
addl $4, %esp
ret
.globl main
	.type main, @function
main:
pushl %ebp
movl %esp, %ebp
movl %esp, %ecx
subl $12, %esp
pushl %eax
movl $24, %eax	# calculate int ExpConst 
pushl %eax
movl $36, %eax	# calculate int ExpConst 
pushl %eax
pushl %ecx
movl %esp, %ecx
call gcd
popl %ecx
popl %eax
popl %eax
popl %eax
pushl %eax
movl $-12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_U
call printf
addl $8, %esp
popa
addl $12, %esp
leave
ret
