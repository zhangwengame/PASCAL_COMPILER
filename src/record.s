.PRINTF_I:
	.string "%i"
.PRINTF_I_N:
	.string "%i\n"
.PRINTF_F:
	.string "%f"
.PRINTF_F_N:
	.string "%f\n"
._REALNUM0:
	.float 1.200000
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
movl $._REALNUM0, %ebx	# calculate real ExpConst 
movl (%ebx), %eax
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
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pusha
pushl %eax
flds (%esp)
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
