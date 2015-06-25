.text
.globl main
	.type main, @function
main:
pushl %ebp
movl %esp, %ebp
movl %esp, %ecx
subl $28, %esp
movl $._REALNUM0, %ebx	# calculate real ExpConst 
movl (%ebx), %eax
pushl %eax
movl $-20, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
popl %eax
movl %eax, -0(%esi)	# assign
movl $-20, %edi
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
pushl $0
movl $._REALNUM1, %ebx	# calculate real ExpConst 
movl (%ebx), %eax
pushl %eax
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fsubp
subl $4, %esp
fstps (%esp)
popl %eax
pushl %eax
movl $-24, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
popl %eax
movl %eax, -0(%esi)	# assign
movl $-24, %edi
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
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
faddp
subl $4, %esp
fstps (%esp)
popl %eax
pushl %eax
movl $._REALNUM2, %ebx	# calculate real ExpConst 
movl (%ebx), %eax
pushl %eax
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fsubp
subl $4, %esp
fstps (%esp)
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
flds (%esp)
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
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fmulp
subl $4, %esp
fstps (%esp)
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
flds (%esp)
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
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fdivp
subl $4, %esp
fstps (%esp)
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
flds (%esp)
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
movl $._REALNUM3, %ebx	# calculate real ExpConst 
movl (%ebx), %eax
pushl %eax
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fucomip %st(1),%st
fstp %st(0)
movl $0x0, %eax
setb %al
cmpl $1, %eax
je __CG__label0 
jmp __CG__label1
__CG__label0:
movl $123, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
jmp __CG__label2
__CG__label1: 
movl $0, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
__CG__label2: 
movl $-28, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pushl %eax
movl $1, %eax	# calculate int ExpConst 
pushl %eax
filds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fucomip %st(1),%st
fstp %st(0)
movl $0x0, %eax
setb %al
cmpl $1, %eax
je __CG__label3 
jmp __CG__label4
__CG__label3:
movl $321, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
jmp __CG__label5
__CG__label4: 
movl $111, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
__CG__label5: 
movl $-28, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax
pushl %eax
pushl $0
movl $._REALNUM4, %ebx	# calculate real ExpConst 
movl (%ebx), %eax
pushl %eax
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fsubp
subl $4, %esp
fstps (%esp)
popl %eax
pushl %eax
flds (%esp)
flds 4(%esp)
popl %eax
popl %eax
fucomip %st(1),%st
fstp %st(0)
movl $0x0, %eax
sete %al
cmpl $1, %eax
je __CG__label6 
jmp __CG__label7
__CG__label6:
movl $666, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
jmp __CG__label8
__CG__label7: 
movl $111, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
movl $999, %eax	# calculate int ExpConst 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
__CG__label8: 
movl $2, %eax	# calculate int ExpConst 
pushl %eax
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
popl %eax
movl %eax, -0(%esi)	# assign
movl $-8, %edi
movl %ecx, %esi
addl %edi, %esi
movl (%esi), %eax	# calculate ExpId 
pusha
pushl %eax
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
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
pushl $.PRINTF_I_N
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
pushl $.PRINTF_I_N
call printf
addl $8, %esp
popa
addl $28, %esp
leave
ret
