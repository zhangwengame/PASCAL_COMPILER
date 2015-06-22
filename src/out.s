.PRINTF_U:
	.string "%u"
.PRINTF_U_N:
	.string "%u\n"
.PRINTF_F:
	.string "%lf"
.PRINTF_F_N:
	.string "%lf\n"
_REALNUM0:
	.double 1.200000
.text
.globl main
	.type main, @function
main:
pushl %ebp
movl %esp, %ebp
movl %esp, %ecx
subl $12, %esp
movl $5, %eax	# calculate int ExpConst 
pushl %eax
movl $-12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl _REALNUM0, %eax	# calculate real ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
popl %eax
movl %eax, -0(%esi)	# assign
movl $-12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_U_N
call printf
addl $8, %esp
popa
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pusha
pushl %eax
fldl (%esp)
subl $4, %esp
fstpl (%esp)
pushl $.PRINTF_F_N
call printf
addl $8, %esp
popl %eax
popa
addl $12, %esp
leave
ret
