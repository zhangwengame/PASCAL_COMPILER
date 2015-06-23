.text
.globl main
	.type main, @function
main:
pushl %ebp
movl %esp, %ebp
movl %esp, %ecx
subl $28, %esp
movl $_REALNUM0, %eax	# calculate real ExpConst 
pushl %eax
movl $-20, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
popl %eax
movl %eax, -0(%esi)	# assign
pushl $0
movl $_REALNUM1, %eax	# calculate real ExpConst 
pushl %eax
fldl $4(%esp)
fldl (%esp)
popl %eax
popl %eax
fsub
subl $4, %esp
fstpll (%esp)
popl %eax
pushl %eax
movl $-24, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
popl %eax
movl %eax, -0(%esi)	# assign
movl $-20, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pushl %eax
movl $-24, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pushl %eax
fldl $4(%esp)
fldl (%esp)
popl %eax
popl %eax
fadd
subl $4, %esp
fstpll (%esp)
popl %eax
pushl %eax
movl $_REALNUM2, %eax	# calculate real ExpConst 
pushl %eax
fldl $4(%esp)
fldl (%esp)
popl %eax
popl %eax
fsub
subl $4, %esp
fstpll (%esp)
popl %eax
pushl %eax
movl $-28, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
popl %eax
movl %eax, -0(%esi)	# assign
movl $-28, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pusha
pushl %eax
flds (%eax)
subl $4, %esp
fstpl (%esp)
pushl $.PRINTF_F_N
call printf
addl $8, %esp
popl %eax
popa
movl $-20, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pushl %eax
movl $-24, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pushl %eax
fldl $4(%esp)
fldl (%esp)
popl %eax
popl %eax
fmul
subl $4, %esp
fstpll (%esp)
popl %eax
pushl %eax
movl $-28, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
popl %eax
movl %eax, -0(%esi)	# assign
movl $-28, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pusha
pushl %eax
flds (%eax)
subl $4, %esp
fstpl (%esp)
pushl $.PRINTF_F_N
call printf
addl $8, %esp
popl %eax
popa
movl $-28, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pushl %eax
movl $_REALNUM3, %eax	# calculate real ExpConst 
pushl %eax
fldl $4(%esp)
fldl (%esp)
popl %eax
popl %eax
fcom
subl $4, %esp
fstpll (%esp)
popl %eax
cmpl $1, %eax
je __CG__label0 
jmp __CG__label1
__CG__label0:
movl $1, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_U_N
call printf
addl $8, %esp
popa
jmp __CG__label2
__CG__label1: 
movl $0, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_U_N
call printf
addl $8, %esp
popa
__CG__label2: 
movl $2, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
pushl $0
movl $3, %eax	# calculate int ExpConst 
pushl %eax
popl %ebx
popl %eax
subl %ebx, %eax
pushl %eax
movl $-12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $-12, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pushl %eax
popl %ebx
popl %eax
xorl %edx, %edx
imull %ebx
pushl %eax
movl $-16, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-16, %edi
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
movl (%esi), %eax	# calculate ExpId 
pushl %eax
movl $-12, %edi
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
movl $-16, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-16, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_U_N
call printf
addl $8, %esp
popa
addl $28, %esp
leave
ret
